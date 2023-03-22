#include <vector>
#include <iostream>


void affichage(std::vector<int> nbs, int largeur)
{
	int compteur = 0;
	for (int i = 0; i < nbs.size(); i++)
	{
		if (nbs[i] >= 0 && nbs[i] < 16)
			std::cout << 'W';
		else if (nbs[i] >= 16 && nbs[i] < 32)
			std::cout << 'w';
		else if (nbs[i] >= 32 && nbs[i] < 48)
			std::cout << 'l';
		else if (nbs[i] >= 48 && nbs[i] < 64)
			std::cout << 'i';
		else if (nbs[i] >= 64 && nbs[i] < 80)
			std::cout << ':';
		else if (nbs[i] >= 80 && nbs[i] < 96)
			std::cout << ',';
		else if (nbs[i] >= 96 && nbs[i] < 112)
			std::cout << '.';
		else if (nbs[i] >= 112 && nbs[i] <= 128)
			std::cout << ' ';
		if (compteur == largeur) {
			std::cout << '\n';
			compteur = 0;
		}
		compteur += 1;
	}
}