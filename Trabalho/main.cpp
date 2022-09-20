#include <iostream> //cin e cout
#include <string> 
#include <stdio.h>
#include <stdlib.h>
#define TAM 10
using namespace std; //omitir o std na frente do cin, por exemplo 

#include "util.h"


int main() {
    Loja vetor[TAM];
    inicializar(vetor,TAM);
    int qtdCliente = 0;
    int opcao;
    //montar o menu
    do {
        system("cls");
        cout << "Ordens de servicos - MENU\n";
        cout << "1 - Cadastrar servico\n";
        cout << "2 - Listar servicos\n";
        cout << "3 - Pesquisar/Atualizar ordem de servico (por numero da ordem ou por contato do dono)\n";
        cout << "4 - Sair\n";
        cout << "Opcao: ";
        cin >> opcao;
        fflush(stdin);

        switch (opcao)
        {
            case 1:
                cout << "Cadastrar servico\n";

                if (inserir(vetor, &qtdCliente)) {
                    cout << "Servico cadastrado com sucesso\n";
                } else {
                    cout << "Problemas para cadastrar. Falta de espaco\n";
                }
                break;
            case 2:
                cout << "Listar servicos\n";

                if (listar(vetor, qtdCliente)) {
                    cout << "Servicos cadastrados\n";
                } else {
                    cout << "Estrutura vazia\n";
                }
                break;

            case 3:
                cout << "Pesquisar/Atualizar\n";

                if (PesquisarAtualizar(vetor, qtdCliente)) {
                    cout << "Alteração realizada com sucesso\n";
                } else {
                    cout << "Estrutura vazia\n";
                }
 
                break;
            case 4:
                cout << "Obrigado por usar o sistema!\n";
                break;                

            default:
                cout << "Opcao invalida!\n";
                break;
        }
        system("pause");
    }  while (opcao != 4);
  
    return 1;
}