

/**
 * \file fonctions.h
 *
 * Déclaration des fonctions fournies.
 */
#pragma once
#include <vector>
#include <string>

typedef unsigned int (*Fonctions) (std::vector<int>& tableau);

//!\brief Crée un tableau aléatoire
std::vector<int> initTabAleat(size_t N);

//!\brief Crée un tableau presque trié
std::vector<int> initTabPresqueTri(size_t N);

//!\brief Crée un tableau presque trié au début
std::vector<int> initTabPresqueTriDeb(size_t N);

//!\brief Crée un tableau presque trié à la fin
std::vector<int> initTabPresqueTriFin(size_t N);

//!\brief Crée un tableau presque trié entre le début et la fin
std::vector<int> initTabPresqueTriDebFin(size_t N);

//!\brief Vérifie qu'un tableau est correctement trié
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