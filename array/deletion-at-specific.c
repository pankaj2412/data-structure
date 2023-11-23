#include<stdio.h>

int main()
{
    int a[30],i,pos,size;

    printf("enter the size of array: ");
    scanf("%d",&size);

    printf("enter the element in array: ");

    for ( i = 0; i < size; i++)   //to enter the element in array
    {
        scanf(" %d",&a[i]);
        /* code */
    }
    printf("enter the pos from which you want to delete the data:");  //pos to delete data in array
    scanf("%d",&pos);

    if (pos<=0 || pos> size) //check whetther the user element size matches to allocates size
    {
        printf("invalid position");  
        /* code */
    }
    
    else
    {
        for ( i = pos-1; i < size-1; i++) // this is the conditon for overridden or deletion loop
        {
            a[i]= a[i+1];
            /* code */
        }
        size-- ;
    }    
        

    printf("updated array list");
    for ( i = 0; i < size; i++)
    {
        printf(" %d",a[i]);
       
    }
    
    
}