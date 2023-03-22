#include <vector>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <fstream>



std::vector<int> convertir_int(std::vector<char> donnees)
{
	std::vector<int> entiers;
	int a;
	for (int i = 0; i < donnees.size(); i++)
	{
		a = donnees[i];
		entiers.push_back(a);
	}
	return entiers;

}

std::vector<size_t> decripteur(std::ifstream &file)
{
	std::string line;
	for (int i = 0; i < 2; i++)
		std::getline(file, line);

	std::vector<size_t> Taille;

	std::getline(file, line);
	std::string ligne;
	std::stringstream sst(line);
	for (int i = 0; i < 2; i++) {
		std::getline(sst, ligne, ' ');
		std::size_t banque;
		std::stringstream sss(ligne);
		sss >> banque;
		Taille.push_back(banque);
	}
	return Taille;
}

std::vector<std::string> choix_palette()
{
	//L'utilisateur entre le nom de la palette a utiliser 
	std::string file_name;
	std::cout << "Entrez la palette a utiliser : ";
	std::cin >> file_name;
	file_name += ".txt"; //ajout de l'extension du fichier

	std::vector<std::string> palette;
	std::ifstream file(file_name);

	//vérification de l'ouverture du fichier
	if (!file.is_open())
		std::cerr << "Problème d'ouverture du fichier \"img.pgm\".\n";
	std::string line;

	//Récupération de tout les caractères du fichier palette
	while (!file.eof()) {
		std::getline(file, line);
		palette.push_back(line);
	}
	return palette;
}

std::string to_char(unsigned char donnees, std::vector<std::string> palette)
{
	std::string caractere;
	int taille = palette.size();
	int pas = 256 / taille;
	int car = pas;
	for (size_t i = 0; i < taille; i++)
	{
		if (donnees < car)
		{
			caractere = palette[i];
			std::cout << caractere;
			break;
		}
		car += pas;
	}
	return caractere;
}