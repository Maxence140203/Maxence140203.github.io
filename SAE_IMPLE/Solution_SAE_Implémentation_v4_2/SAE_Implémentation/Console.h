//////////////////////////////////////////////////////////////////////
//! \file Console.h
//!
//! \brief Ce fichier contient la déclaration des différentes fonctions 
//! d'affichage permettant d'afficher les images avec différentes palettes
//! dans la console.
//!
//! Dans ce ficher nous avons la fonction affichageConsole qui permet d'afficher
//! simplement un image dans la console en prenant en parametres l'image à traiter,
//! la palette a utiliser, la largeur de l'image en pixel et enfin le nombre de pixels 
//! à traiter. 
//! Nous avons aussi la fonction affichagev1 qui affiche l'image en utilisant des 
//! caractères ASCII en fonction des nuances de gris de l'image. Et elle prend en 
//! paramètres le nombre de pixels à traiter et la largeur de l'image en pixel.
//! Ensuite nous avons la fonction affichagev2 qui affiche l'image en utilisant 
//! des caractères d'une palette en fonction des nuances de gris de l'image.
//! Et elle prend en paramètres le nombre de pixels à traiter, la largeur de l'image
//! en pixel et la palette à utiliser.
//! Et enfin nous avons la fonction affichagev3 qui affiche l'image en utilisant
//! des caractères d'une palette en fonction des nuances de gris de l'image.
//! Et elle prend en paramètres l'image a traiter, le nombre de pixels à traiter, 
//! la largeur de l'image en pixel, la palette à utiliser et le fichier de sortie.
//!
//! \date mardi 9 novembre 2021
//! \version 1.0
//////////////////////////////////////////////////////////////////////



#pragma once
#include <vector>

void affichagev1(std::vector<int> nbs, int largeur);

void affichagev2(std::vector<int> nbs, int largeur, std::vector<std::string> palette);

void affichagev3(std::vector<char> donnees, std::vector<std::string> palette, int largeur, int pix, std::string outfile_name);

void affichage_console(std::vector<char> donnees, std::vector<std::string> palette, int largeur, int pix);