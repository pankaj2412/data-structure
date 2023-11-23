#include<stdio.h>

void bubblesort(int array[],int size)
{
    //loop to acess each element
    for ( int step = 0; step < size-1; step++)
    {
        //Loop to compare element
       for (int  i = 0; i < size-step-1; i++)
       {
           if (array[i]> array[i+1])
           {
               int swap= array[i];
               array[i]=array[i+1];
               array[i+1]=swap;
           }
           
       }
       
    }
    

}

void printarray(int array[] ,int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ",array[i]);
    }
    
}

int main()
{
    int data[]={-2,3,8,3,8};
    
    //to finde the size of array
    int size = sizeof(data)/sizeof(data[0]);
    bubblesort(data,size);

    //printed sorted array
    printf("printed in accesending order are \n");
    printarray(data,size);
}