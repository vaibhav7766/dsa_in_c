#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// function to swap elements
void swap(int *a, int *b) {
  int t = *a;
  *a = *b;
  *b = t;
}

// function to find the partition position
int partition(int array[], int low, int high) {
  
  // select the rightmost element as pivot
  int pivot = array[high];
  
  // pointer for greater element
  int i = (low - 1);

  // traverse each element of the array
  // compare them with the pivot
  for (int j = low; j < high; j++) {
    if (array[j] <= pivot) {
        
      // if element smaller than pivot is found
      // swap it with the greater element pointed by i
      i++;
      
      // swap element at i with element at j
      swap(&array[i], &array[j]);
    }
  }

  // swap the pivot element with the greater element at i
  swap(&array[i + 1], &array[high]);
  
  // return the partition point
  return (i + 1);
}

void quickSort(int array[], int low, int high) {
  if (low < high) {
    
    // find the pivot element such that
    // elements smaller than pivot are on left of pivot
    // elements greater than pivot are on right of pivot
    int pi = partition(array, low, high);
    
    // recursive call on the left of pivot
    quickSort(array, low, pi - 1);
    
    // recursive call on the right of pivot
    quickSort(array, pi + 1, high);
  }
}

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

// main function
int main() {
  int lower = 1, upper = 1000, count = 40000;
    int arr1[count];
    int arr2[count];
    srand(time(0));
    for (int i = 0; i < count; i++) {
        int num = (rand() % (upper - lower + 1)) + lower;
        arr1[i]=num;
        arr2[i]=num;
    }
  
  double start=clock();  // Starting Time for quicksort
  quickSort(arr1, 0, count - 1);  // Call the quicksort function
  double end=clock();  // Ending Time for quicksort
  
  printf("Time complexity by quick sort : %.6f",(end-start)/CLOCKS_PER_SEC);

  double start1=clock();  // Starting Time for merge sort
  merge_sort(arr2, 0, count - 1);  // Call the merge sort function
  double end1=clock();  // Ending Time for merge sort

  printf("\nTime complexity by mergesort : %.6f",(end1-start1)/CLOCKS_PER_SEC);
  
  return 0;
}