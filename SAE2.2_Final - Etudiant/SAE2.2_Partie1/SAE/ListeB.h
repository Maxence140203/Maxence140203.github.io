#pragma once

#include "CelluleB.h"

class ListeB {
private:
	CelluleB* _pListDeb = nullptr;
	CelluleB* _pListFin = nullptr;
public:
	CelluleB* acces_tete() { return _pListDeb; };
	CelluleB* acces_queue() { return _pListFin; };

	void ajoute_cellule_en_tete(const CelluleB& cel); // attention 2 cas  // O(1)
	void ajoute_cellule_en_queue(const CelluleB& cel); // O(n)
	void affiche_liste()const; // O(n)
	void affiche_liste_endroit()const; //parcours depuis la queue // O(n)
	void liberer_liste(); // O(n)
	int nbelem() const; // O(n)
	CelluleB* recherche_ptr(int cle)const; // O(n)
	void supprime_cellule(int cle); 

};