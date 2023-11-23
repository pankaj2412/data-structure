#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
} ;
struct node *front = 0;
struct node *rear = 0;
void enqueue(int data);
void dequeue();
void display();
void peek();

void enqueue(int data)
{
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));

    newnode->data = data;
    newnode->next = 0;

    if (front == 0 && rear == 0)
    {
        front = rear = newnode;
    }
    else
    {
        rear->next = newnode;
        rear = newnode;
    }
}

void display()
{
    struct node *temp;
    if (front == 0 && rear == 0)
    {
        printf("list is empty\n");
    }
    else
    {
        temp = front;
        while (temp != 0)
        {
            printf("the data is %d\n: ", temp->data);
            temp = temp->next;
        }
    }
}
void dequeue()
{
    struct node *temp;
    temp = front;
    if(front == 0 && rear == 0)
    {
        printf("the list id empty\n");
    }
    else
    {
        printf("the deleted element is%d: ", front->data);
        front = front->next;
        free(front);
    }
}
void peek()
{
    if(front==0 && rear==0)
    {
       printf("queue is empty\n");
    }
    else
    {
        printf("the data at top%d : ",front->data);
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