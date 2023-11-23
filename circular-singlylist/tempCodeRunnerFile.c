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
// void delete_last();
// void delet_at_any(int pos);

int main()
{
    int n, choice = 1;

    while (choice != 0)
    {
        printf("--------------------------------\n");
        printf("deletion in circular linked list\n");
        printf("-----------------------------------\n");
        printf("1.createlist\n");
        printf("2.display list\n");
        printf("3.delete first node\n");
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
            newnode->data = data;
            newnode->next = NULL;
            last->next = newnode;
            last = newnode;
        }
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