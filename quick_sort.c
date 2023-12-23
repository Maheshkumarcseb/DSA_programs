#include <stdio.h>

void printArray(int *A, int n)    // printing the array element
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");   // printing new line after array
}
int partition(int A[], int low, int high)
{
    int pivot = A[low];  //storing the first element of array into pivot
    int i = low + 1;
    int j = high;
    int temp;

    do
    {
        while (A[i] <= pivot) //checking condition whether second element is lesser than or equal to first element.
        {
            i++;
        }

        while (A[j] > pivot)  // checking condition whether last element is greater than pivot or not.
        {
            j--;
        }

        if (i < j)     
        {
            //swapping A[i] and A[j]
            temp = A[i];
            A[i] = A[j];
            A[j] = temp;
        }
    } while (i < j);  //checking for condition

    // Swap A[low] and A[j]
    temp = A[low];
    A[low] = A[j];
    A[j] = temp;
    return j;
}

void quickSort(int A[], int low, int high)
{
    int partitionIndex; // Index of pivot after partition

    if (low < high)
    {
        partitionIndex = partition(A, low, high); // calling the partition function to split the array by finding pivot point.
        quickSort(A, low, partitionIndex - 1);  // sort left subarray 
        quickSort(A, partitionIndex + 1, high); // sort right subarray
    }
}

int main()
{
    //int A[] = {3, 5, 2, 13, 12, 3, 2, 13, 45};
    // int A[] = {9, 4, 4, 8, 7, 5, 6};
    // 3, 5, 2, 13, 12, 3, 2, 13, 45
    // 3, 2, 2, 13i, 12, 3j, 5, 13, 45
    // 3, 2, 2, 3j, 12i, 13, 5, 13, 45 --> first call to partition returns 3
    // int n = 9;
    // n =7;
    int n,A[90];
    printf("enter the no of element:");
    scanf("%d",&n);
    printf("enter %d element:\n",n);
    for(int i=0;i<n-1;i++)
    {
        scanf("%d ",&A[i]);
    }
    // printf("entered element are\n:");
    // for(int i=0;i<n;i++)
    // {
    //     printf("%d ",A[i]);
    // }

    printArray(A, n);  //printing array before quickSort
    quickSort(A, 0, n - 1);  //calling quickSort function
    printArray(A, n);   //printing array after quickSort
    return 0;
}
