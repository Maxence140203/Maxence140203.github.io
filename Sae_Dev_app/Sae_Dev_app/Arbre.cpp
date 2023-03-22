#include "Arbre.h"
#include <iostream>

void Arbre::ajoute_cellule(const CelluleArbre& cel) {

	CelluleArbre* ptcel1 = new CelluleArbre(cel._deltaT, cel._annee);
	CelluleArbre* p = _pArbre;
	bool nontrouve = true;
	if (p == nullptr) { nontrouve = false; _pArbre = ptcel1; } //insere en tete
	while (nontrouve) {
		if (ptcel1->_deltaT < p->_deltaT) {
			if (p->_pFilsG == nullptr) {
				nontrouve = false; p->_pFilsG = ptcel1;
			}
			else p = p->_pFilsG;
		}
		else {
			if (p->_pFilsD == nullptr) {
				nontrouve = false; p->_pFilsD = ptcel1;
			}
			else p = p->_pFilsD;

		}
	}
}



void Arbre::affiche_arbre_prefixe()const {
	if (_pArbre) {
		Arbre arbregauche(this->_pArbre->_pFilsG);
		Arbre arbredroit(this->_pArbre->_pFilsD);

		std::cout << _pArbre->_deltaT;
		arbregauche.affiche_arbre_prefixe();
		arbredroit.affiche_arbre_prefixe();
	}
}


void Arbre::affiche_arbre_infixe()const {
	if (_pArbre) {
		Arbre arbregauche(this->_pArbre->_pFilsG);
		Arbre arbredroit(this->_pArbre->_pFilsD);


		arbregauche.affiche_arbre_infixe();
		std::cout << _pArbre->_deltaT;
		arbredroit.affiche_arbre_infixe();
	}
}



void Arbre::affiche_arbre_postfixe()const {
	if (_pArbre) {
		Arbre arbregauche(this->_pArbre->_pFilsG);
		Arbre arbredroit(this->_pArbre->_pFilsD);


		arbregauche.affiche_arbre_postfixe();
		arbredroit.affiche_arbre_postfixe();
		std::cout << _pArbre->_deltaT;
	}
}


void Arbre::liberer_arbre() {
	if (_pArbre)
	{
		supprime_cellule(_pArbre->_deltaT);
		liberer_arbre();
	}
}


float Arbre::max()const {
	CelluleArbre* ptr = _pArbre;
	if (_pArbre)
	{
		while (true)
		{
			if (ptr->_pFilsD == nullptr)
				return ptr->_deltaT;
			else
			{
				ptr = ptr->_pFilsD;
			}
		}
	}
	return 0.0;
}

float Arbre::min()const {
	CelluleArbre* ptr = _pArbre;
	if (_pArbre)
	{
		while (true)
		{
			if (ptr->_pFilsG == nullptr)
				return ptr->_deltaT;
			else
			{
				ptr = ptr->_pFilsG;
			}
		}
	}
	return 0.0;
}

size_t Arbre::hauteur()const {
	if (_pArbre)
	{
		Arbre arbregauche(this->_pArbre->_pFilsG);
		Arbre arbredroit(this->_pArbre->_pFilsD);

		return 1 + std::max(arbregauche.hauteur(), arbredroit.hauteur());
	}
	else
		return 0;
}


size_t Arbre::nbelem() const {
	if (_pArbre)
	{
		Arbre arbregauche(this->_pArbre->_pFilsG);
		Arbre arbredroit(this->_pArbre->_pFilsD);

		return 1 + arbregauche.nbelem() + arbredroit.nbelem();
	}
	else
		return 0;
}


size_t Arbre::nbfeuille()const {
	if (_pArbre)
	{
		Arbre arbregauche(this->_pArbre->_pFilsG);
		Arbre arbredroit(this->_pArbre->_pFilsD);

		if (_pArbre->_pFilsD == nullptr && _pArbre->_pFilsG == nullptr)
			return 1;
		else
			return arbregauche.nbfeuille() + arbredroit.nbfeuille();
	}
	else
		return 0;
}


bool Arbre::non_degenere()const {
	if (_pArbre == nullptr)
		return false;
	else {
		if (_pArbre->_pFilsG != nullptr && _pArbre->_pFilsD != nullptr)
			return true;
		else {
			if (_pArbre->_pFilsG == nullptr) {
				Arbre arbredroit(this->_pArbre->_pFilsD);
				return arbredroit.non_degenere();
			}
			else { //_pArbre->_pFilsD == nullptr
				Arbre arbregauche(this->_pArbre->_pFilsG);
				return arbregauche.non_degenere();
			}
		}
	}
}


CelluleArbre* Arbre::recherche_ptr(float cle)const {
	if (!_pArbre)
		return nullptr;
	else
	{
		if (_pArbre->_deltaT == cle)
		{
			return _pArbre;
		}
		else
		{
			if (_pArbre->_deltaT < cle)
			{
				Arbre arbredroit(this->_pArbre->_pFilsD);
				return arbredroit.recherche_ptr(cle);
			}
			else
			{
				Arbre arbregauche(this->_pArbre->_pFilsG);
				return arbregauche.recherche_ptr(cle);
			}
		}
	}
	return nullptr;
}

void Arbre::supprime_cellule(float cle) {

	CelluleArbre* p = _pArbre;
	CelluleArbre* psauve = _pArbre;
	CelluleArbre* pred = _pArbre;
	bool nontrouve = true;
	if (p != nullptr && p->_deltaT == cle) { //suppression en tete
		pred = p->_pFilsG; // pour rattachement
		if (p->_pFilsD != nullptr) {
			p = p->_pFilsD;
			while (p && p->_pFilsG)
				p = p->_pFilsG;
			p->_pFilsG = pred;
			_pArbre = _pArbre->_pFilsD;
		}
		else
			_pArbre = pred; // pas de sous arbre droit
		delete psauve;
		return;
	}

	bool _pFilsDroit = true;;
	while (p != nullptr && nontrouve) {
		if (cle < p->_deltaT) {
			pred = p;
			_pFilsDroit = false;
			p = p->_pFilsG;
		}
		else
			if (cle > p->_deltaT) {
				pred = p;
				_pFilsDroit = true;
				p = p->_pFilsD;
			}
			else
				nontrouve = false;  // on a trouve
	}

	if (p && p->_pFilsG == nullptr && p->_pFilsD == nullptr) {  // si feuille
		if (_pFilsDroit)
			pred->_pFilsD = nullptr;
		else
			pred->_pFilsG = nullptr;
		delete p;
	}
	else { //si pas feuille
		psauve = p;

		if (p && p->_pFilsD != nullptr) {
			p = p->_pFilsD;
			while (p && p->_pFilsG)
				p = p->_pFilsG;
			p->_pFilsG = psauve->_pFilsG;
			if (_pFilsDroit)
				pred->_pFilsD = psauve->_pFilsD;
			else
				pred->_pFilsG = psauve->_pFilsD;
		}
		else
			if (pred && psauve)
				if (_pFilsDroit)
					pred->_pFilsD = psauve->_pFilsG;
				else
					pred->_pFilsG = psauve->_pFilsG; // pas de sous arbre droit
		delete psauve;
	}

}

