#include<stdio.h>
#include<stdlib.h>

void inert_at_specific(int data, int psoition);
void createlist(int n);
void display();

struct node {
    int data;
    struct node *next;
}*head;

void createlist(int n)
{
    int data,i;
    struct node *newnode ,*temp;

    head=(struct node*)malloc(sizeof(struct node));

   if (head==NULL)
    {
       printf("unable to provide memory");
    }

   else
    {
        printf("enter the dat ain node 1 : ");
        scanf("%d",&data);
        
        head->data=data;
        head->next=NULL;

        temp=head;

        for ( i=2; i<=n; i++)
        {
           newnode=(struct node*)malloc(sizeof(struct node));

           if (newnode==NULL)
           {
               printf("unable to allocate memory");
               break;
           }
           else
           {
               printf("enter the data of node %d: ",i);
               scanf("%d",&data);

               newnode->data=data;
               newnode->next=NULL;

               temp->next=newnode;
               temp=temp->next;
           }
           
        }
        printf("linked list created sucesfully");
        

    }
}

void inert_at_specific(int data, int position)
{
    int i;
    struct node *newnode,*temp;

    newnode=(struct node*)malloc(sizeof(struct node));

    if (newnode==NULL)
    {
        printf("unable to allocate memory");

    }
    

    else
    {
       newnode->data=data;
       newnode->next=NULL;

       temp=head;
       
       for ( i = 2; i<=position-1; i++)       //2<=3-1 satisfies cond.
        {
           temp = temp->next;         //temp=200

           if(temp==NULL)
           {
              printf("inavalid position");
              break;            //temp=200 now 
           }
        }   
        if (temp!=NULL)       //temp=200 != null
        {
           newnode->next= temp->next;     /* Link address part of new node */


           temp->next=newnode;   /* Link address part of n-1 node */
            printf("DATA INSERTED SUCCESSFULLY\n");
        }
        else
        {
            printf(" unable to isnert data");
        }
           
           

       
       
       

    }

}

void display()
{
    struct  node *temp;

    if (temp==NULL)
    {
        printf("the list is empty");

    }
    else
    {
        temp=head;
        while (temp!=NULL)
        {
            printf("data=%d\n",temp->data);
            temp= temp->next;
        }
        
    }
}

int main()
{
    int  data, position, n;

    printf("Enter the total number of nodes: ");
    scanf("%d", &n);
    createlist(n);

    printf("\nData in the list \n");
    display();


    printf("enetr the position where you want to insert the data : ");
    scanf("%d",&position);
    printf("enter the data of node you want to insert: ");
    scanf("%d",&data);
    inert_at_specific(data, position);



    printf("\nData in the list \n");
    display();

    return 0;

}