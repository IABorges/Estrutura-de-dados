#include <stdio.h>
#include <stdlib.h>

typedef struct Celula {
	int valor;
	struct Celula *proximo;
	struct Celula *anterior;
} Celula;

typedef struct {
	Celula *head;
	Celula *tail;
	int qtde;
} Queue;

Celula *cria_celula(int valor){
	Celula *celula = malloc(sizeof(Celula));
	celula->proximo = NULL;
	celula->anterior = NULL;
	celula->valor = valor;

	return celula;
}

Queue *cria_queue(){

	Queue *queue = malloc(sizeof(Queue));
	queue->head = NULL;
	queue->tail = NULL;
	queue->qtde = 0;

	return queue;
}

void enqueue(Queue *queue, int valor){
	// implementar
    Celula *nova = cria_celula(valor);

    //colocar a celula na fila
    if(queue->qtde == 0){
        queue->head = nova;
    }   else{
        queue->tail->proximo = nova;
        nova-> anterior = queue->tail;      
    }
    queue -> tail = nova;
    queue->qtde ++;

	}

int dequeue(Queue *queue){
	// implementar

    if(queue->qtde==0){
        return -1;
    }
    Celula *liberar =queue->head;
    int valor = queue->head->valor;

    if(queue->qtde ==1){       
        queue -> head =NULL;
        queue ->tail =NULL;
       
    }else{
        queue->head->proximo->anterior = NULL; //tudo isso para pegar o primeiro valor
        queue -> head = queue->head->proximo;
    }
    queue->qtde --;
    free(liberar);
    return valor;
}

void show(Queue *queue){
	// implementar
    
        Celula *atual = queue->tail;
        while(atual!= NULL){
            printf("%d", atual-> valor);
            atual = atual->anterior;
        }
    
    
}

void show_invertido(Queue *queue){
	// implementar

     Celula *atual = queue->head;
    while(atual != NULL){
        printf("%d", atual-> valor);
        atual = atual->proximo;
    }
    
}

int main(void) {
	Queue *qnum1 = cria_queue();
	Queue *qnum2 = cria_queue();
	Queue *res = cria_queue();
	
	char num1[100];
	char num2[100];
	fgets(num1, sizeof(num1), stdin);
	fgets(num2, sizeof(num2), stdin);

	int i = 0;
	while(num1[i] != '\n'){		
		enqueue(qnum1, (int)(num1[i]) - 48);
		enqueue(qnum2, (int)(num2[i]) - 48);
		i++;
		}



    // show_invertido(qnum1);
    // printf("\n");
    // show_invertido(qnum2);

	// int valor1 = dequeue(qnum1);
	// int valor2 = dequeue(qnum2);
    // int v3 = valor1 + valor2;

    Celula *atual = qnum1->tail;
    Celula *atual2 = qnum2->tail;
    int c = 0;
    while(atual != NULL){
        // printf("%d ", atual-> valor);
        // printf("%d", atual2-> valor);
        int valor = atual-> valor + atual2-> valor + c;
       
            if(valor < 10){
                c =0;

            }else{
                c = 1;
                valor -= 10;
            }
            
        enqueue(res,valor);
        atual = atual->anterior;
        atual2 = atual2->anterior;

    }
    if(c ==1){
        enqueue(res,1);
    }
    show(res);

    // while(atual != NULL){
    //     printf("%d", atual-> valor);
    //     atual = atual->anterior;
    // }
    // while (atual2 != NULL){
    //     printf("%d", atual2-> valor);
    //     atual2 = atual2->anterior;
    //     }
    
}