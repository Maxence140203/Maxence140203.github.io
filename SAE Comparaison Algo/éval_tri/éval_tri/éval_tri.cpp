#include <iostream>
#include "fonctions.h"
#include <Windows.h>
#include <fstream>


/*
************************
	  Description
************************
Cette fonction est la fonction principale qui lance la fonction qui g�re toutes
les actions et fonction
Oui une seule ligne
************************
	  Param�tres
************************

*/
int main() {
#ifdef _WIN32
	SetConsoleCP(CP_UTF8);
	SetConsoleOutputCP(CP_UTF8);
#endif // _WIN32

	menu();
}
