#include <stdio.h>
#include <ctype.h>

#define MAX 50

int STACK[MAX];

int TOP = -1;

void push(int x)
{
    if (TOP == MAX)
    {
        return;
    }
    STACK[++TOP] = x;
}

int pop()
{
    if (TOP == -1)
    {
        return -1;
    }

    int x = STACK[TOP--];

    return x;
}

void main()
{
    char *e, EXPRESSION[50];
    printf("Enter the expression in postfix form only: \n");
    scanf("%s", EXPRESSION);
    int a, b, c, d;
    e = EXPRESSION;
    while (*e != '\0')
    {
        if (isdigit(*e))
        {
            d = *e - 48;
            push(d);
        }
        else
        {
            a = pop();
            b = pop();

            switch (*e)
            {
            case '+':
                c = a + b;
                break;
            case '-':
                c = a - b;
                break;
            case '*':
                c = a * b;
                break;
            case '/':
                c = a / b;
                break;
            }
            push(c);
        }
        e++;
    }
    printf("Result of the expression %s is: %d.", EXPRESSION, pop());
}