<?php

namespace App\Controller;

use App\Entity\Article;
use App\Repository\ArticleRepository;
use Doctrine\ORM\EntityManagerInterface;
use Symfony\Contracts\Cache\ItemInterface;
use Symfony\Component\HttpFoundation\Request;
use Symfony\Component\HttpFoundation\Response;
use Symfony\Component\Routing\Annotation\Route;
use Symfony\Component\HttpFoundation\JsonResponse;
use Symfony\Contracts\Cache\TagAwareCacheInterface;
use JMS\Serializer\SerializationContext;
use JMS\Serializer\SerializerInterface;
use Symfony\Component\Validator\Validator\ValidatorInterface;
use Symfony\Component\Routing\Generator\UrlGeneratorInterface;
use Sensio\Bundle\FrameworkExtraBundle\Configuration\IsGranted;
use Symfony\Bundle\FrameworkBundle\Controller\AbstractController;

class ArticleController extends AbstractController
{
    #[Route('/api/Articles', name: 'Articles', methods: ['GET'])]
    public function getAllArticles(ArticleRepository $ArticleRepository, SerializerInterface $serializer, Request $request, TagAwareCacheInterface $cachePool): JsonResponse
    {
        $page = $request->get('page', 1); // get page number from query string
        $limit = $request->get('limit', 100); // 100 is the default limit for pagination

        $idCache = "getAllArticles-" . $page . "-" . $limit;
        
        $jsonArticleList = $cachePool->get($idCache, function (ItemInterface $item) use ($ArticleRepository, $page, $limit, $serializer) {
            $item->tag("ArticlesCache");
            $item->expiresAfter(60);
            $ArticleList = $ArticleRepository->findAll();
            $context = SerializationContext::create()->setGroups(['getArticles']);
            return $serializer->serialize($ArticleList, 'json', $context);
        });
      
        return new JsonResponse($jsonArticleList, Response::HTTP_OK, [], true);
   }

   #[Route('/api/Articles/{id}', name: 'detailArticle', methods: ['GET'])]
   public function getDetailArticle(Article $Article, SerializerInterface $serializer): JsonResponse 
   {
       $context = SerializationContext::create()->setGroups(['getArticles']);
       $jsonArticle = $serializer->serialize($Article, 'json', $context);
       return new JsonResponse($jsonArticle, Response::HTTP_OK, [], true);
   }

    #[Route('/api/Articles/{id}', name: 'deleteArticle', methods: ['DELETE'])]
    #[IsGranted('ROLE_ADMIN', message: 'Vous n\'avez pas les droits suffisants pour supprimer un livre')]
    public function deleteArticle(Article $Article, EntityManagerInterface $em, TagAwareCacheInterface $cachePool): JsonResponse 
    {
        $cachePool->invalidateTags(["ArticlesCache"]);
        $em->remove($Article);
        $em->flush();
        return new JsonResponse(null, Response::HTTP_NO_CONTENT);
    }

    #[Route('/api/Articles', name:"createArticle", methods: ['POST'])]
    #[IsGranted('ROLE_ADMIN', message: 'Vous n\'avez pas les droits suffisants pour créer un livre')]
    public function createArticle(Request $request, SerializerInterface $serializer, EntityManagerInterface $em, UrlGeneratorInterface $urlGenerator, ValidatorInterface $validator): JsonResponse 
    {
        $Article = $serializer->deserialize($request->getContent(), Article::class, 'json');
        
        // On vérifie les erreurs
        $errors = $validator->validate($Article);

        if ($errors->count() > 0) {
            return new JsonResponse($serializer->serialize($errors, 'json'), JsonResponse::HTTP_BAD_REQUEST, [], true);
        }
    
        $em->persist($Article);
        $em->flush();

        $context = SerializationContext::create()->setGroups(['getArticles']);
        $jsonArticle = $serializer->serialize($Article, 'json', $context);
        $location = $urlGenerator->generate('detailArticle', ['id' => $Article->getId()], UrlGeneratorInterface::ABSOLUTE_URL);

        return new JsonResponse($jsonArticle, Response::HTTP_CREATED, ["Location" => $location], true);

    }

    #[Route('/api/Articles/{id}', name:"updateArticle", methods:['PUT'])]
    #[IsGranted('ROLE_ADMIN', message: 'Vous n\'avez pas les droits suffisants pour éditer un livre')]
    public function updateArticle(Request $request, SerializerInterface $serializer, Article $currentArticle, EntityManagerInterface $em, ValidatorInterface $validator, TagAwareCacheInterface $cache): JsonResponse 
    {
        $newArticle = $serializer->deserialize($request->getContent(), Article::class, 'json');
        $currentArticle->setTitle($newArticle->getTitle());
        $currentArticle->setDescription($newArticle->getDescription());

        // On vérifie les erreurs
        $errors = $validator->validate($currentArticle);
        if ($errors->count() > 0) {
            return new JsonResponse($serializer->serialize($errors, 'json'), JsonResponse::HTTP_BAD_REQUEST, [], true);
        }
    
        $em->persist($currentArticle);
        $em->flush();

        // On vide le cache.
        $cache->invalidateTags(["ArticlesCache"]);

        return new JsonResponse(null, JsonResponse::HTTP_NO_CONTENT);
    }
}