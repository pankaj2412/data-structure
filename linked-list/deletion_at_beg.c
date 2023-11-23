#include <stdio.h>
#include <stdlib.h>

void createlist(int n);
void delete_at_beg();
void display();

struct node
{
    int data;
    struct node *next;
}*head;

void createlist(int n)
{
    int data, i;
    struct node *temp,*newnode;

    head = (struct node*)malloc(sizeof(struct node));

    if (head == NULL)
    {
        printf("unable to allocate memroy");
    }
    else
    {
        printf("enter the dat in node 1 :");
        scanf("%d", &data);

        head->data = data;
        head->next = NULL;

        temp = head;

        for (i = 2; i <= n; i++)
        {
            newnode = (struct node*)malloc(sizeof(struct node));

            if (newnode == NULL)
            {
                printf("unable to allocate memory");
                break;
            }
            else
            {
                printf("enter the data of %d node :", i);
                scanf("%d", &data);
                newnode->data = data;
                newnode->next = NULL;

                temp->next = newnode;
                temp = temp->next;
            }
        }
        printf("SINGLY LINKED LIST CREATED SUCCESSFULLY\n");
    }
}

void delete_at_beg()
{
    struct node *temp;

    if (head == NULL)
    {
        printf("the list is empty");
    }
    else
    {
        temp = head;       // temp contain same adress as the head contain
        head = head->next; // now head ia pointing next of head

        printf(" deleted =%d", temp->data);

        free(temp);

        printf("data deleted sucessfully");
    }
}

void display()
{
    struct node *temp;

    if (head==NULL)
    {
        printf("list is empty");
    }
    else
    {

        temp=head;
        while (temp!=NULL)
        {
            printf("data=%d\n",temp->data);
            temp=temp->next;
        }
        

    }
    
}

int main()
{
    int n, choice;

    /*
     * Create a singly linked list of n nodes
     */
    printf("Enter the total number of nodes: ");
    scanf("%d", &n);
    createlist(n);

    printf("\nData in the list \n");
    display();

    printf("\nPress 1 to delete first node: ");
    scanf("%d", &choice);

    /* Delete first node from list */
    if (choice == 1)
    {
        delete_at_beg();
    }

    printf("\nData in the list \n");
    display();

    return 0;
}