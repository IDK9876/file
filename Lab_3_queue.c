#include<stdio.h>
#define SIZE 6
#include<conio.h>

typedef struct queue{
    int el[SIZE];
    int f;
    int r;
}queue;


void create(queue *q){
    q->f = -1;
    q->r = -1;
}

int isempty(queue *q){
    return (q->f == -1 || q->f > q->r);
}

int isfull(queue *q){
    return (q->r == SIZE - 1);
}

void enqueue(queue *q, int val){
    if(isfull(q)){
        printf("Queue Full\n");
        return;
    }
    if(isempty(q))
        q->f = 0;
    q->r++;
    q->el[q->r] = val;
}

void dequeue(queue *q){
    if(isempty(q)){
        printf("Queue Empty\n");
        return;
    }
    printf("\n%d is deleted\n", q->el[q->f]);
    q->f++;
}

void search(queue *q, int k){
	int i;
    for(i = q->f; i <= q->r; i++){
    	if(q->el[i] == k){
        	printf("Key found at %d position \n", i);
        	return;
    	}
    }
    printf("Not Found\n");
	  	
}
void display(queue *q){
    if(isempty(q)){
        printf("Queue Empty\n");
        return;
    }
    int i;
    printf("\nLinear Queue::\n");
    for(i = q->f; i <= q->r; i++){
        printf("| %d |", q->el[i]);
    }  
}


int c_isempty(queue *q){
    return (q->f == -1 || (q->f+1)%SIZE > (q->r+1)%SIZE);
}

int c_isfull(queue *q){
    return (q->f == (q->r+1)%SIZE);
}

void c_enqueue(queue *q, int val){
    if(c_isfull(q)){
        printf("Queue Full\n");
        return;
    }
    if(c_isempty(q)){
        q->f = 0;
        q->r = 0;
    }

    q->r = (q->r+1)%SIZE;
    q->el[q->r] = val;
}

void c_dequeue(queue *q){
    if(c_isempty(q)){
        printf("Queue Empty\n");
        return;
    }
    printf("\n%d is deleted\n", q->el[(q->f+1)%SIZE]);
    if(q->f == q->r){
        q->f = -1;
        q->r = -1;
    }
    else{
        q->f = (q->f+1)%SIZE;
    }
}

void c_search(queue *q, int k){
	int i;
    for(i = (q->f+1)%SIZE; i != (q->r+1)%SIZE; i++){
    	if(q->el[i] == k){
        	printf("Key found at %d position \n", i);
        	return;
    	}
    }
    printf("Not Found\n");
	  	
}

void c_display(queue *q){
    if(c_isempty(q)){
        printf("Queue Empty\n");
        return;
    }
    int i;
    printf("\nCircular Queue::\n");
    for(i = (q->f+1)%SIZE; i != (q->r+1)%SIZE; i++){
        printf("| %d |", q->el[i]);
    }  
}

int main(){
    queue q, cq;
    create(&q);
    enqueue(&q, 5);
    enqueue(&q, 3);
    enqueue(&q, 8);
    display(&q);
    dequeue(&q);
    display(&q);
    search(&q, 8);

    create(&cq);
    c_enqueue(&cq, 5);
    c_enqueue(&cq, 3);
    c_enqueue(&cq, 8);
    c_display(&cq);
    c_dequeue(&cq);
    c_display(&cq);
    c_search(&cq, 8);
    return 0;
}
