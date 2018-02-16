#include <stdio.h>

typedef struct Nodo{

    int dado;
    struct Nodo *prox;
    struct Nodo *ant;

}Nodo;

void insere(Nodo *atual, int dado);
void remover(Nodo *atual, int dado);
void mostra(Nodo *atual);
int procura(Nodo *atual, int dado);

void insere(Nodo *atual, int dado){

    //atual aponta para o primeiro elemento

    while(atual->prox != NULL){
        atual = atual->prox;
    }

    atual->prox = (Nodo *)malloc(sizeof(Nodo));
    (atual->prox)->prox = atual;
    atual = atual->prox;
    atual->dado = dado;
    atual->prox = NULL;
}

void remover(Nodo *atual, int dado){

    while(atual->prox != NULL && (atual->prox)->dado != dado){
        atual = atual->prox;
    }

    if(atual->prox == NULL){
        printf("\n Elemento %d nao esta na lista \n", dado);
        return;
    }

    Nodo *temp = atual->prox;

    if(temp->prox == NULL){
        atual->prox = NULL;
    }
    else{
        atual->prox = temp->prox;
        (atual->prox)->ant = temp->ant;
    }
    temp->ant = atual;

    free(temp);

    return;
}

void mostra(Nodo *atual){

    while(atual != NULL){
        printf("%d ", atual->dado);
        atual = atual->prox;
    }
}

int procura(Nodo *atual, int dado){

    atual = atual->prox;

    while(atual != NULL){
        if(atual->dado == dado){
            return 1;
        }
        atual = atual->prox;
    }
        return 0;
}

int main(){

    Nodo *cabeca = (Nodo *)malloc(sizeof(Nodo));
    cabeca->prox = NULL;
    cabeca->ant = NULL;

    int dado = 0;
    int op;

    do{

        puts("1- Inserir");
        puts("2- Remover");
        puts("3- Mostra lista");
        puts("4- Encontrar elemento");
        puts("Outro - sair");
        scanf("%d", &op);

        switch(op){

        case 1:
        printf("Digite um elemento para inserir: \n");
        scanf("%d", &dado);
        insere(cabeca, dado);
        break;

        case 2:
        printf("Digite um elemento para ser deletado: \n");
        scanf("%d", &dado);
        remover(cabeca, dado);
        break;

        case 3:
        printf("A lista e: ");
        mostra(cabeca->prox);
        printf("\n\n");
        break;

        case 4:
        printf("Digite um elemento para ser encontrado: \n");
        scanf("%d", &dado);
        int encontra = procura(cabeca, dado);

        if(encontra){
            printf("\n Elemento encontrado! \n");
        }
        else{
            printf("\n Elemento nao encontrado! \n");
        }
        break;

        default:
        break;

       }

        }while(op!=6);


         return 0;
}
