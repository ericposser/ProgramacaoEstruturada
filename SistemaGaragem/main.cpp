#include <iostream>
#include <string>
#include <cstdlib>
#include <sstream>
#include <ctime>
#define TAM 10

using namespace std;

typedef struct 
{
    string placa;
    string data;
    string horaE;
    string horaS;
    int tempoPermanencia;
    float valor;    
} Garagem;

int main (){
    Garagem vagas[TAM];
    int opcao;
    int totalVeiculos = 0;
    string horarioEntradaHora;
    string horarioEntradaMinutos;
    string horarioSaidaMinutos;
    string horarioSaidaHora;
    int horaEntradaMinutos;
    int horaSaidaMinutos;
    string placa;
    bool encontrei = false; 

    do  //Menu do sistema
    {
        system("cls");
        cout << "Menu Garagem\n";
        cout << "1 - Entrada de veiculo\n";
        cout << "2 - Saida de veiculo\n";
        cout << "3 - Listar veiculos da garagem\n";
        cout << "4 - Sair\n";
        cout << "Opcao; ";
        cin >> opcao;

        switch (opcao)
        {
        case 1: // se o usuario escolher 1, fara a entrada de um veiculo na garagem com a obtenção das informações
            cout << "Entrando veiculo...\n";
                if (totalVeiculos == TAM) // se o total de veiculos for igual ao maximo do vetor a garagem esta lotada
                {
                    cout << "Garagem lotada!";
                }

                else
                {
                    cout << "Informe a placa do veiculo: "; //pegando a placa do veiculo
                    cin >> vagas[totalVeiculos].placa;

                    do
                    {
                        cout << "Informe a data: [dd/mm/aaaa]"; //pegando a data de entrada do veiculo
                        cin >> vagas[totalVeiculos].data;
                    } while (vagas[totalVeiculos].data.length() != 10); 

                    do
                    {
                        cout << "Informe a hora de entrada: [hh:mm]"; //pegando a hora de entrada do veiculo
                        cin >> vagas[totalVeiculos].horaE;


                        horarioEntradaHora = vagas[totalVeiculos].horaE.substr(0,2); //pegando os caracteres que representam a hora                        
                        horarioEntradaMinutos = vagas[totalVeiculos].horaE.substr(3,2); //pegando os caracteres que representam os minutos
                        
                        horaEntradaMinutos = stoi(horarioEntradaHora) * 60 + stoi(horarioEntradaMinutos); //transformando a hora de entrada em minutos

                        if (horaEntradaMinutos < 420 || horaEntradaMinutos > 1320) //se o horario nao estiver entre 7h e 22h nao entrada na garagem
                        {
                            cout << "Garagem fechada!! Horario de funcionamento: 7h - 22h\n";
                            //deixando as variaveis vazias
                            vagas[totalVeiculos].placa = "";
                            vagas[totalVeiculos].data = "";
                            vagas[totalVeiculos].horaE = "";
                        }
                        

                    } while (vagas[totalVeiculos].horaE.length() != 5);
                    totalVeiculos++;
                }
                
            break;

        case 2:
            cout << "Saindo veiculo...\n";
                if (totalVeiculos == 0) 
                {
                    cout << "Garagem vazia\n";
                }

                 else{
                    cout << "Informe a placa do veiculo que esta saindo: "; //pegando a placa do veiculo para retirada
                    cin >> placa;

                    for (int i = 0; i <= totalVeiculos; i++)
                    {
                        if (placa == vagas[i].placa) // verificando se tem alguma carro com a placa solicitada
                        {
                            cout << "Digite a hora de saida do veiculo: [hh:mm]"; // se estiver o carro, pega a hora de saida
                            cin >> vagas[i].horaS;

                            horarioSaidaHora = vagas[i].horaS.substr(0,2); // pegando os caracteres que correspondem a hora 
                            horarioSaidaMinutos = vagas[i].horaS.substr(3,2); // pegando os caracteres que correspondem aos minutos 
                            horaSaidaMinutos = stoi(horarioSaidaHora) * 60 + stoi(horarioSaidaMinutos); // transformando a hora de saida em minutos

                            vagas[i].tempoPermanencia = horaSaidaMinutos - horaEntradaMinutos; // vendo quando tempo o veiculo ficou na garagem
                            cout << "Tempo de Permanencia: " << vagas[i].tempoPermanencia << "minutos";

                            //calculos para saber quanto vai ser o valor da garagem
                            if (vagas[i].tempoPermanencia <= 60)
                            {
                                vagas[i].valor = 10;
                                cout << vagas[i].valor;
                            }

                            else if (vagas[i].tempoPermanencia > 60 && vagas[i].tempoPermanencia <= 120)
                            {
                                vagas[i].valor = 10 * 2;
                                cout << vagas[i].valor;
                            }

                            
                            else if (vagas[i].tempoPermanencia > 120 && vagas[i].tempoPermanencia <= 180)
                            {
                                vagas[i].valor = 10 * 3;
                                cout << vagas[i].valor;
                            }
                            
                            
                            else if (vagas[i].tempoPermanencia > 180 && vagas[i].tempoPermanencia <= 240)
                            {
                                vagas[i].valor = 10 * 4;
                                cout << vagas[i].valor;
                            }

                            
                            else if (vagas[i].tempoPermanencia > 240)
                            {
                                vagas[i].valor = 10 * 5;
                                cout << vagas[i].valor;
                            }

                            // zerando as variaveis quando o veiculo sair
                            vagas[i].placa = "";
                            vagas[i].data = "";
                            vagas[i].horaE = "";
                            vagas[i].horaS = "";
                            totalVeiculos--;
                        }
                        
                    }
                    
                }
            break;
        
        case 3:
            cout << "Listando veiculos...\n";
                if (totalVeiculos == 0) 
                {
                    cout << "Garagem vazia\n";
                }
                else 
                {
                    cout << "Digite a placa do carro: "; //pegando a placa do veiculo para listar ele
                    cin >> placa;

                    for (int i = 0; i <= totalVeiculos; i++)
                    {
                        if (placa == vagas[i].placa)
                        {
                            cout << "Placa: " << vagas[i].placa << ". Data: " << vagas[i].data << ". Hora Entrada: " << vagas[i].horaE;
                            encontrei = true;
                        }
                        
                        if(!encontrei) {
                            cout << "Nenhum veiculo com essa placa encontrado!\n";
                        }
                        
                        
                    }
                    
                }
            break;

        case 4:
            cout << "Obrigado por usar o sistema!\n";
            break;

        default:
            cout << "Opcao invalida!";
            break;
        }

        system("pause");
    } while (opcao != 4);
    

    return 1;
}