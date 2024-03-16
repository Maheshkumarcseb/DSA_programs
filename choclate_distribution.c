#include <stdio.h>
#include <stdlib.h>

// Function to partition the array and return the pivot index
int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            // Swap arr[i] and arr[j]
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    // Swap arr[i+1] and arr[high] (pivot)
    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;
    return i + 1;
}

// Function to perform Quick Sort
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// Function to find the minimum difference between any two elements in the array
int findMinDiff(int arr[], int n, int m) {
    if (m == 0 || n == 0)
        return 0;

    // Sorting the array using Quick Sort
    quickSort(arr, 0, n - 1);

    if (n < m)   //no of packet of choclate should be greater than no. of student
        return -1;

    int min_diff = arr[n - 1] - arr[0];  

    for (int i = 0; i < n - m + 1; i++)
        min_diff = min_diff < (arr[i + m - 1] - arr[i]) ? min_diff : (arr[i + m - 1] - arr[i]);

    return min_diff;
}

int main() {
    int n, m;
    printf("Enter no of choclates: ");
    scanf("%d", &n);
    printf("Enter the no of student: ");
    scanf("%d", &m);
    int arr[n];
    printf("Enter %d choclates: ",n);
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    int result = findMinDiff(arr, n, m);
    printf("minimum difference of choclate is %d\n", result);

    return 0;
}
