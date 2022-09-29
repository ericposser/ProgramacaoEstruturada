#include <iostream> //cin e cout
#include <string> 
#include <stdio.h>
#include <stdlib.h>
#define TAM 10
using namespace std; //omitir o std na frente do cin, por exemplo 

#include "util.h"


int main() {
    Agenda vetor[TAM];
    inicializar(vetor,TAM);
    int qtdContato = 0;
    int opcao;
    //montar o menu
    do {
        system("cls");
        cout << "AGENDA - MENU\n";
        cout << "1 - Inserir Contato\n";
        cout << "2 - Remover Contato\n";
        cout << "3 - Atualizar Contato\n";
        cout << "4 - Listar Contatos\n";
        cout << "5 - Pesquisar Contato\n";
        cout << "6 - Sair\n";
        cout << "Opcao: ";
        cin >> opcao;
        fflush(stdin);

        switch (opcao)
        {
            case 1:
                cout << "INSERIR\n";
                if (inserir(vetor, &qtdContato)) {
                    cout << "Contato cadastrado com sucesso\n";
                } else {
                    cout << "Problemas para cadastrar. Falta de espaco\n";
                }
                break;
            case 2:
                cout << "REMOVER\n";

                if (remover(vetor, &qtdContato)) {
                    cout << "Contato removido com sucesso\n";
                } else {
                    cout << "Nao removido. Ou estrutura vazia ou nao localizado.\n";
                }
                break;

                break;
            case 3:
                cout << "ATUALIZAR\n";

                if (atualizar(vetor, qtdContato)) {
                    cout << "Alteracao realizada com sucesso\n";
                } else {
                    cout << "Estrutura vazia\n";
                }
                break;

                break;
            case 4:
                cout << "LISTAR\n";
                if (listar(vetor, qtdContato)) {
                    cout << "Contatos cadastrados\n";
                } else {
                    cout << "Estrutura vazia\n";
                }

                break;
            case 5:
                cout << "PESQUISAR\n";

                if (pesquisar(vetor, qtdContato)) {
                    cout << "Pesquisa realizada com sucesso\n";
                } else {
                    cout << "Estrutura vazia\n";
                }
                break;

                break;
            case 6:
                cout << "Obrigado por usar o sistema!\n";
                break;                
            default:
                cout << "Opcao invalida!\n";
                break;
        }
        system("pause");
    }  while (opcao != 6);
  
    return 1;
}