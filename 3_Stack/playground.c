#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX 100
int top = -1;
int stack[MAX];


bool isEmpty(){
    return top == -1;
}

bool isFull(){
    return top == MAX - 1;
}

void push(int value) {
    if (isFull()) {
        printf("Stack overflow! Cannot push %d\n", value);
        return;
    }
    stack[++top] = value;
    printf("Pushed %d onto the stack.\n", value);
}

void pop() {
    if (isEmpty()) {
        printf("Stack underflow! Cannot pop from an empty stack.\n");
        return;
    }
    int value = stack[top--];
    printf("Popped %d from the stack.\n", value);
}

void peek() {
    if (isEmpty()) {
        printf("Stack is empty! Cannot peek.\n");
        return;
    }
    printf("Top element is %d\n", stack[top]);
}

void display() {
    if (isEmpty()) {
        printf("Stack is empty!\n");
        return;
    }
    printf("Stack elements: ");
    for (int i = top; i >= 0; i--) {
        printf("%d ", stack[i]);
    }
    printf("\n");
}

int main() {
    push(10);
    push(20);
    push(30);
    display();
    
    peek();
    
    pop();
    display();
    
    pop();
    pop();
    pop(); // Attempt to pop from an empty stack
    
    return 0;
}