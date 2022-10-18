#include <ctime>
#include <fstream>
#include <iostream>
#include <string>
using namespace std;

string paraMaiusculo(string frase) {
  for (int i = 0; i < frase.length(); i++) {
    frase[i] = toupper(frase[i]);
  }
  return frase;
}

string pegarPrimeiroNome(string nome) {
  string primeiroNome = "";
  int i;
  for (i = 0; i < nome.length(); i++) {
    if (nome[i] == ' ' || nome[i] == '\0' || nome[i] == '\n') {
      break;
    }
    primeiroNome.append(1, nome[i]);
  }
  return primeiroNome;
}

bool validaNomeCompleto(string nome) {
  for (int i = 0; i < nome.length(); i++) {
    if (nome[i] == ' ' && (nome[i + 1] != ' ' || nome[i + 1] != '\n')) {
      return true;
    }
  }
  return false;
}

void splitstr(string str, string deli = " ") {
  int start = 0;
  int end = str.find(deli);
  while (end != -1) {
    cout << str.substr(start, end - start) << endl;
    start = end + deli.size();
    end = str.find(deli, start);
  }
  cout << str.substr(start, end - start);
}

// MAIN

typedef struct {
  string codigo;
  string jogador;
  string selecao;
} Figurinha;

int contarLinhasArquivo(string nomeArquivo) {
  ifstream procuradorLeitura;
  procuradorLeitura.open(nomeArquivo);

  if (!procuradorLeitura)
    return 0;

  int qtdLinhas = 0;
  string linha;
  while (!procuradorLeitura.eof()) {
    getline(procuradorLeitura, linha); // lendo a linha inteira
    if (linha == "")
      break;
    qtdLinhas++;
  }
  procuradorLeitura.close();
  return qtdLinhas;
}

void popularListaArquivoRepitidas(Figurinha *lista, string nomeArquivo) {
  ifstream procuradorLeitura;
  procuradorLeitura.open(nomeArquivo);
  string jogador, selecao, codigo;
  int i = 0;

  string linha;
  while (!procuradorLeitura.eof()) {
    getline(procuradorLeitura, linha); // lendo a linha inteira
    if (linha == "")
      break;

    int posicaoPrimeiroPontoVirgula = linha.find(";");
    int posicaoUltimoPontoVirgula = linha.find_last_of(";");
    cout << linha << endl;
    cout << "posicaoUltimoPontoVirgula: " << posicaoUltimoPontoVirgula << endl;

    codigo = linha.substr(0, posicaoPrimeiroPontoVirgula);
    jogador = linha.substr(posicaoPrimeiroPontoVirgula + 1,
                           posicaoUltimoPontoVirgula -
                               (posicaoPrimeiroPontoVirgula + 1));
    selecao = linha.substr(posicaoUltimoPontoVirgula + 1, 200);

    lista[i].codigo = codigo;
    lista[i].jogador = jogador;
    lista[i].selecao = selecao;
    i++;
  }
  procuradorLeitura.close();
}

void popularListaArquivoFaltantes(Figurinha *lista, string nomeArquivo) {
  ifstream procuradorLeitura;
  procuradorLeitura.open(nomeArquivo);
  string jogador, selecao, codigo;
  int i = 0;

  string linha;
  while (!procuradorLeitura.eof()) {
    getline(procuradorLeitura, linha); // lendo a linha inteira
    if (linha == "")
      break;

    int posicaoPrimeiroPontoVirgula = linha.find(";");
    int posicaoUltimoPontoVirgula = linha.find_last_of(";");
    cout << linha << endl;
    cout << "posicaoUltimoPontoVirgula: " << posicaoUltimoPontoVirgula << endl;

    codigo = linha.substr(0, posicaoPrimeiroPontoVirgula);
    jogador = linha.substr(posicaoPrimeiroPontoVirgula + 1,
                           posicaoUltimoPontoVirgula -
                               (posicaoPrimeiroPontoVirgula + 1));
    selecao = linha.substr(posicaoUltimoPontoVirgula + 1, 200);

    lista[i].codigo = codigo;
    lista[i].jogador = jogador;
    lista[i].selecao = selecao;
    i++;
  }
  procuradorLeitura.close();
}

void exibirListaRepetidas(Figurinha *lista, int qtdInscritos) {
  for (int i = 0; i < qtdInscritos; i++) {
    cout << "Codigo: " << lista[i].codigo << ". Jogador: " << lista[i].jogador
         << ". Selecao: " << lista[i].selecao << endl;
  }
}

void exibirListaFaltantes(Figurinha *lista, int qtdInscritos) {
  for (int i = 0; i < qtdInscritos; i++) {
    cout << "Codigo: " << lista[i].codigo << ". Jogador: " << lista[i].jogador
         << ". Selecao: " << lista[i].selecao << endl;
  }
}

bool jaCadastradoRepetidas(string codigo, Figurinha *lista, int qtdRepetidas) {
  for (int i = 0; i < qtdRepetidas; i++) {
    if (lista[i].codigo == codigo) {
      return true;
    }
  }
  return false;
}

bool jaCadastradoFaltantes(string codigo, Figurinha *lista, int qtdFaltantes) {
  for (int i = 0; i < qtdFaltantes; i++) {
    if (lista[i].codigo == codigo) {
      return true;
    }
  }
  return false;
}

