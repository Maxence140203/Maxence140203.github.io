#include <vector>
#include <iostream>

std::vector<int> convertir_int(std::vector<char> donnees)
{
	std::vector<int> entiers;
	int a;
	for (int i = 0; i < donnees.size(); i++)
	{
		a = donnees[i];
		if (a < 0) {
			a *= -1;
			entiers.push_back(a);
		}
		else
			entiers.push_back(a);
	}
	return entiers;

}