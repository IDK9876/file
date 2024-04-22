#include<stdio.h>  
#define SIZE 10 
int hash_table[SIZE];  

void init(){     
    for(int i = 0; i < SIZE; i++)  
        hash_table[i] = -1;  
}  

int hash(int key) {
    return key % SIZE;
}

int linear_probe(int key) {
    int index = hash(key);
    while (hash_table[index] != -1) {
        index = (index + 1) % SIZE;
    }
    return index;
}

int quadratic_probe(int key) {
    int index = hash(key);
    for (int i = 1; hash_table[index] != -1; i++) {
        index = (index + i * i) % SIZE;
    }
    return index;
}

void insert(int val)  
{     
    int key = hash(val);  
    if(hash_table[key] == -1)  
    {     
        hash_table[key] = val;  
        printf("%d inserted at index %d\n", val, key);  
    }  
    else  
    {     
        printf("Collision occurred for value %d at index %d\n", val, key);
        //  int index = linear_probe(val);
        
        int index = quadratic_probe(val);
        
        hash_table[index] = val;
        printf("%d inserted at index %d using probing\n", val, index);
    }  
}  

void search(int val)  
{  
    int key = hash(val);  
    if(hash_table[key] == val)  
        printf("Search Found at index %d\n", key);  
    else  
        printf("Search Not Found\n");  
}  

void display()  
{  
    for(int i = 0; i < SIZE; i++)  
        printf("hash_table[%d] = %d\n", i, hash_table[i]);  
}  

int main()  
{  
    init();  
    insert(44);   
    insert(15);    
    insert(30);  
    insert(45);   
    insert(55);
    insert(72);
    insert(90);
    insert(115);
    insert(35);
    insert(10);
    printf("\nHash Table after insertion:\n");
    display();
    printf("\n");  

    printf("Searching value 4.\n");  
    search(4);  
    printf("Searching value 10.\n");  
    search(10);  
  
    return 0;  
}  
