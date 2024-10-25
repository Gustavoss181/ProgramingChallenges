#include "sorting.hpp"
#include <time.h>
#include <stdio.h>

void mostrarVetor(int[], int);

int main(){
    int* vet = new int[10];
    sorting::preencherVetor(vet, 10, time(NULL), 0, 100);
    // int vet[] = {3,2,1,5,4,6,7,0,8,9};

    mostrarVetor(vet, 10);

    sorting::mergeSort(vet, 0, 9);

    mostrarVetor(vet, 10);

    return 0;
}

void mostrarVetor(int vet[], int tam){
    for(int i=0; i<tam; i++)
        printf("%d ", vet[i]);
    printf("\n");
}

// verificarOrdenacao()