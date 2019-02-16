#ifndef CSimulador_h
#define CSimulador_h

#include <vector>
#include "CPressao.h"
#include <iostream>
#include <string>

class CSimulador {
	private:
		std::vector<CPressao> reservatorios;
		int numReser;
		bool SalvaDados = false;
	public:
		CSimulador() {}
		~CSimulador(){}

		void Menu();

	private:
		void TrocarReservatorio();
		void CriarReservatorio();
		void DestruirReservatorio();
		void MostrarReservatorios();
		void SalvarDados();
};

#endif