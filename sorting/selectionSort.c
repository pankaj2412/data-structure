#include <stdio.h>


void swap(int *a, int *b)
{
    int temp= *a;
    *a=*b;
    *b= temp;
}



void selectioSort(int array[], int size)
{
    for (int step = 0; step < size-1; step++)
    {
        int min = step;
        for (int i = step + 1; i < size; i++)
        {
            if (array[i] < array[min])
            {
                min = i;
            }
        }
        swap(&array[min], &array[step]);
    }
}


void printArray(int array[],int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ",array[i]);
    }
    
}
int main()
{
    int data[] = {22, 3, 4, 52, 23};

    int size = sizeof(data) / sizeof(data[0]);

    selectioSort(data, size);

    printf("sorted array is \n");
    printArray(data, size);
}

