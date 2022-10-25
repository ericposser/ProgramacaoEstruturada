#include <ctime>
#include <fstream>
#include <iostream>
#include <string>
using namespace std;

#include "util.h"

typedef struct {
  string codigo;
  string jogador;
  string selecao;
} Figura;

typedef struct {
  string codigo;
  string jogador;
  string selecao;
} FiguraF;

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

void popularListaArquivoRepetidas(Figura *lista, string nomeArquivo) {
  ifstream procuradorLeitura;
  procuradorLeitura.open(nomeArquivo);
  string codigo, jogador, selecao;
  bool especial;
  int i = 0;

  string linha;
  while (!procuradorLeitura.eof()) {
    getline(procuradorLeitura, linha); // lendo a linha inteira
    if (linha == "")
      break;

    int posicaoPrimeiroPontoVirgula = linha.find(";");
    int posicaoUltimoPontoVirgula = linha.find_last_of(";");

    codigo = linha.substr(0, posicaoPrimeiroPontoVirgula);
    jogador = linha.substr(posicaoPrimeiroPontoVirgula + 1,
                           posicaoUltimoPontoVirgula);
    selecao = linha.substr(posicaoPrimeiroPontoVirgula + 1,
                           posicaoUltimoPontoVirgula);
    

    lista[i].codigo = codigo;
    lista[i].jogador = jogador;
    lista[i].selecao = selecao;
    
    i++;
  }
  procuradorLeitura.close();
}

void popularListaArquivoFaltantes(FiguraF *lista, string nomeArquivo) {
  ifstream procuradorLeitura;
  procuradorLeitura.open(nomeArquivo);
  string codigo, jogador, selecao;
  int i = 0;

  string linha;
  while (!procuradorLeitura.eof()) {
    getline(procuradorLeitura, linha); // lendo a linha inteira
    if (linha == "")
      break;

    int posicaoPrimeiroPontoVirgula = linha.find(";");
    int posicaoUltimoPontoVirgula = linha.find_last_of(";");

    codigo = linha.substr(0, posicaoPrimeiroPontoVirgula);
    jogador = linha.substr(posicaoPrimeiroPontoVirgula + 1,
                           posicaoUltimoPontoVirgula);
    selecao = linha.substr(posicaoUltimoPontoVirgula + 1, 200);

    lista[i].codigo = codigo;
    lista[i].jogador = jogador;
    lista[i].selecao = selecao;
    i++;
  }
  procuradorLeitura.close();
}

void exibirListaRepetidas(Figura *lista, int qtdRepetidas) {
  for (int i = 0; i < qtdRepetidas; i++) {
    cout << "Codigo: " << lista[i].codigo
         << ". Nome do jogador: " << lista[i].jogador
         << ". selecao: " << lista[i].selecao << endl;
  }
}

void exibirListaFaltantes(FiguraF *lista, int qtdFaltantes) {
  for (int i = 0; i < qtdFaltantes; i++) {
    cout << "Codigo: " << lista[i].codigo
         << ". Nome do jogador: " << lista[i].jogador
         << ". selecao: " << lista[i].selecao << endl;
  }
}

bool jaCadastradoRepetidas(string codigo, Figura *lista, int qtdRepetidas) {
  for (int i = 0; i < qtdRepetidas; i++) {
    if (lista[i].codigo == codigo) {
      return true;
    }
  }
  return false;
}

bool jaCadastradoFaltantes(string codigo, FiguraF *lista, int qtdFaltantes) {
  for (int i = 0; i < qtdFaltantes; i++) {
    if (lista[i].codigo == codigo) {
      return true;
    }
  }
  return false;
}

