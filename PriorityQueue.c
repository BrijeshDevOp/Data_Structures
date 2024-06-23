#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
int isEmpty();
int isFull();
int getHighestPriority();
int deleteHighestPriority();
void insert(int, int);
void display();
struct priorityQueue
{
    int ele;
    int priority;
} pq[5];

int rear = -1;

void main()
{
    int choice, data, priority;

    do
    {
        printf("\n 1.insert\t2.Show Highest Priority\t3.Display\t4.Delete Highest Priority\t5.Exit\nEnter choice:");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            if (isFull())
            {
                printf("\n Queue is Full");
            }
            else
            {
                printf("\n Enter data:");
                scanf("%d", &data);
                printf("\n Enter priority:");
                scanf("%d", &priority);
                insert(data, priority);
                display();
            }
            break;

        case 2:
            printf("\n Highest priority %d", getHighestPriority());
            break;

        case 3:
            display();
            break;

        case 4:
            if (isEmpty())
            {
                printf("\n Queue is Empty\n");
            }
            else
            {
                deleteHighestPriority();
                display();
            }
            break;

        case 5:
            exit(0);
            break;

        default:
            printf("\n INVALID CHOICE!!!");
        }
    } while (1);
}

int isEmpty()
{
    if (rear == -1)
        return 1;
    else
        return 0;
}

int isFull()
{
    if (rear == 4)
        return 1;
    else
        return 0;
}

void insert(int ele, int p)
{
    rear = rear + 1;
    pq[rear].ele = ele;
    pq[rear].priority = p;
}

int getHighestPriority()
{
    int i, p = -1;
    if (!isEmpty())
    {
        for (int i = 0; i <= rear; i++)
        {
            /* code */
            if (pq[i].priority > p)
                p = pq[i].priority;
        }
    }
    return p;
}

int deleteHighestPriority()
{
    int i, j, p, ele;
    p = getHighestPriority();
    for (i = 0; i <= rear; i++)
    {
        if (pq[i].priority == p)
        {
            ele = pq[i].ele;
            break;
        }
    }

    if (i < rear)
    {
        for (j = 1; j < rear; j++)
        {
            pq[j].ele = pq[j + 1].ele;
            pq[j].priority = pq[j + 1].priority;
        }
    }

    rear = rear - 1;
}

void display()
{
    int i;
    printf("\n Priority  Element ");
    for (i = 0; i <= rear; i++)
    {
        printf("\n\t%d\t%d", pq[i].priority, pq[i].ele);
    }
}
