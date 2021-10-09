#include <stdio.h>

void getFibonacci(int n) {
	long long last = 1LL, cur = 1LL, t;
	for (int i = 1; i <= n; i++) {
		if (i == 1 || i == 2) {
			printf("%d ", 1);
		}
		else {
			t = cur;
			cur = t + last;
			printf("%d ", cur);
			last = t;

		}
	}
	printf("\n");
}

int main() {
	int n;
	printf("Enter a natural number: ");
	scanf("%d", &n);
	printf("The first %d Fibonacci numbers are:\n", n);
	getFibonacci(n);
	return 0;
}
