#include <stdio.h>

int fibonacci(int n) {
    if (n <= 1) {
        return n;
    }
    return fibonacci(n - 1) + fibonacci(n - 2);
}

void main() {
    int number = 5;
    printf("Fibonacci of %d is %d\n", number, fibonacci(number));
}