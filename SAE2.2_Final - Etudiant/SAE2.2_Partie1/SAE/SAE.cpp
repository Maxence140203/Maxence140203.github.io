// SAE.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>
#include "Cellule.h"
#include "Liste.h"
#include "CelluleB.h"
#include "ListeB.h"
#include "CelluleA.h"
#include "Arbre.h"

#include <vector>
#include <string>
#include <array>

int main()
{
   
  
    // Ecrivez vos tests dans le prog principal que l'on presentera proprement
    // ceux qui suivent sont juste la pour vous montrer comment cela marche
    Cellule cel;
    Cellule cel2(5);
    Cellule cel3(1);
    Cellule cel4(9);
    Cellule cel5(8);
    Cellule cel6(3);
    Cellule cel7(4);

    Liste l;
    l.ajoute_cellule_en_tete(cel);
    l.ajoute_cellule_en_tete(cel2);
    l.ajoute_cellule_en_tete(cel3); 
    l.ajoute_cellule_en_tete(cel4);
    l.ajoute_cellule_en_tete(cel5);
    l.ajoute_cellule_en_tete(cel6);
    l.ajoute_cellule_en_queue(cel7);
   
    l.affiche_liste();
    std::cout << "il y a  " << l.nbelem() << " elements \n";
    l.ajoute_cellule_en_queue(cel3);
    l.supprime_cellule(1);
    l.affiche_liste();
    l.liberer_liste();
    l.affiche_liste();


    //Test listes chainees bidirectionnelles
    CelluleB celB;
    CelluleB celB2(5);
    CelluleB celB3(1);
    CelluleB celB4(9);
    CelluleB celB5(8);
    CelluleB celB6(3);
    CelluleB celB7(4);

    ListeB lb;
    lb.ajoute_cellule_en_tete(celB);
    lb.ajoute_cellule_en_tete(celB2);
    lb.ajoute_cellule_en_tete(celB3);
    lb.ajoute_cellule_en_tete(celB4);
    lb.ajoute_cellule_en_tete(celB5);
    lb.ajoute_cellule_en_tete(celB6);

    lb.affiche_liste();
    lb.affiche_liste_endroit();
    std::cout << "il y a  " << lb.nbelem() << " elements \n";
    lb.ajoute_cellule_en_queue(celB3);
    lb.affiche_liste();
    lb.supprime_cellule(1);
    lb.affiche_liste();
    lb.liberer_liste();
    lb.affiche_liste();

    //Test arbre de recherche binaire
    CelluleA celA;
    CelluleA celA2(5);
    CelluleA celA3(1);
    CelluleA celA4(9);
    CelluleA celA5(8);
    CelluleA celA6(3);
    CelluleA celA7(4);

    Arbre a;

    a.ajoute_cellule(celA);
    a.ajoute_cellule(celA2);
    a.ajoute_cellule(celA3);
    a.ajoute_cellule(celA4);
    a.ajoute_cellule(celA5);
    a.ajoute_cellule(celA6);
    a.ajoute_cellule(celA7);

    a.affiche_arbre_infixe();
    std::cout << "\n";
    a.affiche_arbre_postfixe();
    std::cout << "\n";
    a.affiche_arbre_prefixe();
    std::cout << "\n";

    std::cout << a.nbelem() << "\n";

    std::cout << a.max();
    std::cout << "\n" << a.min();

    std::cout << "\n" << a.nbfeuille();

    std::cout << "\n" << a.recherche_ptr(10);

    a.liberer_arbre();
    std::cout << "\nliberation";
    a.affiche_arbre_infixe();
    std::cout << "\nliberer";
    return 0;

}
