#include <stdio.h>
#include <stdlib.h>

// Definição da estrutura de um nó na lista duplamente encadeada
typedef struct no {
    int valor;
    struct no *anterior;
    struct no *proximo;
} No;

// Definição da estrutura da lista duplamente encadeada
typedef struct lista_duplamente_encadeada {
    int quantidade;
    No *inicio;
} ListaDuplamenteEncadeada;

/**
 * Cria uma nova lista duplamente encadeada e a inicializa.
 *
 * @return Um ponteiro para a nova lista criada.
 */
ListaDuplamenteEncadeada *criar_lista() {
    ListaDuplamenteEncadeada *lista = malloc(sizeof(ListaDuplamenteEncadeada));
    lista->inicio = NULL;
    lista->quantidade = 0;
    return lista;
}

/**
 * Cria um novo nó contendo o valor especificado.
 *
 * @param valor O valor a ser armazenado no nó.
 * @return Um ponteiro para o novo nó criado.
 */
No *criar_no(int valor) {
    No *novo_no = malloc(sizeof(No));
    novo_no->valor = valor;
    novo_no->anterior = NULL;
    novo_no->proximo = NULL;
    return novo_no;
}

/**
 * Insere um valor na lista de forma ordenada.
 *
 * @param lista Ponteiro para a lista onde o valor será inserido.
 * @param valor O valor a ser inserido na lista.
 */
void inserir_valor(ListaDuplamenteEncadeada *lista, int valor) {
    // implementar

    No *novo= criar_no(valor);
    No *anterior = NULL;
    No *atual = lista->inicio;

    while(atual != NULL &&  atual -> valor< novo->valor){
        anterior = atual;
        atual = atual->proximo;
    }
    if(anterior == NULL){// inserção no inicio
        lista -> inicio = novo;
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


    lista-> quantidade++;
}

/**
 * Exibe os valores da lista em ordem crescente.
 *
 * @param lista Ponteiro para a lista a ser exibida.
 */
void exibir_lista(ListaDuplamenteEncadeada *lista) {
    // implementar
    printf("Início -> ");
    No *atual = lista->inicio;
    while(atual != NULL ){
        printf("%d ", atual->valor);
        atual = atual->proximo;
    }
    printf("<- Final \n");

    

}
void exibir_lista_invertida(ListaDuplamenteEncadeada *lista) {
    // implementar

    printf("Final -> ");
    
    No *atual = lista->inicio;
    while(atual -> proximo != NULL ){
        atual = atual->proximo;

    }
    while(atual != NULL ){
        printf("%d ", atual ->valor);
        atual = atual->anterior;
    }
    printf("<- Início \n");

}


void remover_valor(ListaDuplamenteEncadeada *lista, int valor) {
    // implementar
    No *anterior = NULL;
    No *atual = lista->inicio;

    while(atual != NULL && atual -> valor < valor ){
        anterior = atual;
        atual = atual->proximo;
    }
    if(atual ->anterior == NULL){ //removendo do inicio
        lista -> inicio = atual->proximo;
        anterior = atual;
        atual = atual -> proximo;
        atual -> anterior = NULL;
        anterior -> proximo = NULL;
    }if(atual -> proximo == NULL){// removendo do fim 

        atual -> anterior = NULL;
        anterior ->proximo =NULL;

    }else if(atual->proximo != NULL && atual->anterior != NULL ){
        //atual -> anterior = NULL;
        anterior -> proximo = atual -> proximo;
        anterior = atual;
        atual = atual->proximo;
        atual -> anterior = anterior->anterior;
        anterior -> proximo = NULL;
        anterior -> anterior = NULL;

    }

    lista -> quantidade--;
}

int main(void) {
    ListaDuplamenteEncadeada *lista = criar_lista();

    inserir_valor(lista, 10);
    exibir_lista(lista);
    exibir_lista_invertida(lista);  

    inserir_valor(lista, 5);
    exibir_lista(lista);
    exibir_lista_invertida(lista);

    inserir_valor(lista, 20);
    exibir_lista(lista);
    exibir_lista_invertida(lista);

    inserir_valor(lista, 15);
    exibir_lista(lista);
    exibir_lista_invertida(lista);

    remover_valor(lista, 5);
    exibir_lista(lista);
    exibir_lista_invertida(lista);

    remover_valor(lista, 15);
    exibir_lista(lista);
    exibir_lista_invertida(lista);

    remover_valor(lista, 20);
    exibir_lista(lista);
    exibir_lista_invertida(lista);

    remover_valor(lista, 10);
    exibir_lista(lista);
    exibir_lista_invertida(lista);

    for (int i = 1; i <= 10; i++) {
        inserir_valor(lista, i);
    }
    exibir_lista(lista);
    exibir_lista_invertida(lista);

    for (int i = 1; i <= 10; i++) {
        remover_valor(lista, i);
    }
    exibir_lista(lista);
    exibir_lista_invertida(lista);

    remover_valor(lista, 100);
    exibir_lista(lista);
    exibir_lista_invertida(lista);

    inserir_valor(lista, 10);
    inserir_valor(lista, 10);
    inserir_valor(lista, 10);
    exibir_lista(lista);
    exibir_lista_invertida(lista);

    return 0;
}
