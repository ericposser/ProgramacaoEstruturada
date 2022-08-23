//Faça um método que receba um número inteiro entre 1 a 10 e o escreva em romanos.
#include <iostream>
using namespace std;

void parimpar(int n){
 switch(n){
   case 1: 
    cout << "I";
   break;
   case 2: 
    cout << "II";
   break;
   case 3: 
    cout << "III";
   break;
   case 4: 
    cout << "IV";
   break;
   case 5: 
    cout << "V";
   break;
   case 6: 
    cout << "VI";
   break;
   case 7: 
    cout << "VII";
   break;
   case 8: 
    cout << "VIII";
   break;
   case 9: 
    cout << "IX";
   break;
   case 10: 
    cout << "X";
   break;

   default: 
    cout << "numero invalido";
   break;
   
 }
}

int main(){
  int n;
  
  cout << "digite o numero: ";
  cin >> n;

  parimpar(n);

  return 1;
}