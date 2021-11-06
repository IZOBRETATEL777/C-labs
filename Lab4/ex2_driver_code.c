#include "array_manipulations.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

Array* inputArray() {
    int n;
    printf("Enter the number of elements of a array: ");
    scanf("%d", &n);
    printf("Enter elements of array:\n");
    Array *array = arrayConstructor(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &(array->data[i]));
    }
    return array;
}

void printArray(Array *array) {
    printf("Our array:\n");
    for (int i = 0; i < array->size; i++) {
        printf("%d ", array->data[i]);
    }
    printf("\n");
}

bool isSorted(Array *array) {
    bool sorted = true;
    for (int i = 1; i < array->size; i++) {
        sorted &= (array->data[i - 1] <= array->data[i]);
    }
    return sorted;
}

int main()
{

    int cmd, n;
    bool go = true;
    Array* arrays[3] = { NULL }; // All values will be NULL. Hack from CP :)
    while (go) {
        printf("Enter what I should do:\n");
        printf("1 - to create emtpty arrays of size n\n2 - to append one array to another\n3 - to merge to NON-DECREASINGLY SORTED arrays\n0 - to exit\n:");
        scanf("%d", &cmd);

        switch (cmd) {
        case 1:
            printf("Enter N: ");
            scanf("%d", &n);
            arrays[2] = arrayConstructor(n);
            printArray(arrays[2]);
            break;
        case 2:
            arrays[0] = inputArray();
            arrays[1] = inputArray();
            arrays[2] = append(arrays[0], arrays[1]);
            printArray(arrays[2]);
            break;
        case 3:
            arrays[0] = inputArray();
            arrays[1] = inputArray();
            if (isSorted(arrays[0]) && isSorted(arrays[1])) {
                arrays[2] = merge(arrays[0], arrays[1]);
                printArray(arrays[2]);
            }
            else {
                printf("Elements of the array should be sorted in non-decreasing order!\nTry again.\n");
            }
            break;
        case 0:
            go = false;
            break;
        default:
            break;
        }

        for (int i = 0; i < 3; i++) {
            if (arrays[i] != NULL) {
                free(arrays[i]);
                arrays[i] = NULL;
            }
        }
    }

    return 0;
}