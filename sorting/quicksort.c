#include<stdlib.h>
#include<stdio.h>

void swap(int *a, int *b)
{
    int temp= *a;
    *a =*b;
    *b = temp;
}
int  partition(int arr[] ,int low, int high)
{
    int pivot = arr[high];

    int i= low-1;

    for (int j = low; j < high; j++)
    {
        if (arr[j]<=pivot)
        {
            //if the element is smaller than the pivot elment is found swap with 
            //greator element pointed by i
            i++;

            //swap element of the i with j
            swap(&arr[i],&arr[j]);
        }
           
    }

    // here the pivot element is swaped with arr[i+1]th element in the array
    swap(&arr[i+1],&arr[high]);
    return (i+1);
}

void quickSort(int arr[], int low, int high)
{
    if (low<high)
    {
        int pi = partition(arr, low,high);

        //sorting of element before and after partition
        quickSort(arr, low,pi-1);
        quickSort(arr,pi+1,high);
    }
    

}
void printArray(int arr[], int size) {
  for (int i = 0; i < size; ++i) {
    printf("%d  ", arr[i]);
  }
  printf("\n");
}

int main()
{
    int data[]= {7,5,6,9,11,10,3,7,16};

    int size=  sizeof(data)/sizeof(data[0]);

    printf("unsorted array\n");
    printArray(data,size);

    quickSort(data,0,size-1);

    printf("sorted arrray \n");
    printArray(data,size);
}