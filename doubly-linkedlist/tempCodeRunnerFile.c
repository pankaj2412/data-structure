include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
    struct node *prev;
} * head, *last;

void createlistt(int n);
void displaylist();
void insertionatfront(int data);
void insertionatlast(int data);
void innsertionatpos(int data, int position);

int main()
{
    int data, n, choice = 1;
    head = NULL;
    last = NULL;

    while (choice != 0)
    {
        printf("----------------------------------\n");
        printf("DOUBLY LINKED LIST PROGRAM  \n");
        printf("-------------------------------------\n");
        printf("1. create linked list\n");
        printf("2.insert node at beginning");
        printf("3. insert at node specific position\n");
        printf("4. insert nmode at end\n");
        printf("5. display list\n");

        printf("enter your choice : ");
        scanf("%d\n", &choice);

        switch (choice)
        {
        case 1:
            printf("enter the number of nodes that you wanna enter in list");
            scanf("%d", &n);
            createlistt(n);
            break;

        case 2:
            printf("inert the data of node thta you want to insert : ");
            scanf("%d", &data);
            insertionatfront(data);
            break;

        case 3:
            printf("enter the position where you want to inwert the data");
            scanf("%d", &n);
            printf("enter the data that you want to insert in the list");
            scanf("%d", &data);

            innsertionatpos(data, n);
            break;

        case 4:
            printf("enter the data for the last node : ");
            scanf("%d", &data);

            insertionatlast(data);
            break;

        case 5:
            displaylist();
            break;

        default:
            printf("invalid choice ");
            break;
        }
    }
    return 0;
}

void createlistt(int n)
{
    int i, data;
    struct node *newnode;

    if (n < 1)
    {
        printf("sorry cant allocate memory\n");
    }
    else
    {
        head = (struct node *)malloc(sizeof(struct node));
        printf("enter the data of the first node : ");
        scanf("%d", &data);

        head->next = NULL;
        head->data = data;
        head->prev = NULL;
        last = head;

        for (i = 2; i <= n; i++)
        {
            newnode = (struct node *)malloc(sizeof(struct node));
            printf("enter the data of%d node: ", i);
            scanf("%d", &data);
            newnode->data = data;
            newnode->next = NULL;
            newnode->prev = last;

            last->next = newnode;
            last = last->next; // temp or last its work same to do travesing at last
        }
        printf("DOUBLY CREATED SUCESSFULLY\n");
    }
}

void insertionatfront(int data)
{
    struct node *newnode;
    if (head == NULL)
    {
        printf("the list is empty!!!!\n ");
    }
    else
    {
        newnode = (struct node *)malloc(sizeof(struct node));

        newnode->data = data;
        newnode->prev = NULL;

        newnode->next = head; // Point to next node which is currently head
        head->prev = newnode;
        head = newnode;

        printf("node inserted sucessfully \n");
    }
}

void insertionatlast(int data)
{
    struct node *newnode;
    if (last == NULL)
    {
        printf("lsit is empty\n");
    }
    else
    {
        newnode = (struct node *)malloc(sizeof(struct node));

        newnode->data = data;
        newnode->next = NULL;
        newnode->prev = last;

        last->next = newnode;
        last = newnode;

        printf("node inserted in last sucessfully \n");
    }
}
void innsertionatpos(int data, int position)
{
    int i;
    struct node *newnode, *temp;

    if (head == NULL)
    {
        printf("list is empty!!!\n");
    }
    else
    {
        temp = head;
        i = 1;
        while (i < position - 1 && temp != NULL)
        {
            temp = temp->next;
            i++;
        }
        if (position == 1)
        {
            insertionatfront(data);
        }
        else if (position == last)
        {
            insertionatlast(data);
        }
        else if (temp != NULL)
        {
            newnode = (struct node *)malloc(sizeof(struct node));

            newnode->data = data;
            newnode->next = temp->next;
            newnode->prev = temp;

            if (temp->next != NULL)
            {
                /* Connect n+1th node with new node */
                temp->next->prev = newnode;
            }
            /* Connect n-1th node with new node */
            temp->next = newnode;
            printf("NODE INSERTED SUCCESSFULLY AT %d POSITION\n", position);
        }
        else
        {
            printf("Error, Invalid position\n");
        }
    }
}

void displaylist()
{
    struct node *temp;
    int n = 1;

    if (head == NULL)
    {
        printf("List is empty.\n");
    }
    else
    {
        temp = head;
        printf("DATA IN THE LIST:\n");

        while (temp != NULL)
        {
            printf("DATA of %d node = %d\n", n, temp->data);

            n++;

            /* Move the current pointer to next node */
            temp = temp->next;
        }
    }
}