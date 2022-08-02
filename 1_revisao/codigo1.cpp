#include <iostream>
#include <string>

using namespace std;

int main(){
    string nome;

    cout << "Digite seu nome: ";
    
    cin >> nome; // equivale ao scanf ou ao gets

    cout << nome << endl;

    cout << "O nome digitado tem " << nome.size() << "caracteres \n";

    
    return 1;
}