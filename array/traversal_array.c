#include<stdio.h>
int main()
{
    int a[50],size,i;

    printf("enter the size of array that you want to insert: ");
    scanf("%d",&size); //jitne array insert krna chahte ho unka size like 10 array dalane h //

    printf("enter the element in arrray : ");//element or data like number form ,char form that you want to insert//
    
    for ( i = 0; i < size; i++)
    {
        scanf("%d",&a[i]);
        /* code */
    }

    printf("elemenet in array are : ");// to print that value you on display that you insert//

     for ( i = 0; i < size; i++)
     {
        /* code */
        printf(" %d",a[i]);
     }
     
    
}