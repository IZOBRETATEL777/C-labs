#include "sorting.h"

void merge(int* left, int leftSize, int* right, int rightSize, int* arr, int arrSize) {
    int li = 0, ri = 0;
    for (int i = 0; i < arrSize; i++) {
        if (ri >= rightSize || (li < leftSize && left[li] < right[ri])) {
            arr[i] = left[li];
            li++;
        }
        else {
            arr[i] = right[ri];
            ri++;
        }
    }
}

void sort(int* arr, int size) {
    if (size <= 1) {
        return;
    }
    int leftSize = size / 2;
    int left[leftSize];
    for (int i = 0; i < leftSize; i++) {
        left[i] = arr[i];
    }
    int rightSize = size / 2 + size % 2;
    int right[rightSize];
    for (int i = 0; i < rightSize; i++) {
        right[i] = arr[leftSize + i]; 
    }
    sort(left, leftSize);
    sort(right, rightSize);
    merge(left, leftSize, right, rightSize, arr, size);

}

