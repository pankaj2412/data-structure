#include <stdlib.h>
#include <stdio.h>

struct node
{
    int data;
    struct node *next;
} * head, *last;

void createlist(int n);
void display();
void delete_first();
void delete_last();
void delet_at_any(int pos);

int main()
{
    int n, pos, choice = 1;

    while (choice != 0)
    {
        printf("--------------------------------\n");
        printf("deletion in circular linked list\n");
        printf("-----------------------------------\n");
        printf("1.createlist\n");
        printf("2.display list\n");
        printf("3.delete first node\n");
        printf("4.delete at last\n");
        printf("5.delete at any\n");
        printf("0.exit\n");
        printf("enter the choice");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("enter the size of the list: ");
            scanf("%d", &n);
            createlist(n);
            break;

        case 2:
            display();
            break;
        case 3:
            delete_first();
            break;
        case 4:
            delete_last();
            break;
        case 5:
            printf("enter the position : ");
            scanf("%d", &pos);
            delet_at_any(pos);
            break;
        case 0:
            exit(0);
            break;

        default:
            printf("error enter b/w 0-3");
            break;
        }
        printf("\n\n\n\n");
    }
    return 0;
}
void createlist(int n)
{
    struct node *newnode;
    int i, data;

    if (n >= 1)
    {
        head = (struct node *)malloc(sizeof(struct node));
        printf("enter the data of first node : ");
        scanf("%d", &data);
        head->data = data;
        head->next = NULL;
        last = head;

        for (i = 2; i <= n; i++)
        {
            newnode = (struct node *)malloc(sizeof(struct node));
            printf("enter the data of the of the %d node : ", i);
            scanf("%d", &data);
            newnode->data = data; // assign the data in newnode
            newnode->next = NULL; // next adress of newnode set as null

            last->next = newnode; // linking previous node with newnode
            last = newnode;       // previous node is advanced
        }
        last->next = head; // last node linked with first nonde
    }
}
void delete_first()
{
    struct node *temp;
    temp = head;
    if (head == NULL)
    {
        printf("list is empty");
    }
    else
    {
        last->next = temp->next;
        head = temp->next;
        free(temp);
    }
}
void display()
{
    int n = 1;
    struct node *curr;
    if (head == NULL)
    {
        printf("list is empty");
    }
    else
    {
        curr = head;

        do
        {
            printf("data at %d node=%d\n", n, curr->data);
            n++;
            curr = curr->next;
        } while (curr != head);
    }
}
void delete_last()
{
    struct node *preivous, *current;

    current = last->next;
    if (last == NULL)
    {
        printf("the list is empty");
    }
    else if (current->next == current)
    {
        last = 0;
        free(current);
    }
    else
    {
        while (current->next != last->next)
        {
            preivous = current;
            current = current->next;
        }
        preivous->next = last->next;
        last = preivous;
        free(current);
    }
}
void delet_at_any(int pos)
{
    int i = 1;
    struct node *current, *temp;
    current = last->next;
    
    if (pos < 1)
    {
        printf("invalid position");
    }
    else if (pos == 1)
    {
        delete_first();
    }
    else if (current == last)
    {
        delete_last();
    }
    else
    {
        while (i < pos-1)
        {
            current = current->next;
            i++;
        }
        temp = current->next;

        current->next = temp->next;
        free(temp);
    }
}