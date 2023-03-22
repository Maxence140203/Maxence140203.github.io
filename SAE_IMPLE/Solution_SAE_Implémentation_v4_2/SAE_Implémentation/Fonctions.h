//////////////////////////////////////////////////////////////////////
//! \file Fonctions.h
//!
//! \brief Ce fichier contient la d�claration des diff�rentes fonctions 
//! permettant diff�rentes op�rations sur les images.
//!
//! Dans ce ficher nous avons la fonction convertir_int qui permet de convertir
//! chaque pixel de l'image en un entier. Et elle prend en param�tre l'image
//! � convertir.
//! Nous avons aussi la fonction decripteur qui permet de r�cup�rer et 
//! de d�coder l'ent�te de l'image. Et elle prend en param�tre le fichier de 
//! l'image � d�coder.
//!	Ensuite nous avons la fonction choix_palette qui permet de choisir la palette
//! � utiliser pour convertir notre image. Et elle prend en param�tre le nom de 
//! la palette � utiliser.
//! Nous avons �galement la fonction to_char qui permet de convertir un caract�re
//! de l'image en son �quivalent de la palette choisie. Et elle prend en param�tre
//! le caract�re � convertir et la palette choisie.
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