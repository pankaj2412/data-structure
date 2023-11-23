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
void reverse();

int main()
{
    int n, data, choice=1;
    head = NULL;
    last = NULL;

    while (choice != 0)
    {
        printf("------------------------------------\n");
        printf("REVERSE OF DOUBLY LINKRD LIST PROGRAM\n");
        printf("------------------------------------\n");
        printf("1.create list\n");
        printf("2.reverse list\n");
        printf("1.display list\n");

        switch (choice)
        {
        case 1:
            printf("enter the total number of nodes in the list");
            scanf("%d", &n);
            createlist(n);
            break;
        case 2:
            reverse();
            break;
        case 3:
            display();
            break;
        case 0:
            break;
        default:
            printf("error please enter valid choice");
            break;
        }
        printf("\n\n\n\n\n");
    }
    return 0;
}

void createlist(int n)
{
    int data, i;
    struct node *newnode;

    if (head == NULL)
    {
        printf("list is empty");
    }
    else
    {
        newnode = (struct node *)malloc(sizeof(struct node));

        printf("enter the data of first node : ");
        scanf("%d", &data);

        head->data = data;
        head->prev = NULL;
        head->next = NULL;
        last = head;

        for (i = 2; i <= n; i++)
        {
            newnode = (struct node *)malloc(sizeof(struct node));
            printf("enter the data %d node : ", i);
            scanf("%d", &data);

            newnode->data = data;
            newnode->next = NULL;
            newnode->prev = NULL;

            last->next = newnode;
            last = newnode;
        }
        printf("DOUBLY LINKED LIST CREATED SUCESSFULLY");
    }
}

void reverse()
{
    struct node *current, *nextnode;
    current = head;

    while (current != NULL)
    {
        nextnode = current->next;
        current->next = current->prev;
        current->prev = nextnode;

        current = nextnode;
    }
    nextnode = head;
    head = last;
    last = nextnode;
    printf("revrse the linked list is sucessfully");
}
void display()
{
    struct node * temp;
    int n = 1;

    if(head == NULL)
    {
        printf("List is empty.\n");
    }
    else
    {
        temp = head;
        printf("DATA IN THE LIST:\n");

        while(temp != NULL)
        {
            printf("DATA of %d node = %d\n", n, temp->data);

            n++;

            /* Move pointer to next node */
            temp = temp->next;
        }
    }
}