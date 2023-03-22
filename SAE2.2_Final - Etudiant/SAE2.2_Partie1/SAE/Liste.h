#pragma once

#include "Cellule.h"

class Liste {
private :
	Cellule* _pList=nullptr;
public :
	Cellule* acces_plist() { return _pList; };

	void ajoute_cellule_en_tete(const Cellule &cel); // Complexite O(1)
	void affiche_liste()const;  // Complexite O(n)  (n : nombre d'elements)

	void ajoute_cellule_en_queue(const Cellule& cel); // Complexite O(n) (n : nombre d'elements)
	int nbelem() const; // O(n)

	//recherche du pointeur vers la Cellule contenant cle 
	Cellule* recherche_ptr(int cle)const; // O(n)

	//recherche du pointeur vers la Cellule avant la Cellule contenant cle (utile pour la suppression pour chainage)
	Cellule* recherche_ptr_avant_cle(int cle)const; // O(n) 
	void supprime_cellule(int cle); // O(n)

	void liberer_liste();  //vide la liste // O(n)

};
