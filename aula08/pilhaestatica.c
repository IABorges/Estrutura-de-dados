#include <stdio.h>
#include <stdlib.h>

typedef struct Cell {
  struct Cell *anterior;
  struct Cell *proximo;
  char valor;
} Cell;

typedef struct {
  Cell *top;
  int qtde;
} Stack;

Cell *start_cell(char valor) {
  Cell *nova = malloc(sizeof(Cell));
  nova->anterior = NULL;
  nova->proximo = NULL;
  nova->valor = valor;
  return nova;
}

Stack *start_stack() {
  Stack *stack = malloc(sizeof(Stack));
  stack->qtde = 0;
  stack->top = NULL;
  return stack;
}

void push(Stack *stack, char valor) {
  Cell *nova = start_cell(valor);
  if (stack->qtde != 0) {
    nova->proximo = stack->top;
    stack->top->anterior = nova;
  }
  stack->top = nova;
  stack->qtde++;
}

char pop(Stack *stack) {
  if (stack->qtde > 0) {
    char valor = stack->top->valor;
    Cell *top = stack->top;
    stack->top = stack->top->proximo;
    if (stack->top != NULL)
      stack->top->anterior = NULL;
    stack->qtde--;
    free(top);
    return valor;
  } else {
    return 'x';
  }
}

void mostrar(Stack *pilha){

    Cell *atual = pilha->top;
    printf("TOPO ->");
    while(atual != NULL){
        printf("%d ", atual->valor);
        atual = atual->anterior;
    }
    printf("<- Base\n");

}

int main(void) {
    Stack *stackCol = start_stack();
    Stack *stackPar = start_stack();
    Stack *stackCha = start_stack();
    char expr[100];
    fgets(expr, sizeof(expr), stdin);
    
    int Erro = 0;
    for(int i =0; expr[i] != '\0';i++){
        // // printf("%c\n",expr[i]);

        if(expr[i] == '{'  ){
           push(stackCha, expr[i]);
           // printf("%d\n",stackCha ->qtde);

        }
        else if(expr[i] == '[' && stackCha -> qtde != 0){
            push(stackCol, expr[i]);
            // printf("%d\n",stackCol ->qtde);

        }else if(expr[i] == '('  ){
            if(stackPar -> qtde != 0){
                Erro++;
                break;
            }
            push(stackPar, expr[i]);

        }else if(expr[i] == '[' && stackCha -> qtde == 0){
            Erro++;
 
         }else if(expr[i] == '(' && stackCol -> qtde == 0){
            Erro++;
         }
        else if(expr[i] == ')'){
            pop(stackPar);

        }else if(expr[i] == ']' && stackPar->qtde == 0){
            pop(stackCol);

        }else if(expr[i] == '}' && stackCol->qtde == 0){
            pop(stackCha);
        }
        

 
}

    if(stackCha->qtde == 0 && stackCol->qtde == 0 && stackPar->qtde == 0 && Erro == 0){
        printf("correto");
    } else{
        printf("incorreto");
    }

    return 0;
}
