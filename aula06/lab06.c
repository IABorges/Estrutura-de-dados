 #include <stdio.h>
  #define LEN 100

typedef struct {
char data[LEN];
int head;
int tail;
int qtde;
} Queue;

void enqueue(Queue *queue, char caracter) {
if(queue->qtde == LEN){
return ;
}
queue->data[queue->tail % LEN] = caracter;
queue->tail++;
queue->qtde++;
}

int dequeue(Queue *queue) {


if(queue->qtde == 0){
return 0;
}
int valor = queue->data[queue->head % LEN];
queue->head++;
queue->qtde--;
return valor;
}

void show(Queue *queue) {
for(int i = queue->head; i < queue->tail; i++){
printf("%c", queue->data[i % LEN]);

}

}

void start_queue(Queue *queue) {
queue-> head = 0;
queue->tail = 0;
queue-> qtde = 0;
}

int main(void) {
char s[LEN];
char x;
int flag = 1;
fgets(s, sizeof(s), stdin);
Queue queue;
Queue queue2;


start_queue(&queue);
start_queue(&queue2);

for (int i = 0; s[i] != '\0'; i++) {
enqueue(&queue, s[i]);
}



for (int i = 0; s[i] != '\0'; i++) {
x = dequeue(&queue);
if(x == '('){
enqueue(&queue2, x);
} else if(x == ')'){
if(dequeue(&queue2) == 0){
flag = 0;
break;
}
}
show(&queue);
}

if(queue2.qtde > 0){
flag = 0;
}

if(flag == 1){
printf("correto");
}else{
printf("incorreto");
}



return 0;
}