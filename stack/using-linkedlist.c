#include <stdlib.h>
#include <stdio.h>

struct node
{
    int data;
    struct node *next;
}; struct node *top = 0;

void push(int data);
void peek();
void display();
void pop();

int main()
{
    int choice, data;

    while (choice != 0)
    {
        /* Menu */
        printf("------------------------------------\n");
        printf("    STACK IMPLEMENTATION PROGRAM    \n");
        printf("------------------------------------\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3.display\n");
        printf("4.peek\n ");
        printf("5. Exit\n");
        printf("------------------------------------\n");
        printf("Enter your choice: ");

        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter data to push into stack: ");
            scanf("%d", &data);

            // Push element to stack
            push(data);
            break;

        case 2:
            pop();
            break;

        case 3:
            display();
            break;
        case 4:
            peek();
            break;

        case 5:
            printf("Exiting from app.\n");
            exit(0);
            break;

        default:
            printf("Invalid choice, please try again.\n");
        }

        printf("\n\n");
    }

    return 0;
}

void push(int data)
{
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));

    newnode->data = data;
    newnode->next = top;
    top = newnode;
}

void peek()
{
    if (top == NULL)
    {
        printf("stack is empty\n");
    }
    else
    {
        printf("the top element is %d : ", top->data);
    }
}

void pop()
{
    struct node *temp;
    temp = top;
    if (top == NULL)
    {
        printf("stack is empty\n");
    }
    else
    {
        printf("the pop element is : %d", top->data);
        top = temp->next;
        free(temp);
    }
}
void display()
{
    struct node *temp;
    temp = top;
    if (top == NULL)
    {
        printf("stack is empty\n");
    }
    else
    {
        printf("the element int stack\n ");
        while (temp != NULL)
        {
            printf("data=%d\n", temp->data);
            temp = temp->next;
        }
    }
}
