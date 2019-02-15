#ifndef CReservatorio_h
#define CReservatorio_h

#include <string>
#include <iostream>
#include <fstream>

class CReservatorio {
protected:
	///Propriedades do poco/reservatorio (nao variam)
	double PressaoInicial;
	double Vazao;
	double Permeabilidade;
	double Viscosidade;
	double RaioPoco;
	double FatorVolForm;
	double ComprTotal;
	double Porosidade;
	double AlturaReser;
	double Latitude;
	double Longitude;
	double FatorPelicula;
	double RaioExterno;
	double FatorForma;
	double Area;

	///Informacao sobre unidades e modelo para simulacao
	bool anp;
	int TipoReservatorio;

public:
	CReservatorio() {}

	CReservatorio(double _PressaoInicial, double _Vazao, double _Permeabilidade, double _Viscosidade, double _RaioPoco,
		double _FatorVolForm, double _ComprTotal, double _Porosidade, double _AlturaReser,
		double _Latitude, double _Longitude, double _FatorPelicula, bool _anp, double _RaioExterno = 0,
		double _FatorForma = 0, double _Area = 0) :
		PressaoInicial(_PressaoInicial), Vazao(_Vazao), Permeabilidade(_Permeabilidade), Viscosidade(_Viscosidade), RaioPoco(_RaioPoco),
		FatorVolForm(_FatorVolForm), ComprTotal(_ComprTotal), Porosidade(_Porosidade),
		AlturaReser(_AlturaReser), Latitude(_Latitude), Longitude(_Longitude),
		FatorPelicula(_FatorPelicula), anp(_anp), RaioExterno(_RaioExterno), FatorForma(_FatorForma), Area(_Area)
	{
	}

	CReservatorio(std::string NomeArquivo) {
		LerDados(NomeArquivo);
	}

protected:
	void LerDados(std::string NomeArquivo);
};

#endif
