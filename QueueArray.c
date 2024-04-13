// To demonstrate Simple Queue using Array

#include <stdio.h>
#include <conio.h>
#define N 10

int Q[N], f = -1, r = -1;

int isFull()
{
    if (r == N - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isEmpty()
{
    if (r == -1 && f == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void printQueue()
{
    printf("\n r-> %d and f-> %d ", r, f);
    printf("\n\n------------------------------------------\n");
    if (isEmpty())
        printf("\n The Queue is Empty");
    else
        for (int i = f; i <= r; i++)
        {
            printf("  %d", Q[i]);
        }
    printf("\n------------------------------------------\n");
}

void enQueue(int val)
{
    if (isFull())
    {
        printf("Q is FULL");
        return;
    }
    else if (isEmpty())
    {
        r = f = 0;
    }
    else
    {
        r = r + 1;
    }
    Q[r] = val;
}

void deQueue()
{
    if (isEmpty())
    {
        printf(" \n The Queue is Empty ");
        return;
    }
    else if (r == f)
    {
        printf(" \n Element %d removed from Queue \n ", Q[f]);
        r = f = -1;
    }
    else
    {
        printf(" \n Element %d removed from Queue \n ", Q[f]);
        f = f + 1;
    }
}

int peek()
{
    if (isEmpty)
        printf("\n Queue is Empty");
    else
        return Q[f];
}

void main()
{
    int choice, value;
    while (1)
    {
        printf("\n-----------------------------------------\n");
        printf("\n1. EnQueue\n2. DeQueue\n3. Peek\n4. Display\n5. Exit");
        printf("\n Enter Your choice:");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("\n Enter element you want to add:");
            scanf("%d", &value);
            enQueue(value);
            break;

        case 2:
            deQueue();
            break;

        case 3:
            printf("\nElement at front is %d ", peek());
            break;

        case 4:
            printQueue();
            break;

        case 5:
            exit(0);
            break;
        default:
            printf("\n Wrong choice");
            break;
        }
    }
}