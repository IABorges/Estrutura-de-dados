#include <stdio.h>
#include <stdlib.h>

typedef struct Celula{
    struct Celula *proximo;
    struct Celula *anterior;
    int valor;
}Celula;

typedef struct{
    int qtd;
    Celula *topo;
}Pilha;

Celula*criar_celula(int valor){

    Celula *nova = malloc(sizeof(Celula));
    nova->anterior =NULL;
    nova->proximo = NULL;
    nova -> valor = valor;

    return nova;
}

Pilha *criar_pilha(){

    Pilha *pilha = malloc(sizeof(Pilha));

    pilha->topo = NULL;
    pilha -> qtd = 0;
    return pilha;
}

void push(Pilha *pilha ,int valor){

    Celula *nova = criar_celula(valor);
    if(pilha->qtd > 0){ // vazia
        pilha -> topo->proximo = nova;
        nova -> anterior = pilha->topo;
    }

    pilha->topo = nova;
    pilha->qtd++;

}

// Pilha pop(Pilha *pilha){

//     Celula *atual = pilha->topo;
//     if(pilha->qtd>0){
//         pilha->topo->anterior = NULL;
//         pilha->topo = pilha->topo->anterior;
//         free(atual);
//     }
//     atual = pilha->topo;
// }

void mostrar(Pilha *pilha){

    Celula *atual = pilha->topo;
    printf("TOPO ->");
    while(atual != NULL){
        printf("%d ", atual->valor);
        atual = atual->anterior;
    }
    printf("<- Base\n");

}

int main(){
    Pilha *pilha = criar_pilha();

    for(int i = 0 ;i<9;i++){
        push(pilha,i);
        mostrar(pilha);
    }

    // for(int i = 0 ;i<9;i++){
    //     pop(pilha);
    //     mostrar(pilha);
    // }

    return 0;

}