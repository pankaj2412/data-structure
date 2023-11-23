#include <stdio.h>
#define N 5
int queue[N];
int front = -1;
int rear = -1;

void enqueue(int data)
{
    if (front == -1 && rear == -1)
    {
        front = rear = 0;
        queue[rear] = data;
    }
    else if ((rear + 1) % N == front)
    {
        printf("queue is full\n ");
    }
    else
    {
        rear = (rear + 1) % N;
        queue[rear] = data;
    }
}
void dequeue()
{
    if (front == -1 && rear == -1)
    {
        printf("queue is empty\n");
    }
    else if (front == rear)
    {
        front = rear = -1;
    }
    else
    {
        printf("the dequeued element is: %d", queue[front]);
        front = (front + 1) % N;
    }
}
void display()
{
    int i = front;
    if (front == -1 && rear == -1)
    {
        printf("queue is empty");
    }
    else
    {
        printf("queue is");
        while (i != rear)
        {
            printf("%d\n", queue[i]);
            i = (i + 1) % N;
        }
        printf("%d", queue[rear]);
    }
}
void peek()   
{
    if (front == -1 && rear == -1)
    {
        printf("list is empty\n");
    }
    else
    {
        printf("the %d is : ",queue[front]);
    }
}
int main()
{
    int ch, data;
    while (1)
    {
        /* Queue menu */
        printf("--------------------------------------\n");
        printf("  QUEUE ARRAY IMPLEMENTATION PROGRAM  \n");
        printf("--------------------------------------\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. peek\n");
        printf("4. display\n");
        printf("0. Exit\n");
        printf("--------------------------------------\n");
        printf("Select an option: ");

        scanf("%d", &ch);

        /* Menu control switch */
        switch (ch)
        {
        case 1:

            printf("\nEnter data to enqueue: ");
            scanf("%d", &data);
            enqueue(data);
            break;

        case 2:
            dequeue();
            break;

        case 3:
            peek();
            break;

        case 4:
            display();
            break;

        case 0:
            printf("Exiting from app.\n");
            break;

        default:
            printf("Invalid choice, please input number between (0-5).");
            break;
        }

        printf("\n\n");
    }
}