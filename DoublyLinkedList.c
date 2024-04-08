// Program to demonstrate Doubly Linked List

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *prev;
    struct Node *next;
};

struct Node *head;

struct Node *getNewNode(int x)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = x;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}
void insertAtHead(int x)
{
    struct Node *newNode = getNewNode(x);

    if (head == NULL)
    {
        head = newNode;
        return;
    }
    head->prev = newNode;
    newNode->next = head;
    head = newNode;
}

void insertAtTail(int x)
{
    struct Node *newNode = getNewNode(x);
    struct Node *temp = head;
    if (head == NULL)
    {
        head = newNode;
        return;
    }

    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    newNode->prev = temp;
    temp->next = newNode;
    newNode = head;
}

void PrintForward()
{
    struct Node *temp = head;
    printf("\n Forward List");

    while (temp != NULL)
    {
        printf("\n %d", temp->data);
        temp = temp->next;
    }
}

void PrintReverse()
{
    struct Node *temp = head;
    // Traversing to last Node
    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    // Traversing to starting Node from tail Node
    printf("\n Reverse List");
    while (temp != NULL)
    {
        printf("\n %d", temp->data);
        temp = temp->prev;
    }
}

void main()
{
    head = NULL;
    insertAtHead(5);
    insertAtHead(2);
    insertAtTail(0);
    insertAtTail(6);
    PrintForward();
    PrintReverse();
    insertAtTail(6);
    PrintReverse();
}
