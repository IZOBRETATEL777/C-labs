#include "ex2_array_summation.h"
#include <stdlib.h>
#include <stdio.h>

int max(int a, int b) {
    return (a > b ? a : b);
}

int* sum(int* arr1, int* arr2, int size1, int size2) {
    int maxLen = max(size1, size2);
    int* sumArr = (int* )malloc(maxLen * sizeof(int));
    for (int i = 0; i < maxLen; i++) {
        if (size1 > i && size2 > i) {
           sumArr[i] = arr1[i] + arr2[i]; 
        }
        else if (size2 <= i && size1 > i) {
            sumArr[i] = arr1[i];
        }
        else if (size1 <= i && size2 > i) {
            sumArr[i] = arr2[i];
        }
    }
    return sumArr;
}

