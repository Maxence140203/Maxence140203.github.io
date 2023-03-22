<?php
// src\DataFixtures\AppFixtures.php

namespace App\DataFixtures;

use App\Entity\Article;
use App\Entity\User;
use Doctrine\Persistence\ObjectManager;
use Doctrine\Bundle\FixturesBundle\Fixture;
use Symfony\Component\PasswordHasher\Hasher\UserPasswordHasherInterface;

class AppFixtures extends Fixture
{
    private $userPasswordHasher;

    public function __construct(UserPasswordHasherInterface $userPasswordHasher)
    {
        $this->userPasswordHasher = $userPasswordHasher;
    }

    public function load(ObjectManager $manager): void
    {
        $cat = ["sport", "science", "mode", "politique"];
        // Création d'un user "normal"
        $user = new User();
        $user->setUsername("user");
        $user->setRoles(["ROLE_USER"]);
        $user->setPassword($this->userPasswordHasher->hashPassword($user, "password"));
        $manager->persist($user);

        // Création d'un user admin
        $userAdmin = new User();
        $userAdmin->setUsername("admin");
        $userAdmin->setRoles(["ROLE_ADMIN"]);
        $userAdmin->setPassword($this->userPasswordHasher->hashPassword($userAdmin, "password"));
        $manager->persist($userAdmin);

        for ($i = 0; $i < 20; $i++) {
            $Article = new Article();
            $Article->setTitle("Titre " . $i);
            $Article->setdescription("Descrition de l'article numéro : " . $i);
            //random category between sport science mode politique
            $RandomNumber = rand(0, 3);
            $Article->setCategory($cat[$RandomNumber]);
            $manager->persist($Article);
        }

        $manager->flush();
    }
}
