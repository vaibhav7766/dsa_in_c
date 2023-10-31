#include <stdio.h>
#include <time.h>

// Function to perform Bubble Sort on an array
void BubbleSort(int n, int arr[n]){
    for(int i=0; i<n-1; i++){
        for(int j=0; j<n-i-1; j++){
            if(arr[j] > arr[j+1]){
                // Swap elements if they are in the wrong order
                int swap = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = swap;
            }
        }
    }
}

int main(){
    int array[1000], n, i;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter %d integers: ", n);
    for(i=0; i<n; i++){
        scanf("%d", &array[i]);
    }
    
    clock_t start = clock(); // Record the starting time
    
    // Only perform sorting if there are more than one element
    if(n > 1){
        BubbleSort(n, array);
        printf("Sorted list in ascending order:\n");
        for (i = 0; i < n; i++){
            printf("%d ", array[i]);
        }
    }
    else if (n == 0){
        printf("\nArray is empty.");
    }
    else{
        printf("Please enter a valid size.");
    }
    
    clock_t end = clock(); // Record the ending time
    
    // Calculate and display the time taken in seconds
    double timeTaken = (double)(end - start) / CLOCKS_PER_SEC;
    printf("\nTime taken: %.6f seconds", timeTaken);

    return 0;
}
