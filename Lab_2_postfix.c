#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define SIZE 100

typedef struct stack {
    int top;
    char el[SIZE];
} stack;

void emptystack(stack *s) {
    s->top = -1;
}

void push(stack *s, char val) {
    s->top++;
    s->el[s->top] = val;
}

char pop(stack *s) {
    char scan = s->el[s->top];
    s->top--;
    return scan;
}

int precedence(char ch) {
    switch (ch) {
        case '$':
            return 3;
        case '*':
        case '/':
            return 2;
        case '+':
        case '-':
            return 1;
        default:
            return -1;
    }
}

int main() {
    stack opstack;
    stack poststack;
    char ch[SIZE] = "A+B*(C-D)$E/F";
    char temp;


    emptystack(&opstack);
    emptystack(&poststack);

    int i;

    printf("Postfix Expression: ");
    for (i = 0; i < strlen(ch); i++) {
        printf("%c",  ch[i]);

        if (ch[i] == '(') {
            push(&opstack, ch[i]);
        } 
		else if (ch[i] == ')') {
            while (opstack.top != -1 && opstack.el[opstack.top] != '(') {
                temp = pop(&opstack);
                push(&poststack, temp);
            }

            if (opstack.top != -1) {
                temp = pop(&opstack);
            }
        }
		
		 else if (isalpha(ch[i])) {
            push(&poststack, ch[i]);
        }
		
		 else if (ch[i] == '+' || ch[i] == '-' || ch[i] == '*' || ch[i] == '/' || ch[i] == '$') {
            while (opstack.top != -1 && precedence(opstack.el[opstack.top]) >= precedence(ch[i])) {
                temp = pop(&opstack);
                push(&poststack, temp);
            }
            push(&opstack, ch[i]);
        }
    }

    while (opstack.top != -1) {
        temp = pop(&opstack);
        push(&poststack, temp);
    }

    printf("\nPostfix Expression: ");
    for (i = 0; i <= poststack.top; i++) {
        printf("%c", poststack.el[i]);
    }

    scanf("%d", &i);
    return 0;
}
