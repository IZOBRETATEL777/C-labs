#include "ex3_array_manipulations.h"
#include <stdio.h>

int main() {
    Array *arr1 = arrayConstructor(10); // array of size 10 initialized with zeros
    Array *arr2 = arrayConstructor(5);  // array of size 5 initialized with zeros
    arr1->print(arr1);
    arr2->print(arr2);

    printf("Enter %d elements of arr1:\n", arr1->size);
    for (int i = 0; i < arr1->size; i++) {
        scanf("%d", &(arr1->data[i]));
    }

    printf("Enter %d elements of arr2:\n", arr2->size);
    for (int i = 0; i < arr2->size; i++) {
        scanf("%d", &(arr2->data[i]));
    }

    Array *merged = arr1->merge(arr1, arr2);
    merged->print(merged);
    Array *appended = arr1->append(arr1, arr2);
    appended->print(appended);

    int sum1 = arr1->sum(arr1);
    double avg1 = arr1->average(arr1);

    int sum2 = arr2->sum(arr2);
    double avg2 = arr2->average(arr2);
    

    printf("Sum of arr1: %d\nAverage: %.2lf\n\n", sum1, avg1);
    printf("Sum of arr2: %d\nAverage: %.2lf\n\n", sum2, avg2);

    arrayDestructor(arr1);
    arrayDestructor(arr2);
    arrayDestructor(merged);
    arrayDestructor(appended);

    return 0;
}