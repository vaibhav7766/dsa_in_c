#include <stdio.h>
#include <string.h>

int binarySearch(int n, char arr[][100], char* target) {
    int low = 0;
    int high = n - 1;
    while (low <= high) {
        int mid = (high + low) / 2;
        int cmp = strcmp(arr[mid], target);
        if(cmp == 0){
            return mid;
        }
        else if(cmp < 0){
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }
    }

    return -1;
}

int main() {
    int n = 6;
    char words[][100] = {"apple", "banana", "cherry", "grape", "orange", "peach"};
    char* target = "grape";
    int x = binarySearch(n, words, target);
    if (x == -1) {
        printf("Word is not in the array.\n");
    } else {
        printf("Word is located at index %d\n", x);
    }

    return 0;
}