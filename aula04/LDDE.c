#include <stdio.h>
#include <stdlib.h>

typedef struct Celula{
    struct Celula *anterior;
    struct Celula *proximo;
    int valor;

}Celula;

typedef struct{
    Celula *primeiro;
    int qtd;
}LDDE;


void inserir(LDDE *lista, int valor){
    Celula *novo= criar_celula(valor);
    Celula *anterior = NULL;
    Celula *atual = lista->primeiro;

    while(atual != NULL &&  atual -> valor< novo->valor){
        anterior = atual;
        atual = atual->proximo;
    }
    if(anterior == NULL){// inserção no inicio
        lista -> primeiro = novo;
        if(atual != NULL){
            novo->proximo = atual;
            atual->anterior = novo;
        }
    }else if(atual == NULL){//inerção no final
        anterior -> proximo =novo;
        novo->anterior = anterior;
    }else{ // inserção no meio
        anterior -> proximo = novo;
        novo -> anterior = anterior;
        novo ->proximo = atual;
        atual-> anterior = novo;
    }


    lista-> qtd++;
}

Celula * criar_celula(int valor){
    Celula *novo = malloc(sizeof(Celula));
    novo->anterior = NULL;
    novo->proximo =NULL;
    novo->valor =valor;
    return novo;
}

LDDE *criar_lista(){
    LDDE *lista = malloc(sizeof(LDDE));
    lista->primeiro = NULL;
    lista->qtd = 0;
    return lista;
}
