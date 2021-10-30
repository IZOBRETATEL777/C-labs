#include "ex2_array_summation.h"
#include <stdlib.h>
#include <stdio.h>

void inputArray(int *arr, int size) {
    printf("Enter elements of the array:\n");
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }
}


int main() {
    int *arr1, size1, *arr2, size2;
    printf("Enter a size of the first array:\n");
    scanf("%d", &size1);
    arr1 = (int* )malloc(size1 * sizeof(int));
    inputArray(arr1, size1);
    printf("Enter a size of the second array:\n");
    scanf("%d", &size2);
    arr2 = (int* )malloc(size2 * sizeof(int));
    inputArray(arr2, size2);
    int* res = sum(arr1, arr2, size1, size2);

    if (res != NULL) {
        printf("The resulting array:\n");
        for (int i = 0; i < max(size1, size2); i++) {
            printf("%d ", res[i]);
        }
        printf("\n");
        free(res);
    }
    else {
        printf("Error: NULL pointer recieved\n");
    }
    if (arr1 != NULL) {
        free(arr1);
    }
    if (arr2 != NULL) {
        free(arr2);
    }
    return 0;
}
