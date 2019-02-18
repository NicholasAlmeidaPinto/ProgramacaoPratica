#ifndef CSimulador_h
#define CSimulador_h

#include <vector>
#include "CPressao.h"
#include <iostream>
#include <string>
#include <math.h>  //sqrt
#include <iomanip> //setw

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
		inline double DistanciaEuclidiana(double lat0, double lon0, double lat1, double lon1) {
				return sqrt((lat0 - lat1)*(lat0 - lat1) + (lon0 - lon1)*(lon0 - lon1));
		}
		void PressaoVariandoTempo();
		void PressaoVariandoEspaco();
};

#endif