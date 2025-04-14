#include <stdio.h>
#include <stdlib.h>

#define LEN 10

typedef struct {
  int valores[LEN];
  int qtde;
} heap;

int filho_esq(int pai) { 
    return (pai * 2) + 1;
}

int filho_dir(int pai) { 
    return 2 * pai + 2;
}

int pai(int filho) { 
    int conta = (filho - 1) / 2;
    return conta;
}

int ultimo_pai(heap *h) { 
    int n = h->qtde; 
    return (n / 2) - 1;
}

void peneirar(heap *h, int pai) {
    int maior = pai;
    int esq = filho_esq(pai);
    int dir = filho_dir(pai);

    if (esq < h->qtde && h->valores[esq] > h->valores[maior]) {
        maior = esq;
    }
    if (dir < h->qtde && h->valores[dir] > h->valores[maior]) {
        maior = dir;
    }

    if (maior != pai) {
        int temp = h->valores[pai];
        h->valores[pai] = h->valores[maior];
        h->valores[maior] = temp;
        peneirar(h, maior);
    }
}

void mostrar(heap *h) {
    for (int i = 0; i < h->qtde; i++) {
        printf("%d", h->valores[i]);
        if (i < h->qtde - 1) printf(" ");
    }
    printf("\n");
}

void construir(heap *h) {
    for (int i = ultimo_pai(h); i >= 0; i--) {
        peneirar(h, i);
    }
}

void inserir(heap *h, int valor) {
    if (h->qtde < 10) {
        h->valores[h->qtde] = valor;
        int i = h->qtde;
        h->qtde++;

        while (i > 0 && h->valores[pai(i)] < h->valores[i]) {
            int temp = h->valores[i];
            h->valores[i] = h->valores[pai(i)];
            h->valores[pai(i)] = temp;
            i = pai(i);
        }
    }
}

void remover(heap *h) {
    if (h->qtde > 0) {
        h->valores[0] = h->valores[h->qtde - 1];
        h->qtde--;
        peneirar(h, 0);
    }
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

    free(h);
    return 0;
}
