#include "ex3_caesar_cipher.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    printf("Welcome to the Caesar cipher program!\nWhat you want to do?\n[1] Encrypt text\n[2] Decrypt text\n");
    int cmd;
    printf("Enter command: ");
    scanf("%d", &cmd);
    char string[500];
    printf("Enter a string (max 500 chars, only lowercase english letters are allowed):\n");
    scanf("%s", string);
    int size = strlen(string);
    printf("Enter a key (from 1 to 26): ");
    int key;
    scanf("%d", &key);
    char *res = NULL;
    switch (cmd) {
        case 1:
            printf("%s\n", string);
            res = caesarEncrypt(string, size, key);
            break;
        case 2:
            res = caesarDecrypt(string, size, key);
            break;
        default:
            printf("Unknown option: %d\n", cmd);
            break;

    }
    if (res != NULL) {
        printf("Result:\n%s\n", res);
        free(res);
    }
    return 0;
}
