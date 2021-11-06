struct Array {
    int *data;
    int size;
    struct Array *(*append)(struct Array *self, struct Array *toAppend);
    struct Array *(*merge)(struct Array *self, struct Array *toMerge);

    //returns sum of array elements
    int (*sum)(struct Array *self);

    //returns average of array elements
    double (*average)(struct Array *self);

    // prints array in the following format: [0,1 ... N]
    void (*print)(struct Array *self);

};
typedef struct Array Array;

Array* arrayConstructor(int size);
void arrayDestructor(Array* arr);
