#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
} * head;

void createlist(int n);
void display();

int main()
{
    int n, choice = 1;
    head = NULL;

    while (choice != 0)
    {
        printf("----------------------------------\n");
        printf("DOUBLY LINKED LIST PROGRAM  \n");
        printf("-------------------------------------\n");
        printf("1. create linked list\n");
        printf("2. display list\n");
        printf("0. exist\n");
        printf("enter your choice : ");

        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("enter the number of nodes that you wanna enter in list:");
            scanf("%d", &n);

            createlist(n);
            break;
        case 2:
            display();
            break;
        case 0:
            break;

        default:
            printf("invalid choice ");
            break;
        }
        printf("\n\n\n");
    }
}

void createlist(int n)
{
    int data, i;
    struct node *newnode, *temp;

    head = (struct node *)malloc(sizeof(struct node));

    if (n < 1)
    {
        printf("unable to alocate memory");
    }
    else
    {
        printf("ente the data of node 1 : ");
        scanf("%d", &data);
        head->data = data;
        head->next = NULL;
        temp = head;

        for (i = 2; i <= n; i++)
        {
            newnode = (struct node *)malloc(sizeof(struct node));
            if (newnode == NULL)
            {
                printf("unable to allocate memory");
                break;
            }
            else
            {
                printf("enter the data of the %d node : ", i);
                scanf("%d", &data);
                newnode->data = data;
                newnode->next = NULL;

                temp->next = newnode; // linked the previous node with newnode
                temp = newnode;
            }
            temp->next = head;
        }

        printf("lsit created sucessfully");
    }
}

void display()
{
    struct node *current;
    int n = 1;

    if (head == NULL)
    {
        printf("List is empty.\n");
    }
    else
    {
        current = head;
        printf("DATA IN THE LIST:\n");

        do
        {
            printf("Data %d = %d\n", n, current->data);

            current = current->next;
            n++;
        } while (current != head);
    }
}
