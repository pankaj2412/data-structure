#include<stdio.h>

int main()
{
    int a[20],size,i;

    printf("enter the size of array :");
    scanf("%d",&size);

    printf("enter the the element in array:");
    for ( i = 0; i < size; i++)
    {
        scanf("%d",&a[i]);
        /* code */
    }
    
    for ( i = 0; i< size-1; i++)
    {
        a[i]=a[i+1];
        /* code */
    }
    size-- ;

    printf("the elemt of updated array are :");
    for ( i = 0; i< size; i++)
    {
        printf(" %d",a[i]);
    }
    
    
}