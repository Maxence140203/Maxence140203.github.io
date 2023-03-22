//////////////////////////////////////////////////////////////////////
//! \file Fonctions.h
//!
//! \brief Ce fichier contient la déclaration des différentes fonctions 
//! permettant différentes opérations sur les images.
//!
//! Dans ce ficher nous avons la fonction convertir_int qui permet de convertir
//! chaque pixel de l'image en un entier. Et elle prend en paramètre l'image
//! à convertir.
//! Nous avons aussi la fonction decripteur qui permet de récupérer et 
//! de décoder l'entète de l'image. Et elle prend en paramètre le fichier de 
//! l'image à décoder.
//!	Ensuite nous avons la fonction choix_palette qui permet de choisir la palette
//! à utiliser pour convertir notre image. Et elle prend en paramètre le nom de 
//! la palette à utiliser.
//! Nous avons également la fonction to_char qui permet de convertir un caractère
//! de l'image en son équivalent de la palette choisie. Et elle prend en paramètre
//! le caractère à convertir et la palette choisie.
//! Enfin nous avons la fonction help qui permet d'afficher l'aide.
//! 
//! \date mardi 9 novembre 2021
//! \version 1.0
//////////////////////////////////////////////////////////////////////


#pragma once
#include <vector>
#include <fstream>

std::vector<int> convertir_int(std::vector<char>);

std::vector<size_t> decripteur(std::ifstream &file);

std::vector<std::string> choix_palette(std::string file_name);

std::string to_char(unsigned char donnees, std::vector<std::string> palette);

void help();