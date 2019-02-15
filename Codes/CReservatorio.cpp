#include "CReservatorio.h"

void CReservatorio::LerDados(std::string NomeArquivo) {
	NomeArquivo = NomeArquivo+".txt";
	std::ifstream f(NomeArquivo);
	std::string line;
	int a;

	while (!f.eof()) {
		std::getline(f, line); std::getline(f, line); PressaoInicial = std::stof(line);
		std::getline(f, line); std::getline(f, line); Vazao = std::stof(line);
		std::getline(f, line); std::getline(f, line); Permeabilidade = std::stof(line);
		std::getline(f, line); std::getline(f, line); Viscosidade = std::stof(line);
		std::getline(f, line); std::getline(f, line); RaioPoco = std::stof(line);
		std::getline(f, line); std::getline(f, line); FatorVolForm = std::stof(line);
		std::getline(f, line); std::getline(f, line); ComprTotal = std::stof(line);
		std::getline(f, line); std::getline(f, line); Porosidade = std::stof(line);
		std::getline(f, line); std::getline(f, line); AlturaReser = std::stof(line);
		std::getline(f, line); std::getline(f, line); Latitude = std::stof(line);
		std::getline(f, line); std::getline(f, line); Longitude = std::stof(line);
		std::getline(f, line); std::getline(f, line); FatorPelicula = std::stof(line);
		std::getline(f, line); std::getline(f, line); RaioExterno = std::stof(line);
		std::getline(f, line); std::getline(f, line); FatorForma = std::stof(line);
		std::getline(f, line); std::getline(f, line); Area = std::stof(line);
		std::getline(f, line); std::getline(f, line); a = std::stoi(line);
		if (a == 0)
			anp = true;
		else
			anp = false;
	}
}