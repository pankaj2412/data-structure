#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *prev;
    struct node *next;
} * head, *last;

void createlist(int n);
void display();
void insert_at_beg(int data);
void insert_at_end(int data);
void insert_at_any(int position, int data);

int main()
{
    head = NULL;
    int n, data, position, choice = 1;

    while (choice != 0)
    {
        printf("--------------------------------\n");
        printf("INSERTION IN DCLL\n");
        printf("--------------------------------\n");
        printf("1.createlist\n");
        printf("2.insert at beginning\n");
        printf("3.insert at end\n");
        printf("4.insert at any\n");
        printf("5.display\n");
        printf("0.exist\n");

        printf("enter the choice : ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("enter the size of the list : ");
            scanf("%d", &n);
            createlist(n);
            break;

        case 2:

            insert_at_beg(data);
            break;

        case 3:
            insert_at_end(data);
            break;

        case 4:
            printf("enter the position of data : ");
            scanf("%d", &position);
            printf("enter the data : ");
            scanf("%d", &data);
            insert_at_any(position, data);
            break;

        case 5:
            display();
            break;
        case 0:
            break;
        default:
            printf("nvalid position");
            break;
        }
        printf("\n\n\n");
    }
}

void createlist(int n)
{
    int data, i;
    struct node *newnode;

    if (n >= 1)
    {
        head = (struct node *)malloc(sizeof(struct node));
        printf("enter the data of the first node: ");
        scanf("%d", &data);
        head->data = data;
        head->next = head;
        head->prev = head;
        last = head;

        for (i = 2; i <= n; i++)
        {
            newnode = (struct node *)malloc(sizeof(struct node));
            printf("enter the data of %d node : ", i);
            scanf("%d", &data);
            newnode->data = data;

            last->next = newnode; // linked previous node with newnode
            newnode->prev = last; // linked newnode with previous node

            newnode->next = head;
            head->prev = newnode;
            last = newnode;
        }
    }
    else
    {
        printf("invlid value");
    }
}
void insert_at_beg(int data)
{
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("enter the data : ");
    scanf("%d", &data);
    newnode->data = data;

    newnode->next = head;
    head->prev = newnode;

    newnode->prev = last;
    last->next = newnode;
    head = newnode;
}
void insert_at_end(int data)
{
    struct node *newnode;

    newnode = (struct node *)malloc(sizeof(struct node));
    printf("enter the for last node: ");
    scanf("%d", &data);
    newnode->data = data;

    newnode->next = head;
    newnode->prev = last;
    last->next = newnode;
    head->prev = newnode;
    last = newnode;
}
void insert_at_any(int position, int data)
{
    struct node *temp, *newnode;
    int i;
    temp = head;
    if (temp == NULL)
    {
        printf("list is empty");
    }
    else
    {
        i = 1;
        while (i < position - 1)
        {
            temp = temp->next;
            i++;
        }
        if (position == 1)
        {
            insert_at_beg(data);
        }
        else
        {
            newnode = (struct node *)malloc(sizeof(struct node));
            newnode->data = data;

            newnode->prev = temp;
            newnode->next = temp->next;
            temp->next->prev = newnode;
            temp->next = newnode;
        }
    }
}
void display()
{
    struct node *temp;
    int n = 1;
    temp = head;
    if (head == NULL)
    {
        printf("thelist is empty");
    }
    else
    {
        printf("the data in the list \n");
        do
        {
            printf("the data at %d is =%d\n", n, temp->data);
            temp = temp->next;
            n++;
        } while (temp != head);
    }
}