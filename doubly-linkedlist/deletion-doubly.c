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
void delete_at_front();
void delete_at_end();
void delete_at_any();

int main()
{
    int n, data, choice = 1;
    head = NULL;
    last = NULL;

    while (choice != 0)
    {
        printf("-----------------------------\n");
        printf("1.create list of n \n");
        printf("2.delete node at front \n");
        printf("3.delete node at end \n");
        printf("4.delete node at any \n");
        printf("5.display list\n ");
        printf("0. exit \n");
        printf("------------------------------\n");
        printf("enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("enter the size of node you want to create : ");
            scanf("%d", &n);
            createlist(n);
            break;

        case 2:
            delete_at_front();
            break;
        case 3:
            delete_at_end();
            break;
        case 4:
            printf("enter the psoition of node to delete: ");
            scanf("%d",&n);
            delete_at_any();
            break;
        case 5:
            display();
            break;

        case 0:
            break;
        default:
            printf("error invalid choice please ente in between range");
            break;
        }
        printf("\n\n\n\n");
    }

    return 0;
}

void createlist(int n)
{
    int data, i;
    struct node *newnode;

    if (n >= 1)
    {
        head = (struct node *)malloc(sizeof(struct node));
        printf("enter the data of first node: ");
        scanf("%d",& data);

        head->data = data;
        head->next = NULL;
        head->prev = NULL;

        last = head;

        for (i = 2; i <= n; i++)
        {
            newnode = (struct node *)malloc(sizeof(struct node));

            printf("enter the data %d node : ",i);
            scanf("%d", &data);

            newnode->data = data;
            newnode->next = NULL;
            newnode->prev = NULL;

            last->next = newnode; // newnode->prev=head try it
            last = newnode;
        }
        printf("DOUBLY LINKED LIST CREATED  SUCESS FULLY");
    }
}

void display()
{
    struct node *temp;
    int n = 1;

    if (head == NULL)
    {
        printf("list is empty\n");
    }
    else
    {
        temp = head;
        printf("THE DATA IN LIST: \n");

        while (temp != NULL)
        {
            printf("the of %d node is :%d \n", n, temp->data);
            n++;
            temp = temp->next;
        }
    }
}
void delete_at_front()
{
    struct node *front;

    if (head == NULL)
    {
        printf("list is empty: ");
    }
    else
    {
        front = head;
        head = head->next;

        if (head != NULL)
        {
            head->prev = NULL;
            free(front);
            printf("node deletetd sucessfully");
        }
    }
}
void delete_at_end()
{
    struct node *todelete; // to delete her work as the temp variable to which will free in the end

    if (last == NULL)
    {
        printf("list is empty");
    }
    else
    {
        todelete = last; // asigning hte value of the last in to delete function
        last = last->prev;

        if (last == NULL)
        {
            last->next = NULL;

            free(todelete);
            printf("the node deleted sucessfully");
        }
    }
}

void delete_at_any(int position)
{
    struct node *current;
    int i;
    current=head;

    for ( i = 1; i<position && current!=NULL; i++)  //loop for the traversal
    {
        current=current->next;
    }
    
    if (position ==1)
    {
        delete_at_front();
    }
    else if (current==last)
    {
        delete_at_end();
    }
    else if (current!=NULL)
    {
        current->prev->next=current->next;
        current->next->prev=current->prev;

        free(current);
        printf("delete node from position that you given");
    }
    else
    {
        printf("the given posiition is invalid");
    }

}