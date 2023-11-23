#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
    struct node *prev;
} * head, *last;

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
void createlist(n)
{
    int data, i;
    struct node *newnode;

    if (n >= 1)
    {
        head = (struct node *)malloc(sizeof(struct node));
        printf("enter the data of the first node : ");
        scanf("%d", &data);

        head->data = data;
        head->next = head;
        head->prev = head;
        last = head;

        for (i = 2; i <= n; i++)
        {
            newnode = (struct node *)malloc(sizeof(struct node));
            if (newnode == NULL)
            {
                printf("unable to laoocate memory");
            }
            else
            {
                printf("enter the data in %d node : ", i);
                scanf("%d", &data);
                newnode->data = data;
                newnode->prev = last;
                newnode->next = NULL;

                last->next = newnode;
                last = newnode;
            }
            last->next = head;
        }
    }
    else
    {
        printf("unable to aloocate memory ");
    }
}
void display()
{
    struct node *temp;
    int n = 1;
    temp = head;
    if (head == NULL)
    {
        printf("list is empty");
    }
    else
    {

        printf("the data in the list \n ");

        do
        {
            printf("data at %d is =%d\n ", n, temp->data);
            temp = temp->next;
            n++;
        } while (temp != head);
    }
}