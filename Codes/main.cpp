#include <iostream>
#include "CPressao.h"
#include <string>

using namespace std;

int main()
{
	string nome = "Reservatorio0";
	CPressao pressao(nome);
	cout << "\nQueda de pressao: " << pressao.ReservatorioInfinito(100,10);
	cin.get();
	return 0;
}