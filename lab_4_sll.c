#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int el;
    struct node *next;
} node;

node *head = NULL;
node *tail = NULL;
int size = 0;

void addfromhead(int val) {
    node *n = (node *) malloc(sizeof(node));
    n->el = val;

    if (head == NULL) {
        n->next = NULL;
        head = n;
        tail = n;
    } else {
        n->next = head;
        head = n;
    }
    printf("Inserted number %d from head\n", n->el);
    size++;
}

void addfromtail(int val) {
    node *n = (node *) malloc(sizeof(node));
    n->el = val;

    if (head == NULL) {
        n->next = NULL;
        head = n;
        tail = n;
    } else {
        n->next = NULL;
        tail->next = n;
        tail = n;
    }
    printf("Inserted number %d from tail\n", n->el);
    size++;
}

void addfromkpos(int val, int k) {
    node *n = (node *) malloc(sizeof(node));
    n->el = val;

    if (k <= 0 || k > size + 1) {
        printf("Out of scope\n");
        return;
    }

    if (k == 1) {
        addfromhead(val);
    } else if (k == size + 1) {
        addfromtail(val);
    } else {
        node *temp = head;
        int i;
        for (i = 1; i < k - 1; i++) {
            temp = temp->next;
        }
        n->next = temp->next;
        temp->next = n;
    printf("Inserted %d to %d position\n", n->el, k);
    size++;
    }
}

void deletefromhead() { 
    if (head == NULL) {
        printf("Empty List");
        return;
    }
    if(head == tail){
        free(head);
        head = NULL;
        tail = NULL;
        size = 0;
        return;
    }
    node *temp = head;
    head = temp->next;
    printf("Deleted number %d from head\n", temp->el);  
    free(temp);
    size--;
}

void deletefromtail() { 
    if (head == NULL) {
        printf("Empty List");
        return;
    }
    node *temp = head;

    if (head == tail) {
        free(temp);
        head = NULL;
        tail = NULL;
        size = 0;
        return;
    }

    node *prev = NULL;
    while (temp->next != NULL) {
        prev = temp;
        temp = temp->next;
    }
    printf("Deleted number %d from tail\n", temp->el);
    free(temp);
    prev->next = NULL;
    tail = prev;
    size--;
}


void delfromkpos(int k){
    if(head == NULL){
        printf("Empty List");
    }
    if (k == 1) 
        deletefromhead();

    else if (k == size) 
        deletefromtail();

    else {
        node *temp = head;
        node *prev = NULL;
        int i;
        for (i = 1; i < k ; i++) {
            prev = temp;
            temp = temp->next;
        }
        prev->next = temp->next;
        printf("Deleted number %d from %d position\n", temp->el, k);
        free(temp);
        size--;
    }
}


void display() { 
    if(head == NULL){
        printf("Empty list\n");
        return;
    }

    node *temp = head;
    while(temp != NULL) {
        printf("[%d]", temp->el);
        temp = temp->next;
    }
    printf("\n");
}



int main() {
    node *nn;
    addfromhead(5);
    addfromhead(6);
    addfromtail(8);
    display();
    addfromkpos(1, 2);
    deletefromhead();
    deletefromtail();
    addfromtail(4);
    display();
    delfromkpos(2);
    display();
    return 0;
}

