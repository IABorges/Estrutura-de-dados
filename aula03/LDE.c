#include <stdlib.h>
#include <stdio.h>

typedef struct Celula{
    int valor;
    struct Celula * proximo ; 
}Celula;

typedef struct{
  Celula *primeira;
  int qtd;  
}LDE; //  lista dinamica encadeada



Celula *criar_celula(int valor){
    Celula *nova = malloc(sizeof(Celula));
    nova -> proximo = NULL;
    nova -> valor = valor;
    return nova;
}

LDE *criar_lista(){
    LDE * lista = malloc(sizeof(LDE));
    lista->primeira = NULL;
    lista->qtd = 0;

    return lista;
}

void inserir(LDE *lista,int valor){
    Celula *nova = criar_celula(valor);
    if(lista -> primeira == NULL){
        lista -> primeira = nova;
        lista -> qtd++;
        return;
    }

    Celula *anterior = NULL;
    Celula *atual = lista ->primeira;
    while( atual != NULL && atual -> valor < nova -> valor){
        anterior = atual;
        atual = atual -> proximo;
        lista -> qtd++;
        return;
    }
    if(anterior == NULL && atual != NULL){
        nova -> proximo = atual;
        lista -> primeira = nova;
        lista -> qtd++;
        return;
    }
    if(atual == NULL && anterior != NULL){
        anterior ->proximo = nova;
        lista -> qtd++;
        return;

    }
    if(atual != NULL && anterior!= NULL){
        anterior -> proximo = nova;
        nova -> proximo = atual;
        lista -> qtd++;
        return;
    }
}

void mostar(LDE *lista){
    Celula *atual = lista->primeira;
    while(atual != NULL){
        printf("%d ", atual ->valor);
        atual = atual ->proximo;
    }
    printf("\n");
}

int main(){
    LDE *lista =criar_lista();
    for(int i = 10; i>0; i--){
        inserir(lista,i);
        mostar(lista);
    }


    return 0;
}