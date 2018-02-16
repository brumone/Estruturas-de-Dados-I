#include <stdio.h>

typedef struct pilhaNodo{

int num;
struct pilhaNodo *prox;
}no;

int tam;

no *temp;

void iniciar(no *pilha){

    pilha->prox = NULL;
    tam = 0;
}

int testaVazio(no *pilha){

    if(pilha->prox == NULL ){
        return 1;
    }
    else{
        return 0;
    }
}

no *add(){

    no *novo = (no*) malloc(sizeof(no));
    if(!novo){
        printf("Sem memoria \n");
    }
    else{
        printf("Digite um numero: \n");
        scanf("%d", &novo->num);
    }
    return novo;
}

void push(no *pilha){

    no *novo = add();
    novo->prox = NULL;
    if(testaVazio(pilha)){
        pilha->prox = novo;
        tam++;
    }
    else{
        temp = pilha->prox;
        while(temp->prox != NULL){
            temp = temp->prox;
        }
        temp->prox = novo;
        tam++;
    }
}

no *pop(no *pilha){

    if(testaVazio(pilha)){
        printf("Pilha vazia! \n");
        return NULL;
    }
    else{
        no *ultimo = pilha->prox;
        no *ant = pilha;

        while(ultimo->prox != NULL){
            ant = ultimo;
            ultimo = ultimo->prox;
        }
        ant->prox = NULL;
        tam--;
        return ultimo;
    }
}

void mostra(no *pilha){

    if(testaVazio(pilha)){
        printf("Pilha vazia! \n");
    }

    else{
        temp = pilha->prox;
        printf("\n");
        while(temp != NULL){
            printf("%d", temp->num);
            temp = temp->prox;
        }
        printf("Tamanho da fila: \n", tam);
    }
}

void limpa(no *pilha){

    if(testaVazio(pilha)){
        printf("Pilha vazia! \n");
    }
    else{
        no *nodo = pilha->prox, *proxNodo;

        while(nodo != NULL){
            proxNodo = nodo->prox;
            free(nodo);
            nodo = proxNodo;
        }
        printf("Pilha esvaziada");
    }
}

int main(){

no *pilha = (no*) malloc(sizeof(no));

    if(!pilha){
        printf("Sem memoria");
    }
    else{
       iniciar(pilha);
    }

    int op;

    do{

    printf("1- Push");
    printf("2- Pop");
    printf("3- Mostrar pilha");
    printf("4- Esvaziar pilha");

    switch(op){

    case 1:
    push(pilha);
    break;
    case 2:
    temp = pop(pilha);
     if(temp != NULL){
        printf("Elemento removido! \n", temp->num);
        free(temp);
     }
     break;
    case 3:
      mostra(pilha);
      iniciar(pilha);
      break;
    case 4:
    limpa(pilha);
    iniciar(pilha);
    break;
    default:
      if(op != 0){
        printf("Digite uma opçao valida!");
      }


    }

    }while(op!=0);
}
