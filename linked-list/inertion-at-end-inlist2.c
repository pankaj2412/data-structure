#include<stdio.h>
#include<stdlib.h>

void createlist(int n);
void insertedatend(int data);
void display();
struct node
{ 
    int data;
    struct node *next;
}*head;

void createlist(int n)
{
    struct node *newnode ,*temp;
    int data,i;

    head = (struct node*)malloc(sizeof(struct node));


    if (head==NULL)
    {
        printf("unable toallocate memory");

    }

  else
    {
      printf("enter the data in node 1 :");
     scanf("%d",&data);

     head->data=data;  //here data is adding into the data part of the node 
     head->next=NULL;   //linking is performing here link null into head

     temp=head;

     for ( i = 2; i <=n; i++)
        {
          newnode= (struct node*)malloc(sizeof(struct node));
          if (newnode==NULL)
            {
                printf("unable to allocate memory");
                break;

            }
            else
            {
                printf("enter the data of the node %d :",i);
                scanf("%d",&data);


                newnode->data=data;
                newnode->next=NULL;

                temp->next=newnode;  //linked the or storing adress writeen in newnode in temp which is storing the adres of any other node 
                temp=temp->next;    //updating temp now temp next adress
            }
        }
       printf("linked list created uscess fully");
    }  

}

void insertedatend(int data)
{
    struct node *temp,*newnode;
    newnode=(struct node*)malloc(sizeof(struct node));
      
    if (newnode==NULL)
    {
        printf("unable to allocate memrory");

    }
    else
    {
        newnode->data=data;
        newnode->next=NULL;
        

        temp=head;

        while (temp!=NULL && temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next=newnode;
        printf("the data INSERTED in linked list is sucessfull\n");
    }  
     
      
}


void display()
{
    struct node*temp;

    if (head==NULL)
    {           
        printf("the list is empty");

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
    int data,n;
    printf("enter the number of nodes : ");
    scanf("%d",&n);
    createlist(n);

    printf("\n the of list is gievn below\n");
    display();
 
    printf("enter the data that you want to insert inthe list :");
    scanf("%d",&data);  
    insertedatend(data);

    printf("the updated list is given below");
    display();


   return 0;


    

}