//input through user

#include<stdio.h>
#include<stdlib.h>

struct node 
{
    int data;
    struct node* next ;  //this is the node 2nd colum which is called next or link part

};

struct node* head; //global variable acess for anywhere

void Insert(int x)
{
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data = x;
    temp->next = head;
    head = temp;
}

void Print()
{
   struct node* temp = head;
   printf("the list is :");
   while (temp != NULL)
   {
       printf(" %d",temp->data);
       temp = temp->next;
    }
    printf("\n");
   
}
void Print();
int main()
{
    head = NULL; // list is empty asumming that starting head doesn't conatian any variable
    int n,x,i;
    printf(" how many number you want to enter in the node: ");
    scanf("%d",&n);

    for (i=0; i<n; i++)
    {
        printf("enter the data in node: \n");
        scanf("%d",&x);
        Insert(x);
        Print();
    }
   
    
}
