#include "CPressao.h"

void CPressao::CalcPressaoAdmen() {
	if (anp)
		ConstPressaoAdmen = Permeabilidade * AlturaReser / (19.03*
			Vazao*FatorVolForm*Viscosidade);
	else
		ConstPressaoAdmen = Permeabilidade * AlturaReser / (141.2*
			Vazao*FatorVolForm*Viscosidade);
}

double CPressao::CalcDistAdmen(double _Dist) {
	if (_Dist <= RaioPoco)
		return 1;
	else
		return _Dist / RaioPoco;
}

void CPressao::CalcTempoAdmen() {
	if (anp)
		ConstTempoAdmen = 0.0003484*Permeabilidade / (Porosidade*
			Viscosidade*ComprTotal*RaioPoco*RaioPoco);
	else
		ConstTempoAdmen = 0.0002637 * Permeabilidade / (Porosidade*
			Viscosidade*ComprTotal*RaioPoco*RaioPoco);
}

double CPressao::ReservatorioInfinito(double _Tempo, double _Dist) {
	double TempoAdmen;
	double DistAdmen;
	double PressaoAdmen;

	TempoAdmen = _Tempo * ConstTempoAdmen;
	DistAdmen = CalcDistAdmen(_Dist);

	double S;
	if (DistAdmen == 1)
		S = FatorPelicula;
	else
		S = 0;

	PressaoAdmen = 0.5 * log(4 * TempoAdmen / (DistAdmen*exp(gama)));
	return PressaoDimen(PressaoAdmen + S);
}

double CPressao::ReservatorioCircularManutencaoPressao(double _Tempo, double _Dist) {
	double TempoAdmen;
	double DistAdmen;
	double TempoAdmenA;
	double PressaoAdmen;

	if (RaioExterno == 0) {
		std::cout << "\nNAO INFORMADO: RAIO EXTERNO!\n";
		return 0;
	}
	double RaioExternoAd = RaioExterno / RaioPoco;

	TempoAdmen = _Tempo * ConstTempoAdmen;
	DistAdmen = CalcDistAdmen(_Dist);

	double S;
	if (DistAdmen == 1)
		S = FatorPelicula;
	else
		S = 0;

	TempoAdmenA = TempoAdmen / (pi*RaioExternoAd*RaioExternoAd);

	if (TempoAdmenA < 0.1)
		return ReservatorioInfinito(_Tempo, _Dist);
	else
		PressaoAdmen = log(RaioExternoAd);

	return PressaoDimen(PressaoAdmen + S);
}

double CPressao::ReservatorioCircularSelado(double _Tempo, double _Dist) {
	double TempoAdmen;
	double DistAdmen;
	double TempoAdmenA;
	double PressaoAdmen;

	if (RaioExterno == 0) {
		std::cout << "\nNAO INFORMADO: RAIO EXTERNO!\n";
		return 0;
	}
	double Red = RaioExterno / RaioPoco;

	TempoAdmen = _Tempo * ConstTempoAdmen;
	DistAdmen = CalcDistAdmen(_Dist);

	double S;
	if (DistAdmen == 1)
		S = FatorPelicula;
	else
		S = 0;

	TempoAdmenA = TempoAdmen / (pi*Red*Red);

	if (TempoAdmenA < 0.1)
		return ReservatorioInfinito(_Tempo, _Dist);
	else {
		if (DistAdmen == 1)
			PressaoAdmen = 2 * TempoAdmen / (Red*Red) - 3 / 4 + log(Red);
		else
			PressaoAdmen = 2 * (DistAdmen*DistAdmen / 4 + TempoAdmen) / (Red*Red - 1) - Red * Red*log(DistAdmen) / (Red*Red - 1) -
			(3 * Red*Red*Red*Red - Red * Red*Red*Red*log(Red) - 2 * Red*Red*Red - 1) / (4 * (Red*Red - 1)*(Red*Red - 1));
	}

	return PressaoDimen(PressaoAdmen + S);
}

double CPressao::GeometriaArbitrariaSelado(double _Tempo, double _Dist) {
	double TempoAdmen;
	double DistAdmen;
	double TempoAdmenA;
	double PressaoAdmen;

	if (RaioExterno == 0) {
		std::cout << "\nNAO INFORMADO: RAIO EXTERNO!\n";
		return 0;
	}
	double Red = RaioExterno / RaioPoco;
	if (FatorForma == 0) {
		std::cout << "\nNAO INFORMADO: FATOR DE FORMA DE DIETZ!\n";
		return 0;
	}
	if (Area == 0) {
		std::cout << "\nNAO INFORMADO: AREA!\n";
		return 0;
	}

	TempoAdmen = _Tempo * ConstTempoAdmen;
	DistAdmen = CalcDistAdmen(_Dist);

	double S;
	if (DistAdmen == 1)
		S = FatorPelicula;
	else
		S = 0;

	TempoAdmenA = TempoAdmen / (pi*Red*Red);

	if (TempoAdmenA < 0.1)
		return ReservatorioInfinito(_Tempo, _Dist);
	else
		PressaoAdmen = 2 * pi*TempoAdmenA +
		0.5*Area * 4 / (exp(gama)*FatorForma*RaioPoco*RaioPoco);
	return PressaoDimen(PressaoAdmen + S);
}

void CPressao::MostrarVariaveis() {
	using namespace std;
	cout << "\nVazao: " << Vazao;
	cout << "\nPermeabilidade: " << Permeabilidade;

}

double CPressao::GerarPressao(double _Tempo, double _Dist) {
	double P;
	switch (ModeloReservatorio) {
		case 1:
			P = ReservatorioInfinito(_Tempo, _Dist);
			break;
		case 2:
			P = ReservatorioCircularManutencaoPressao(_Tempo, _Dist);
			break;
		case 3:
			P = ReservatorioCircularSelado(_Tempo, _Dist);
			break;
		case 4:
			P = GeometriaArbitrariaSelado(_Tempo, _Dist);
			break;
	}
	return P;
}