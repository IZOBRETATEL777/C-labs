#include "ex3_array_manipulations.h"
#include <stdio.h>
#include <stdlib.h>

Array* append(Array* arr1, Array* arr2) {
    Array* array = arrayConstructor(arr1->size + arr2->size);
    for (int i = 0; i < arr1->size; i++)
        array->data[i] = arr1->data[i];
    for (int i = 0; i < arr2->size; i++)
        array->data[i + arr1->size] = arr2->data[i];
    return array;
}

Array* merge(Array* arr1, Array* arr2) {
    int it1 = 0, it2 = 0;
    Array* array = arrayConstructor(arr1->size + arr2->size);
    for (int i = 0; i <array->size; i++) {
        if (it1 < arr1->size && (it2 >= arr2->size || arr1->data[it1] < arr2->data[it2])) {
            array->data[i] = arr1->data[it1];
            it1++;
        }
        else {
            array->data[i] = arr2->data[it2];
            it2++;
        }
    }
    return array;
}

int sum(Array *array) {
    int res = 0;
    for (int i = 0; i < array->size; i++) {
        res += array->data[i];
    }
    return res;
}

double average(Array *array) {
    return array->sum(array) / array->size;
}

void print(Array *array) {
    printf("[");
    for (int i = 0; i < array->size; i++) {
        if (i != array->size - 1) {
            printf("%d, ", array->data[i]);
        }
        else {
            printf("%d]\n", array->data[i]);
        }
    }
}


Array *arrayConstructor(int size)
{
    Array *arr1 = (Array *)malloc(sizeof(Array));
    arr1->data = (int *)calloc(size, sizeof(int));
    arr1->size = size;
    arr1->append = append;
    arr1->merge = merge;
    arr1->sum = sum;
    arr1->average = average;
    arr1->print = print;
    return arr1;
}

void arrayDestructor(Array *arr) {
    if (arr->data != NULL) {
        free(arr->data);
    }
    if (arr != NULL) {
        free(arr);
    }
}
