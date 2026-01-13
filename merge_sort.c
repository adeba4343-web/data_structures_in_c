#include <stdio.h>
void merge(int arr[], int low, int mid, int high) {
    int i = low;
    int j = mid + 1;
    int k = 0;
    int temp[high - low + 1];

    // Merge the two halves
    while (i <= mid && j <= high) {
        if (arr[i] < arr[j])
            temp[k++] = arr[i++];
        else
            temp[k++] = arr[j++];
    }

    // Copy remaining elements of left subarray
    while (i <= mid)
        temp[k++] = arr[i++];

    // Copy remaining elements of right subarray
    while (j <= high)
        temp[k++] = arr[j++];

    // Copy temp array back to original array
    for (i = low, k = 0; i <= high; i++, k++)
        arr[i] = temp[k];
}

void mergeSort(int arr[], int low, int high) {
    if (low < high) {
        int mid = (low + high) / 2;

        mergeSort(arr, low, mid);       // Sort left half
        mergeSort(arr, mid + 1, high);  // Sort right half
        merge(arr, low, mid, high);     // Merge both halves
    }
}


void display(int arr[], int size) {
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int n;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    printf("Original array: ");
    display(arr, n);

    mergeSort(arr, 0, n - 1);

    printf("Sorted array: ");
    display(arr, n);

    return 0;
}
