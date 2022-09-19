typedef struct {
    int NumeroServico;
    string Data;
    string Hora;
    string Marca;
    string Modelo;
    string Descricao;
    string NomeDono;
    string ContatoDono;
    string DataEntrega;
    string HoraEntrega;
} Loja; //tipo artificial construido pelo programador

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

void inicializar(Loja vetor[], int n) {
    for (int i = 0; i < n; i++) {
        vetor[i].NumeroServico = 0;
        vetor[i].Data = "";
        vetor[i].Hora = "";
        vetor[i].Marca = "";
        vetor[i].Modelo = "";
        vetor[i].Descricao = "";
        vetor[i].NomeDono = "";
        vetor[i].ContatoDono = "";
        vetor[i].DataEntrega = "";
        vetor[i].HoraEntrega = "";

    }
}

bool validaNomeCompleto(string nome) {
    for (int i = 0; i < nome.length(); i++) {
        if (nome[i] == ' ' && (nome[i+1] != ' ' || nome[i+1] != '\n')){
            return true;
        }
    }
    return false;
}

bool validaData(string data){
    if (data == "" || data.length() != 10 || data[2] != '/' || data[5] != '/'){
        return false;
    }

bool inserir(Loja vetor[], int *qtd) {
    if (*qtd == TAM) {
        return false;
    } /*else*/
    string NomeDono;
    for (int i = 0; i < TAM; i++) {
        if (vetor[i].NomeDono == "") {
            *qtd = *qtd + 1; //(*qtd)++
            
           
            break;
        }
    }
    
    return true;
}

bool listar(Agenda vetor[], int qtd) {
    if (qtd == 0) return false;

    for (int i = 0; i < qtd; i++) {
        if (vetor[i].nome != "") {
            cout << "Nome: " << vetor[i].nome << endl;
            cout << "Email: " << vetor[i].email << endl;
            cout << "Telefone: " << vetor[i].telefone << endl;
            cout << "--------------------------------------" << endl;
        }
    }
    return true;
}

bool remover(Agenda vetor[], int *qtd) {
    if (*qtd == 0) return false;
    string nomePesquisa;
    cout << "Digite o nome completo: ";
    getline(cin,nomePesquisa);
    nomePesquisa = paraMaiusculo(nomePesquisa);
    int confirma;

    for (int i = 0; i < *qtd; i++) {
        if (vetor[i].nome != "") {
            if (vetor[i].nome == nomePesquisa) {
                cout << "Nome: " << vetor[i].nome << endl;
                cout << "Email: " << vetor[i].email << endl;
                cout << "Telefone: " << vetor[i].telefone << endl;
                cout << "1 - Confirma a remocao; 2 - Aborta a remocao!\n";
                cin >> confirma;

                if (confirma == 1) {
                    vetor[i].nome = "";
                    vetor[i].email = "";
                    vetor[i].telefone = "";
                    *qtd = *qtd - 1;
                    return true;
                } 
            }
        }
    }
    return false;
}

bool PesquisarAtualizar(Agenda vetor[], int qtd) {
    if (qtd == 0) return false;
    string nomePesquisa;
    string nome, email, telefone;
    cout << "Digite o nome completo: ";
    getline(cin,nomePesquisa);
    nomePesquisa = paraMaiusculo(nomePesquisa);
    int confirma;

    for (int i = 0; i < qtd; i++) {
        if (vetor[i].nome != "") {
            if (vetor[i].nome == nomePesquisa) {
                cout << "Nome: " << vetor[i].nome << endl;
                cout << "Email: " << vetor[i].email << endl;
                cout << "Telefone: " << vetor[i].telefone << endl;
                cout << "1 - Confirma a atualizacao; 2 - Aborta a atualizacao!\n";
                cin >> confirma;
                fflush(stdin);

                if (confirma == 1) {
                    //recebendo um nome
                    do {
                        cout << "Entre com o nome completo: ";
                        getline(cin, nome);                        
                        nome = paraMaiusculo(nome);
                    } while (!validaNomeCompleto(nome));
                    vetor[i].nome = nome;

                    //recebendo um email
                    cout << "Entre com o email: ";
                    getline(cin, email);
                    email = paraMaiusculo(email);
                    vetor[i].email = email;

                    //recebendo um telefone
                    cout << "Entre com o numero de telefone: ";
                    getline(cin, vetor[i].telefone);
                        break;
                    return true;
                }                 
            }
        }
    }
    return true;


}

bool pesquisar(Agenda vetor[], int qtd) {
    if (qtd == 0) return false;
    string nomePesquisa;
    cout << "Digite o nome completo: ";
    getline(cin,nomePesquisa);
    nomePesquisa = paraMaiusculo(nomePesquisa);

    for (int i = 0; i < qtd; i++) {
        if (vetor[i].nome != "") {
            if (vetor[i].nome.find(nomePesquisa) != -1) {
                cout << "Nome: " << vetor[i].nome << endl;
                cout << "Email: " << vetor[i].email << endl;
                cout << "Telefone: " << vetor[i].telefone << endl;
                cout << "--------------------------------------" << endl;
            }
        }
    }
    return true;
}