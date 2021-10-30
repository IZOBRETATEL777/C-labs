#include "ex1_string_on_heap.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LEN 1024

char* askForString() {
    printf("Enter a string (maximum size is %d characters)\n", MAX_LEN);
    char inp[MAX_LEN];
    scanf("%s", inp);
    size_t len = strlen(inp);
    printf("The length of your string is %ld\n", len);
    char* ptr = (char* )malloc(len * sizeof(char));
    strcpy(ptr, inp);
    return ptr;
}

