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

void CPressao::CalcEstocagemAdmen() {
	if (anp)
		ConstEstocagemAdmen = 1 / (2 * pi) / (Porosidade*AlturaReser*ComprTotal*RaioPoco*RaioPoco);
	else
		ConstEstocagemAdmen = 0.8936 / (Porosidade*AlturaReser*ComprTotal*RaioPoco*RaioPoco);
}

double CPressao::ReservatorioInfinito(double _Tempo, double _Dist) {
	double TempoAdmen;
	double DistAdmen;
	double PressaoAdmen;
	double EstocaAdmen = 0;

	TempoAdmen = _Tempo * ConstTempoAdmen;
	DistAdmen = CalcDistAdmen(_Dist);
	//EstocaAdmen = Estocagem * ConstEstocagemAdmen;

	double S;
	if (DistAdmen == 1) { ///Pw -> Pressao no poco, considera fator de pelicula e estocagem
		S = FatorPelicula;
		if ((S >= 0 && TempoAdmen < (60 + 3.5*S)*EstocaAdmen) || (S < 0 && TempoAdmen < (60 * EstocaAdmen))){
			PressaoAdmen = TempoAdmen / EstocaAdmen;
			return PressaoDimen(PressaoAdmen);
		}
		else {///Depois do efeito de estocagem
			PressaoAdmen = 0.5 * log(4 * TempoAdmen / (DistAdmen*exp(gama)));
			return PressaoDimen(PressaoAdmen + S);
		}
	}
	else { ///Fora do poco
		PressaoAdmen = 0.5 * log(4 * TempoAdmen / (DistAdmen*exp(gama)));
		return PressaoDimen(PressaoAdmen);
	}
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