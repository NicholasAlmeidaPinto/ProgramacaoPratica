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
		cout << "SIMULADOR DE PRESSAO EM RESERVATORIO DE PETROLEO"
			<< "\n\nRESERVATORIOS CADASTRADOS: " << reservatorios.size() << "   SALVAR DADOS: ";
		if (SalvaDados)
			cout << "S";
		else
			cout << "N";
			
		cout << "\n1-ADICIONAR RESERVATORIO"
			<< "\n2-TROCAR RESERVATORIO"
			<< "\n3-EXCLUIR RESERVATORIO"
			<< "\n4-SALVAR/NAO SALVAR DADOS"
			<< "\n\n5-MOSTRAR RESERVATORIOS"
			<< "\n6-CALCULAR PRESSAO VARIANDO O TEMPO"
			<< "\n7-CALCULAR PRESSAO VARIANDO A DISTANCIA"
			<< "\n\n0-SAIR"
			<<"\n----------------------------------------"
			<< "\n\n--> ";
		cin >> Opt;
		string abc;
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
				MostrarReservatorios();
				cout << "\n--------------------\nDigite algo para continuar\n-- > ";
				cin >> abc;
				break;
			case 6:
				PressaoVariandoTempo();
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
	//int posicao;
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

double DistanciaEuclidiana(double lat0, double lon0, double lat1, double lon1) {
	return sqrt((lat0 - lat1)*(lat0 - lat1) + (lon0 - lon1)*(lon0 - lon1));
}
///*
void CSimulador::PressaoVariandoTempo() {
	int grade = 100;
	system("cls");
	cout << "PRESSAO VARIANDO NO TEMPO";

	cout << "\nLatitude: ";
	double lat; cin >> lat;
	cout << "\nLongitude: ";
	double lon; cin >> lon;

	cout << "\nInicio do tempo (segundos): ";
	double inicio; cin >> inicio;
	cout << "\nFim do tempo (segundos): ";
	double fim; cin >> fim;

	vector<double> tempos;
	for (int i = 0; i < grade; i++) {
		tempos.push_back( inicio + i * (fim - inicio) / grade);
	}

	vector<double> PressaoTotal;
	for (int i = 0; i < grade; i++)
		PressaoTotal.push_back(0);
	
	double DistanciaPoco;
	for (int i = 0; i < (int) reservatorios.size(); i++) {
		double lat0 = reservatorios[i].latitude();
		double lon0 = reservatorios[i].longitude();
		//DistanciaPoco = DistanciaEuclidiana(lat0, lon0, lat, lon);
		DistanciaPoco = sqrt((lat0 - lat)*(lat0 - lat) + (lon0 - lon)*(lon0 - lon));
		for (int k = 0; k < grade; k++)
			PressaoTotal[k] += reservatorios[i].GerarPressao(tempos[k], DistanciaPoco);
	}

	cout << "\nValores da Pressao:";
	for (int i = 0; i < grade; i++) 
		cout << "\n" << setw(8)<<tempos[i] << ": " << setw(8) <<  PressaoTotal[i];
	cout << "\n----------------\nDigite algo para continuar\n-->";
	//cin.get();
	string abcd; cin >> abcd;
}//*/