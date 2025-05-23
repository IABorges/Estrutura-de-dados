#include <stdio.h>
#include <stdlib.h>
typedef struct Vertice {
int valor;
struct Vertice *esq;
struct Vertice *dir;
struct Vertice *pai;
} Vertice;

typedef struct Arvore {
Vertice *raiz;
int qtde;
} Arvore;

void RotacaoEsquerda(Arvore *arvore, Vertice *x) {
printf("Esquerda em %d \n" , x->valor);
Vertice *y = x->dir;
Vertice *beta = y->esq;
if (x->pai == NULL){
arvore->raiz = y;
y->pai = NULL ;
}
else if (x->pai->esq == x){
x->pai->esq = y;
y->pai=x->pai;
} else {
x->pai->dir = y;
y->pai=x->pai;
}
y->esq = x;
x->pai= y;



x->dir= beta ;
if (beta!= NULL){
beta->pai = x;
}

}

void RotacaoDireita(Arvore *arvore, Vertice *y) {
printf("Direita em %d \n" , y->valor);
Vertice *x = y->esq;
Vertice *beta = x->dir;
if (y->pai == NULL){
arvore->raiz = x;
x->pai = NULL ;
}
else if (y->pai->esq == y){
y->pai->esq = x;
x->pai=y->pai;
} else {
y->pai->dir = x;
x->pai=y->pai;
}

x->dir= y ;
y->pai= x;

y->esq = beta;
if (beta!= NULL){
beta->pai = y;
}

}

int MAX(int x, int y) {
if (x >= y)
return x;
else
return y;
}

int altura(Vertice *x) {
if (x == NULL) {
return -1;
}
return MAX(altura(x->esq), altura(x->dir)) + 1;
}

int fatorBalanceamento(Vertice *x) { return altura(x->dir) - altura(x->esq); }

void balanceie(Arvore *arvore, Vertice *x) {
if(fatorBalanceamento(x) >= 2){
if (fatorBalanceamento(x->dir)>= 0){
RotacaoEsquerda(arvore,x);
} else {
RotacaoDireita(arvore,x->dir);
RotacaoEsquerda(arvore,x);
}
}
else if(fatorBalanceamento(x) <= -2){
if (fatorBalanceamento(x->esq) <= 0){
RotacaoDireita(arvore,x);
}else {
RotacaoEsquerda(arvore,x->esq);
RotacaoDireita(arvore,x);
}
}

}

int insere(Arvore *arvore, int valor) {
Vertice *novo = malloc(sizeof(Vertice));
novo->dir = NULL;
novo->esq = NULL;
novo->pai = NULL;
novo->valor = valor;

Vertice *anterior = NULL;
Vertice *atual = arvore->raiz;

while (atual != NULL) {
anterior = atual;
if (valor <= atual->valor) {
atual = atual->esq;
} else {
atual = atual->dir;
}
}

novo->pai = anterior;
if (anterior != NULL) {
if (valor <= anterior->valor) {
anterior->esq = novo;
} else {
anterior->dir = novo;
}
} else {
arvore->raiz = novo;
}
arvore->qtde++;

Vertice *temp = novo->pai;
while (temp != NULL) {
balanceie(arvore, temp);
temp = temp->pai;
}
return 1;
}

int remover(Arvore *arvore, Vertice *x) {
int filhos = 0;

if (x != NULL && x->esq != NULL) {
filhos++;
}
if (x != NULL && x->dir != NULL) {
filhos++;
}

Vertice *pai = x->pai;
if (filhos == 0) {
if (pai != NULL) {
if (pai->esq == x) {
pai->esq = NULL;
} else {
pai->dir = NULL;
}
} else {
arvore->raiz = NULL;
}
arvore->qtde--;
} else if (filhos == 1) {
Vertice *filho = x->esq;
if (filho == NULL)
filho = x->dir;

if (pai == NULL)
arvore->raiz = filho;
else {
if (pai->esq == x)
pai->esq = filho;
else
pai->dir = filho;
}
filho->pai = pai;
arvore->qtde--;
} else {
Vertice *sucessor = x;
sucessor = sucessor->dir;
while (sucessor->esq != NULL)
sucessor = sucessor->esq;
x->valor = sucessor->valor;
return remover(arvore, sucessor);
}

return 1;
}

int buscar_e_remover(Arvore *arvore, int valor) {
Vertice *atual = arvore->raiz;
while (atual != NULL) {
if (valor < atual->valor)
atual = atual->esq;
else if (valor > atual->valor)
atual = atual->dir;
else
return remover(arvore, atual);
}
return 0;
}

int getValor(Arvore *arvore) { return arvore->qtde; }

void imprimeInOrdem(Vertice *raiz) {
if (raiz != NULL) {
imprimeInOrdem(raiz->esq);
printf("%d ", raiz->valor);
imprimeInOrdem(raiz->dir);
}
}

void imprimePosOrdem(Vertice *raiz) {
if (raiz != NULL) {
imprimePosOrdem(raiz->esq);
}

int main(void){
  Arvore *arvore = malloc(sizeof(Arvore));
  arvore->raiz = NULL;
  arvore->qtde = 0;

  testeInsere(arvore, 54);
  testeInsere(arvore, 48);
  testeInsere(arvore, 62);
  testeInsere(arvore, 56);
  testeInsere(arvore, 55);
  testeInsere(arvore, 58);
  testeInsere(arvore, 59);
  testeRemove(arvore, 48);
  testeRemove(arvore, 55);
  testeRemove(arvore, 58);
  testeRemove(arvore, 62);
  testeRemove(arvore, 50);
  testeRemove(arvore, 60);
  testeRemove(arvore, 54);
  testeRemove(arvore, 59);
  testeRemove(arvore, 56);

  return 0;
}
