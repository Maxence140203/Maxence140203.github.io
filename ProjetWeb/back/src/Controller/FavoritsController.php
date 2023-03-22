<?php

namespace App\Controller;

use App\Entity\Favorits;
use App\Repository\FavoritsRepository;
use JMS\Serializer\SerializerInterface;
use Doctrine\ORM\EntityManagerInterface;
use JMS\Serializer\SerializationContext;
use Symfony\Contracts\Cache\ItemInterface;
use Symfony\Component\HttpFoundation\Request;
use Symfony\Component\HttpFoundation\Response;
use Symfony\Component\Routing\Annotation\Route;
use Symfony\Component\HttpFoundation\JsonResponse;
use Symfony\Contracts\Cache\TagAwareCacheInterface;
use Symfony\Bundle\FrameworkBundle\Controller\AbstractController;

class FavoritsController extends AbstractController
{


    #[Route('/api/favorits', name: 'all_fav', methods: ['GET'])]
    public function getAllFavorits(FavoritsRepository $FavoritsRepository, SerializerInterface $serializer, TagAwareCacheInterface $cache): JsonResponse
    {
        $FavoritsList = $cache->get('favorits', function (ItemInterface $item) use ($FavoritsRepository) {
            $item->tag('favorits');
            return $FavoritsRepository->findAll();
        });

        $context = SerializationContext::create()->setGroups(['getFavorits']);
        $jsonFavoritsList = $serializer->serialize($FavoritsList, 'json', $context);

        return new JsonResponse($jsonFavoritsList, Response::HTTP_OK, [], true);
    }

    #[Route('/api/favorits/{id}', name: 'one_fav', methods: ['GET'])]
    public function getOneFavorits(int $id, FavoritsRepository $FavoritsRepository, SerializerInterface $serializer, TagAwareCacheInterface $cache): JsonResponse
    {
        $Favorits = $cache->get('favorits_' . $id, function (ItemInterface $item) use ($FavoritsRepository, $id) {
            $item->tag('favorits');
            return $FavoritsRepository->find($id);
        });

        $context = SerializationContext::create()->setGroups(['getFavorits']);
        $jsonFavorits = $serializer->serialize($Favorits, 'json', $context);

        return new JsonResponse($jsonFavorits, Response::HTTP_OK, [], true);
    }

    #[Route('/api/favorits', name: 'post_fav', methods: ['POST'])]
    public function postFavorits(Request $request, SerializerInterface $serializer, EntityManagerInterface $em, TagAwareCacheInterface $cache): JsonResponse
    {
        $Favorits = $serializer->deserialize($request->getContent(), Favorits::class, 'json');

        $em->persist($Favorits);
        $em->flush();

        $cache->invalidateTags(['favorits']);

        return new JsonResponse(
            $serializer->serialize($Favorits, 'json', SerializationContext::create()->setGroups(['getFavorits'])),
            JsonResponse::HTTP_CREATED,
            [],
            true
        );
    }

    #[Route('/api/favorits/{id_article}', name: 'delete_Fav_by_article', methods: ['DELETE'])]
    public function deleteFavoritsByArticle(int $id_article, FavoritsRepository $FavoritsRepository, EntityManagerInterface $em, TagAwareCacheInterface $cache): JsonResponse
    {
        $Favorits = $FavoritsRepository->findOneBy(['id_article' => $id_article]);

        $em->remove($Favorits);
        $em->flush();

        $cache->invalidateTags(['favorits']);

        return new JsonResponse(null, JsonResponse::HTTP_NO_CONTENT);
    }
}
