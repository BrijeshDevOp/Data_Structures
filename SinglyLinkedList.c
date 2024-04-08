#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

// defininig the type of Node
struct Node
{
    int data;
    struct Node *next;
};

// Declaring the type of head
struct Node *head;

//  Creating A new Node
struct Node *getNewNode(int x)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = x;
    newNode->next = NULL;
    return newNode;
}

// Counting Number of Node
int countNode()
{
    int count = 0;
    struct Node *temp = head;
    printf("\n List Elements are:\n");
    while (temp != NULL)
    {
        printf("   %d", temp->data);
        temp = temp->next;
        count++;
    }
    return count;
}

// Print the elements in forward direction
void print()
{
    struct Node *temp = head;
    printf("\n List Elements are:\n");
    while (temp != NULL)
    {
        printf("   %d", temp->data);
        temp = temp->next;
    }
}

// Inserting ELement at HEAD
void insertAtBegining(int val)
{
    struct Node *temp = getNewNode(val);
    temp->data = val;
    temp->next = NULL;
    if (head != NULL)
    {
        temp->next = head;
    }
    head = temp;
}

// Inserting Element at END
void insertAtEnd(int x)
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
    temp->next = newNode;
    newNode = head;
}

// Inserting an Element at a given position
void insertAt(int data, int n)
{
    if (countNode() < n)
    {
        printf("\n Can not insert at this position \n");
        return;
    }
    struct Node *temp1 = getNewNode(data);
    temp1->data = data;
    temp1->next = NULL;

    if (n == 1)
    {
        temp1->next = head;
        head = temp1;
        print();
        return;
    }

    struct Node *temp2 = head;
    for (int i = 0; i < n - 2; i++)
    {
        temp2 = temp2->next;
    }
    temp1->next = temp2->next;
    temp2->next = temp1;
    print();
}

// Deleting an Element at a Given Position
void deleteAt(int n)
{

    if (countNode() < n)
    {
        printf("\n Can not Delete at this position \n");
        return;
    }

    struct Node *temp1 = head;

    if (n == 1)
    {
        head = temp1->next;
        free(temp1);
        print();
        return;
    }

    for (int i = 0; i < n - 2; i++)
    {
        temp1 = temp1->next;
    }

    struct Node *temp2 = temp1->next;
    temp1->next = temp2->next;
    free(temp2);
    print();
}

// Delete a data present in LIST
void deleteData(int data)
{
    if (head == NULL)
    {
        printf("\n linked list empty");
    }
    else
    {
        struct Node *temp = head;
        struct Node *prev = NULL;
        while (temp != NULL && temp->data != data)
        {
            prev = temp;
            temp = temp->next;
        }
        if (temp == NULL)
        {
            printf("\n element not found");
        }
        else
        {
            if (prev == NULL)
            {
                head = temp->next;
            }
            else
            {
                prev->next = temp->next;
            }
            free(temp);
            print();
        }
    }
}

// Reverse the List Iteratively
void reverseListIteratively()
{
    struct Node *current, *prev, *NEXT;
    current = head;
    prev = NULL;

    while (current != NULL)
    {
        NEXT = current->next;
        current->next = prev;
        prev = current;
        current = NEXT;
    }
    head = prev;
    print();
}

// Reverse the List Recursively
void reverseListRecursively(struct Node *p)
{
    if (p->next == NULL)
    {
        head = p;
        return;
    }
    reverseListRecursively(p->next);
    struct Node *q = p->next;
    q->next = p;
    p->next = NULL;
}

// Print the elements in backward direction
void printReverse()
{
    struct Node *p = head;
    if (p == NULL)
        return;
    printReverse(p->next);
    printf("  %d", p->data);
}

void main()
{
    head = NULL;
    int i, n, x, choice;

    while (1)
    {
        printf("\n\n\n Linked List Operations ");
        printf("\n1. Insert at begining\n2. Insert at end\n3. Insert At a Position\n4. Delete At a position\n5. Delete Data\n6. Reverse the list Iteratively\n7. Reverse a List Recursively\n8. Reverse print the list\n9. Print Elements of the list\n10. Count Nodes\n11. Exit\n");
        printf("\nEnter Your Choice:");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("\n Enter how many elements you want to enter: ");
            scanf("%d", &n);

            for (i = 0; i < n; i++)
            {
                printf("\n Enter element you wnat to insert:");
                scanf("%d", &x);
                insertAtBegining(x);
                print();
            }
            break;

        case 2:
            printf("\n Enter how many elements you want to enter: ");
            scanf("%d", &n);

            for (i = 0; i < n; i++)
            {
                printf("\n Enter element you wnat to insert:");
                scanf("%d", &x);
                insertAtEnd(x);
                print();
            }
            break;

        case 3:
            printf("\n Enter element you want to insert:");
            scanf("%d", &x);
            printf("\n Enter the position:");
            scanf("%d", &n);
            insertAt(x, n);
            break;

        case 4:
            printf("\n Enter the position of the element you want to delete:");
            scanf("%d", &n);
            deleteAt(n);
            break;

        case 5:
            printf("\n Enter the  element you want to delete:");
            scanf("%d", &n);
            deleteData(n);
            break;

        case 6:
            reverseListIteratively();
            break;

        case 7:
            reverseListRecursively(head);
            break;

        case 8:
            printReverse();
            break;

        case 9:
            print();
            break;

        case 10:
            countNode();
            break;

        case 11:
            exit(0);
            break;

        default:
            printf("\n Inavlid Choice \n");
            break;
        }
    }
}
