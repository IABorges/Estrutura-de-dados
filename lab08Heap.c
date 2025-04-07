#include <stdio.h>
#include <stdlib.h>

#define LEN 10

typedef struct {
  int valores[LEN];
  int qtde;
} heap;

int filho_esq(int pai) { 
    // implementar
    return (pai*2)+1; // atenção;
    }

int filho_dir(int pai) { 
    // implementar
    return 2*pai +2;
    }

int pai(int filho) { 
    // implementar
    int  conta = (filho -1)/2;
    return conta;
    }

int ultimo_pai(heap *h) { 
    // implementar
    int n = h->qtde; 
    return ((n/2)-1);
}

void peneirar(heap *h, int pai) {
  // implementar
}

void mostrar(heap *h) {
  // implementar
    for(int i = 0; i < h->qtde ;i++ ){
        printf("%d", h->valores[i]);
    }

}

void construir(heap *h) {
  // implementar
}

void inserir(heap *h, int valor) {
    
    while(h->qtde < LEN){
        h->valores[h->qtde]=valor;
        h->qtde++;
    }
}

void remover(heap *h) {
  // implementar
}

int main(void) {
  heap *h = malloc(sizeof(heap));
  int valor;
  h->qtde = 0;
  for (int i = 0; i < LEN; i++) {
    scanf("%d", &valor);
    inserir(h, valor);
    mostrar(h);
  }
  for (int i = 0; i < LEN; i++) {
    remover(h);
    mostrar(h);
  }

  return 0;
}