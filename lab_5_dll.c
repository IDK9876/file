#include <stdio.h>
#include <stdlib.h>

typedef struct dll {
    int el;
    struct dll *next;
    struct dll *prev;
} node;

node *head = NULL;
node *tail = NULL;
int size = 0;

void addfromhead(int val) {
    node *n = (node *)malloc(sizeof(node));
    if (n == NULL) {
        printf("Memory allocation failed\n");
        return;
    }
    n->el = val;
    if (head == NULL) {
        n->prev = NULL;
        n->next = NULL;
        head = n;
        tail = n;
    } else {
        n->prev = NULL;
        n->next = head;
        head->prev = n;
        head = n;
    }
    size++;
}

void addfromtail(int val) {
    node *n = (node *)malloc(sizeof(node));
    if (n == NULL) {
        printf("Memory allocation failed\n");
        return;
    }
    n->el = val;
    if (head == NULL) {
        n->prev = NULL;
        n->next = NULL;
        tail = n;
        head = n;
    } else {
        n->next = NULL;
        n->prev = tail;
        tail->next = n;
        tail = n;
    }
    size++;
}

void addfromkpos(int val, int k) {
    if (k < 1 || k > size + 1) {
        printf("Out of scope\n");
        return;
    }

    if (k == 1)
        addfromhead(val);
    else if (k == size + 1)
        addfromtail(val);
    else {
        node *n = (node *)malloc(sizeof(node));
        if (n == NULL) {
            printf("Memory allocation failed\n");
            return;
        }
        n->el = val;
        node *temp = head;
        int i;
        for (i = 1; i < k - 1; i++) {
            temp = temp->next;
        }
        n->prev = temp;
        n->next = temp->next;
        temp->next->prev = n;
        temp->next = n;
        size++;
    }
}

void delfromhead() {
    if (head == NULL) {
        printf("Empty list\n");
        return;
    }
    if (head == tail) {
        free(head);
        head = NULL;
        tail = NULL;
        size = 0;
        return;
    }
    node *temp = head;
    head = temp->next;
    head->prev = NULL;
    free(temp);
    size--;
}

void delfromtail() {
    if (head == NULL) {
        printf("Empty list\n");
        return;
    }
    if (head == tail) {
        free(head);
        head = NULL;
        tail = NULL;
        size = 0;
        return;
    }
    node *temp = tail;
    tail = temp->prev;
    tail->next = NULL;
    free(temp);
    size--;
}

void delfromkpos(int k) {
    if (k < 1 || k > size) {
        printf("Out of scope\n");
        return;
    }

    if (k == 1) {
        delfromhead();
    } else if (k == size) {
        delfromtail();
    } else {
        node *temp = head;
        int i;
        for (i = 1; i < k; i++) {
            temp = temp->next;
        }

        temp->next->prev = temp->prev;
        temp->prev->next = temp->next;
        free(temp);
        size--;
    }
}

void display() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    node *temp = head;
    while (temp != NULL) {
        printf("[%d] ", temp->el);
        temp = temp->next;
    }
    printf("\n");
}

void search(int key) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    node *temp = head;
    while (temp != NULL) {
        if (key == temp->el) {
            printf("Key found\n");
            return;
        }
        temp = temp->next;
    }
    printf("Key not found\n");
}

int main() {
    addfromhead(1);
    addfromtail(5);
    addfromkpos(2, 2);
    display();
    delfromkpos(2);
    addfromhead(3);
    addfromtail(7);
    display();
    delfromhead();
    delfromtail();
    display();
    search(6);
    return 0;
}
