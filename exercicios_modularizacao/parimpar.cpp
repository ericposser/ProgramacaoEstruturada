//Faça um método que receba uma valor inteiro qualquer e que exiba se o valor passado no parâmetro é par ou ímpar.
#include <iostream>
using namespace std;

void parimpar(int n){
  if(n % 2 == 0){
    cout << "numero par";
  }else if(n % 2 == 1){
    cout << "numero impar";
  }
}

int main(){
  int n;
  cout << "digite seu numero: ";
  cin >> n;
  
  parimpar(n);

  return 1;
}