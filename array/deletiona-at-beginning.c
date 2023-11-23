#include<stdio.h>

int main()
{
    int a[40],i,size;

    printf("enter the size of the array:");
    scanf("%d",&size);

    printf("enter the element in array:");
    for ( i = 0; i < size; i++)
    {
        scanf("%d",&a[i]);
        /* code */
    }

    for ( i = 0; i < size-1; i++)
    {
        a[i] =a[i+1];
        /* code */
    }
    size-- ;

    printf("the updated array list:");
    for ( i = 0; i < size; i++)
    {
        printf(" %d",a[i]);
        /* code */
    }
    
    
    
}