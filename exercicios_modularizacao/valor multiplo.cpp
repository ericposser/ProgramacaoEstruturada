//Faça um método que receba dois valores inteiros e escreva na tela se o primeiro parâmetro é ou não múltiplo
//do segundo 
#include <iostream>
using namespace std;

void parimpar(int n1, int n2){
  if(n1 % n2 == 0){
    cout << "valor multiplo";
  }else{
    cout << "valor nao multiplo";
  }
}

int main(){
  int n1;
  int n2;
  cout << "digite o n1: ";
  cin >> n1;
  
  cout << "digite o n2: ";
  cin >> n2;

  parimpar(n1, n2);
 
  return 1;
}