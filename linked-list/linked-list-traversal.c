#include<stdio.h>
#include<stdlib.h>

int main()
{
    struct node
    {
     int data;                     // data is basically part of the node having two part data & linked part.
     struct node *next;            //just like int *p pointer p which storing the address of the a variable whose data type is intiger.
    };

    struct node *head,*newnode,*temp;
    head =0;                           //head is pointer whose store value of a node or base adress of node.intially head doesn't contain any value so decalre as 0
    int choice;

    while (choice)
    {
       newnode = (struct node*)malloc(sizeof(struct node));

       printf("enter the data :");
       scanf("%d",&newnode->data);

       newnode->next=0;

       if (head==0)
       {
           head = temp =newnode;    // we wan t to store new node value in head which is 100 so simply wwrite head = new node means head storing new node value
        }
       else
       {
           temp->next = newnode;
           temp = newnode;
       }
       printf("do you wna to continue(0,1)?");
       scanf("%d",&choice);
     }
      temp = head;
      while (temp!=0)
      {
        printf(" %d",temp->data);
        temp = temp->next;
      }
      
    
  
    
}