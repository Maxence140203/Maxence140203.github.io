<?php

namespace App\Controller;

use App\Entity\User;
use App\Repository\UserRepository;
use Doctrine\ORM\EntityManagerInterface;
use JMS\Serializer\SerializationContext;
use Symfony\Component\HttpFoundation\Request;
use Symfony\Component\HttpFoundation\Response;
use Symfony\Component\Routing\Annotation\Route;
use Symfony\Component\HttpFoundation\JsonResponse;
use Symfony\Component\Validator\Validator\ValidatorInterface;
use Symfony\Component\Routing\Generator\UrlGeneratorInterface;
use Symfony\Bundle\FrameworkBundle\Controller\AbstractController;
use JMS\Serializer\SerializerInterface;
use Symfony\Component\PasswordHasher\Hasher\UserPasswordHasherInterface;

class UserController extends AbstractController
{
    #[Route('/api/users', name: 'users', methods: ['GET'])]
    public function getAllUsers(UserRepository $UserRepository, SerializerInterface $serializer): JsonResponse
    {
        $UserList = $UserRepository->findAll();

        $context = SerializationContext::create()->setGroups(['getUser']);
        $jsonUserList = $serializer->serialize($UserList, 'json', $context);

        return new JsonResponse($jsonUserList, Response::HTTP_OK, [], true);
    }



    #[Route('/api/user/{username}', name: 'user_detail_username', methods: ['GET'])]
    public function getDetailUserByUsername(User $User, SerializerInterface $serializer): JsonResponse
    {
        $context = SerializationContext::create()->setGroups(['getUser']);
        $jsonUser = $serializer->serialize($User, 'json', $context);

        return new JsonResponse($jsonUser, Response::HTTP_OK, [], true);
    }

    #[Route('/api/users', name: 'add_user', methods: ['POST'])]
    public function addUser(Request $request, SerializerInterface $serializer, EntityManagerInterface $em, UrlGeneratorInterface $urlGenerator, ValidatorInterface $validator, UserPasswordHasherInterface $userPasswordHasher): JsonResponse
    {
        $User = $serializer->deserialize($request->getContent(), User::class, 'json');
        $User->setRoles(["ROLE_USER"]);
        $User->setPassword($userPasswordHasher->hashPassword($User, $User->getPassword()));

        // On vérifie les erreurs
        $errors = $validator->validate($User);

        if ($errors->count() > 0) {
            return new JsonResponse($serializer->serialize($errors, 'json'), JsonResponse::HTTP_BAD_REQUEST, [], true);
        }

        $em->persist($User);
        $em->flush();

        return new JsonResponse(
            $serializer->serialize($User, 'json', SerializationContext::create()->setGroups(['getUser'])),
            JsonResponse::HTTP_CREATED,
            [
                'Location' => $urlGenerator->generate('user_detail_username', ['username' => $User->getUsername()], UrlGeneratorInterface::ABSOLUTE_URL)
            ],
            true
        );
    }


    //create User


}
