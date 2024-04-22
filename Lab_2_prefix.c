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

// Function to swap parentheses
// void swapParentheses(char* expr) {
//     int len = strlen(expr);
//     for (int i = 0; i < len; i++) {
//         if (expr[i] == '(')
//             expr[i] = ')';
//         else if (expr[i] == ')')
//             expr[i] = '(';
//     }
// }

// Function to reverse a string
void reverse(char* str) {
    int i = 0, j = strlen(str) - 1;
    while (i < j) {
        char temp = str[i];
        str[i] = str[j];
        str[j] = temp;
        i++;
        j--;
    }
}

int main() {
    stack opstack;
    stack prestack;
    char ch[SIZE] = "A+B/C*(D+E)-F";
    char temp;

    // Reverse the infix expression and swap parentheses
    reverse(ch);

    emptystack(&opstack);
    emptystack(&prestack);

    int i;

    // Print infix expression
    printf("Infix Expression: ");
    for (i = strlen(ch) - 1; i >= 0; i--) {
        printf("%c",  ch[i]);
    }

    printf("\nPrefix Expression: ");
    for (i = 0; i < strlen(ch); i++) {
        if (ch[i] == ')') {
            push(&opstack, ch[i]);
        } 
        else if (ch[i] == '(') {
            while (opstack.top != -1 && opstack.el[opstack.top] != ')') {
                temp = pop(&opstack);
                push(&prestack, temp);
            }

            if (opstack.top != -1) {
                temp = pop(&opstack);
            }
        }
        else if (isalpha(ch[i])) {
            push(&prestack, ch[i]);
        }
        else if (ch[i] == '+' || ch[i] == '-' || ch[i] == '*' || ch[i] == '/' || ch[i] == '$') {
            while (opstack.top != -1 && precedence(opstack.el[opstack.top]) > precedence(ch[i])) {
                temp = pop(&opstack);
                push(&prestack, temp);
            }
            push(&opstack, ch[i]);
        }
    }

    while (opstack.top != -1) {
        temp = pop(&opstack);
        push(&prestack, temp);
    }

    for (i = prestack.top; i >= 0; i--) {
        printf("%c", prestack.el[i]);
    }
    scanf("%d", &i);
    return 0;
}
