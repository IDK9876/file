#include<stdio.h>
#define MAX 15

void swap(int *x, int *y){
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

void bubblesort(int arr[], int n){
    int i, j;
    for(i = 0; i< n-1; i++){
        for(j = 0; j< n-1-i; j++){
            if(arr[j] > arr[j+1]){
                swap(&arr[j], &arr[j+1]);
            }
        }
    }
}


void insertionsort(int arr[], int n){
    int i, j, temp;
    for(i = 0; i< n; i++){
        temp = arr[i];
        j = i-1;
        while(j>=0 && arr[j]> temp){
            arr[j+1] = arr[j];
            j --;
        }
        arr[j+1] = temp;
    }
}


void selectionsort(int arr[], int n){
    int i, j;
    for(i = 0; i< n-1; i++){
        int min = i;
        for(j = i+1; j< n; j++){
            if(arr[j] < arr[min]){
                min = j;
            }
        }
        if(min != i){
        swap(&arr[i], &arr[min]);
        }

    }
}


int partition(int arr[], int l, int r){
    int x, y, p;
    x = l;
    y = r;
    p = arr[l];
    while(x < y){
        while(arr[x]<=p)
            x++;
        while(arr[y]>p)
            y--;
        if(x< y)
            swap(&arr[x], &arr[y]);
    }
    arr[l] = arr[y];
    arr[y] = p;
    return y;
}
void quicksort(int arr[], int l, int r){
    if(l < r){
        int p = partition(arr, l, r);
        quicksort(arr, l, p-1);
        quicksort(arr, p+1, r); 
    }
}


void merge(int arr[], int l, int m, int r) {
    int x, y, k, brr[r-l+1];
    x = l;
    y = m+1;
    k = 0;
    while (x <= m && y <= r) {
        if (arr[x] < arr[y]) {
            brr[k++] = arr[x++];
        } else {
            brr[k++] = arr[y++];
        }
    }
    while (x <= m) {
        brr[k++] = arr[x++];
    }
    while (y <= r) {
        brr[k++] = arr[y++];
    }
    for (int i = 0; i < k; i++) {
        arr[l + i] = brr[i];
    }
}
void mergesort(int arr[], int l, int r) {
    if (l < r) {
        int m = (l + r) / 2;
        mergesort(arr, l, m);
        mergesort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}


void display(int arr[], int n) {
    for(int i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }
}

int main(){
    int arr1[] =  {64, 25, 43, 12, 22, 17, 91, 51};
    int arr2[] =  {89, 32, 57, 41, 18, 29, 68, 14};
    int arr3[] =  {50, 36, 77, 55, 19, 30, 82, 63};
    int arr4[] =  {75, 28, 49, 62, 34, 47, 88, 10};
    int arr5[] =  {91, 14, 38, 67, 23, 41, 56, 29};

    int n = sizeof(arr1)/sizeof(arr1[0]);
    
    printf("Original array:\n");
    display(arr1, n);
    
    // Sorting using Bubble Sort
    bubblesort(arr1, n);
    printf("\nSorted array using Bubble Sort:\n");
    display(arr1, n);
    
    printf("\n");
    
    printf("Original array:\n");
    display(arr2, n);
    
    // Sorting using Insertion Sort
    insertionsort(arr2, n);
    printf("\nSorted array using Insertion Sort:\n");
    display(arr2, n);
    
    printf("\n");
    
    printf("Original array:\n");
    display(arr3, n);
    
    // Sorting using Selection Sort
    selectionsort(arr3, n);
    printf("\nSorted array using Selection Sort:\n");
    display(arr3, n);
    
    printf("\n");
    
    printf("Original array:\n");
    display(arr4, n);
    
    // Sorting using Quick Sort
    quicksort(arr4, 0, n-1);
    printf("\nSorted array using Quick Sort:\n");
    display(arr4, n);
    
    printf("\n");
    
    printf("Original array:\n");
    display(arr5, n);

    mergesort(arr5, 0, n-1);
    printf("\nSorted array using Merge Sort:\n");
    display(arr5, n);
    
    return 0;
}