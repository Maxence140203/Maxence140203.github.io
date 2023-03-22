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
	//Ouverture du fichier "ImageTest1.pgm" en mode binaire :
	std::ifstream fichier("img.pgm", std::ios_base::binary);
	//Ici vous devez décoder l'entête du fichier
	std::vector<std::string> header;
	int pix = 213 * 237;
	int largeur = 213;
	if (!fichier.is_open())
		std::cerr << "Problème d'ouverture du fichier \"img.pgm\".\n";
	std::string line;
	for (int indice = 0; indice < 4; indice++)
	{
		std::getline(fichier, line);
		if (line.empty())
			continue;
		header.push_back(line);
	}
	for (int i = 0; i < 4; i++)
	{
		std::cout << header[i] << '\n';
	}

	//Création d'une mémoire de 10 octets :
	std::vector<char> donnees(pix);
	//Lecture de 10 octets depuis le fichier et stockage dans le tableau donnees :
	fichier.read(donnees.data(), pix);
	
	affichage(convertir_int(donnees), largeur);
}