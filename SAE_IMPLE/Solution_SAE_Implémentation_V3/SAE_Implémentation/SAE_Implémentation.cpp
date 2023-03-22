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

int main()
{
#ifdef _WIN32
	SetConsoleCP(CP_UTF8);
	SetConsoleOutputCP(CP_UTF8);
#endif 

	//L'utilisateur entre le nom du fichier puis on l'ouvre
	std::string nom_fichier;
	std::cout << "Entrez le nom du fichier a traiter : ";
	std::cin >> nom_fichier;
	nom_fichier += ".pgm";

	//Ouverture du fichier "ImageTest1.pgm" en mode binaire :
	std::ifstream fichier(nom_fichier, std::ios_base::binary);
	if (!fichier.is_open()) {
		std::cerr << "Problème d'ouverture du fichier \"img.pgm\".\n";
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

	//Affichage de l'image en ASCII art
	//affichagev1(convertir_int(donnees), largeur);
	std::vector<std::string> palette = choix_palette();
	int compteur = 0;
	for (int i = 0; i < pix; i++)
	{
		std::string car = to_char(donnees[i], palette);       // <= a mettre dans fonction
		std::cout << car;
		if (compteur == largeur)
		{
			compteur = 0;
			std::cout << '\n';
		}
		compteur += 1;
	}
}