#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node
{
    int data;
    struct Node *next;
} node;

node *head = NULL;

node *createNode(int value)
{
    node *newnode = (node *)malloc(sizeof(node));
    if (newnode)
    {
        newnode->data = value;
        newnode->next = NULL;
    }
    return newnode;
}

int countNode()
{
    int count = 0;
    for (node *ptr = head; ptr != NULL; ptr = ptr->next)
    {
        count++;
    }
    return count;
}

bool isEmpty()
{
    return head == NULL;
}

void freeAllNodes()
{
    node *ptr;
    while (head)
    {
        ptr = head;
        head = head->next;
        free(ptr);
    }
}

void printList()
{
    if (isEmpty())
    {
        printf("\nList is empty!\n");
        return;
    }
    printf("\nList: ");
    for (node *ptr = head; ptr != NULL; ptr = ptr->next)
    {
        printf("%d ", ptr->data);
    }
    printf("\n");
}

void insertAtBeginning(int value)
{
    node *newnode = createNode(value);
    if (newnode)
    {
        newnode->next = head;
        head = newnode;
        printf("Element inserted at the beginning.\n");
    }
}

void insertAtEnd(int value)
{
    node *newnode = createNode(value);
    if (newnode)
    {
        if (isEmpty())
        {
            head = newnode;
        }
        else
        {
            node *ptr = head;
            while (ptr->next)
                ptr = ptr->next;
            ptr->next = newnode;
        }
        printf("Element inserted at the end.\n");
    }
}

void insertAtGivenIndex(int value, int pos)
{
    int n = countNode();
    if (pos < 0 || pos > n)
    {
        printf("Index out of bounds!\n");
        return;
    }
    node *newnode = createNode(value);
    if (newnode)
    {
        if (pos == 0)
        {
            newnode->next = head;
            head = newnode;
        }
        else
        {
            node *ptr = head;
            for (int i = 1; i < pos; i++)
                ptr = ptr->next;
            newnode->next = ptr->next;
            ptr->next = newnode;
        }
        printf("Element inserted at position %d.\n", pos);
    }
}

void deleteAtBeginning()
{
    if (isEmpty())
    {
        printf("List is empty.\n");
        return;
    }
    node *ptr = head;
    head = head->next;
    printf("Element %d deleted from the beginning.\n", ptr->data);
    free(ptr);
}

void deleteAtEnd()
{
    if (isEmpty())
    {
        printf("List is empty.\n");
        return;
    }
    node *ptr = head, *prev = NULL;
    while (ptr->next)
    {
        prev = ptr;
        ptr = ptr->next;
    }
    if (prev)
    {
        prev->next = NULL;
    }
    else
    {
        head = NULL;
    }
    printf("Element %d deleted from the end.\n", ptr->data);
    free(ptr);
}

void deleteFromGivenIndex(int pos)
{
    int n = countNode();
    if (pos < 0 || pos >= n)
    {
        printf("Index out of bounds!\n");
        return;
    }
    node *ptr = head, *prev = NULL;
    for (int i = 0; i < pos; i++)
    {
        prev = ptr;
        ptr = ptr->next;
    }
    if (prev)
    {
        prev->next = ptr->next;
    }
    else
    {
        head = ptr->next;
    }
    printf("Element %d deleted from position %d.\n", ptr->data, pos);
    free(ptr);
}

int main()
{
    insertAtBeginning(10);
    insertAtEnd(20);
    insertAtEnd(30);
    printList();
    insertAtGivenIndex(15, 1);
    insertAtGivenIndex(5, 0);
    inserAtBeginning(1);
    printList();
    DeleteAtBeginning();
    deleteAtEnd();
    deleteFromGivenIndex(1);
    printList();
}
