#include "sorting.hpp"

#include <stdlib.h>
#include <stdio.h>

namespace sorting{

    void preencherVetor(int* vet, int tam, int seed = 0, int min = 0, int max = 100){
        srand(seed);
        for(int i=0; i<tam; i++){
            vet[i] = (rand() % (max-min)) + min;
        }
    }

    void swap(int* a1, int* a2){
        int aux = *a1;
        *a1 = *a2;
        *a2 = aux;
    }

    void mergeInPlace(int vet[], int l, int m, int r){
        int i = l, j = m+1;
        while(i <= m and j <= r){
            if(vet[i] <= vet[j]){
                i++;
            }else{
                int value = vet[j];
                int index = j;

                while(index != i){
                    vet[index] = vet[index-1];
                    index--;
                }
                vet[i] = value;
                j++;
                m++;
                i++;          
            }
        }
    }
    
    void mergeSortInPlace(int vet[], int l, int r){
        if(l < r){
            int m = l + (r - l) / 2;
            mergeSortInPlace(vet, l, m);
            mergeSortInPlace(vet, m+1, r);
            mergeInPlace(vet, l, m, r);
        }
    }

    void merge(int vet[], int l, int m, int r){
        int i = l, j = m+1;
        while(i <= m and j <= r){
            if(vet[i] <= vet[j]){
                i++;
            }else{
                int value = vet[j];
                int index = j;

                while(index != i){
                    vet[index] = vet[index-1];
                    index--;
                }
                vet[i] = value;
                j++;
                m++;
                i++;          
            }
        }
    }

    void mergeSort(int vet[], int l, int r){
        if(l < r){
            int m = l + (r - l) / 2;
            mergeSort(vet, l, m);
            mergeSort(vet, m+1, r);
            merge(vet, l, m, r);
        }
    }

}