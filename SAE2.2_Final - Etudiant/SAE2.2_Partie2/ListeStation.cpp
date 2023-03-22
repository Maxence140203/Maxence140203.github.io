#include "ListeStation.h"

#include <iostream>



// Cette fonction est un peu a modifier par rapport a la partie 1 car il y a un tableau maintenant en plus
void ListeStation::ajoute_cellule_en_tete(const CelluleStation& cel) {
	CelluleStation* cel1 = new CelluleStation(cel._ID);
	if (_pListDeb == nullptr)
	{
		cel1->_pSuiv = _pListDeb;
		_pListDeb = cel1;
		_pListFin = cel1;
	}
	else
	{
		cel1->_pSuiv = _pListDeb;
		_pListDeb = cel1;
		_pListDeb->_pSuiv->_pPred = cel1;
	}
}

void ListeStation::affiche_liste() const {
	CelluleStation* p = _pListDeb;
	while (p != nullptr) {
		std::cout << p->_ID << " ";
		p = p->_pSuiv;
	}
	std::cout << std::endl;
}

void ListeStation::affiche_liste_endroit() const {
	CelluleStation* p = _pListFin;
	while (p != nullptr) {
		std::cout << p->_ID << " ";
		p = p->_pPred;
	}
	std::cout << std::endl;
}




size_t ListeStation::nbelem() const {
	CelluleStation* p = _pListDeb;
	int nb = 0;
	while (p != nullptr) {
		nb += 1;
		p = p->_pSuiv;
	}
	return nb;
}


// renvoie le ptr vers cellule avec cle. Si cle absente renvoie null
CelluleStation* ListeStation::recherche_ptr(int cle)const {
	 
	CelluleStation* p = _pListDeb;
	if (!_pListDeb) return nullptr;  //liste vide
	else {
		while (p != nullptr && p->_ID != cle)
		{
			p = p->_pSuiv;
		}
		if (p)
			return p;
		else return nullptr;
	}
}


void ListeStation::supprime_cellule(int cle) {
	CelluleStation* pred = recherche_ptr(cle);
	CelluleStation* p;

	if (pred != nullptr)
	{
		p = pred;
		if (p->_pPred == nullptr && p->_pSuiv == nullptr) //cas ou p est seul dans la liste
		{
			_pListDeb = nullptr;
			_pListFin = nullptr;
		}
		if (p->_pPred != nullptr && p->_pSuiv != nullptr) //cas ou p est au milieu de la liste
		{
			p->_pPred->_pSuiv = p->_pSuiv;
			p->_pSuiv->_pPred = p->_pPred;
		}
		if (p->_pPred == nullptr && p->_pSuiv != nullptr) //cas ou p est en fin de liste
		{
			p->_pSuiv->_pPred = nullptr;
			_pListDeb = p->_pSuiv;
		}
		if (p->_pPred != nullptr && p->_pSuiv == nullptr) //cas ou p est en debut de liste
		{
			p->_pPred->_pSuiv = nullptr;
			_pListFin = p->_pPred;
		}
		delete p;
	}
}


void ListeStation::liberer_liste() {
	CelluleStation* p = _pListDeb;
	while (_pListDeb != nullptr) {
		CelluleStation* p = _pListDeb;
		_pListDeb = _pListDeb->_pSuiv;
		delete p;
	}
}

