#include <stdio.h>
void printArray(int *A, int n)   //function for printing array
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");   //print a new line after printing array values
}
void merge(int A[], int mid, int low, int high)
{
    int i, j, k, B[100];
    i = low;
    j = mid + 1;
    k = low;
    while (i <= mid && j <= high)
    {
        if (A[i] < A[j])
        {
            B[k] = A[i];
            i++;
            k++;
        }
        else
        {
            B[k] = A[j];
            j++;
            k++;
        }
    }
    while (i <= mid)
    {
        B[k] = A[i];
        k++;
        i++;
    }
    while (j <= high)
    {
        B[k] = A[j];
        k++;
        j++;
    }
    for (int i = low; i <= high; i++)
    {
        A[i] = B[i];
    }
    
}
void mergeSort(int A[], int low, int high){    // function for merge sort
    int mid; 
    if(low<high){
        mid = (low + high) /2;    //finding the middle of the array.it will split array into two parts.
        mergeSort(A, low, mid);  //calling mergeSort function for left array
        mergeSort(A, mid+1, high);  //calling mergeSort function for right array
        merge(A, mid, low, high);  // calling merge function, it will merge the array element in single array.
    }
}
int main()
{
    // int A[] = {9, 14, 4, 8, 7, 5, 6};
    int n,A[90];
    printf("enter the no of element:");
    scanf("%d",&n);    // asking to user for number of element in array
    printf("enter %d element:\n",n);
    for(int i=0;i<n;i++)
    {
        scanf("%d ",&A[i]);   //taking the array input from user
    }
    printf("entered element are:\n");
    for(int i=0;i<n;i++)
    {
        printf("%d ",A[i]);   //printing the array element that user input
    }
    printf("\n");   //printing a new line after printing array
    // printArray(A, n);   //calling printArray function before merge sort
    printf("array after sorting");
    mergeSort(A, 0, 6);    //calling mergeSort function
    printArray(A, n);    //calling printArray function after merge sort
    return 0;
}
