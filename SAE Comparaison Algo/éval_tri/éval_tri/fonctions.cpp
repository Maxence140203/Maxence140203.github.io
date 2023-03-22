/**
 * \file fonctions.cpp
 *
 * Définition des fonctions fournies.
 */
#include "fonctions.h"
#include <iostream>
#include <fstream>

 /**
  * Crée un tableau d'entiers dont tous les éléments sont choisis aléatoirement.
  *
  * Un tel tableau peut par exemple être 30968 28073 31177 2882 6140 17999 13828 20039 2310 24865.
  *
  * \param[in] N taille du tableau
  * \return le tableau initialisé
  */
std::vector<int> initTabAleat(size_t N)
{
    std::vector<int> tab(N);
    for (auto& val : tab)
        val = rand();
    return tab;
}

/**
 * Crée un tableau d'entiers presque triés. Chaque élément est quasiment à sa place définitive, échangé éventuellement d'une place.
 *
 * Un tel tableau peut par exemple être 1 3 2 4 6 5 8 7 9 10.
 *
 * \param[in] N taille du tableau
 * \return le tableau initialisé
 */
std::vector<int> initTabPresqueTri(size_t N)
{
    std::vector<int> tab(N);
    for (int i = 0; i < N; i++)
        tab[i] = i;
    for (int i = 0; i < N - 1; i++)
    {
        if (rand() % 2 == 0)
        {
            std::swap(tab[i], tab[i + 1]);
            ++i;
        }
    }
    return tab;
}

/**
 * Crée un tableau d'entiers presque triés. Seuls le premier et le deuxième élément sont échangés.
 *
 * Un tel tableau peut par exemple être 2 1 3 4 5 6 7 8 9 10.
 *
 * \param[in] N taille du tableau
 * \return le tableau initialisé
 */
std::vector<int> initTabPresqueTriDeb(size_t N)
{
    std::vector<int> tab(N);
    for (int i = 0; i < N; i++)
        tab[i] = i;
    std::swap(tab[0], tab[1]);
    return tab;
}

/**
 * Crée un tableau d'entiers presque triés. Seuls le dernier et l'avant dernier élément sont échangés.
 *
 * Un tel tableau peut par exemple être 1 2 3 4 5 6 7 8 10 9.
 *
 * \param[in] N taille du tableau
 * \return le tableau initialisé
 */
std::vector<int> initTabPresqueTriFin(size_t N)
{
    std::vector<int> tab(N);
    for (int i = 0; i < N; i++)
        tab[i] = i;
    std::swap(tab[N - 1], tab[N - 2]);
    return tab;
}

/**
 * Crée un tableau d'entiers presque triés. Seuls le premier et le dernier élément sont échangés.
 *
 * Un tel tableau peut par exemple être 10 2 3 4 5 6 7 8 9 1.
 *
 * \param[in] N taille du tableau
 * \return le tableau initialisé
 */
std::vector<int> initTabPresqueTriDebFin(size_t N)
{
    std::vector<int> tab(N);
    for (int i = 0; i < N; i++)
        tab[i] = i;
    std::swap(tab[N - 1], tab[0]);
    return tab;
}

/**
 * Vérifie qu'un tableau est correctement trié. Si le tableau est mal trié, un message d'erreur est
 * affiché sur le flux d'erreur et le programme est terminé.
 *
 * \param[in] tab Le tableau à vérifier
 * \param[in] algoName Le nom de l'algorithme de tri qui a été utilisé. Ce paramètre est optionnel.
 */
void verifTri(const std::vector<int>& tab, const std::string& algoName)
{
    const size_t taille = tab.size();
    for (size_t i = 1; i < taille; i++)
    {
        if (tab[i - 1] > tab[i])
        {
            std::cerr << "Erreur dans le tri " << algoName << (algoName.empty() ? "!" : " !") << '\n';
            exit(EXIT_FAILURE);
        }
    }
}

/*
************************
      Description
************************
Cette fonction permet de trier un vecteur graçe à l'algorithme de Selection.
Il traite le tri du vecteur en cherchant l'élément de plus petit et le place
en première position puis il cherche le second plus petit et le place en
seconde position et ainsi de suite jusqu'à avoir traité l'ensemble du vecteur
************************
      Paramètres
************************
Le vecteur a trier
*/
unsigned int triSelection(std::vector<int>& tableau)
{
    unsigned int nb_iter = 0;
    int taille = tableau.size();
    int min;
    for (int i = 0; i < taille - 1; i++)
    {
        min = i;
        for (int j = i + 1; j < taille; j++)
        {
            nb_iter += 1;
            if (tableau[j] < tableau[min])
            {
                min = j;
            }
        }
        if (min != i)
        {
            std::swap(tableau[i], tableau[min]);
        }
    }
    return nb_iter;
}

