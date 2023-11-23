#include<stdio.h>

int binaryserach(int arr[], int x, int low , int high)
{
    while (low<=high)
    {
       int  mid= low+(high-low)/2;

       if (arr[mid] == x)
       {
           return mid;
       }
       if (arr[mid]<x)
       {
            low =  mid +1;  
       }
       else
       {
           high = mid-1;
       }
       
       
    }
    return -1;

}

int main()
{
    int arr[]= {11,22,33,44,55,66,67,78};
    int n= sizeof(arr)/sizeof(arr[0]);

    int x = 55;
    int result = binaryserach(arr, x, 0, n-1);

    if (result==-1)
    {
        printf("element is not found\n");
    }
    else
    {
        printf("element is found at position %d ",result);

    }
    return 0;
}

//recursive approach

// int binaryserach1(int arr[], int x , int low, int high)
// {
//     while (low<=high)
//     {
//         int mid1 = low+(high-low)/2;

//         if (arr[mid1]== x)
//         {
//             return mid1;
//         }
//         if (arr[mid1]<x)
//         {
//            return binaryserach1(arr, x,mid1+1 , high);
//         }
//         else
//         {
//             return binaryserach1(arr,x,low,mid1-1);
//         }
        
//     }
//     return -1;
    
// } 

// int main()
// {
//     int arr[]= {11,22,33,44,55,66,67,78};
//     int n= sizeof(arr)/sizeof(arr[0]);

//     int x = 55;
//     int result = binaryserach(arr, x, 0, n-1);

//     if (result==-1)
//     {
//         printf("element is not found\n");
//     }
//     else
//     {
//         printf("element is found at position %d ",result);

//     }
//     return 0;
// }