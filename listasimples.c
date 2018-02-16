#include <stdio.h>

struct nodo{

    int val;
    struct nodo *prox;

};

typedef struct nodo NODO_DADO;

NODO_DADO *cabeca_nodo, *prim_nodo, *nodo_temp = 0, *nodo_ant, prox_nodo;

int dado;

int main(){

    int op;

    do{

    puts("\nOpcoes: \n");
    puts("1- Inserir");
    puts("2- Remover");
    puts("3- Mostrar lista");
    puts("4- Contar lista");
    puts("Outros: Sair()\n");
    puts("Digite uma opcao: \n");
    scanf("%d", &op);

        switch(op){

        case 1:
        insere();
        break;
        case 2:
        remover();
        break;
        case 3:
        mostra();
        break;
        case 4:
        conta();
        break;
        default:
        break;

        }

    }while(op!=5);

    return 0;
}

void insere(){

    printf("Digite um elemento para inserir na lista\n");
    scanf("%d", &dado);

    nodo_temp = (NODO_DADO *) malloc(sizeof (NODO_DADO));

    nodo_temp->val = dado;

    if(prim_nodo == 0){
        prim_nodo = nodo_temp;
    }
    else{
        cabeca_nodo->prox = nodo_temp;
    }

    nodo_temp->prox = 0;
    cabeca_nodo = nodo_temp;
    fflush(stdin);
}

void remover(){

    int contval, pos, i = 0;
    contval = conta();
    nodo_temp = prim_nodo;
    printf("Lista ligada: \n");

    printf("Digite a posicao para deletar o elemento: \n");
    scanf("%d", &pos);

    if(pos > 0 && pos <= contval){
      if(pos == 1){
        nodo_temp = nodo_temp -> prox;
        prim_nodo = nodo_temp;
        printf("Remocao efetuada! \n");
      }
      else{
        while(nodo_temp != 0){
            if(i == (pos - 1)){
                nodo_ant->prox = nodo_temp->prox;
                if(i == (contval - 1)){
                    cabeca_nodo = nodo_ant;
                }
        printf("Remocao efetuada! \n");
        break;
            }
            else{
                i++;
                nodo_ant = nodo_temp;
                nodo_temp = nodo_temp->prox;
         }
        }
      }
    }else
        printf("Posicao invalida \n\n");
}

void mostra(){

    int conta = 0;
    nodo_temp = prim_nodo;
    printf("Lista ligada: \n");

    while(nodo_temp != 0){
        printf("%d #", nodo_temp->val);
        conta++;
        nodo_temp = nodo_temp -> prox;
    }
    printf("Numero de itens na lista: \n", conta);
}

int conta(){

    int conta = 0;
    nodo_temp = prim_nodo;
    while(nodo_temp != 0){
        conta++;
        nodo_temp = nodo_temp -> prox;
    }

    printf("Numero de itens na lista: %d\n", conta);
    return conta;
}