void cadastrarNaListaRepetidas(Figura *lista, int *qtdRepetidas,
                               string nomeArquivo) {
  ofstream procuradorEscrita;
  string codigo, jogador, selecao;
  procuradorEscrita.open(nomeArquivo, ios::out | ios::app);

  cout << "Digite o codigo da figura: ";
  getline(cin, codigo);
  codigo = paraMaiusculo(codigo);

  do {
    cout << "Digite o nome do jogador: ";
    getline(cin, jogador);
    jogador = paraMaiusculo(jogador);
  } while (!validaNomeCompleto(jogador));

  cout << "Digite o nome da selecao: ";
  getline(cin, selecao);
  selecao = paraMaiusculo(selecao);

  // teria que verificar se esse par nome e email já estão na lista
  if (jaCadastradoRepetidas(codigo, lista, *qtdRepetidas)) {
    cout << "Erro: Codigo ja cadastrado no sistema\n";
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

void cadastrarNaListaFaltantes(FiguraF *lista, int *qtdFaltantes,
                               string nomeArquivo) {
  ofstream procuradorEscrita;
  string codigo, jogador, selecao;
  procuradorEscrita.open(nomeArquivo, ios::out | ios::app);

  cout << "Digite o codigo da figura: ";
  getline(cin, codigo);
  codigo = paraMaiusculo(codigo);

  do {
    cout << "Digite o nome do jogador: ";
    getline(cin, jogador);
    jogador = paraMaiusculo(jogador);
  } while (!validaNomeCompleto(jogador));

  cout << "Digite o nome da selecao: ";
  getline(cin, selecao);
  selecao = paraMaiusculo(selecao);

  // teria que verificar se esse par nome e email já estão na lista
  if (jaCadastradoFaltantes(codigo, lista, *qtdFaltantes)) {
    cout << "Erro: Codigo ja cadastrado no sistema\n";
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

void menu(Figura *listaRepetidas, FiguraF *listaFaltantes, int qtdRepetidas,
          int qtdFaltantes, string nomeArquivoRepetidas,
          string nomeArquivoFaltantes) {
  int opcao;
  do {
    system("clear");
    cout << "MENU\n";
    cout << "1 - Cadastrar figura repetida\n";
    cout << "2 - Listar figuras repetidas\n";
    cout << "3 - Registrar figura faltante\n";
    cout << "4 - Listar figuras faltantes\n";
    cout << "5 - Sair\n";
    cout << "Opcao: ";
    cin >> opcao;
    cin.ignore();

    switch (opcao) {
    case 1:
      cadastrarNaListaRepetidas(listaRepetidas, &qtdRepetidas,
                                nomeArquivoRepetidas);
      break;
    case 2:
      exibirListaRepetidas(listaRepetidas, qtdRepetidas);
      break;
    case 3:
      cadastrarNaListaFaltantes(listaFaltantes, &qtdFaltantes,
                                nomeArquivoFaltantes);
      break;
    case 4:

      exibirListaFaltantes(listaFaltantes, qtdFaltantes);
      break;
    case 5:
      break;
    default:
      cout << "Opcao invalida!!\n";
      break;
    }

    system("sleep 3s");

  } while (opcao != 5);
}

int main() {
  Figura *listaRepetidas;  // um inscrito, com nome, email e matricula
  FiguraF *listaFaltantes; // somente a matricula dos presentes
  int quantidadeRepetidas;
  int quantidadeFaltantes;
  string nomeArquivoRepetidas = "repetidas.csv";
  string nomeArquivoFaltantes = "faltantes.csv";

  quantidadeRepetidas = contarLinhasArquivo(nomeArquivoRepetidas);
  quantidadeFaltantes = contarLinhasArquivo(nomeArquivoFaltantes);
  listaRepetidas =
      (Figura *)malloc(sizeof(Figura) * (quantidadeRepetidas + 100));
  listaFaltantes =
      (FiguraF *)malloc(sizeof(FiguraF) * (quantidadeFaltantes + 100));

  // popular lista com dados do arquivo ao iniciar o sistema
  popularListaArquivoRepetidas(listaRepetidas, nomeArquivoRepetidas);
  popularListaArquivoFaltantes(listaFaltantes, nomeArquivoFaltantes);
  // chamar menu
  menu(listaRepetidas, listaFaltantes, quantidadeRepetidas, quantidadeFaltantes,
       nomeArquivoRepetidas, nomeArquivoFaltantes);

  return 1;
}
