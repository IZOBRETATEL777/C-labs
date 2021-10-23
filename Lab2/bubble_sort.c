#include "char_sorting.h"
#include "string.h"

void swap(char *first, char *second) {
    char temp = *first;
    *first = *second;
    *second =  temp;
}

void sort(char* arr) {
    int size = strlen(arr);
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}
