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
	double ConstEstocagemAdmen;

	const double gama = 0.57721566;
	const double pi = 3.14159265;

public:
	///Construtores
	CPressao() {
		CalcPressaoAdmen();
		CalcTempoAdmen();
		CalcEstocagemAdmen();
	}
	///Construtor por nome de arquivo
	CPressao(std::string NomeArquivo) {
		LerDados(NomeArquivo);
		CalcPressaoAdmen();
		CalcTempoAdmen();
		CalcEstocagemAdmen();
	}
	///Destrutor 
	~CPressao() {}

	double GerarPressao(double _Tempo, double _Dist);

	void MostrarVariaveis(){
	std::cout << "\nPressao: " << ConstPressaoAdmen << "\nTempo: " << ConstTempoAdmen << "\nEstocagem: " << ConstEstocagemAdmen;
	}

private:
	///Obter variaveis admensionais
	void CalcPressaoAdmen();
	double CalcDistAdmen(double _Dist);
	void CalcTempoAdmen();
	void CalcEstocagemAdmen();
	double PressaoDimen(double PressaoAdmen) { return PressaoAdmen / ConstPressaoAdmen; }

	//Somente eh chamado pelo GerarPressao(...)
	double ReservatorioInfinito(double _Tempo, double _Dist);
	double ReservatorioCircularManutencaoPressao(double _Tempo, double _Dist);
	double ReservatorioCircularSelado(double _Tempo, double _Dist);
	double GeometriaArbitrariaSelado(double _Tempo, double _Dist);
};
#endif