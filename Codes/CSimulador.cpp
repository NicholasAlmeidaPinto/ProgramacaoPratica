#include "CSimulador.h"

using namespace std;


void CSimulador::Menu() {
	int Opt;
	bool RodarMenu = true;
	//cout << "Entre com o numero de reservatorios: ";
	//cin >> numReser;
	//reservatorios.resize(numReser);
	while (RodarMenu) {
		system("cls");
		cout << "\n\n\n\nSIMULADOR DE PRESSAO EM RESERVATORIO DE PETROLEO"
			<< "\n\nRESERVATORIOS CADASTRADOS: " << reservatorios.size() << "   SALVAR DADOS: " << SalvaDados
			<< "\n1-ADICIONAR RESERVATORIO"
			<< "\n2-TROCAR RESERVATORIO"
			<< "\n3-EXCLUIR RESERVATORIO"
			<< "\n4-SALVAR/NAO SALVAR DADOS"
			<< "\n\n5-CALCULAR PRESSAO SIMPLES"
			<< "\n6-CALCULAR PRESSAO VARIANDO NO TEMPO"
			<< "\n7-CALCULAR PRESSAO VARIANDO A DISTANCIA"
			<< "\n0-SAIR"
			<< "\n\n--> ";
		cin >> Opt;

		switch (Opt) {
			case 1:
				CriarReservatorio();
				break;
			case 2:
				TrocarReservatorio();
				break;
			case 3:
				DestruirReservatorio();
				break;
			case 4:
				SalvarDados();
				break;
			case 5:
				break;
			case 6:
				break;
			case 7:
				break;
			case 0:
				RodarMenu = false;
				break;
			default:
				cout << "\nOPCAO INVALIDA!";
		}
	}
}

void CSimulador::TrocarReservatorio() {
	cout << "\nQual deseja ser trocado: ";
	int a; cin >> a;
	string nomeZ;
	cout << "\nNome do arquivo: ";
	cin >> nomeZ;
	reservatorios[a].LerDados(nomeZ);
}

void CSimulador::CriarReservatorio() {
	string nome;
	cout << "\nNome do arquivo com o reservatorio: ";
	cin >> nome;
	CPressao pressao(nome);
	reservatorios.push_back(pressao);
}

void CSimulador::DestruirReservatorio() {
	MostrarReservatorios();
	int posicao;
	//cout << "\nReservatorio a ser excluido: ";
	//cin >> posicao;
	//reservatorios.erase(posicao);
	reservatorios.pop_back();
}

void CSimulador::SalvarDados() {
	if (SalvaDados)
		SalvaDados = false;
	else
		SalvaDados = true;
}

void CSimulador::MostrarReservatorios() {
	cout << "------#-----#-----#-----#------"
		<< "\nRESERVATORIOS/POCOS ADICIONADOS";
	for (int i = 0; i < (int) reservatorios.size(); i++) {
		cout << "\n" << i << " --> " << reservatorios[i].Nome();
	}
}