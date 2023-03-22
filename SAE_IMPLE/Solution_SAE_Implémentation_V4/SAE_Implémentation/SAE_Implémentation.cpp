#ifdef _WIN32
#define NOMINMAX
#include <Windows.h>
#endif // _WIN32

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



	std::string nom_fichier;
	std::string outfile_name;
	std::string palette_name;
	for (int i = 1; i < argc; ++i)
	{
		if (std::string(argv[i]) == "--input")
		{
			nom_fichier = std::string(argv[i + 1]);
		}
		else if (std::string(argv[i]) == "--palette_name")
		{
			palette_name = std::string(argv[i + 1]);
		}
		else if (std::string(argv[i]) == "--outfile_name")
		{
			outfile_name = std::string(argv[i + 1]);
		}
	}

	//L'utilisateur entre le nom du fichier puis on l'ouvre
	
	//Ouverture du fichier "ImageTest1.pgm" en mode binaire :
	std::ifstream fichier(nom_fichier, std::ios_base::binary);
	if (!fichier.is_open()) {
		std::cerr << "Problème d'ouverture du fichier " << nom_fichier << ".\n";
		return -1;
	}
	//Ici vous devez décoder l'entête du fichier
	std::vector<size_t> header = decripteur(fichier);
	int largeur = header[0];
	int hauteur = header[1];
	int pix = largeur * hauteur;

	//Création d'une mémoire de pix octets :
	std::vector<char> donnees(pix);

	//Lecture de pix octets depuis le fichier et stockage dans le tableau donnees :
	fichier.read(donnees.data(), pix); 

	//L'utilisateur entre le nom de la palette a utiliser 

	
	//Récupération de la palette choisie
	std::vector<std::string> palette = choix_palette(palette_name);

	

	//Affichage de l'image en ASCII art
	affichagev3(donnees, palette, largeur, pix, outfile_name);
}