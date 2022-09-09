typedef struct {
    string fabricante;
    string tipo;
    string data; 
    int nota;
} Degustacao; //tipo artificial construido pelo programador

string paraMaiusculo(string frase) {
    for (int i = 0; i < frase.length(); i++)
    {
        frase[i] = toupper(frase[i]);
    }
    return frase;
}

string pegarPrimeiroNome(string nome) {
    string primeiroNome = "";
    int i;
    for (i = 0; i < nome.length() ; i++) {
        if (nome[i] == ' ' || nome[i] == '\0' || nome[i] == '\n') {
            break;
        }       
        primeiroNome.append(1,nome[i]);
    }    
    return primeiroNome;
}

void inicializar(Degustacao vetor[], int n) {
    for (int i = 0; i < n; i++) {
        vetor[i].fabricante = "";
        vetor[i].tipo = "";
        vetor[i].data = "";
        vetor[i].nota = 0;
    }
}

bool ValidaNota(int nota){
    return (nota >= 0 && nota <= 5);
} 

//OU
//
// bool ValidaNota(int nota){
//     if (nota >= 0 && nota <= 5){
//         return true;
//     }
//     return false;
// }

bool validaNomeCompleto(string nome) {
    for (int i = 0; i < nome.length(); i++) {
        if (nome[i] == ' ' && (nome[i+1] != ' ' || nome[i+1] != '\n')){
            return true;
        }
    }
    return false;
}

bool inserir(Degustacao vetor[], int *qtd) {
    if (*qtd == TAM) {
        return false;
    } /*else*/
    string fabricante, tipo;
    for (int i = 0; i < TAM; i++) {
        if (vetor[i].tipo == "") {
            *qtd = *qtd + 1; //(*qtd)++
            
            //recebendo o fabricante
            do {
                cout << "Entre com a fabricante: ";
                getline(cin, fabricante);
                fabricante = paraMaiusculo(fabricante);
            } while (!validaNomeCompleto(fabricante));
            vetor[i].fabricante = fabricante;

            //recebendo o tipo da cerveja
            cout << "Entre com o tipo da cerveja: ";
            getline(cin, tipo);
            tipo = paraMaiusculo(tipo);
            vetor[i].tipo = tipo;

            //recebendo a data da degustação
            do{
                cout << "Entre com a data da degustacao [dd/mm/aaaa]: "; 
                cin >> vetor[i].data;
            }while (vetor[i].data.length() != 10);      

            //recebendo a nota da cerveja
            do{
                cout << "Entre com a nota: ";
                cin >> vetor[i].nota;
            }while(!ValidaNota(vetor[i].nota));
            break;
        }
    }
    
    return true;
}

bool listar(Degustacao vetor[], int qtd) {
    if (qtd == 0) return false;

    for (int i = 0; i < qtd; i++) {
        if (vetor[i].tipo != "") {
            cout << "Fabricante: " << vetor[i].fabricante << endl;
            cout << "Tipo: " << vetor[i].tipo << endl;
            cout << "Data: " << vetor[i].data << endl;
            cout << "Nota: " << vetor[i].nota << endl;
            cout << "--------------------------------------" << endl;
        }
    }
    return true;
}

bool remover(Degustacao vetor[], int *qtd) {
    if (*qtd == 0) return false;
    string nomePesquisa;
    cout << "Digite parte do tipo ou tipo completo: ";
    getline(cin,nomePesquisa);
    nomePesquisa = paraMaiusculo(nomePesquisa);
    int confirma;

    for (int i = 0; i < *qtd; i++) {
        if (vetor[i].tipo != "") {
            if (vetor[i].tipo == nomePesquisa) {
                cout << "Fabricante: " << vetor[i].fabricante << endl;
                cout << "Tipo: " << vetor[i].tipo << endl;
                cout << "Data: " << vetor[i].data << endl;
                cout << "Nota: " << vetor[i].nota << endl;
                cout << "1 - Confirma a remocao; 2 - Aborta a remocao!\n";
                cin >> confirma;

                if (confirma == 1) {
                    vetor[i].fabricante = "";
                    vetor[i].tipo = "";
                    vetor[i].data = "";
                    *qtd = *qtd - 1;
                    return true;
                } 
            }
        }
    }
    return false;
}

bool atualizar(Degustacao vetor[], int qtd) {
    if (qtd == 0) return false;
    string nomePesquisa;
    string tipo, fabricante, data, nota;
    cout << "Digite parte do tipo ou tipo completo: ";
    getline(cin,nomePesquisa);
    nomePesquisa = paraMaiusculo(nomePesquisa);
    int confirma;

    for (int i = 0; i < qtd; i++) {
        if (vetor[i].tipo != "") {
            if (vetor[i].tipo == nomePesquisa) {
                cout << "Fabricante: " << vetor[i].fabricante << endl;
                cout << "Tipo: " << vetor[i].tipo << endl;
                cout << "Data: " << vetor[i].data << endl;
                cout << "Nota: " << vetor[i].nota << endl;
                cout << "1 - Confirma a atualizacao; 2 - Aborta a atualizacao!\n";
                cin >> confirma;
                fflush(stdin);

                if (confirma == 1) {
                    //recebendo um tipo
                    do {
                        cout << "Entre com o fabricante: ";
                        getline(cin, fabricante);                        
                        fabricante = paraMaiusculo(fabricante);
                    } while (!validaNomeCompleto(fabricante));
                    vetor[i].fabricante = fabricante;

                    //recebendo um tipo de cerveja
                    cout << "Entre com tipo valido: ";
                    getline(cin, tipo);
                    tipo = paraMaiusculo(tipo);
                    vetor[i].tipo = tipo;

                    //recebendo uma data
                    do{
                    cout << "Entre com a data da degustacao [dd/mm/aaaa]: "; 
                    cin >> vetor[i].data;
             } while (vetor[i].data.length() != 10);      

                    //recebendo uma nota
                    do{
                        cout << "Entre com a nota: ";
                        cin >> vetor[i].nota;    
                    }while(vetor[i].nota <= 5);
                        break;
                    return true;
                }                 
            }
        }
    }
    return true;


}

bool pesquisar(Degustacao vetor[], int qtd) {
    if (qtd == 0) return false;
    string nomePesquisa;
    cout << "Digite parte do tipo ou tipo completo: ";
    getline(cin,nomePesquisa);
    nomePesquisa = paraMaiusculo(nomePesquisa);

    for (int i = 0; i < qtd; i++) {
        if (vetor[i].tipo != "") {
            if (vetor[i].tipo.find(nomePesquisa) != -1) {
                cout << "Fabricante: " << vetor[i].fabricante << endl;
                cout << "Tipo: " << vetor[i].tipo << endl;
                cout << "Data: " << vetor[i].data << endl;
                cout << "Nota: " << vetor[i].nota << endl;
                cout << "--------------------------------------" << endl;
            }
        }
    }
    return true;
}