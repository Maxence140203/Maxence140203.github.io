#pragma once
#include <vector>
#include <fstream>

std::vector<int> convertir_int(std::vector<char>);

std::vector<size_t> decripteur(std::ifstream &file);

std::vector<std::string> choix_palette(std::string file_name);

std::string to_char(unsigned char donnees, std::vector<std::string> palette);

