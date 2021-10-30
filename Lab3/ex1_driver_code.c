#include "ex1_string_on_heap.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
    char *ptr = askForString();
    if (ptr != NULL) {
        printf("Your string address is %p\n", ptr);
        printf("You entered: %s\n", ptr);
    }
    else {
        printf("Oops, smth got wrong and we have NULL_POINTER_EXCEPTION there\n");
    }

    return 0;
}