/*
************************
      Description
************************
Cette fonction permet de trier un vecteur graçe à l'algorithme Bulle.
Il traite le tri de ce vecteur en le parcourant et s'il trouve un nombre plus
grand que celui qu'il traitait, il le déplace jusqu'à arriver a la fin du vecteur
************************
      Paramètres
************************
Le vecteur a trier
*/
unsigned int TriBulle(std::vector<int>& tableau)
{
    unsigned int nb_iter = 0;
    int taille = tableau.size();
    for (int i = taille - 1; i > 0; i--)
    {
        for (int j = 0; j < i; j++)
        {
            nb_iter += 1;
            if (tableau[j] > tableau[j + 1])
            {
                std::swap(tableau[j], tableau[j + 1]);
            }
        }
    }
    return nb_iter;
}


/*
************************
      Description
************************
Cette fonction permet de trier un vecteur graçe à l'algorithme Bulle mais de façon plus efficace
************************
      Paramètres
************************
Le vecteur a trier
*/
unsigned int TriBulleOpti(std::vector<int>& tableau)
{
    unsigned int nb_iter = 0;
    int taille = tableau.size();
    bool tableau_tri;
    for (int i = taille - 1; i > 0; i--)
    {
        tableau_tri = true;
        for (int j = 0; j < i; j++)
        {
            nb_iter += 1;
            if (tableau[j + 1] < tableau[j])
            {
                std::swap(tableau[j], tableau[j + 1]);
                tableau_tri = false;
            }
        }
        if (tableau_tri)
        {
            return nb_iter;
        }
    }
    return nb_iter;
}

/*
************************
      Description
************************
Cette fonction a pour but de créer le fichier csv avec le nombre de comparaisons
en fonction de la fonction appelée
Après avoir appelé la fonction de tri adéquate on lance la fonction pour vérifier
que les tableaux sont bien triés
************************
      Paramètres
************************
La Fonction a appeler
Le fichier de sortie
Le nom de la fonction s'il y a une erreur
Le nombre de fois que l'on va répéter des tri
La taille de chaque tableau
Et enfin la variation de la taille des tableaux
*/
void exel(unsigned int (*Fonctions) (std::vector<int>& tableau), std::ofstream& out, std::string nom_tri, int nb, int N, int incre)
{
    out << "N;Aleat Select.;PresqueTri Select.;PresqueTriDeb Select.;PresqueTriDebFin Select.;PresqueTriFin Select.\n";
    for (int i = 0; i < nb; i++)
    {
        out << N << ";";
        unsigned int nb_iter;

        std::vector <int>h = initTabAleat(N);
        nb_iter = Fonctions(h);
        verifTri(h, nom_tri);
        out << nb_iter << ';';

        std::vector <int>h2 = initTabPresqueTri(N);
        nb_iter = Fonctions(h2);
        verifTri(h2, nom_tri);
        out << nb_iter << ';';

        std::vector <int>h3 = initTabPresqueTriDeb(N);
        nb_iter = Fonctions(h3);
        verifTri(h3, nom_tri);
        out << nb_iter << ';';

        std::vector <int>h4 = initTabPresqueTriDebFin(N);
        nb_iter = Fonctions(h4);
        verifTri(h4, nom_tri);
        out << nb_iter << ';';

        std::vector <int>h5 = initTabPresqueTriFin(N);
        nb_iter = Fonctions(h5);
        verifTri(h5, nom_tri);
        out << nb_iter << ';';
        out << '\n';

        N += incre;
    }
    out << '\n';
}


/*
************************
      Description
************************
Cette fonction permet de trier un vecteur graçe à l'algorithme Peigne qui est une version un peu plus amélioré du tri a bulle .
************************
      Paramètres
************************
Le vecteur a trier
*/
unsigned int Tri_a_peigne(std::vector<int>& tableau) {
    unsigned int nb_iter = 0;
    int  inter = tableau.size();
    bool echange = true;
    while (inter > 1 || echange == true) {
        inter = int(inter / 1.3);
        if (inter < 10) {
            inter = 1;
        }

        int i = 0;
        echange = false;

        while (i < tableau.size() - inter) {
            nb_iter += 1;
            if (tableau[i] > tableau[i + inter]) {
                std::swap(tableau[i], tableau[i + inter]);
                echange = true;
            }
            i = i + 1;

        }
    }
    return nb_iter;
}


