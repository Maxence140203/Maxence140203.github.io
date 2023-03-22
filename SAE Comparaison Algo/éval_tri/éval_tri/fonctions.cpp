/**
 * \file fonctions.cpp
 *
 * D�finition des fonctions fournies.
 */
#include "fonctions.h"
#include <iostream>
#include <fstream>

 /**
  * Cr�e un tableau d'entiers dont tous les �l�ments sont choisis al�atoirement.
  *
  * Un tel tableau peut par exemple �tre 30968 28073 31177 2882 6140 17999 13828 20039 2310 24865.
  *
  * \param[in] N taille du tableau
  * \return le tableau initialis�
  */
std::vector<int> initTabAleat(size_t N)
{
    std::vector<int> tab(N);
    for (auto& val : tab)
        val = rand();
    return tab;
}

/**
 * Cr�e un tableau d'entiers presque tri�s. Chaque �l�ment est quasiment � sa place d�finitive, �chang� �ventuellement d'une place.
 *
 * Un tel tableau peut par exemple �tre 1 3 2 4 6 5 8 7 9 10.
 *
 * \param[in] N taille du tableau
 * \return le tableau initialis�
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
 * Cr�e un tableau d'entiers presque tri�s. Seuls le premier et le deuxi�me �l�ment sont �chang�s.
 *
 * Un tel tableau peut par exemple �tre 2 1 3 4 5 6 7 8 9 10.
 *
 * \param[in] N taille du tableau
 * \return le tableau initialis�
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
 * Cr�e un tableau d'entiers presque tri�s. Seuls le dernier et l'avant dernier �l�ment sont �chang�s.
 *
 * Un tel tableau peut par exemple �tre 1 2 3 4 5 6 7 8 10 9.
 *
 * \param[in] N taille du tableau
 * \return le tableau initialis�
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
 * Cr�e un tableau d'entiers presque tri�s. Seuls le premier et le dernier �l�ment sont �chang�s.
 *
 * Un tel tableau peut par exemple �tre 10 2 3 4 5 6 7 8 9 1.
 *
 * \param[in] N taille du tableau
 * \return le tableau initialis�
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
 * V�rifie qu'un tableau est correctement tri�. Si le tableau est mal tri�, un message d'erreur est
 * affich� sur le flux d'erreur et le programme est termin�.
 *
 * \param[in] tab Le tableau � v�rifier
 * \param[in] algoName Le nom de l'algorithme de tri qui a �t� utilis�. Ce param�tre est optionnel.
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
Cette fonction permet de trier un vecteur gra�e � l'algorithme de Selection.
Il traite le tri du vecteur en cherchant l'�l�ment de plus petit et le place
en premi�re position puis il cherche le second plus petit et le place en
seconde position et ainsi de suite jusqu'� avoir trait� l'ensemble du vecteur
************************
      Param�tres
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
Cette fonction permet de trier un vecteur gra�e � l'algorithme Bulle.
Il traite le tri de ce vecteur en le parcourant et s'il trouve un nombre plus
grand que celui qu'il traitait, il le d�place jusqu'� arriver a la fin du vecteur
************************
      Param�tres
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
Cette fonction permet de trier un vecteur gra�e � l'algorithme Bulle mais de fa�on plus efficace
************************
      Param�tres
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
Cette fonction a pour but de cr�er le fichier csv avec le nombre de comparaisons
en fonction de la fonction appel�e
Apr�s avoir appel� la fonction de tri ad�quate on lance la fonction pour v�rifier
que les tableaux sont bien tri�s
************************
      Param�tres
************************
La Fonction a appeler
Le fichier de sortie
Le nom de la fonction s'il y a une erreur
Le nombre de fois que l'on va r�p�ter des tri
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
Cette fonction permet de trier un vecteur gra�e � l'algorithme Peigne qui est une version un peu plus am�lior� du tri a bulle .
************************
      Param�tres
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
Cette fonction permet de trier un vecteur gra�e � l'algorithme Cocktail qui est aussi une version du tri � bulle mais bidirectionnel.
************************
      Param�tres
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
Cette fonction permet de trier un vecteur gra�e � l'algorithme Rapide. Il traite
le tri de ce vecteur de mani�re recursive en le d�coupant en plus petit vecteur jusqu'� n'avoir que des vecteurs de 2 �l�ments qu'il interverti ou non et ainsi
de suite jusqu'� avoir tri� l'ensemble du vecteur
************************
      Param�tres
************************
Le vecteur a trier
L'indice du premier �l�ment
L'indice du dernier �l�ment
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
Cette fonction permet � la fonction de tri rapide de diviser le vecteur en parties
plus petites
************************
      Param�tres
************************
Le vecteur a traiter
L'indice du premier �l�ment de la partie
L'indice du dernier �l�ments de la partie
L'indice du pivot qui est l'endroit o� on va partitionner le vecteur a traiter
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
Cette fonction permet de lancer la fonction de tri rapide avec un seul param�tre
pour ne pas poser probl�me dans la liste de fonctions cr��e dans la fonction
menu
************************
      Param�tres
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
Cette fonction permet de s�l�ctionner la taille des tableaux a cr�er, le nombre
de fois que l'on veut r�p�ter la cr�ation de vecteurs et le tri de ceux ci et
ensuite elle cr�e le fichier de sortie et lance toutes les fonctions de tri

************************
      Param�tres
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
    exel(tri[0], out, "S�lection", nb, N, incre);
    exel(tri[1], out, "Bulle", nb, N, incre);
    exel(tri[2], out, "Bulle Opti", nb, N, incre);         //Lancement des 
    exel(tri[3], out, "Peigne", nb, N, incre);             //fonctions
    exel(tri[4], out, "Rapide", nb, N, incre);
    exel(tri[5], out, "Cocktail", nb, N, incre);
}