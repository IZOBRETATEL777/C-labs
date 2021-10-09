#include <stdio.h>

int bin_to_dec(int n) {
	char sign = 0;
	if (n < 0) {
		sign = 1;
		n *= -1;
	}
	int res = 0, p = 1;
	while (n > 0) {
		int d = n % 10;
		if (d != 1 && d != 0) {
			return -2;
		}
		res += d * p;
		n /= 10;
		p <<= 1;
	}
	if (sign)
		res *= -1;
	return res;
}

int dec_to_bin(int n) {
	char sign = 0;
	if (n < 0) {
		n *= -1;
		sign = 1;
	}
	int res = 0;
	while (n > 0) {
		res = res * 10 + (n % 2 == 0 ? 2 : 1);
		n /= 2;
	}
	int ans = 0;
	while (res > 0) {
		ans = ans * 10 +  (res % 10 == 1 ? 1 : 0);
		res /= 10;
	}
	if (sign)
		ans *= -1;
	return ans;
}


int main() {
	printf("What I should do?\n[1] Convert to decimal\n[2] Convert to binary\nEnter the number of option: ");
	int cmd, res, n;
	scanf("%d", &cmd);
	if (cmd == 1 || cmd == 2) {
		printf("Enter a number: ");
		scanf("%d", &n);
	}
	else {
		printf("Wrong option!");
	}
	if (cmd == 1) {
		res = bin_to_dec(n);
		if (res == -2) {
			printf("Impossible to convert!");
		}
		else {
			printf("%d", res);
		}
	}
	else if (cmd == 2) {
		res = dec_to_bin(n);
		printf("%d", res);
	}
	printf("\n");
	return 0;
}
