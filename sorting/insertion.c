#include <stdio.h>

void insertionSort(int array[], int size)
{
    //loop for the acess each element of array

    for (int step = 0; step < size; step++)
    {
        int key = array[step];

        //variable to compare previous element with next element
        int j = step - 1;

        while (key < array[j] && j >= 0)
        {
            array[j + 1] = array[j];
            --j;
        }
        array[j + 1] = key;
    }
}

void printArray(int array[],int size)
{
    for ( int i = 0; i < size; i++)
    {
      printf("%d ",array[i]);
    }
    
}

int main()
{
    int data[] ={5,4,10,6,2,8};

    int size= sizeof(data)/sizeof(data[0]);

    insertionSort(data,size);

    printf("sorted data form is\n");
    printArray(data,size);
}