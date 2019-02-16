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
	cout << "\nQueda de pressao: " << pressao.ReservatorioInfinito(100,10);
	cin.get()//*/
	CSimulador simulador;
	simulador.Menu();


	return 0;
}