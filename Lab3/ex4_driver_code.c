#include "ex4_sort_str_arr.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    printf("Enter a number of strings\n");
    int n;
    char inp[500];
    scanf("%d", &n);
    char** strings = (char** )malloc(n * sizeof(char*));
    printf("Enter %d strings. Max lenght of each string should not be greater that 500 characters!\n", n);
    for (int i = 0; i < n; i++) {
        memset(&inp[0], 0, sizeof(inp));
        scanf("%s", inp);
        strings[i] = (char* )malloc(strlen(inp) * sizeof(char));
        strcpy(strings[i], inp);
    }
    sort(strings, n);
    printf("Sorted:\n");
    for (int i = 0; i < n; i++) {
        printf("%s\n", strings[i]);
    }
    if (strings != NULL) {
        for (int i = 0; i < n; i++) {
            if (strings[i] != NULL) {
                free(strings[i]);
            }
        }
        free(strings);
    }
    return 0;
}
