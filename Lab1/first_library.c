#include "first_library.h"
#include <stdio.h>
#include <stdlib.h>

long binaryToDecimal(long binary) {
	char sign = 0;
	long res = 0, p = 1;
	if (binary < 0) {
		sign = 1;
		binary *= -1;
	}
	while (binary > 0) {
		res += p * (binary % 10);
		binary /= 10;
		p <<= 1;
	}
	if (sign)
		res *= -1;
	return res;	
}

long decimalToBinary(long decimal) {
	char sign = 0;
	long res = 0, temp = 0;
	if (decimal < 0) {
		decimal *= -1;
		sign = 1;
	}
	while (decimal > 0) {
		temp = temp * 10 + (decimal % 2 == 0 ? 2 : 1);
		decimal /= 2;
	}
	while (temp > 0) {
		res = res * 10 + (temp % 10 == 1 ? 1 : 0);
		temp /= 10;
	}
	if (sign)
		res *= -1;
	return res;
}

double milesToKilometers(double miles) {
	if (miles < 0) {
		printf("Error\n");
		return -1;
	}

	return miles * 1.6;
}

double kilometersToMiles(double kilometers) {
	if (kilometers < 0) {
		printf("Error\n");
		return -1;
	}
	return kilometers / 1.6;
}

void primeCheck(long number) {
	long n = number;
	if (n < 2) {
		printf("Not Prime\n");
		return;
	}
	char prime = 1;
	long i = 2;
	while (i * i <= n) {
		prime &= (n % i != 0);
		i++;
	}
	if (prime) {
		printf("Prime\n");

	}
	else {
		printf("Not Prime\n");
	}
}

void palindromeCheck(long number) {
	long rev = reverse(number);
	if (rev == number) {
		printf("Palindrome\n");
	}
	else {
		printf("Not Palindrome\n");
	}
	
}

long reverse(long number) {
	char sign = 0;
	long res = 0;
	if (number < 0) {
		number *= -1;
		sign = 1;
	}
	while (number > 0) {
		res = res * 10 + (number % 10);
		number /= 10;
	}
	if (sign) {
		res *= -1;
	}
	return res;
}

int randomInRange(int min, int max) {
	int res = (rand() % (min - max + 1)) + min;	
	return res;
}

int gcd(int num1, int num2) {
	if (num1 < 0) {
		num1 *= -1;
	}
	if (num2 < 0) {
		num2 *= -1;
	}

	while (num1 != num2) {
		if (num1 > num2) {
			num1 -= num2;
		}
		else {
			num2 -= num1;
		}
	}
	return num1;
}

int lcm(int num1, int num2) {
	return num1 / gcd(num1, num2) * num2;
}

