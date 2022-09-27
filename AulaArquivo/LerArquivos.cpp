#include <iostream>
#include <string>
#include <fstream> //usar arquivos

using namespace std;

string pegarDominioEmail(string email) {

}

int main() {
    //abrir um arquivo texto e exibir seu conteudo na tela

    //solicita pro usuario nome do arquivo origem
	char nomeArquivo[200];
	cout << "Informe nome do arquivo que quer exibir na tela: ";
	cin >> nomeArquivo;

    //abrir arquivo para leitura
	//https://www.tutorialspoint.com/cplusplus/cpp_files_streams
	ifstream procuradorArquivo; //tipo de arquivo para leitura
    procuradorArquivo.open(nomeArquivo);

    if (!procuradorArquivo) {
        cout << "Arquivo não localizado. Programa encerrado." << endl;
        exit(0);
    }


	//le o arquivo capturando as frases
	string linha;
	int posicao;
	string nome, email;
	while (!procuradorArquivo.eof()) {
		getline(procuradorArquivo,linha); //lendo a linha inteira
		posicao = linha.find(";");
		nome = linha.substr(0, posicao);
		email = linha.substr(posicao+1, 200);

		cout << email << endl;
	}

	procuradorArquivo.close();

    return 1;
}