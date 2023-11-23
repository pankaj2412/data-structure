#include <stdlib.h>
#include <stdio.h>

struct node {
    int data;          // Data 
    struct node *next; // Address 
}*head;
void createlist(int n);
void insertnodeatend(int data);
void displaylist();



int main()
{
    int n, data;

    /*
     * Create a singly linked list of n nodes
     */
    printf("Enter the total number of nodes:");
    scanf("%d",&n);
    createlist(n);

    printf("\nData in the list \n");
    displaylist();

    /*
     * Insert data at the end of the singly linked list
     */
    printf("\nEnter data to insert at end of the list: ");
    scanf("%d", &data);
    insertnodeatend(data);

    printf("\nData in the list \n");
    displaylist();

    return 0;
}


/* to create linked list through user data */
//trversing 
void createlist(int n)
{
    struct node *newnode,*temp;
    int data,i;

    head= (struct node*)malloc(sizeof(struct node));  //base node that header is able to point it

    if (head==NULL)
    {
       printf("unable to allocate memory");
    }
    else
    {
        printf("enter the data of node 1");
        scanf("%d",&data);

        head->data= data;
        head->next= NULL;
        temp = head;


        for (i=2 ; i<=n ; i++)
        {
           newnode= (struct node*)malloc(sizeof(struct node));   //to allocate memory to adding more no of node in list
           if (newnode==NULL)
           {
               printf("unable to allocate memory");
               break;
           }
           else
           {
             printf("ennter the data in node %d",i);
             scanf("%d",&data);

             newnode->data=data;
             newnode->next=NULL;    //till now node is not linked witj any nextnode

             temp->next=newnode;   //here 200 is value of new node which assign in temp->next temp me 100 add us node ke next me null ki jagah 200 aa jayega aur link hojayegi
             temp= temp->next;    //here we are traversing temp through temp in linked list
            }
           
        }
        
       printf("linked list created sucessfully");

    }
    
}
void insertnodeatend(int data)
{
   struct node *newnode ,*temp;

  newnode= (struct node*)malloc(sizeof(struct node));

  if (newnode == NULL)
   {
      printf("unable to alocat memeory");
    }
  else
   {
      newnode->data=data;
      newnode->next=NULL;

      temp= head;

      while (temp!=NULL && temp->next!=NULL)
       {
          temp=temp->next;
          temp->next=newnode;
          

        }
      
    }
  
}
void displaylist()
{
    struct node *temp;

    /*
     * If the list is empty i.e. head = NULL
     */
    if(head == NULL)
    {
        printf("List is empty.");
    }
    else
    {
        temp = head;
        while(temp != NULL)
        {
            printf("Data = %d\n", temp->data); // Print data of current node
            temp = temp->next;                 // Move to next node
        }
    }
}