#include <stdio.h>
#include <stdlib.h>
#define size 100

int stack[size];
int top = -1;

void push(int data);
void pop();
void display();

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
        printf("4. Exit\n");
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
    if (top >= size)
    {
        printf("stack is overflow unable to add more element\n");
        return;
    }
    else
    {
        top++;
        stack[top] = data;
        printf("data pushed sucessfully\n");
    }
}
void pop()
{
    if (top < 0)
    {
        printf("underflow condtion\n");
    }
    else
    {
        printf("the popped element is %d", stack[top]);
        top--;
    }
}
void display()
{
    int i;
    if (top >= 0)
    {
        printf("the elment in stack is\n");
        for (i = top; i >= 0; i--)
        {
            printf("\n%d", stack[i]);
            //printf("\npress next choice\n");
        }
    }
    else
    {
        printf("the stack is empty\n");
    }
}