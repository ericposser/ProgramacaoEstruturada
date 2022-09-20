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
    if(data.length() == 10){
        return true;
    }
    return false;
}

bool validaHora(string hora){
    if(hora.length() == 5){
        return true;
    }
    return false;
}

bool inserir(Loja vetor[], int *qtd){
    if (*qtd == TAM) {
        return false;
    } /*else*/
    string NomeDono, nomeMarca, nomeModelo, Descricao, ContatoDono;
    for (int i = 0; i < TAM; i++) {
        if (vetor[i].NomeDono == "") {
            *qtd = *qtd + 1; //(*qtd)++
            
           //numero de serviço
            for(int n = 0 ; n < 10; n++){
                vetor[i].NumeroServico = rand() % 10;
            }

            //marca do produto
            cout << "Entre com a marca do telefone: ";
            getline(cin, nomeMarca); 
            nomeMarca = paraMaiusculo(nomeMarca);
            vetor[i].Marca = nomeMarca;   

            //modelo do produto
            cout << "Entre com o modelo do telefone: ";
            getline(cin, nomeModelo);
            nomeModelo = paraMaiusculo(nomeModelo);
            vetor[i].Modelo = nomeModelo;

            //descrição
            cout << "Entre com a descricao do problema: ";
            getline(cin, Descricao);
            Descricao = paraMaiusculo(Descricao);
            vetor[i].Descricao = Descricao;

            //nome do dono
            do {
                cout << "Nome completo do dono: ";
                getline(cin, NomeDono);
                NomeDono = paraMaiusculo(NomeDono);
            } while (!validaNomeCompleto(NomeDono));
            vetor[i].NomeDono = NomeDono;

            //contato do dono
            cout << "Entre com o contato do dono: ";
            getline(cin, vetor[i].ContatoDono);

            //data do serviço  
            do{
                cout << "Entre com a data do servico [dd/mm/aaaa]: ";
                cin >> vetor[i].Data;   
            }while (!validaData(vetor[i].Data));
 
            
            //hora do serviço
            do{
            cout << "Entre com a hora do servico [hh:mm]: ";
            cin >> vetor[i].Hora;
            }while (!validaHora(vetor[i].Hora));


            //previsão da data de entrega
            do{
                cout << "Entre com a previsao da data de entrega do servico [dd/mm/aaaa]: ";
                cin >> vetor[i].DataEntrega;   
            }while (!validaData(vetor[i].DataEntrega));

            //previsão hora entrega
            do{
            cout << "Entre com a  previsao da hora de entrega do servico [hh:mm]: ";
            cin >> vetor[i].HoraEntrega;
            }while (!validaHora(vetor[i].HoraEntrega));
            break;
        }
    }
    
    return true;
}

bool listar(Loja vetor[], int qtd) {
    if (qtd == 0) return false;

    for (int i = 0; i < qtd; i++) {
        if (vetor[i].NomeDono != "") {
            cout << "Numero da ordem: " << vetor[i].NumeroServico << endl;
            cout << "Data do servico: " << vetor[i].Data << endl;
            cout << "Hora do servico: " << vetor[i].Hora << endl;
            cout << "Marca do telefone: " << vetor[i].Marca << endl;
            cout << "Modelo do telefone: " << vetor[i].Modelo << endl;
            cout << "Descricao: " << vetor[i].Descricao<< endl;
            cout << "Nome do dono: " << vetor[i].NomeDono << endl;
            cout << "Contato do dono: " << vetor[i].ContatoDono << endl;
            cout << "Previsao da data de entrega: " << vetor[i].DataEntrega << endl;
            cout << "Previsao do horario de entrega: " << vetor[i].HoraEntrega << endl;
            cout << "--------------------------------------" << endl;
        }
    }
    return true;
}



bool PesquisarAtualizar(Loja vetor[], int qtd) {
    if (qtd == 0) return false;
    string Pesquisa;
    string NomeDono, nomeMarca, nomeModelo, Descricao, ContatoDono;
    cout << "Digite o contato do dono do telefone ou o numero de ordem: ";
    getline(cin,Pesquisa);
    Pesquisa = paraMaiusculo(Pesquisa);
    int confirma;

    for (int i = 0; i < qtd; i++) {
        if (vetor[i].ContatoDono != "") {
            if (vetor[i].ContatoDono == Pesquisa) {
                cout << "Numero da ordem: " << vetor[i].NumeroServico << endl;
                cout << "Data do servico: " << vetor[i].Data << endl;
                cout << "Hora do servico: " << vetor[i].Hora << endl;
                cout << "Marca do telefone: " << vetor[i].Marca << endl;
                cout << "Modelo do telefone: " << vetor[i].Modelo << endl;
                cout << "Descricao: " << vetor[i].Descricao<< endl;
                cout << "Nome do dono: " << vetor[i].NomeDono << endl;
                cout << "Contato do dono: " << vetor[i].ContatoDono << endl;
                cout << "Previsao da data de entrega: " << vetor[i].DataEntrega << endl;
                cout << "Previsao do horario de entrega: " << vetor[i].HoraEntrega << endl;

                cout << "1 - Confirma a atualizacao; 2 - Aborta a atualizacao!\n";
                cin >> confirma;
                fflush(stdin);

                if (confirma == 1) {
                     //numero do serviço

            //numero de serviço
            for(int n = 0 ; n < 10; n++){
                vetor[i].NumeroServico = rand() % 10;
            }

            //marca do produto
            cout << "Entre com a marca do telefone: ";
            getline(cin, nomeMarca); 
            nomeMarca = paraMaiusculo(nomeMarca);
            vetor[i].Marca = nomeMarca;   

            //modelo do produto
            cout << "Entre com o modelo do telefone: ";
            getline(cin, nomeModelo);
            nomeModelo = paraMaiusculo(nomeModelo);
            vetor[i].Modelo = nomeModelo;

            //descrição
            cout << "Entre com a descricao do problema: ";
            getline(cin, Descricao);
            Descricao = paraMaiusculo(Descricao);
            vetor[i].Descricao = Descricao;

            //nome do dono
            do {
                cout << "Nome completo do dono: ";
                getline(cin, NomeDono);
                NomeDono = paraMaiusculo(NomeDono);
            } while (!validaNomeCompleto(NomeDono));
            vetor[i].NomeDono = NomeDono;

            //contato do dono
            cout << "Entre com o contato do dono: ";
            getline(cin, vetor[i].ContatoDono);

            //data do serviço  
            do{
                cout << "Entre com a data do servico [dd/mm/aaaa]: ";
                cin >> vetor[i].Data;   
            }while (!validaData(vetor[i].Data));
 
            
            //hora do serviço
            do{
            cout << "Entre com a hora do servico [hh:mm]: ";
            cin >> vetor[i].Hora;
            }while (!validaHora(vetor[i].Hora));


            //previsão da data de entrega
            do{
                cout << "Entre com a previsao da data de entrega do servico [dd/mm/aaaa]: ";
                cin >> vetor[i].DataEntrega;   
            }while (!validaData(vetor[i].DataEntrega));

            //previsão hora entrega
            do{
            cout << "Entre com a  previsao da hora de entrega do servico [hh:mm]: ";
            cin >> vetor[i].HoraEntrega;
            }while (!validaHora(vetor[i].HoraEntrega));
            break;
                    return true;
                }                 
            }
        }
    }
    return true;
}