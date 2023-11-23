#include <stdio.h>
#include <stdlib.h>

struct node
{ // basic stucture of nodes
    int data;
    struct node *next;
    struct node *perv;
}*head, *last;

void createlist(int n); // function which we are using in program
void showfront();
void showend();

int main()
{

    int choice, n;

    head = NULL;
    last = NULL;

    printf("enter the number of nodes you want to create: ");
    scanf("%d", &n);
    createlist(n);

    printf("\nPress 1 to display list from First");
    printf("\nPress 2 to display list from End : ");
    scanf("%d", &choice);

    if (choice == 1)
    {
        showfront();
    }
    else if (choice == 2)
    {
        showend();
    }

    return 0;
}

void createlist(int n)
{
    int i,data;
    struct node *newnode;

    if (n >= 1)
    {
        head = (struct node *)malloc(sizeof(struct node));

        if (head != NULL)
        {
            printf("enter the data in node1 : ");
            scanf("%d", &data);

            head->data = data;
            head->next = NULL;
            head->perv = NULL;

            last = head;

            for (i = 2; i<=n; i++) 
            {
                newnode = (struct node *)malloc(sizeof(struct node));       // head node is fixed that why take newnode to allocat memory to each node

                if (newnode == NULL)
                {
                    printf("unable to allocate memory");
                    break;
                }
                else
                {
                    printf("enter the data of %d node : ", i);
                    scanf("%d", &data);

                    newnode->data = data; // it put data to innewnode
                    newnode->next = NULL; // no next node to link thats why put null
                    newnode->perv = last; // linked with previous node

                    last->next = newnode;
                    last = newnode; // make newnode as last
                }
            }
            // printf("\nDoubly linked list created sucessfully");
        }
        else
        {
            printf("unable to allocate memory");
        }
    }
}

void showfront()
{
    struct node *temp;
    int n = 1;
    if (head == NULL)
    {
        printf("list is empty");
    }
    else
    {
        temp = head;
        printf("\n data in the list \n");

        while (temp != NULL)
        {
            printf("\nData of %d node is= %d ", n, temp->data);
            n++;
            temp = temp->next;
        }
    }
}

void showend()
{
    struct node *temp;
    int n = 0;
    if (last == NULL)
    {
        printf("list is empty");
    }
    else
    {
        temp = last;
        printf("\n data in the list \n");

        while (temp != NULL)
        {
            printf("\nData of %d node is= %d ", n,temp->data);
            n++;
            temp = temp->perv;
        }
    }
}
