//Faça um método que receba uma frase qualquer e exiba caracter por caracter, um abaixo do outro.
#include <iostream>
using namespace std;

void parimpar(string frase){
  for(int i = 0; i < frase.length(); i++){
    cout << frase[i] << endl;
  }
  
}

int main(){
  string frase;
  cout << "digite a frase: ";

  getline (cin, frase);
  
  parimpar(frase);
 
  return 1;
}