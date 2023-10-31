#include <stdio.h>

int find_missing(int arr[], int n) {
    int missing = 1;

    for (int i = 0; i < n; i++) {
        if (arr[i] == missing) {
            missing++;
        }
    }

    return missing;
}

int main() {
    int n;
    printf("Enter size of array: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter elements of array: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Missing element is %d", find_missing(arr, n));

    return 0;
}