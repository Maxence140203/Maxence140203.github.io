#include "Arbre.h"
#include <iostream>

void Arbre::ajoute_cellule(const CelluleA& cel)
{
	CelluleA* ptcel1 = new CelluleA(cel._info);
	CelluleA* p = _pArbre;
	bool nontrouve = true;
	if (p == nullptr) // cas ou l'arbre est vide 
	{ 
		nontrouve = false; 
		_pArbre = ptcel1; 
	} 
	while (nontrouve) 
	{
		if (ptcel1->_info < p->_info)  // on verifie si notre cellule est plus petite que la cellule courrante
		{
			if (p->_pFilsG ==nullptr) // si le fils gauche est vide alors on lui affecte la nouvelle cellule
			{
				nontrouve = false;  
				p->_pFilsG = ptcel1; 
			}
			else p = p->_pFilsG; // on continue de parcourir l'arbre a partir du fils gauche			
		}
		else // si la cellulle est plus grand que la cellule courrante
		{
			if (p->_pFilsD == nullptr) // si le fils droit est vide alors on lui affecte la nouvelle cellule
			{
				nontrouve = false; 
				p->_pFilsD = ptcel1;
			}
			else p = p->_pFilsD; // on continue de parcourir l'arbre a partir du fils droit
		
		}
	}
}



void Arbre::affiche_arbre_prefixe()const {
	if (_pArbre) {
		Arbre arbregauche(this->_pArbre->_pFilsG);
		Arbre arbredroit(this->_pArbre->_pFilsD);

		std::cout << _pArbre->_info;
		arbregauche.affiche_arbre_prefixe();
		arbredroit.affiche_arbre_prefixe();
	}
}


void Arbre::affiche_arbre_infixe()const{
	if (_pArbre) {
		Arbre arbregauche(this->_pArbre->_pFilsG);
		Arbre arbredroit(this->_pArbre->_pFilsD);

		
		arbregauche.affiche_arbre_infixe();
		std::cout << _pArbre->_info;
		arbredroit.affiche_arbre_infixe();
	}
}



void Arbre::affiche_arbre_postfixe()const{
	if (_pArbre) {
		Arbre arbregauche(this->_pArbre->_pFilsG);
		Arbre arbredroit(this->_pArbre->_pFilsD);

		
		arbregauche.affiche_arbre_postfixe();
		arbredroit.affiche_arbre_postfixe();
		std::cout << _pArbre->_info;
	}
}


int Arbre::max()const {
	CelluleA* ptr = _pArbre;
	if (_pArbre)
	{
		while (true)
		{
			if (ptr->_pFilsD == nullptr)
				return ptr->_info;
			else
			{
				ptr = ptr->_pFilsD;
			}
		}
	}
	
	return 0;
}

int Arbre::min()const {
	CelluleA* ptr = _pArbre;
	if (_pArbre)
	{
		while (true)
		{
			if (ptr->_pFilsG == nullptr)
				return ptr->_info;
			else
			{
				ptr = ptr->_pFilsG;
			}
		}
	}
	
	return 0;
}

int Arbre::hauteur()const {
	if (_pArbre)
	{
		Arbre arbregauche(this->_pArbre->_pFilsG);
		Arbre arbredroit(this->_pArbre->_pFilsD);

		return 1 + std::max(arbregauche.hauteur(), arbredroit.hauteur());
	}
	else 
		return 0;
}


int Arbre::nbelem() const{
	if (_pArbre)
	{
		Arbre arbregauche(this->_pArbre->_pFilsG);
		Arbre arbredroit(this->_pArbre->_pFilsD);

		return 1 + arbregauche.nbelem() + arbredroit.nbelem();
	}
	else
		return 0;
}


int Arbre::nbfeuille()const 
{
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
	if (_pArbre == nullptr) return false;
	else 
	{
		// l'arbre est non degenere si au moins 1 noeud possede 2 fils
		if (_pArbre->_pFilsG != nullptr && _pArbre->_pFilsD != nullptr) return true;
		else 
		{
			if (_pArbre->_pFilsG == nullptr) 
			{
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


// On exploite dans la recherche le fait que l arbre soit un ABR
// Renvoie le pointeur sur la cellule contenant cle, nullptr si pas trouve
// Fonction importante
CelluleA* Arbre::recherche_ptr(int cle)const 
{  
	if (!_pArbre)
		return nullptr;
	else
	{
		if (_pArbre->_info == cle)
		{
			return _pArbre;
		}
		else
		{
			if (_pArbre->_info < cle)
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




void Arbre::supprime_cellule(int cle) {
	
	CelluleA* p = _pArbre;
	CelluleA* psauve = _pArbre;
	CelluleA* pred=_pArbre;
	bool nontrouve = true;
	if (p != nullptr && p->_info == cle) { //suppression en tete
		pred = p->_pFilsG; // pour rattachement
		if (p->_pFilsD != nullptr) {
			p = p->_pFilsD;
			while (p && p->_pFilsG)
				p = p->_pFilsG;
			p->_pFilsG = pred;
			_pArbre = _pArbre->_pFilsD;
		}
		else _pArbre = pred; // pas de sous arbre droit
		delete psauve;
		return;	
	}
	
	bool filsdroit = true;;
	while (p!=nullptr && nontrouve) {
		if (cle < p->_info) {
			pred = p;
			filsdroit = false;
			p = p->_pFilsG;
		}
		else
			if (cle > p->_info) {
				pred = p;
				filsdroit = true;
				p = p->_pFilsD;
			}
			else nontrouve = false;  // on a trouve
	}

	if (p && p->_pFilsG ==nullptr && p->_pFilsD == nullptr) {  // si feuille
		if (filsdroit) 
			pred->_pFilsD = nullptr;
		
		else pred->_pFilsG = nullptr;
		delete p;
	}
	else { //si pas feuille
			psauve = p;
			
			if (p && p->_pFilsD != nullptr) {
				p = p->_pFilsD;
				while (p && p->_pFilsG)
					p = p->_pFilsG;
				p->_pFilsG = psauve->_pFilsG;
				if (filsdroit)
					pred->_pFilsD = psauve->_pFilsD;
				else
					pred->_pFilsG = psauve->_pFilsD;
			}
			else 
				if (pred && psauve)
					if (filsdroit)
						pred->_pFilsD = psauve->_pFilsG;
					else
						pred->_pFilsG = psauve->_pFilsG; // pas de sous arbre droit
			delete psauve;

	}	
}




void Arbre::liberer_arbre() {
	if (_pArbre)
	{
		supprime_cellule(_pArbre->_info);
		liberer_arbre();
	}
}
