#include <stdio.h> // for printf 
#include <stdlib.h> // for atoi
#include "binary_search.h"

int main(int argsNum, char** argv){ 

    if (argsNum < 2) {
        printf("Data is insuffient! Please insert proper input at command line. \n");
        return 0;
    }
    int n = argsNum - 1, array[n];
    int toFind;
    printf("What we should find: ");
    scanf("%d", &toFind);

    for (int i = 0; i < n; i++){ // argv[1] = "32"
        array[i] = atoi(argv[i+1]); // array[0] = atoi("32")
    }
    int *ans = binarySearch(array, n, toFind);
    if (ans == NULL) {
        printf("Not found\n");
    }
    else {
        printf("Found %d at index %d\n", *ans, ans - array);
    }
    return 0;

}
