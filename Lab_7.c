//fibonacci, factorial, toh, gcd


#include<stdio.h>


int fibo(int n){
    if(n == 0 || n == 1)
        return n;
    return fibo(n-1) + fibo(n-2);
}


int factorial(int n){
    if(n < 0){
        printf("Choose a  positive number.\n");
    }
    if(n==1)
        return 1;
    return n*factorial(n-1);
}


void toh(int n, char S, char A, char D){
    if(n == 1){
        printf("Move disk from %c to %c.\n", S, D);
        return;
    }
    toh(n-1, S, D, A);
    printf("Move disk from %c to %c.\n", S, D);
    toh(n-1, A, S, D);
}


int gcd(int n1, int n2){
   if (n2 == 0)
        return n1;
    return gcd(n2, n1 % n2);
}




int main(){
    int i, a, b, n = 6;
    printf("Fibonacci::\n");
    for(i = 0; i < n; i++){
        printf("%d\t", fibo(i));
        }
    printf("\nFactorial::\n");
    printf("The factorial of %d is :: %d\n", n, factorial(n));
    printf("\nTower of Hanoi for 4 disk::\n");
    toh(4, 'A', 'B', 'C');
   
   printf("\ngcd function:\n");
   a=35;
   b=18;
   printf("GCD(%d,%d)=%d\n",a,b,gcd(a,b));
   
    printf("\nThe gcd of %d and %d is %d", a, b, gcd(a, b));
    return 0;
}
