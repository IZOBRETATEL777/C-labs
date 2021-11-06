#include "array_manipulations.h"
#include <stdlib.h>

Array* arrayConstructor(int size) {
    Array* array = (Array*)malloc(sizeof(Array));
    array->size = size;
    array->data = (int*)calloc(size, sizeof(int));
    return array;
}

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
