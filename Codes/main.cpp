#include <iostream>
#include "CPressao.h"
#include <string>

using namespace std;

int main()
{

	string nome = "C:/Users/nicho/Source/Repos/NicholasAlmeidaPinto/ProgramacaoPratica/Codes/Dados/Reservatorio0.txt";
	CPressao pressao(nome);
	cout << "\nQueda de pressao: " << pressao.ReservatorioInfinito(100,10);
	cin.get();
	
	return 0;
}