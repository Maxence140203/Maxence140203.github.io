<?php

namespace App\Entity;

use App\Repository\FavoritsRepository;
use Doctrine\ORM\Mapping as ORM;
use JMS\Serializer\Annotation\Groups;

#[ORM\Entity(repositoryClass: FavoritsRepository::class)]
class Favorits
{
    #[ORM\Id]
    #[ORM\GeneratedValue]
    #[ORM\Column]
    #[Groups(["getFavorits"])]
    private ?int $id = null;

    #[ORM\Column]
    #[Groups(["getFavorits"])]
    private ?int $id_article = null;

    #[ORM\Column]
    #[Groups(["getFavorits"])]
    private ?int $id_user = null;

    public function getId(): ?int
    {
        return $this->id;
    }

    public function getid_article(): ?int
    {
        return $this->id_article;
    }

    public function setid_article(int $id_article): self
    {
        $this->idAArticle = $id_article;

        return $this;
    }

    public function getid_user(): ?int
    {
        return $this->id_user;
    }

    public function setid_user(int $id_user): self
    {
        $this->id_user = $id_user;

        return $this;
    }
}
