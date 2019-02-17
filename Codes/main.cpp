#include <iostream>
#include "CPressao.h"
#include <string>
#include "CSimulador.h"

using namespace std;

int main()
{
	/*
	string nome = "Reservatorio0";
	CPressao pressao(nome);
	cout << "\nQueda de pressao: " << pressao.GerarPressao(500000,0);
	cin.get();//*/
	CSimulador simulador;
	simulador.Menu();
	

	return 0;
}