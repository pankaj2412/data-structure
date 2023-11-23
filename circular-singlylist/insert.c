#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
}*head, *last;

void createlist(int n);
void display();
void insert_front(int data);
void insert_end(int data);
void insert_at_any(int position, int data);

int main()
{
    int n, data, position, choice = 1;
    head = NULL;
    last = NULL;

    while (choice != 0)
    {
        printf("-----------------------\n");
        printf("CIRCULAR SINGLY LIST\n ");
        printf("-----------------------\n");
        printf("1.create list\n");
        printf("2.insert at begnning\n");
        printf("3.insert at end\n");
        printf("4.insert at any\n");
        printf("5.displaylist\n");
        printf("0. exist\n");

        printf("enter your choice : ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("enter the size of the node : ");
            scanf("%d", &n);
            createlist(n);
            break;
        case 2:
            insert_front(data);
            break;
        case 3:
            insert_end(data);
            break;
        case 4:
            
            printf("enter the position: ");
            scanf("%d", &position);
            printf("enter the data for that position");
            scanf("%d", &data);
            insert_at_any(data,position);

            break;
        case 5:
            display();
            break;
        case 0:
            break;
        default:
            printf("invalid choice ");
            break;
        }
    }
}
void createlist(int n)
{
    int i, data;
    struct node *newnode;

    if (n >= 1)
    {
        head = (struct node *)malloc(sizeof(struct node));
        printf("enter the data of first node : ");
        scanf("%d", &data);

        head->data = data;
        head->next = NULL;
        last = head;

        for (i = 2; i<=n; i++)
        {
            newnode = (struct node *)malloc(sizeof(struct node));
            printf("enter the data of the %d node : ", i);
            scanf("%d", &data);

            newnode->data = data;
            newnode->next = NULL;

            last->next = newnode;
            last = newnode;
            
        }
        printf("enter data is sucessfully and created list sucessfully\n");
    }
}
void insert_front(int data)
{
    struct node *newnode;

    if (head == NULL)
    {
        printf("the list is empty");
    }
    else
    {
        newnode = (struct node *)malloc(sizeof(struct node));
        printf("enter the data of the first node  : ");
        scanf("%d", &data);

        newnode->data = data;
        newnode->next = head;
        head = newnode;
        printf("list inserted sucessfully");
    }
}
void insert_end(int data)
{
    struct node *newnode;
    if (last == NULL)
    {
        printf("list is empty");
    }
    else
    {
        newnode = (struct node *)malloc(sizeof(struct node));
        printf("enter the data of last node");
        scanf("%d", &data);

        newnode->data = data;
        newnode->next = head;

        last->next = newnode;
        last = newnode;
    }
}
void insert_at_any(data, position)
{
    struct node *newnode, *temp;
    int i;
    if (head == NULL)
    {
        printf("the list is empty\n");
    }
    else if (position == 1)
    {
        insert_front(data);
    }
    else
    {
        newnode = (struct node *)malloc(sizeof(struct node));
        newnode->data = data;
        newnode->next=NULL;
        temp = head;

        for (i = 2; i <= position-1; i++)
        {
            temp= temp->next;
        }
        newnode->next = temp->next;
        temp->next = newnode;

        printf("NODE INSERTED SUCCESSFULLY.\n");
    }
}
void display()
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
