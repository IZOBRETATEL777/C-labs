#include "sorting.h"

void swap(int *arr, int firstIndex,int secondIndex) {
    int temp = arr[firstIndex];
    arr[firstIndex] = arr[secondIndex];
    arr[secondIndex] =  temp;
}

void sort(int* arr, int size) {
    for (int i = 0; i < size - 1; i++) {
        int minIdx = i;
        for (int j = i; j < size; j++) {
            if (arr[j] < arr[minIdx]) {
                minIdx = j;
            }
        }
        if (minIdx != i) {
            swap(arr, minIdx, i);
        }
    }

}

