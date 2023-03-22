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

std::vector<std::string> choix_palette(std::string file_name)
{
	std::vector<std::string> palette;
	std::ifstream file(file_name);

	//!vérification de l'ouverture du fichier
	if (!file.is_open()) {
		std::cerr << "Problème d'ouverture du fichier " << file_name << ".\n";
	}
	std::string line;

	//!Récupération de tout les caractères du fichier palette
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

void help() {
	std::cout << "Usage :\npgm2txt [options]\n\nOptions :\n--input fichier";
	std::cout << std::setw(45) << "Spécifie le fichier image à convertir\n" << std::setw(90) << "Si ce paramètre n'est pas spécifié, le fichier est demandé via la\n";
	std::cout << std::setw(28) << "console.";
	std::cout << "\n\n--output fichier";
	std::cout << std::setw(59) << "Spécifie le nom du fichier qui contiendra l'Ascii Art\n" << std::setw(90) << "Si ce paramètre n'est pas spécifié, l'Ascii Art est sortie dans la\n";
	std::cout << std::setw(28) << "console.";
	std::cout << "\n\n--palette fichier";
	std::cout << std::setw(68) << "Spécifie un fichier texte contenant la palette de couleur Ascii\n" << std::setw(85) << "Chaque ligne du fichier contient un caractère en UTF-8, du plus\n" << std::setw(42) << "sombre au plus clair.\n";
	std::cout << std::setw(85) << "Si ce paramettre n'est pas spécifié, la palette par defaut est\n";
	std::cout << std::setw(59) << "\"W\", \"w\", \"l\", \"i\", \":\", \",\", \".\", \" \"\n";
	std::cout << "\n--help" << std::setw(34) << "Afficher cette aide.";
}