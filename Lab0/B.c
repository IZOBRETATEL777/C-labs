#include <stdio.h>

int factorial(int n) {
	int res = 1;
	for (int i = 2; i <= n; i++) {
		res *= i;
	}
	return res;
}

int main() {
	int n;
	printf("Enter an integer: ");
	scanf("%d", &n);
	if (n > 27) {
		printf("Sorry, our answer will be incorrect since the given number is too big :(\n");
	}
	printf("%d! = %d\n", n, factorial(n));

	return 0;
}
