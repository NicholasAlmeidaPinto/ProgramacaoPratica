#include "CSimulador.h"

using namespace std;

void CSimulador::Menu() {
	int Opt;
	bool RodarMenu = true;
	while (RodarMenu) {
		system("cls");
		cout << "SIMULADOR DE PRESSAO EM RESERVATORIO DE PETROLEO"
			<< "\n\nRESERVATORIOS CADASTRADOS: " << reservatorios.size() << "   SALVAR DADOS: ";
		if (SalvaDados)
			cout << "S";
		else
			cout << "N";
			
		cout << "\n\n1-ADICIONAR RESERVATORIO"
			<< "\n2-TROCAR RESERVATORIO"
			<< "\n3-EXCLUIR RESERVATORIO"
			<< "\n4-SALVAR/NAO SALVAR DADOS"
			<< "\n5-MOSTRAR RESERVATORIOS"
			<< "\n\n6-CALCULAR PRESSAO VARIANDO O TEMPO"
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
				PressaoVariandoEspaco();
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
	reservatorios.pop_back();
}

void CSimulador::SalvarDados() {
	if (SalvaDados)
		SalvaDados = false;
	else
		SalvaDados = true;
}

void CSimulador::SalvarTempo(std::vector<double> _Pressao, std::vector<double> _tempo, double _lat, double _lon) {
	cout << "\nNome do arquivo para salvar os dados: ";
	string _nome; cin >> _nome;

	ofstream out;
	_nome = "C:/Users/nicho/Source/Repos/NicholasAlmeidaPinto/ProgramacaoPratica/Codes/DadosGerados/" + _nome + ".data";
	out.open(_nome);

	out << "Latitude: " << _lat << "\nLongitude: " << _lon;
	out << "\n\n  TEMPO--> PRESSAO";
	for (int i = 0; i < (int)_Pressao.size(); i++) 
		out << "\n" << setw(7) << _tempo[i] << "--> " << setw(7) << _Pressao[i];	
	out.close();
}

void CSimulador::SalvarEspaco(std::vector<double> _Pressao, std::vector<double> _lat, std::vector<double> _lon, double _tempo) {
	cout << "\nNome do arquivo para salvar os dados: ";
	string _nome; cin >> _nome;

	ofstream out;
	_nome = "C:/Users/nicho/Source/Repos/NicholasAlmeidaPinto/ProgramacaoPratica/Codes/DadosGerados/" + _nome + ".data";
	out.open(_nome);

	out << "TEMPO: " << _tempo << " segundos\n(LATITUDE, LONGITUDE)--> PRESSAO";
	for (int i = 0; i < (int)_Pressao.size(); i++) 
		out << "\n(" << setw(8) << _lat[i] << ", " << setw(9) << _lon[i] << ")--> " << setw(7) << _Pressao[i];
	out.close();
}

void CSimulador::MostrarReservatorios() {
	cout << "------#-----#-----#-----#------"
		<< "\nRESERVATORIOS/POCOS ADICIONADOS";
	for (int i = 0; i < (int) reservatorios.size(); i++) {
		cout << "\n" << i << " --> " << reservatorios[i].Nome();
	}
}

void CSimulador::PressaoVariandoTempo() {
	if ((int)reservatorios.size() == 0) {
		cout << "\nNENHUM RESERVATORIO CADASTRADO";
		cin.get();
	}
	else {
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
			tempos.push_back(inicio + i * (fim - inicio) / grade);
		}

		vector<double> PressaoTotal;
		for (int i = 0; i < grade; i++)
			PressaoTotal.push_back(0);

		double DistanciaPoco;
		for (int i = 0; i < (int)reservatorios.size(); i++) {
			double lat0 = reservatorios[i].latitude();
			double lon0 = reservatorios[i].longitude();
			DistanciaPoco = DistanciaEuclidiana(lat0, lon0, lat, lon);
			//DistanciaPoco = sqrt((lat0 - lat)*(lat0 - lat) + (lon0 - lon)*(lon0 - lon));
			for (int k = 0; k < grade; k++)
				PressaoTotal[k] += reservatorios[i].GerarPressao(tempos[k], DistanciaPoco);
		}

		if (SalvaDados) 
			SalvarTempo( PressaoTotal, tempos, lat, lon);

		cout << "\nValores da Pressao:";
		for (int i = 0; i < grade; i++)
			cout << "\n" << setw(8) << tempos[i] << ": " << setw(8) << PressaoTotal[i];
		cout << "\n----------------\nDigite algo para continuar\n-->";
		//cin.get();
		string abcd; cin >> abcd;
	}
}

void CSimulador::PressaoVariandoEspaco() {
	if ((int)reservatorios.size() == 0) {
		cout << "\nNENHUM RESERVATORIO CADASTRADO";
		cin.get();
	}
	else {
		///Iniciar variaveis
		vector<double> lat;
		vector<double> lon;
		vector<double> PressaoTotal;
		double tempoSimulacao;
		int grade = 100; ///numero de pontos para simulacao
		double DistanciaPoco; ///distancia euclidiana para simulacao

		system("cls");
		cout << "PRESSAO VARIANDO NO ESPACO";

		///Obter vetores das coordenadas
		cout << "\nInicio da latitude analisada: ";
		double inicio; cin >> inicio;
		cout << "Fim da latitude analisada: ";
		double fim; cin >> fim;
		for (int i = 0; i < grade; i++)
			lat.push_back(inicio + i * (fim - inicio) / grade);

		cout << "\nInicio da longitude analisada: ";
		cin >> inicio;
		cout << "Fim da longitude analisada: ";
		cin >> fim;
		for (int i = 0; i < grade; i++)
			lon.push_back(inicio + i * (fim - inicio) / grade);

		///Tempo analisado para simulacao
		cout << "\nTempo analisado (segundos): ";
		cin >> tempoSimulacao;

		///Iniciar vetor nulo de pressao para adicionar valores de todos os reservatorios com +=
		for (int i = 0; i < grade; i++)
			PressaoTotal.push_back(0);

		///Calculo da pressao
		for (int i = 0; i < (int)reservatorios.size(); i++) { ///loop dos reservatorios

			///coordenadas do reservatorio analisado
			double lat0 = reservatorios[i].latitude();
			double lon0 = reservatorios[i].longitude();

			for (int k = 0; k < grade; k++) {
				DistanciaPoco = DistanciaEuclidiana(lat0, lon0, lat[k], lon[k]);
				PressaoTotal[k] += reservatorios[i].GerarPressao(tempoSimulacao, DistanciaPoco);
			}
		}

		if (SalvaDados)
			SalvarEspaco( PressaoTotal, lat, lon, tempoSimulacao);

		cout << "\nValores da Pressao:\nCoordenadas: Pressao";
		for (int i = 0; i < grade; i++)
			cout << "\n(" << setw(8) << lat[i] << ";" << setw(8) << lon[i] << "): " << setw(8) << PressaoTotal[i];
		cout << "\n----------------\nDigite algo para continuar\n-->";
		//cin.get();
		string abcd; cin >> abcd;
	}
}