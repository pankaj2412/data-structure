#include<stdio.h>

int main()
{
    int a[20],i,size,num;

    printf("enter the size of array : "); //size of array that you want to insert
    scanf("%d",&size);

    printf("enter the element in array : "); //elemnt insert in array
    for ( i = 0; i < size; i++)
    {
        scanf("%d",&a[i]);
    }

    printf("enter the element data that you want to insert :");
    scanf("%d",&num);

    a[size]=num;
    size++;

    printf("the elemt of updated array are :");
    for ( i = 0; i< size; i++)
    {
        printf(" %d",a[i]);
    }
    
    
}