#include "CReservatorio.h"

void CReservatorio::LerDados(std::string NomeArquivo) {
	//NomeArquivo = NomeArquivo+".txt";
	std::ifstream f(NomeArquivo);
	std::string line;
	int a;

	std::getline(f, line); std::getline(f, line); PressaoInicial = std::stod(line);
	std::getline(f, line); std::getline(f, line); Vazao = std::stod(line);
	std::getline(f, line); std::getline(f, line); Permeabilidade = std::stod(line);
	std::getline(f, line); std::getline(f, line); Viscosidade = std::stod(line);
	std::getline(f, line); std::getline(f, line); RaioPoco = std::stod(line);
	std::getline(f, line); std::getline(f, line); FatorVolForm = std::stod(line);
	std::getline(f, line); std::getline(f, line); ComprTotal = std::stod(line);
	std::getline(f, line); std::getline(f, line); Porosidade = std::stod(line);
	std::getline(f, line); std::getline(f, line); AlturaReser = std::stod(line);
	std::getline(f, line); std::getline(f, line); Latitude = std::stod(line);
	std::getline(f, line); std::getline(f, line); Longitude = std::stod(line);
	std::getline(f, line); std::getline(f, line); FatorPelicula = std::stod(line);
	std::getline(f, line); std::getline(f, line); RaioExterno = std::stod(line);
	std::getline(f, line); std::getline(f, line); FatorForma = std::stod(line);
	std::getline(f, line); std::getline(f, line); Area = std::stod(line);
	std::getline(f, line); std::getline(f, line); a = std::stoi(line);
	if (a == 0)
		anp = true;
	else
		anp = false;
}