#include "ex3_caesar_cipher.h"
#include <stdlib.h>

char* caesarEncrypt(char* str, int stringLength, int rotationNumber) {
    char* res = (char *)malloc(stringLength * sizeof(char));
    for (int i = 0; i < stringLength; i++) {
        res[i] = (char)('a' + ((str[i] - 'a' + rotationNumber) % 26));
    }
    return res;
}

char* caesarDecrypt(char* str, int stringLength, int rotationNumber) {
    char* res = (char *)malloc(stringLength * sizeof(char));
    for (int i = 0; i < stringLength; i++) {
        int t = (str[i] - 'a' - rotationNumber);
        if (t < 0) {
            res[i] = (char)('a' + 26 + t);
        }
        else {
            res[i] = (char)('a' + t);
        }
    }
    return res;
}

