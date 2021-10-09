#include <stdio.h>
#include <stdlib.h>
#include "first_library.h"

#define BINARY_TO_DECIMAL 1
#define DECIMAL_TO_BINARY 2
#define MILES_TO_KILOMETERS 3
#define KILOMETERS_TO_MILES 4
#define PRIME_CHECK 5
#define PALINDROME_CHECK 6
#define REVERSE 7
#define RANDOM_IN_RANGE 8
#define GCD 9
#define LCM 10

int main(int argNum, char **args) {
	if (argNum - 1) {
		printf("You provided %d arguments\n", argNum - 1);
	} else {
		printf("You didn't provide any arguments\n");
		return -1;
	}
	int operation = atoi(args[1]); // atoi converts string (char[] | char*) to int
	switch (operation) {
		case BINARY_TO_DECIMAL: {
			if (argNum < 3) {
				printf("Too few arguments\n");
				break;
			}
			long n = atol(args[2]);
			printf("Decima: %ld\n", binaryToDecimal(n));
			break;
		}
		case DECIMAL_TO_BINARY: {
			if (argNum < 3) {
				printf("Too few arguments\n");
				break;
			}
			long n = atol(args[2]);
			printf("Binary: %ld\n", decimalToBinary(n));
           	 	break;
       	 	}
		case MILES_TO_KILOMETERS: {
			if (argNum < 3) {
				printf("Too few arguments\n");
				break;
			}
			double n = atof(args[2]);
			printf("%.2lfkm\n", milesToKilometers(n));
			break;
		}

		case KILOMETERS_TO_MILES: {
			if (argNum < 3) {
				printf("Too few arguments\n");
				break;
			}
			double n = atof(args[2]);
			printf("%.2lfmile\n", kilometersToMiles(n));
			break;
		}
		
		case PRIME_CHECK: {
			if (argNum < 3) {
				printf("Too few arguments\n");
				break;
			}
			long n = atol(args[2]);
			primeCheck(n);
			break;
		}
		case PALINDROME_CHECK: {
			if (argNum < 3) {
				printf("Too few arguments\n");
				break;
			}
			long n = atol(args[2]);
			palindromeCheck(n);
			break;
		}
		case REVERSE: {
			if (argNum < 3) {
				printf("Too few arguments\n");
				break;
			}
			long n = atol(args[2]);
			printf("Reversed: %ld\n", reverse(n));
			break;
		}
		case RANDOM_IN_RANGE: {
			if (argNum < 4) {
				printf("Too few arguments\n");
				break;
			}
			int a = atoi(args[2]);
			int b = atoi(args[3]);
			printf("Random number: %d\n", randomInRange(a, b));
			break;
		}
		case GCD: {
			if (argNum < 4) {
				printf("Too few arguments\n");
				break;
			}
			long a = atol(args[2]);
			long b = atol(args[3]);
			printf("GCD: %ld\n", gcd(a, b));
			break;

		}
		case LCM: {
			if (argNum < 4) {
				printf("Too few arguments\n");
				break;
			}
			long a = atol(args[2]);
			long b = atol(args[3]);
			printf("LCM: %ld\n", lcm(a, b));
			break;
		}

    }
    return 0;
}

