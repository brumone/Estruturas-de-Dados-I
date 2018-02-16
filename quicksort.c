#include <stdio.h>

void troca(int* a, int* b){

    int t = *a;
    *a = *b;
    *b = t;
}

int compara(int v[], int menor, int maior){

    int pivo = v[maior];
    int i = (menor - 1);
    int j;

    for(j = menor; j<=maior - 1; j++){

        if(v[j] <= pivo){
            i++;
            troca(&v[i], &v[j]);
        }
    }
    troca(&v[i+1], &v[maior]);
    return(i + 1);
}

void quickSort(int v[], int menor, int maior){

    if(menor < maior){

        int ci = compara(v, menor, maior);

        quickSort(v, menor, ci - 1);
        quickSort(v, ci + 1, maior);

    }
}

void imprimirVetor(int v[], int size){

    int i;

    for(i = 0; i<size; i++){

        printf("%d ", v[i]);
    }
}

int main (){

    int v[] = {5, 8, 4, 11, 82};

    int n = sizeof(v)/sizeof(v[0]);

    quickSort(v, 0, n-1);

    printf("Vetor ordenado: ");

    imprimirVetor(v, n);

}
