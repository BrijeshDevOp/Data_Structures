// To demonstrate Linked - List using Array

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *rear = NULL;
struct Node *front = NULL;

void EnQueue(int x)
{
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data = x;
    temp->next = NULL;

    if (rear == NULL && front == NULL)
    {
        front = rear = temp;
        return;
    }

    rear->next = temp;
    rear = temp;
}

void DeQueue()
{
    struct Node *temp = front;
    if (rear == NULL)
    {
        printf("\n Queue is Empty");
        return;
    }
    else if (rear == front)
    {
        rear = front = NULL;
    }
    else
    {
        front = front->next;
    }
    free(temp);
}

void printQueue()
{
    struct Node *temp = front;

    if (temp == NULL)
    {
        printf("\n The Queue is Empty");
        return;
    }

    printf("\n");
    while (temp != NULL)
    {
        printf("  %d", temp->data);
        temp = temp->next;
    }
}

void peek()
{
    struct Node *temp = front;

    if (temp == NULL)
    {
        printf("\n Queue is empty");
    }
    else
    {
        printf("\n%d", temp->data);
    }
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
            EnQueue(value);
            break;

        case 2:
            DeQueue();
            break;

        case 3:
            peek();
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