/*
************************
      Description
************************
Cette fonction permet de trier un vecteur graçe à l'algorithme Cocktail qui est aussi une version du tri à bulle mais bidirectionnel.
************************
      Paramètres
************************
Le vecteur a trier
*/
unsigned int Tri_Cocktail(std::vector<int>& tableau) {
    unsigned int nb_iter = 0;
    bool Ech = true;
    int D = 0;
    int fin = tableau.size() - 1;
    while (Ech) {
        Ech = false;

        for (int i = 0; i < fin; i++) {
            nb_iter += 1;
            if (tableau[i] > tableau[i + 1]) {
                std::swap(tableau[i], tableau[i + 1]);
                Ech = true;
            }
        }
        fin -= 1;
        for (int i = fin; i > D; i--) {
            nb_iter += 1;
            if (tableau[i] > tableau[i + 1]) {
                std::swap(tableau[i], tableau[i + 1]);
                Ech = true;
            }
        }
        D += 1;
    }
    return nb_iter;
}

/*
************************
      Description
************************
Cette fonction permet de trier un vecteur graçe à l'algorithme Rapide. Il traite
le tri de ce vecteur de manière recursive en le découpant en plus petit vecteur jusqu'à n'avoir que des vecteurs de 2 éléments qu'il interverti ou non et ainsi
de suite jusqu'à avoir trié l'ensemble du vecteur
************************
      Paramètres
************************
Le vecteur a trier
L'indice du premier élément
L'indice du dernier élément
*/
unsigned int Tri_Rapide_Bis(std::vector<int>& tableau, int premier, int dernier) {
    int compteur = 0;
    compteur += 1;
    if (premier < dernier)
    {
        int pivot = premier + (int)((float)rand() * (dernier - premier + 1) / (RAND_MAX - 1));
        pivot = partitionner(tableau, premier, dernier, pivot);
        compteur += Tri_Rapide_Bis(tableau, premier, pivot - 1);
        compteur += Tri_Rapide_Bis(tableau, pivot + 1, dernier);
    }
    return compteur;
}

/*
************************
      Description
************************
Cette fonction permet à la fonction de tri rapide de diviser le vecteur en parties
plus petites
************************
      Paramètres
************************
Le vecteur a traiter
L'indice du premier élément de la partie
L'indice du dernier éléments de la partie
L'indice du pivot qui est l'endroit oû on va partitionner le vecteur a traiter
*/
unsigned int partitionner(std::vector<int>& tableau, int premier, int dernier, int pivot)
{
    std::swap(tableau[pivot], tableau[dernier]);
    int j = premier;
    for (int i = premier; i < dernier; i++)
    {
        if (tableau[i] <= tableau[dernier])
        {
            std::swap(tableau[i], tableau[j]);
            j += 1;
        }
    }
    std::swap(tableau[dernier], tableau[j]);
    return j;
}

/*
************************
      Description
************************
Cette fonction permet de lancer la fonction de tri rapide avec un seul paramètre
pour ne pas poser problème dans la liste de fonctions créée dans la fonction
menu
************************
      Paramètres
************************
Le vecteur a trier
*/
unsigned int Tri_Rapide(std::vector<int>& tableau)
{
    int compteur;
    compteur = Tri_Rapide_Bis(tableau, 0, tableau.size() - 1);//Lancement de la
    return compteur;                                          //fonction de tri rapide
}


/*
************************
      Description
************************
Cette fonction permet de séléctionner la taille des tableaux a créer, le nombre
de fois que l'on veut répéter la création de vecteurs et le tri de ceux ci et
ensuite elle crée le fichier de sortie et lance toutes les fonctions de tri

************************
      Paramètres
************************

*/
void menu()
{
    Fonctions tri[] =
    {
        triSelection,
        TriBulle,
        TriBulleOpti,           //Tableau de fonctions 
        Tri_a_peigne,
        Tri_Rapide,
        Tri_Cocktail
    };
    std::cout << "\nEntrez la taille des tableaux : ";
    int N;
    std::cin >> N;
    std::cout << "\nEntrez le nombre de fois que vous voulez faire des tri : ";
    int nb;
    std::cin >> nb;
    std::cout << "\nEntrez de combien vous voulez faire varier la taille des tableaux : ";
    int incre;
    std::cin >> incre;
    std::ofstream out("Resultat.csv");
    exel(tri[0], out, "Sélection", nb, N, incre);
    exel(tri[1], out, "Bulle", nb, N, incre);
    exel(tri[2], out, "Bulle Opti", nb, N, incre);         //Lancement des 
    exel(tri[3], out, "Peigne", nb, N, incre);             //fonctions
    exel(tri[4], out, "Rapide", nb, N, incre);
    exel(tri[5], out, "Cocktail", nb, N, incre);
}