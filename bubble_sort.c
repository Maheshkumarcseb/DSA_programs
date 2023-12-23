#include<stdio.h>
void printArray(int* A, int n){    //function for printing array.
    for (int i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");    // it will print new line after array printing.
}
void bubbleSort(int *A, int n){
    int temp;  // temp is a temporary variable used for swapping two number.
    for (int i = 0; i < n-1; i++) // For number of pass
    {
       // printf("Working on pass number %d\n", i+1); 
        for (int j = 0; j <n-1-i ; j++) // For comparison in each pass
        {
            if(A[j]>A[j+1]){     //checking for condition whether first element of array is greter than second element.
                temp = A[j];    //if above condition is true then it will swap the number. 
                A[j] = A[j+1];
                A[j+1] = temp; 
            }
        }  
    } 
}
int main(){
    // int A[] = {12, 54, 65, 7, 23, 9};
   
    int A[] = {1, 2, 5, 6, 12, 54, 625, 7, 23, 9, 987};
    // // int A[] = {1, 2, 3, 4, 5, 6};
    int n = 11;
    printArray(A, n); // Printing the array before sorting.
    bubbleSort(A, n); // calling bubbleSort Function to sort the array.
    printArray(A, n); // Printing the array before sorting.
    return 0;
}
