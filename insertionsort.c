#include <stdio.h>
#include <stdlib.h>

void preencheVet(int *v, int n){

    int i;

    for(i=0; i<n; i++){
        scanf("%d", &v[i]);
    }

}

void insertion(int *v, int n){

    int aux, i, j, k;

    for(i=0; i<n; i++){
      aux = v[i];
      j = i - 1;
      while((j>=0) && (v[j]>aux)){
        v[j+1]=v[j];
        j=j-1;
      }
      v[j+1]=aux;
      printf("\nSort numero %d: ", i);
      for(k=0; k<n; k++){
        printf("%d ", v[k]);
      }
    }

}

int main(){

int v, n, op;

printf("Digite o tamanho do vetor: \n");
scanf("%d", &n);

v = (int*) malloc (n * (sizeof(int)));

do{

   puts("\n1- Preencher o vetor");
   puts("\n2- Insertion sort\n");
   scanf("%d", &op);

   switch(op){
        case 1:
        preencheVet(v, n);
        break;
        case 2:
        insertion(v, n);
        break;
        default:
        puts("Tente novamente");
   }

}while(op!=4);

}

