#include <stdio.h>
#define N 5

int queue[N];
int front = -1;
int rear = -1;

void enqueue(int x);
void dequeue();
void display();
void peek();

int main()
{
    int ch,x;
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
                scanf("%d", &x);
                enqueue(x);
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

void enqueue(int x)
{
    if (rear == N - 1)
    {
        printf("overflow condition");
    }
    else if (rear == -1 && front == -1)
    {
        front = rear = 0;
        queue[rear] = x;
    }
    else
    {
        rear++;
        queue[rear] = x;
    }
}
void dequeue()
{
    if (front == -1 && rear == -1)
    {
        printf("the list is empty\n");
    }
    else if (front == rear)
    {
        front = rear = -1;
    }
    else
    {
        printf("the deleted data of the queue is %d: ", queue[front]);
        front++;
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
        printf("the %d is : ", queue[front]);
    }
}
void display()
{
    int i;
    if (front == -1 && rear == -1)
    {
        printf("list is empty\n");
    }
    else
    {
        

        for (i = front; i<rear+1; i++)
        {
            printf("the data %d: \n", queue[i]);
        }
    }
}