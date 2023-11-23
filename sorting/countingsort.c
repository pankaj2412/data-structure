#include <stdio.h>
#include <stdlib.h>
void countingsort(int arr[], int size)
{
    int output[10];
    int max = arr[0];
    for (int i = 0; i < size; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }
    // The size of count must be at least (max+1) but
    // we cannot declare it as int count(max+1) in C as
    // it does not support dynamic memory allocation.
    //  So, its size is provided statically.
    int count[10];

    for (int i = 0; i <= max; i++)
    {
        count[i]=0;
    }
    

    //to store the count of every element
    for (int i = 0; i < size; i++)
    {
        count[arr[i]]++;
    }

    // store the cummulative count of the each  array
    for (int i = 1; i <= max; i++)
    {
        count[i] += count[i - 1];
    }

    // Find the index of each element of the original array in count array, and
    // place the elements in output array
    for (int i =size; i >=0; i--)
    {
        output[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }

    // Copy the sorted elements into original array
    for (int i = 0; i < size; i++)
    {
        arr[i]= output[i];
    }
}

// Function to print an array
void printArray(int arr[], int size) {
  for (int i = 0; i < size; ++i) {
    printf("%d  ", arr[i]);
  }
  printf("\n");
}

int main()
{
    int arr[] = {1, 4, 3, 6, 3, 2, 1, 3};

    int size = sizeof(arr) / sizeof(arr[0]);
    countingsort(arr, size);
    printArray(arr, size);
}