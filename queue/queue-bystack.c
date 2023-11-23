#include <stdio.h>
#include <stdlib.h>
#define N 5

void push1(int data);
int pop1();
int pop2();
void push2(int data);
void enqueue(int data);
void dequeue();
void dsiplay();

int top1 = -1;
int top2 = -1;
int count = 0;
int s1[N], s2[N];

void enqueue(int data)
{
    push1(data);
    count++;
}
void dequeue()
{
    int i, a, b;
    if (top1 == -1 && top2 == -1)
    {
        printf("the queue is empty\n");
    }
    else
    {
        for (i = 0; i < count; i++)
        {
            a = pop1();
            push2(a);
        }
        b = pop2();
        printf("%d", b);
        count--;
        for (i = 0; i < count; i++)
        {
            a = pop2();
            push1(a);
        }
    }
}
void push1(int data)
{
    if (top1 == N - 1)
    {
        printf("the queue is empty\n");
    }
    else
    {
        top1++;
        s1[top1] = data;
    }
}
void push2(int data)
{
    if (top1 == N - 1)
    {
        printf("the queue is empty\n");
    }
    else
    {
        top2++;
        s2[top2] = data;
    }
}
int pop1()
{
    return (s1[top1--]);
}
int pop2()
{
    return (s2[top2--]);
}
void display()
{
    int i;
    for (i = 0; i <= top1; i++)
    {
        printf("the data in stack is =%d ", s1[i]);
    }
}
int main()
{
    int choice,data;

    while (1)
    {
        printf("\n------------------------------\n");
        printf("\nQUEUE USING STACK\n");
        printf("\n-------------------------------\n");
        printf("1.enqueue\n");
        printf("2.dequeue\n");
        printf("3.display\n");
        printf("0.exit\n");

        printf("enter the choice: ");
        scanf("%d",&choice);

        switch (choice)
        {
        case 1:
            enqueue(data);
            printf("enter the data : ");
            scanf("%d",&data);
            break;

        case 2:
            dequeue();
            break;    
        case 3:
            display();
            break;

        case 0:
             
            break;

        default:
        printf("enter the valid choice in between 1-4\n");
            break;
        }
    }
}