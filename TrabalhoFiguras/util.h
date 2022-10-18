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

typedef struct {
  int codigo;
  string jogador;
  string selecao;
  int quantidade;
  bool especial;
  double precoEstimado;
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

void popularListaArquivoFigurinhasRepetidas(Figurinha *lista, string nomeArquivo) {
  ifstream procuradorLeitura;
  procuradorLeitura.open(nomeArquivo);
  string jogador, selecao;
  int codigo, quantidade;
  double precoEstimado;
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
    quantidade = linha.substr(posicaoUltimoPontoVirgula + 1, 200);
    precoEstimado = linha.substr(posicaoUltimoPontoVirgula + 1, 200);

    lista[i].codigo = codigo;
    lista[i].jogador = jogador;
    lista[i].selecao = selecao;
    lista[i].quantidade = quantidade;
    lista[i].precoEstimado = precoEstimado;

    i++;
  }
  procuradorLeitura.close();
}

void popularListaArquivoFigurinhasFaltantes(string *lista, string nomeArquivo) {
  ifstream procuradorLeitura;
  procuradorLeitura.open(nomeArquivo);
  string matricula;
  int i = 0;

  string linha;
  while (!procuradorLeitura.eof()) {
    getline(procuradorLeitura, linha); // lendo a linha inteira
    if (linha == "")
      break;

    int posicaoPrimeiroPontoVirgula = linha.find(";");

    matricula = linha.substr(0, posicaoPrimeiroPontoVirgula);

    lista[i] = matricula;

    i++;
  }
  procuradorLeitura.close();
}

void exibirListaFigurinhasRepetidas(Figurinha *lista, int qtdFigurinhas) {
  for (int i = 0; i < qtdFigurinhas; i++) {
    cout << "Codigo da figura: " << lista[i].codigo << ". Jogador: " << lista[i].jogador
         << ". Selecao: " << lista[i].selecao << ". Quantidade: " << lista[i].quantidade << ". Especial: " << lista[i].especial << ". Preco estimado: " << lista[i].precoEstimado << endl; }
}

void exibirListaFigurinhasRepitidas(string *lista, int qtdFigurinhas) {
  for (int i = 0; i < qtdFigurinhas; i++) {
    cout << "Matricula: " << lista[i] << endl;
  }
}

bool jaCadastrado(string email, Inscrito *lista, int qtdInscritos) {
  for (int i = 0; i < qtdInscritos; i++) {
    if (lista[i].email == email) {
      return true;
    }
  }
  return false;
}

bool jaCadastradoMatricula(string matricula, string *lista, int qtdPresencas) {
  for (int i = 0; i < qtdPresencas; i++) {
    if (lista[i] == matricula) {
      return true;
    }
  }
  return false;
}

void cadastrarNaListaInscritos(Inscrito *lista, int *qtdInscritos,
                               string nomeArquivo) {
  ofstream procuradorEscrita;
  string nome, email, matricula;
  procuradorEscrita.open(nomeArquivo, ios::out | ios::app);
  cout << "Inscrito sendo cadastrado na posicao " << *qtdInscritos << endl;
  do {
    cout << "Digite seu nome completo: ";
    getline(cin, nome);
    nome = paraMaiusculo(nome);
  } while (!validaNomeCompleto(nome));

  cout << "Digite seu email: ";
  cin >> email;

  cout << "Digite sua matricula: ";
  cin >> matricula;

  // teria que verificar se esse par nome e email já estão na lista
  if (jaCadastrado(email, lista, *qtdInscritos)) {
    cout << "Erro: Email ja cadastrado no sistema\n";
  } else {
    lista[*qtdInscritos].nome = nome;
    lista[*qtdInscritos].email = email;
    lista[*qtdInscritos].matricula = matricula;
    *qtdInscritos = *qtdInscritos + 1;
    // adicionar no final do arquivo
    procuradorEscrita << nome << ";" << email << ";" << matricula << endl;
  }
  procuradorEscrita.close();
}

void cadastrarNaListaPresencas(string *lista, int *qtdPresencas,
                               string nomeArquivo) {
  ofstream procuradorEscrita;
  string matricula, data;
  procuradorEscrita.open(nomeArquivo, ios::out | ios::app);

  do {
    cout << "Presenca sendo cadastrado na posicao " << *qtdPresencas << endl;

    cout << "Digite sua matricula (-27 para sair): ";
    cin >> matricula;
    if (matricula == "-27") {
      procuradorEscrita.close();
      return;
    }

    if (jaCadastradoMatricula(matricula, lista, *qtdPresencas)) {
      cout << "Erro: Matrícula ja registrada no evento\n";
    } else {
      time_t t = time(nullptr);
      tm *now = localtime(&t);

      string dia = to_string(now->tm_mday);
      string mes = to_string(now->tm_mon + 1);
      string ano = to_string(now->tm_year + 1900);

      lista[*qtdPresencas] = matricula;
      *qtdPresencas = *qtdPresencas + 1;

      // adicionar no final do arquivo
      procuradorEscrita << matricula << ";" << dia << "/" << mes << "/" << ano
                        << endl;

      procuradorEscrita.close();
    }
  } while (true);
}

void menu(Inscrito *listaInscritos, string *listaPresencas, int qtdInscritos,
          int qtdPresencas, string nomeArquivoInscritos,
          string nomeArquivoPresencas) {
  int opcao;
  int tecla;
  do {
    system("clear");
    cout << "MENU\n";
    cout << "1 - Cadastrar figurinhas repetidas\n";
    cout << "2 - Cadastrar figurinhas faltantes\n";
    cout << "3 - Listar figurinhas repetidas\n";
    cout << "4 - Listar figurinhas faltantes\n";
    cout << "5 - Sair\n";
    cout << "Opcao: ";
    cin >> opcao;
    cin.ignore();

    switch (opcao) {
    case 1:
      cout << "INSCRICAO\n";
      cadastrarNaListaInscritos(listaInscritos, &qtdInscritos,
                                nomeArquivoInscritos);
      break;
    case 2:
      cout << "LISTAGEM DE INSCRITOS\n";
      exibirListaInscritos(listaInscritos, qtdInscritos);
      break;
    case 3:
      cout << "REGISTRAR PRESENCA\n";
      cadastrarNaListaPresencas(listaPresencas, &qtdPresencas,
                                nomeArquivoPresencas);
      break;
    case 4:
      cout << "LISTAGEM DE PRSENTES\n";
      exibirListaPresencas(listaPresencas, qtdPresencas);
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