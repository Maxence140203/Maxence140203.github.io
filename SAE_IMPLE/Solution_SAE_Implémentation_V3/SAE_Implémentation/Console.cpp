#include <vector>
#include <iostream>
#include <fstream>


void affichagev1(std::vector<int> nbs, int largeur)
{
	int compteur = 0;
	for (int i = 0; i < nbs.size(); i++)
	{
		if (nbs[i] >= 0 && nbs[i] < 32)
			std::cout << 'W';
		else if (nbs[i] >= 32 && nbs[i] < 64)
			std::cout << 'w';
		else if (nbs[i] >= 64 && nbs[i] < 96)
			std::cout << 'l';
		else if (nbs[i] >= 96 && nbs[i] < 128)
			std::cout << 'i';
		else if (nbs[i] >= -128 && nbs[i] < -96)
			std::cout << ':';
		else if (nbs[i] >= -96 && nbs[i] < -64)
			std::cout << ',';
		else if (nbs[i] >= -64 && nbs[i] < -32)
			std::cout << '.';
		else if (nbs[i] >= -32 && nbs[i] < 0)
			std::cout << ' ';
		if (compteur == largeur) {
			std::cout << '\n';
			compteur = 0;
		}
		compteur += 1;
	}
}

void affichagev2(std::vector<int> nbs, int largeur, std::vector<std::string> palette)
{
	std::ofstream outfile("outfile.txt");
	int taille = palette.size();
	int compteur = 0;
	for (int i = 0; i < nbs.size(); i++)
	{
		if (nbs[i] >= 0 && nbs[i] < 32)
		{
			std::cout << palette[0];
			outfile << palette[0];
		}
		else if (nbs[i] >= 32 && nbs[i] < 64)
		{
			std::cout << palette[1];
			outfile << palette[1];
		}
		else if (nbs[i] >= 64 && nbs[i] < 96)
		{
			std::cout << palette[2];
			outfile << palette[2];
		}
		else if (nbs[i] >= 96 && nbs[i] < 128)
		{
			std::cout << palette[3];
			outfile << palette[3];
		}
		else if (nbs[i] >= -128 && nbs[i] < -96)
		{
			std::cout << palette[4];
			outfile << palette[4];
		}
		else if (nbs[i] >= -96 && nbs[i] < -64)
		{
			std::cout << palette[5];
			outfile << palette[5];
		}
		else if (nbs[i] >= -64 && nbs[i] < -32)
		{
			std::cout << palette[6];
			outfile << palette[6];
		}
		else if (nbs[i] >= -32 && nbs[i] < 0)
		{
			std::cout << palette[7];
			outfile << palette[7];
		}		if (compteur == largeur) {
			std::cout << '\n';
			outfile << '\n';
			compteur = 0;
		}
		compteur += 1;
	}
}