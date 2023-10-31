#include <stdio.h>

int comparisons = 0;  // Counter to keep track of comparisons performed

// Merge function to merge two subarrays
void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;  // Size of left subarray
    int n2 = right - mid;     // Size of right subarray

    int L[n1], R[n2];  // Temporary arrays to hold subarray elements

    // Copy elements to temporary left and right arrays
    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;  // Index variables for merging

    // Merge the temporary arrays back into the original array
    while (i < n1 && j < n2) {
        comparisons++;  // Increment comparison count
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Copy remaining elements from left and right arrays
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// Recursive merge sort function
void merge_sort(int arr[], int left, int right) {
    if (left < right) {
        int mid = (right + left) / 2;  // Calculate middle index
        merge_sort(arr, left, mid);    // Recursively sort left half
        merge_sort(arr, mid + 1, right); // Recursively sort right half

        // Check if the two subarrays are already sorted
        if (arr[mid] <= arr[mid + 1]) {
            return;  // Skip merge if no merging is needed
        }

        merge(arr, left, mid, right);  // Merge the two subarrays
    }
}



int main() {
    int n;
    printf("Enter number of elements: ");  // User input for no. of array elements
    scanf("%d",&n);

    if(n==1){               // Validating size of array
        printf("Array is already sorted.");
        return 0;
    }
    else if (n<0){
        printf("Please enter valid size of array.");
        return 0;
    }

    int arr[n];
    printf("Enter elements of array: ");
    for(int i =0; i<n; i++){
        scanf("%d",&arr[i]);  // Input elements of array
    }
    merge_sort(arr, 0, n - 1);  // Call the merge sort function

    // Print the sorted array
    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    // Print the number of comparisons performed
    printf("\nNumber of comparisons: %d\n", comparisons);

    return 0;
}