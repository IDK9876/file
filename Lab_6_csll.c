#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    struct node *next;
    int el;
} node;

node *head = NULL;
node *tail = NULL;
int size = 0;

void addfromhead(int val) {
    node *n = (node *)malloc(sizeof(node));
    n->el = val;

    if (head == NULL) {
        head = n;
        tail = n;
        n->next = head;
    } else {
        n->next = head;
        head = n;
        tail->next = head; 
    }
    printf("Inserted number %d from head\n", n->el);
    size++;
}

void addfromtail(int val) {
    node *n = (node *)malloc(sizeof(node));
    n->el = val;

    if (head == NULL) {
        head = n;
        tail = n;
        n->next = head;
    } 
    else{
        n->next = head;
        tail->next = n;
        tail = n;
    }
    printf("Inserted number %d from tail\n", n->el);
    size++;
}

void addfromkpos(int val, int k) {
    if (k < 1 || k >size + 1) {
        printf("Out of Scope\n");
        return;
    }

    node *n = (node *)malloc(sizeof(node));
    n->el = val;

    if (k == 1) 
        addfromhead(val);
    else if (k == size + 1)
        addfromtail(val);
    else {
        node *temp = head;
        int i;
        for (i = 1; i < k - 1; i++) {
            temp = temp->next;
        }

        n->next = temp->next;
        temp->next = n;
        size++;
        printf("Inserted %d to %d position\n", n->el, k);
    }

}

void deletefromhead() {
    if (head == NULL) {
        printf("List Empty\n");
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
    tail->next = head; 
    printf("Deleted number %d from head\n", temp->el);
    free(temp);
    size--;
}

void deletefromtail() {
    if (head == NULL) {
        printf("List Empty\n");
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
    node *prev = NULL;
    while (temp->next != head) {
        prev = temp;
        temp = temp->next;
    }
    printf("Deleted number %d from tail\n", temp->el);
    free(temp);
    prev->next = head;
    tail = prev;
    size --;
}

void deletefromkpos(int k) {
    if (head == NULL || k < 1 || k > size) {
        printf("Invalid\n");
        return;
    }

    if (k == 1)
        deletefromhead();
    else if (k == size)
        deletefromtail();
    else {
        node *temp = head;
        node *prev = NULL;
        int i;
        for (i = 1; i < k; i++) {
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
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    int i;
    node *temp = head;
    do{
        printf("[%d]", temp->el);
        temp = temp->next;
    }while(temp!= head);

    printf("\n");
}

void search(int key) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    int i;
    node *temp = head;
    printf("Searching for %d\n", key);
    do{
        if(key == temp->el){
        	printf("Key found\n");
        	return;
		}
        temp = temp->next;
    }while(temp!= head);
    printf("Key not found\n");
}

int main() {
    addfromhead(1);
    addfromtail(5);
    addfromkpos(2, 2);
    display();
    deletefromkpos(2);
    addfromhead(3);
    addfromtail(7);
    display();
    deletefromhead();
    deletefromtail();
    search(5);
    display();

    return 0;
}