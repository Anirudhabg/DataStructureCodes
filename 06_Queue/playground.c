// Design, develop, and execute a program in C to simulate the working of a queue of integers using an array.
// Provide the following operations: a. Insert b. Delete c. Display

#include <stdio.h>
#include <stdlib.h>

#define MAX 5

void insert();
void delete();
void display();

int QUEUE[MAX];
int REAR = -1;
int FRONT = -1;

void insert()
{
    if (REAR == MAX - 1)
    {
        printf("Queue is Full\n");
        return;
    }
    if (FRONT == -1)
    {
        FRONT = 0;
    }
    printf("\n Insert: ");
    int item;
    scanf("%d", &item);
    QUEUE[++REAR] = item;
    printf("\n Item Inserted to Queue\n");
}

void delete()
{
    if (FRONT == -1 || FRONT > REAR)
    {
        printf("Queue is Empty\n");
        return;
    }
    int item = QUEUE[FRONT++];

    printf("\n Delete: %d", item);
}

void display()
{
    if (FRONT == -1 || FRONT > REAR)
    {
        printf("Queue is Empty\n");
        return;
    }
    printf("\n Queue: \t");
    for (int i = FRONT; i <= REAR; i++)
    {
        printf("%d\t", QUEUE[i]);
    }
    printf("\n");
}

void main()
{
    int choice;
    while (1)
    {
        printf("\n1. Insert\t 2. Delete\t 3. Display\t 4. Exit\n Choose any one option: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            insert();
            break;
        case 2:
            delete ();
            break;
        case 3:
            display();
            break;
        case 4:
            exit(1);
            break;
        default:
            printf("Invalid Choice!\n");
        }
    }
}