struct Array {
    int *data;
    int size;
};

typedef struct Array Array;

//constructor that initializes array on the heap with zeros
Array* arrayConstructor(int size);

//creates a new array that contains all elements of arr1 followed by all elements of arr2
// [1,2] [3,4,5] -> [1,2,3,4,5]
Array* append(Array* arr1, Array* arr2);

//given that arr1 and arr2 sorted, merge them in sorted order and return a new array

//    ex. arr1 = [1,4,9]  arr2 = [2,3,8,9]
//    result = [1,2,3,4,8,9,9]
Array* merge(Array* arr1, Array* arr2);
