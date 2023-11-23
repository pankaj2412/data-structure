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
    printf("enter the pos where you want to insert the data: ");
    scanf("%d",&pos);

    if (pos<=0 || pos>size-1)//to check if size of array greater than pos then //
    {
        printf("invalid pos");
        
    }
    else
    {
        for (i = size-1; i >= pos-1; i--)
        {
           a[i+1]=a[i];
        }
        a[pos-1]=num;
        size++;
        

    }
    printf("elemenet in array are : ");// to print that value you on display that you insert//

     for ( i = 0; i < size; i++)
     {
        /* code */
        printf(" %d",a[i]);
     }
     

    
    
}