#ifdef _WIN32
#define NOMINMAX
#include <Windows.h>
#endif //! _WIN32

#include <iostream>
#include <iomanip>
#include <vector>
#include <fstream>
#include <string>
#include "Fonctions.h"
#include "Console.h"

int main(int argc, char* argv[])
{
#ifdef _WIN32
	SetConsoleCP(CP_UTF8);
	SetConsoleOutputCP(CP_UTF8);
#endif 

    //!Declaration des variables que nous utiliserons dans le main.cpp.
    std::string nom_fichier, outfile_name, palette_name;

    //!Déclaration des variables qui nous servirons à vérifier les arguments.
    std::string chaine_palette = "palette";
    std::string test_palette = "--palette_name";
    std::string input = "--input";
    std::string pgm = ".pgm";
    std::string output = "--outfile_name";

    //!Déclaration du vecteur de string contenant les different sarguments et ajout de ceux-ci.
    std::vector<std::string> par;
    for (size_t i = 1; i < argc; i++)
    {
        par.push_back(argv[i]);
    }

    //!Nous vérfions ici si il y a des arguments.
    if (argc)
    {
        palette_name = "palette.txt";
        par.push_back(" ");
        outfile_name = "";

        //!Vérifications des arguments et de leur présence.
        for (size_t i = 0; i < par.size(); i++)
        {
            //!Vérifications si arguement est "--help".
            if (par[i] == "--help") {
                help();
                return 0;
            }

            //!Vérifications si il y a un arguement "--palette".
            if (par[i].find(test_palette) != std::string::npos || par[i].find(chaine_palette) != std::string::npos)
            {
                palette_name = par[i];
                par[i] = "€";

            }

            //!Vérifications si il y a un arguement "--input" de type ".pgm".
            if (par[i].find(input) != std::string::npos || par[i].find(pgm) != std::string::npos && nom_fichier == "")
            {
                nom_fichier = par[i + 1];
                par[i] = "€";
                par[i + 1] = "€";
            }

            //!Vérifications si il y a un arguement "--output".
            if (par[i].find(output) != std::string::npos)
            {
                if (par[i + 1] == "")
                {
                    outfile_name = "€";
                }
                else if (par[i + 1].find(input) != std::string::npos)
                {
                    outfile_name = "€";
                }
                else if (par[i + 1].find(test_palette) != std::string::npos)
                {
                    outfile_name = "€";
                }
                else {
                    outfile_name = par[i + 1];
                }
            }
            else if (outfile_name == "")
            {
                outfile_name = "€";
            }
        }
    }
    else {
        std::cout << "Arguments absents, le programme ne peut démarrer.";
        return -1;
    }

    //!Déclaration et intentation d'un verteur de string contenant les caractères de la palette choisie.
    std::vector<std::string> palette;
    if (palette_name != "") //!Si la palette n'a pas été déclarée, elle prend une valeur par défault.
        palette = choix_palette(palette_name);
        
    if (nom_fichier == "") //!Si le fichier .pgm n'est pas déclaré, on demande à l'utilisateur d'en rentrer un autre ou de le rentrer à nouveau.
    {
        std::cout << "Le fichier .pgm est manquant, entrez le à nouveau : ";
        std::cin >> nom_fichier;
    }

    //! Ouverture du fichier .pgm, si celui ci ne s'ouvre pas, on demande de l'ouvrir à nouveau.
    std::ifstream file(nom_fichier, std::ios_base::binary);
    if (!file.is_open())
    {
        std::cerr << "Le fichier .pgm est manquant, entrez le à nouveau :";
        std::cin >> nom_fichier;
    }

	//!Ouverture du fichier "ImageTest1.pgm" en mode binaire :
	std::ifstream fichier(nom_fichier, std::ios_base::binary);
	if (!fichier.is_open()) {
		std::cerr << "Problème d'ouverture du fichier " << nom_fichier << ".\n";
		return -1;
	}
	//!Ici vous devez décoder l'entête du fichier
	std::vector<size_t> header = decripteur(fichier);
	int largeur = header[0];
	int hauteur = header[1];
	int pix = largeur * hauteur;

	//!Création d'une mémoire de pix octets :
	std::vector<char> donnees(pix);

	//!Lecture de pix octets depuis le fichier et stockage dans le tableau donnees :
	fichier.read(donnees.data(), pix);

	//!Récupération de la palette choisie
	std::vector<std::string> palette2 = choix_palette(palette_name);

	//!Affichage de l'image en ASCII art
	if (outfile_name == "")
		affichage_console(donnees, palette2, largeur, pix);
	else
		affichagev3(donnees, palette2, largeur, pix, outfile_name);
}