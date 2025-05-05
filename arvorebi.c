#include <stdio.h>
#include <stdlib.h>

typedef struct Vertice{
	int valor;
	struct Vertice* esq;
	struct Vertice* dir;
	struct Vertice* pai;
} Vertice;

typedef struct Arvore{
	Vertice* raiz;
	int qtde;
} Arvore;

void in_ordem(Vertice *raiz) {
    if (raiz != NULL) {
        in_ordem(raiz->esq);
        printf("%d ", raiz->valor);
        in_ordem(raiz->dir);
    }
}

void pre_ordem(Vertice *raiz) {
    if (raiz != NULL) {
        printf("%d ", raiz->valor);
        pre_ordem(raiz->esq);
        pre_ordem(raiz->dir);
    }
}

void pos_ordem(Vertice *raiz) {
    if (raiz != NULL) {
        pos_ordem(raiz->esq);
        pos_ordem(raiz->dir);
        printf("%d ", raiz->valor);
    }
}

Vertice *cria_vertice(int valor){
	Vertice* novo = malloc(sizeof(Vertice));
	novo->dir = NULL;
	novo->esq = NULL;
	novo->pai = NULL;
	novo->valor = valor;
	
	return novo;
}

Arvore *cria_arvore(){
	Arvore* arvore = malloc(sizeof(Arvore));
	arvore->raiz = NULL;
	arvore->qtde = 0;

	return arvore;
}

void inserir(Arvore* arvore, int valor){
	Vertice* novo = cria_vertice(valor);

	Vertice* anterior = NULL;
	Vertice* atual = arvore->raiz;

	while(atual != NULL){
		anterior = atual;
		if(valor <= anterior->valor){
			atual = atual->esq;
		}else{
			atual = atual->dir;
		}
	}

	novo->pai = anterior;
	if(anterior != NULL){
		if(valor <= anterior->valor){
			anterior->esq = novo;
		}else{
			anterior->dir = novo;
		}
	}else{
		arvore->raiz = novo;
	}
	arvore->qtde++;
}

int remover_vertice(Arvore* arvore, Vertice* vertice) {
    // implementar
    
   int count = 0;
   if(vertice->dir != NULL){
    count++;
   }if(vertice->esq!=NULL){
    count++;
   }

   if(count == 0){
    if(arvore->raiz == vertice){
        arvore->raiz = NULL;
    }else{
        if(vertice->pai->dir== vertice){
            vertice->pai->dir = NULL;
        }else{
            vertice->pai->esq = NULL;
        }
    }
	free(vertice);
	arvore->qtde--;

   }if(count ==1){
    if(vertice->pai != NULL){
        if(vertice->pai->esq==vertice){
            if(vertice->esq !=NULL){
                vertice->esq->pai = vertice->pai;
                vertice->pai->esq = vertice->esq;
                
            }else{
                vertice->dir->pai = vertice->pai;
                vertice->pai->dir = vertice->dir;
            }
        }else{
            if(vertice->esq !=NULL){
                vertice->esq->pai = vertice->pai;
                vertice->pai->esq = vertice->esq;

            }else{
				vertice->pai->dir = vertice->pai;
                vertice->pai->dir = vertice->dir;
            }
			
        }
		
    }else{ //se for raiz
        if (vertice->esq != NULL) {
			vertice->esq->pai = NULL;
			arvore->raiz = vertice->esq;
		} else {
			vertice->dir->pai = NULL;
			arvore->raiz = vertice->dir;
		}
    }
	free(vertice);
		arvore->qtde--;
   }
   if(count==2){
	Vertice* sucessor = vertice->dir;
        while (sucessor->esq != NULL) {
            sucessor = sucessor->esq;
        }
        vertice->valor = sucessor->valor;
        remover_vertice(arvore, sucessor);
   }
}

Vertice *buscar_valor(Arvore* arvore, int valor){
	Vertice* atual = arvore->raiz;
	while(atual != NULL){
		if(valor < atual->valor){
			atual = atual->esq;
		}else if(valor > atual->valor){
			atual = atual->dir;
		}else{
			return atual;
		}
	}
	return NULL;
}


int main(void) {
	int dados[] = {5, 3, 8, 2, 4, 7, 9, 1, 6, 10};
  	Arvore *arvore = cria_arvore();
  	
	for(int i = 0; i < 10; i++){
		inserir(arvore, dados[i]);
		printf("Inseriu %d mostra em ordem -> ", dados[i]);
		in_ordem(arvore->raiz);
		printf("\n");
		printf("Inseriu %d mostra em pré-ordem -> ", dados[i]);
		pre_ordem(arvore->raiz);
		printf("\n");
		printf("Inseriu %d mostra em pós-ordem -> ", dados[i]);
		pos_ordem(arvore->raiz);
		printf("\n");
	}

	for(int i = 0; i < 10; i++){
		Vertice *vertice = buscar_valor(arvore, dados[i]);
		if(vertice != NULL){
			remover_vertice(arvore, vertice);
		}
		printf("Removeu %d mostra em ordem -> ", dados[i]);
		in_ordem(arvore->raiz);
		printf("\n");
		printf("Removeu %d mostra em pré-ordem -> ", dados[i]);
		pre_ordem(arvore->raiz);
		printf("\n");
		printf("Removeu %d mostra em pós-ordem -> ", dados[i]);
		pos_ordem(arvore->raiz);
		printf("\n");
	}

	free(arvore);
		
    return 0;
}
