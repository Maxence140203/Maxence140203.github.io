#pragma once


#include "CelluleA.h"

class Arbre {
private :
	CelluleA* _pArbre = nullptr;
public:
	Arbre() {
		_pArbre = nullptr;
	};

	Arbre(CelluleA* ptr) {
		_pArbre = ptr;
	};

	CelluleA* acces_rac() { return _pArbre; };

	void ajoute_cellule(const CelluleA& cel); // O(n)
	void affiche_arbre_prefixe()const; // O(n)
	void affiche_arbre_infixe()const; // O(n)
	void affiche_arbre_postfixe()const; // O(n)
	void liberer_arbre(); // O(n)
	int nbelem() const; // O(n)
	int max()const; // O(n)
	int min()const; // O(n)
	int hauteur()const; // O(n)
	int nbfeuille()const; // O(n)
	bool non_degenere()const; // O(n)
	CelluleA* recherche_ptr(int cle)const; // O(n)
	void supprime_cellule(int cle); 

};