#include "ex4_sort_str_arr.h"
#include <string.h>
void swap(char** arr, int a, int b) {
    char* t = arr[a];
    arr[a] = arr[b];
    arr[b] = t;
}

void sort(char** arr, int n) {
    for (int i = 0; i < n - 1; i++) {
        int idx = i;
        for (int j = i + 1; j < n; j++) {
            if (strcmp(arr[idx], arr[j]) > 0) {
                idx = j;
            }
        }
        if (idx != i) {
            swap(arr, idx, i);
        }
    }
}
