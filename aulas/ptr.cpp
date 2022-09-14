#include <iostream>
#include <string>
#include <stdio.h>

using namespace std;

void MinMax(int *menor, int *maior, int *vetor, int posicao){
    *menor= vetor[0];
    *maior= vetor[0];
    for (int i=0;i < posicao;i++){
        if(vetor[i] < *menor){
            *menor=vetor[i];
        }
        if(vetor[i] > *maior){
            *maior=vetor[i];
        }
    }
}

void imprimir(int *vetor, int posicao){
    for(int i=0; i < posicao; i++){
        cout << "vetor["<< i << "]=" << vetor[i] << endl;
        
    }
}

main(){
    int vetor[] = {10,1,20,30,40}; 
    int menor, maior;
    MinMax(&menor, &maior, vetor, 5);
    
    cout << "menor: " <<  menor <<endl;
    cout << "maior: " << maior <<endl;
    imprimir(vetor,5);

    return 1;
}