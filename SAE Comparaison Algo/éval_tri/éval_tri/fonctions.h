

/**
 * \file fonctions.h
 *
 * D�claration des fonctions fournies.
 */
#pragma once
#include <vector>
#include <string>

typedef unsigned int (*Fonctions) (std::vector<int>& tableau);

//!\brief Cr�e un tableau al�atoire
std::vector<int> initTabAleat(size_t N);

//!\brief Cr�e un tableau presque tri�
std::vector<int> initTabPresqueTri(size_t N);

//!\brief Cr�e un tableau presque tri� au d�but
std::vector<int> initTabPresqueTriDeb(size_t N);

//!\brief Cr�e un tableau presque tri� � la fin
std::vector<int> initTabPresqueTriFin(size_t N);

//!\brief Cr�e un tableau presque tri� entre le d�but et la fin
std::vector<int> initTabPresqueTriDebFin(size_t N);

//!\brief V�rifie qu'un tableau est correctement tri�
void verifTri(const std::vector<int>& tab, const std::string& algoName = {});

//!\brief Trie le tableau dans l'ordre croissant 
unsigned int triSelection(std::vector<int>& tableau);

unsigned int TriBulle(std::vector<int>& tableau);

unsigned int TriBulleOpti(std::vector<int>& tableau);

void exel(Fonctions, std::ofstream& out, std::string nom_tri, int nb, int N, int incre);

unsigned int Tri_a_peigne(std::vector<int>& tableau);

unsigned int Tri_Cocktail(std::vector<int>& tableau);

unsigned int Tri_Rapide_Bis(std::vector<int>& tableau, int premier, int dernier, int nb_iter);

unsigned int Tri_Rapide(std::vector<int>& tableau);

unsigned int partitionner(std::vector<int>& tableau, int premier, int dernier, int pivot);

void menu();