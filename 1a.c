#include <stdio.h>

void merge(int arr[], int p, int q, int r) {
    int n1 = q - p + 1;
    int n2 = r - q;
    int low[n1], high[n2];

    for (int i = 0; i < n1; i++) {
        low[i] = arr[p + i];
    }
    for (int j = 0; j < n2; j++) {
        high[j] = arr[q + 1 + j];
    }

    int i = 0, j = 0, k = p;

    while (i < n1 && j < n2) {
        if (low[i] <= high[j]) {
            arr[k] = low[i];
            i++;
        } else {
            arr[k] = high[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = low[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = high[j];
        j++;
        k++;
    }
}

void merge_sort(int arr[], int p, int r) {
    if (p < r) {
        int q = (p + r) / 2;
        merge_sort(arr, p, q);
        merge_sort(arr, q + 1, r);
        merge(arr, p, q, r);
    }
}

int find_missing(int arr[], int n) {
    merge_sort(arr, 0, n - 1);
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

    merge_sort(arr, 0, n - 1);
    printf("Missing element is %d", find_missing(arr, n));

    return 0;
}
