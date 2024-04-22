#include<stdio.h>
#define MAX 6

typedef struct queue{
    int f, r;
    int el[MAX];
} qt;

void create(qt *q){
    q->f = 0;
    q->r = -1;
}

int isempty(qt *q){
    return (q->f == q->r + 1);
}

int isfull(qt *q){
    return (q->f == (q->r + 1) % MAX);
}

void enqueue(qt *q, int val){
    if(isfull(q)){
        printf("Queue Full\n");
        return;
    }
    q->r = (q->r + 1) % MAX;
    q->el[q->r] = val;
}

void dequeue(qt *q){
    if(isempty(q)){
        printf("Queue Empty\n");
        return;
    }
    printf("%d is dequeued\n", q->el[q->f]);
    if (q->f == q->r) { 
        q->f = 0;
        q->r = -1;
    } else {
        q->f = (q->f + 1) % MAX;
    }
}

void display(qt *q){
    if(isempty(q)){
        printf("Queue Empty\n");
        return;
    }
    printf("Queue: ");
    int i = q->f;
    do {
        printf("%d ", q->el[i]);
        i = (i + 1) % MAX;
    } while (i != (q->r + 1) % MAX); 
    printf("\n");
}

int main(){
    qt cq;
    create(&cq);
    enqueue(&cq, 9);
    enqueue(&cq, 8);
    enqueue(&cq, 7);
    display(&cq);

    dequeue(&cq);
    display(&cq);

    return 0;
}
