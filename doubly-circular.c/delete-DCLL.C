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
void delete_beg();
void delete_end();
void delete_any(int position);

int main()
{
    head = NULL;
    int n,position,choice=1;
    while (choice!=0)
    {
        printf("=======================================\n");
        printf("deletion ninthe DCLL\n");
        printf("==========================================\n");
        printf("1.createlist\n");
        printf("2.delete at begnning\n");
        printf("3.delete at end\n");
        printf("4.delet at specific position\n");
        printf("5.display\n");
        printf("0.exist\n");

        printf("enter your choice :");
        scanf("%d",&choice);

        switch (choice)
        {
        case 1:
            printf("enter the size of list : ");
            scanf("%d",&n);
            createlist(n);
            break;
        case 2:
            delete_beg();
            break;
        case 3:
            delete_end();
            break;
        case 4:
            printf("enter the position: ");
            scanf("%d",&position);   
            delete_any(position);
            break;
        case 5:
            display();
            break; 
        case 0:
            
            break;            
        
        default:
            printf("error enter valid number\n");
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
        printf("enter the data for the first node : ");
        scanf("%d", &data);

        head->data = data;
        head->next = head;
        head->prev = head;
        last = head;

        for (i = 2; i <= n; i++)
        {
            newnode = (struct node *)malloc(sizeof(struct node));
            printf("enter the data of the %d node : ", i);
            scanf("%d", &data);
            newnode->data = data;

            newnode->next = head;
            newnode->prev = last;

            last->next = newnode;
            head->prev = newnode;
            last = newnode;
        }
    }
    else
    {
        printf("enter the vlid number!!!!\n");
    }
}
void display()
{
    int n = 1;
    struct node *temp;
    temp = head;
    if (head == NULL)
    {
        printf("the list is empty");
    }
    else
    {
        printf("the is int list is given below");
        do
        {
            printf("the data at %d= %d\n", n, temp->data);
            temp = temp->next;
            n++;
        } while (temp != head);
    }
}
void delete_beg()
{
    struct node *temp;
    temp = head;
    if (head == NULL)
    {
        printf("list is empty");
    }
    else if (head->next == head)
    {
        head = last = 0;
        free(temp);
    }
    else
    {
        head = head->next;
        head->prev = last;
        last->next = head;
        free(temp);
    }
}
void delete_end()
{
    struct node *end;
    end = last;
    if (head == NULL)
    {
        printf("list is empty");
    }
    else if (last->next == last)
    {
        last = head = 0;
        free(end);
    }
    else
    {
        last = last->prev;
        last->next = head;
        head->prev = last;
        free(end);
    }
}
void delete_any(int position)
{
    struct node *temp;
    int i;
    temp=head;

    if(position<1)
    {
        printf("invalid psotion");

    }
    else if(position==1)
    {
        delete_beg();
    }
    else
    {
        while (i<position)
        {
            temp=temp->next;
            i++;
        }
        temp->prev->next=temp->next;
        temp->next->prev=temp->prev;
        
        if (temp->next==head)
        {
            last=temp->prev;
            free(temp);
        }
        else
        {
           free(temp);
        }
        
    }
    
    
}