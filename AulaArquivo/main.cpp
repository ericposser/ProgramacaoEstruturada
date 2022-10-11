#include <iostream> //cin e cout
#include <stdio.h>
#include <stdlib.h>
#include <string>

using namespace std; //omitir o std na frente do cin, por exemplo 

int main(){
    FILE *procurador;
    char nomeArquivo[200];

    cout << "Digite o nome do arquivo: ";
    cin >> nomeArquivo;

    procurador = fopen(nomeArquivo,"a");

    char nome[200], email[200]; char opcao;

    do{
        cout << "nome: ";
        cin >> nome;

        cout << "email: ";
        cin >> email;

        fprintf(procurador, "%s;%s\n", nome, email);
        fflush(procurador);

        cout << "1- continuar, 2- sair";
        cin >> opcao;

    }while (opcao == '1');

    fclose(procurador);
    
    
    return 1;
}