#include <stdbool.h>
#include <stdio.h>
#include <time.h>

void swap(int* xp, int* yp)
{
	int temp = *xp;
	*xp = *yp;
	*yp = temp;
}

void bubbleSort(int arr[], int n)
{
	int i, j;
	bool swapped;
	for (i = 0; i < n - 1; i++) {
		swapped = false;
		for (j = 0; j < n - i - 1; j++) {
			if (arr[j] > arr[j + 1]) {
				swap(&arr[j], &arr[j + 1]);
				swapped = true;
			}
		}
		if (swapped == false)
			break;
	}
}

void printArray(int arr[], int size)
{
	int i;
	for (i = 0; i < size; i++)
		printf("%d ", arr[i]);
}

int main()
{
    int n;
    printf("Enter size of array: ");
    scanf("%d",&n);
    int arr[n];
    printf("Enter elements: ");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    double start=clock();
	bubbleSort(arr, n);
	printf("Sorted array: \n");
	printArray(arr, n);
    double end=clock();
    printf("\n%f",(end-start)/CLOCKS_PER_SEC);
    return 0;
}