void cadastrarNaListaRepitidas(Figurinha *lista, int *qtdRepetidas,
                               string nomeArquivo) {
  ofstream procuradorEscrita;
  string codigo, jogador, selecao;
  procuradorEscrita.open(nomeArquivo, ios::out | ios::app);
  cout << "Jogador sendo cadastrado na posicao " << *qtdRepetidas << endl;
  do {
    cout << "Digite o nome do jogador: ";
    getline(cin, jogador);
    jogador = paraMaiusculo(jogador);
  } while (!validaNomeCompleto(jogador));

  cout << "Digite a selecao do jogador: ";
  getline(cin, selecao);
  selecao = paraMaiusculo(selecao);

  cout << "Digite o codigo do jogador: ";
  cin >> codigo;
  codigo = paraMaiusculo(codigo);

  // teria que verificar se esse par nome e email já estão na lista
  if (jaCadastradoRepetidas(codigo, lista, *qtdRepetidas)) {
    cout << "Erro: Jogador ja cadastrado no sistema\n";
  } else {
    lista[*qtdRepetidas].codigo = codigo;
    lista[*qtdRepetidas].jogador = jogador;
    lista[*qtdRepetidas].selecao = selecao;
    *qtdRepetidas = *qtdRepetidas + 1;
    // adicionar no final do arquivo
    procuradorEscrita << codigo << ";" << jogador << ";" << selecao << endl;
  }
  procuradorEscrita.close();
}

void cadastrarNaListaFaltantes(Figurinha *lista, int *qtdFaltantes,
                               string nomeArquivo) {
  ofstream procuradorEscrita;
  string codigo, jogador, selecao;
  procuradorEscrita.open(nomeArquivo, ios::out | ios::app);
  cout << "Jogador sendo cadastrado na posicao " << *qtdFaltantes << endl;
  do {
    cout << "Digite o nome do jogador: ";
    getline(cin, jogador);
    jogador = paraMaiusculo(jogador);
  } while (!validaNomeCompleto(jogador));

  cout << "Digite a selecao do jogador: ";
  getline(cin, selecao);
  selecao = paraMaiusculo(selecao);

  cout << "Digite o codigo do jogador: ";
  cin >> codigo;
  codigo = paraMaiusculo(codigo);

  // teria que verificar se esse par nome e email já estão na lista
  if (jaCadastradoRepetidas(codigo, lista, *qtdFaltantes)) {
    cout << "Erro: Jogador ja cadastrado no sistema\n";
  } else {
    lista[*qtdFaltantes].codigo = codigo;
    lista[*qtdFaltantes].jogador = jogador;
    lista[*qtdFaltantes].selecao = selecao;
    *qtdFaltantes = *qtdFaltantes + 1;
    // adicionar no final do arquivo
    procuradorEscrita << codigo << ";" << jogador << ";" << selecao << endl;
  }
  procuradorEscrita.close();
}

void menu(Figurinha *listaRepetidas, string *listaFaltantes, int qtdRepetidas,
          int qtdFaltantes, string nomeArquivoRepetidas,
          string nomeArquivoFaltantes) {
  int opcao;
  int tecla;
  do {
    system("clear");
    cout << "MENU\n";
    cout << "1 - Cadastrar figurinhas repetidas\n";
    cout << "2 - Cadastrar figurinhas faltantes\n";
    cout << "3 - Listar repetidas\n";
    cout << "4 - Listar faltantes\n";
    cout << "5 - Sair\n";
    cout << "Opcao: ";
    cin >> opcao;
    cin.ignore();

    switch (opcao) {
    case 1:
      cout << "CADASTRAR FIGURA\n";
      cadastrarNaListaRepitidas(listaRepetidas, &qtdRepetidas,
                                nomeArquivoRepetidas);
      break;
    case 2:
      cout << "LISTAGEM DE REPETIDAS\n";
      exibirListaRepetidas(listaRepetidas, qtdRepetidas);
      break;
    case 3:
      cout << "REGISTRAR PRESENCA\n";
      cadastrarNaListaFaltantes(listaFaltantes, &qtdFaltantes,
                                nomeArquivoFaltantes);
      break;
    case 4:
      cout << "LISTAGEM DE PRSENTES\n";
      exibirListaFaltantes(listaRepetidas, qtdRepetidas);
      break;
    case 5:
      break;
    default:
      cout << "Opcao invalida!!\n";
      break;
    }

    system("sleep 10s");

  } while (opcao != 5);
}

int main() {
  Figurinha *listaRepetidas; // um inscrito, com nome, email e matricula
  Figurinha *listaFaltantes; // somente a matricula dos presentes
  int quantidadeRepetidas;
  int quantidadeFaltantes;
  string nomeArquivoFaltantes = "Faltantes.csv";
  string nomeArquivoRepetidas = "Repetidas.csv";

  quantidadeRepetidas = contarLinhasArquivo(nomeArquivoRepetidas);
  quantidadeFaltantes = contarLinhasArquivo(nomeArquivoFaltantes);
  listaRepetidas =
      (Figurinha *)malloc(sizeof(Figurinha) * (quantidadeRepetidas + 100));
  listaFaltantes =
      (Figurinha *)malloc(sizeof(Figurinha) * (quantidadeFaltantes + 100));

  // popular lista com dados do arquivo ao iniciar o sistema
  popularListaArquivoRepetidas(listaRepetidas, nomeArquivoRepetidas);
  popularListaArquivoFaltantes(listaFaltantes, nomeArquivoFaltantes);
  // chamar menu
  menu(listaRepetidas, listaFaltantes, quantidadeRepetidas, quantidadeFaltantes,
       nomeArquivoRepetidas, nomeArquivoFaltantes);

  return 1;
}
