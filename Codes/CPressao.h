#ifndef CPressao_h
#define CPressao_h

#include <iostream>
#include <math.h>
#include <string>

#include "CReservatorio.h"

class CPressao : public CReservatorio {
private:
	///Variaveis para transformar em admensional <--> dimensional
	double ConstPressaoAdmen;
	double ConstTempoAdmen;

	const double gama = 0.57721566;
	const double pi = 3.14159265;

public:
	///Construtores
	CPressao() {
		CalcPressaoAdmen();
		CalcTempoAdmen();
	}
	///Construtor por nome de arquivo
	CPressao(std::string NomeArquivo) {
		LerDados(NomeArquivo);
		CalcPressaoAdmen();
		CalcTempoAdmen();
	}
	///Destrutor 
	~CPressao() {}

	double ReservatorioInfinito(double _Tempo, double _Dist);
	double ReservatorioCircularManutencaoPressao(double _Tempo, double _Dist);
	double ReservatorioCircularSelado(double _Tempo, double _Dist);
	double GeometriaArbitrariaSelado(double _Tempo, double _Dist);

	void MostrarVariaveis();

private:
	///Obter variaveis admensionais
	void CalcPressaoAdmen();
	double CalcDistAdmen(double _Dist);
	void CalcTempoAdmen();
	double PressaoDimen(double PressaoAdmen) { return PressaoAdmen / ConstPressaoAdmen; }
};
#endif