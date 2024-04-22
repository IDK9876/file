#include <stdio.h>
#define SIZE 5

typedef struct stack {
    int top;
    int el[SIZE];
} st;

int isempty(st *s) {
    return (s->top == -1);
}

int isfull(st *s) {
    return (s->top == SIZE - 1);
}

void push(st *s, int val) {
    if (isfull(s)) {
        printf("Stack full\n");
        return;
    }
    s->top++;
    s->el[s->top] = val;
}

void pop(st *s) {
    if (isempty(s)) {
        printf("Stack empty\n");
        return;
    }
    printf("%d is popped\n", s->el[s->top]);
    s->top--;
}

int search(st *s, int val) {
    if (isempty(s)) {
        printf("Stack empty\n");
        return 0;
    }
    for (int i = s->top; i >= 0; i--) {
        if (s->el[i] == val)
            return val;
    }
    printf("Not found\n");
    return 0;
}


void display(st *s) {
    if (isempty(s)) {
        printf("Stack empty\n");
        return;
    }

    printf("Stack:\n");
    for (int i = s->top; i >= 0; i--) {
        printf("%d\n", s->el[i]);
    }
}

// void display(st *s) {
//     if (isempty(s)) {
//         printf("Stack empty\n");
//         return;
//     }

//     printf("Stack:\n");
//     printf("------\n");
//     for (int i = SIZE - 1; i > s->top; i--) {
//         printf("|   |\n");
//         printf("------\n");
//     }
//     for (int i = s->top; i >= 0; i--) {
//         printf("| %d |\n", s->el[i]);
//         printf("------\n");
//     }
//     printf("\n");
// }


int main() {
    st mystack; 
    mystack.top = -1; 

    push(&mystack, 5);
    push(&mystack, 3);
    push(&mystack, 6);
    display(&mystack);
    pop(&mystack);
    display(&mystack);

    return 0;
}