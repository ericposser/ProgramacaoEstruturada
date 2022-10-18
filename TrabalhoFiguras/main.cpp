#include <ctime>
#include <fstream>
#include <iostream>
#include <string>
using namespace std;

#include "util.h"

int main() {
  Figurinha *listaFigurinhas; // um inscrito, com nome, email e matricula
  string *listaPresencas;   // somente a matricula dos presentes
  int quantidadeFigurinhasRepitidas;
  int quantidadeFigurinhasFaltantes;
  string nomeArquivoFigurinhasRepetidas = "FigurinhasRepetidas.csv";
  string nomeArquivoFigurinhasFaltantes = "FigurinhasFaltantes.csv";

  quantidadeFigurinhasRepetidas = contarLinhasArquivo(nomeArquivoFigurinhasRepetidas);
  quantidadeFigurinhasFaltantes = contarLinhasArquivo(nomeArquivoFigurinhasFaltantes);
  listaFigurinhas =
      (Figurinha *)malloc(sizeof(Figurinha) * (quantidadeFigurinhasRepitidas + 100));
  listaPresencas =
      (string *)malloc(sizeof(string) * (quantidadeFigurinhasFaltantes + 100));

  // popular lista com dados do arquivo ao iniciar o sistema
  popularListaArquivoInscritos(listaInscritos, nomeArquivoInscritos);
  popularListaArquivoPresencas(listaPresencas, nomeArquivoPresencas);
  // chamar menu
  menu(listaInscritos, listaPresencas, quantidadeInscritos, quantidadePresencas,
       nomeArquivoInscritos, nomeArquivoPresencas);

  return 1;
}