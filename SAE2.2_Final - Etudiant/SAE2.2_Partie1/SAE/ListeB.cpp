#include "ListeB.h"
#include <iostream>


// attention 2 cas
void ListeB::ajoute_cellule_en_tete(const CelluleB& cel) {
	CelluleB* cel1 = new CelluleB(cel._info);
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

void ListeB::ajoute_cellule_en_queue(const CelluleB& cel) {
	CelluleB* p = _pListFin;
	CelluleB* cel1 = new CelluleB(cel._info);
	p->_pSuiv = cel1;
	p->_pSuiv->_pPred = p;
	_pListFin = p->_pSuiv;
}


void ListeB::affiche_liste() const {
	CelluleB* p = _pListDeb;
	while (p != nullptr) {
		std::cout << p->_info << " ";
		p = p->_pSuiv;
	}
	std::cout << std::endl;
}

void ListeB::affiche_liste_endroit() const {
	CelluleB* p = _pListFin;
	while (p != nullptr) {
		std::cout << p->_info << " ";
		p = p->_pPred;
	}
	std::cout << std::endl;
}

int ListeB::nbelem() const {
	CelluleB* p = _pListDeb;
	int nb = 0;
	while (p != nullptr) {
		nb += 1;
		p = p->_pSuiv;
	}
	return nb;
}


// renvoie le ptr vers cellule avec cle. Si cle absente renvoie null
CelluleB* ListeB::recherche_ptr(int cle)const {
	CelluleB* p = _pListDeb;
	if (!_pListDeb) return nullptr;  //liste vide
	else {
		while (p != nullptr && p->_info != cle) 
		{
			p = p->_pSuiv;
		}
		if (p)
			return p;
		else return nullptr;
	}
}


void ListeB::supprime_cellule(int cle) 
{
	CelluleB* pred = recherche_ptr(cle);
	CelluleB* p;

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


void ListeB::liberer_liste() {
	CelluleB* p = _pListDeb;
	while (_pListDeb != nullptr) {
		CelluleB* p = _pListDeb;
		_pListDeb = _pListDeb->_pSuiv;
		delete p;
	}
}