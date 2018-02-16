#include <stdio.h>
#define MAX 50

int fila[MAX];

int fim = -1;
int inicio = -1;

void inserir(){

   int add;

   if(fim == MAX - 1){
        printf("Overflow na fila");
   }
   else if(inicio == -1){
      inicio = 0;
      printf("Insira elemento na fila: \n");
      scanf("%d", &add);
      fim = fim + 1;
      fila[fim] = add;
   }


}

void remover(){


    if(inicio == -1 || inicio > fim){
        printf("Underflow na fila");
    }
    else{
        printf("O elemento deletado foi: %d\n", fila[inicio]);
        inicio = inicio + 1;
    }

}

void mostrar(){

   int i;

   if(inicio == -1){
       printf("Fila vazia!");
    }
   else{
    printf("Fila: \n");
      for(i=inicio; i<=fim; i++){
        printf("%d ", fila[i]);
        printf("\n");
      }
   }
}

int main(){

int op;

    do{

    printf("1- Inserir na fila\n");
    printf("2- Deletar elemento da fila\n");
    printf("3- Mostrar os elementos da fila\n");
    printf("4- Sair\n");
    scanf("%d", &op);

    switch(op){

    case 1:
    inserir();
    break;
    case 2:
    remover();
    break;
    case 3:
    mostrar();
    break;
    case 4:
    exit(1);
    default:
    printf("Opçao invalida!");

    }

    }while(op!=4);

}
