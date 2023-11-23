#include<stdio.h>
#include<stdlib.h>

void createlist(int n);
void display();
void del_at_end();

struct node{
    int data;
    struct node *next;
}*head;

void createlsit(int n)
{
    struct node *temp,*newnode;
    int data,i;

    head= (struct node*)malloc(sizeof(struct node));

    if (head==NULL)
    {
        printf("unable to allocate memory");
    }
    else
    {
        printf("enter the node 1 data: ");
        scanf("%d",&data);

        head->data=data;
        head->next=NULL;

        temp=head;

        for ( i = ; i <=n; i++)
        {
            if (newnode==NULL)
            {
                printf("unable to allcoate memory");
                break;
            }
            else
            {
                newnode=(struct node*)malloc(sizeof(struct node));
                printf("enter the data of node %d : ",i);
                scanf("%d",&data);

                newnode->data=data;
                newnode->next=NULL;

                temp->next=newnode;
                temp=temp->next;

            }
            
        }
        printf("LINKD LIST CREATED SUCESSFULLY\n");
        
    }
    
}

void del_at_end()
{
    struct node *temp, *lastnode;

    if (head==NULL)
    {
        printf("list is empty");
    }
    else
    {
        temp=head;
        lastnode=head;

        while (temp->next!=NULL)
        {
            lastnode=temp;
            temp=temp->next;
        }
        
    }
