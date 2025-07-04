#include <stdio.h>

int factorial(int n) {
    if (n <= 1) {
        return 1;
    }
    return n * factorial(n - 1);
}

void main(){
    int number = 2;
    printf("Factorial of %d is %d\n", number, factorial(number));
}