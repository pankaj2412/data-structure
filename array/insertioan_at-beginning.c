#include<stdio.h>

int main()
{
    int a[30],size,i,num,pos;

    printf("enter the size of the element you want to insert : " );
    scanf("%d",&size);

    printf("enter the element in array : ");

    for ( i = 0; i < size; i++)//data like element thta you want to insert //
    {
        scanf("%d",&a[i]);
        
    }

    printf("enter the data that you wan tto insert: ");
    scanf("%d",&num);
   
        for ( i = size-1; i >= 0; i--)
        {
            a[i+1] = a[i];
        }
        a[0]=num;
        size++;
        
    printf("elemenet in array are : ");// to print that value you on display that you insert//

     for ( i = 0; i < size; i++)
     {
        /* code */
        printf(" %d",a[i]);
     }
}    