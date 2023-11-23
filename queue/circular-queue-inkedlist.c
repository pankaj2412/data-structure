#include <stdlib.h>
#include <stdio.h>

void enqueue(int data);
void dequeue();
void peek();
void display();

struct node
{
    int data;
    struct node *next;
};
struct node *front = 0;
struct node *rear = 0;

void enqueue(int data)
{
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->next = 0;
    if (rear == 0)
    {
        front = rear = newnode;
        rear->next = front;
    }
    else
    {
        rear->next = newnode;
        rear = newnode;
        rear->next = front;
    }
}
void dequeue()
{
    struct node *temp;
    temp=front;
    if (front == 0 && rear == 0)
    {
        printf("queue is empty");
    }
    else if (front == rear)
    {
        front = rear = 0;
        free(temp);
    }
    else
    {
        front = front->next;
        rear->next = front;
        free(temp);
    }
}
void display()
{
    struct node *temp;
    temp = front;
    if (front == 0 && rear == 0)
    {
        printf("list is empty");
    }
    else
    {
        printf("the data in quese is \n");
        while (temp->next != front)
        {
            printf("data=%d\n", temp->data);
            temp = temp->next;
        }
        printf("data=%d\n", temp->data);
    }
}
void peek()
{
    if (front == 0 && rear == 0)
    {
        printf("queue is empty\n");
    }
    else
    {
        printf("%d\n",front->data);
    }
    
}
int main()
{
    int ch,data;
     while (1)
    {
        /* Queue menu */
        printf("--------------------------------------\n");
        printf("  QUEUE linked list IMPLEMENTATION PROGRAM  \n");
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