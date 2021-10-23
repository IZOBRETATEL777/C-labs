#include <stdio.h> // for printf 
#include <stdlib.h> // for atoi
#include "char_sorting.h"

int main(int n, char** argv){ // ["./sort", "agzh"]
    if (n < 1) {
        printf("Data is insuffient! Please insert proper input at command line. \n");
        return 0;
    }
    char *array = argv[1];
    sort(array);
    printf("%s\n", array);
    return 0;

}
