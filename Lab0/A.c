#include <stdio.h>

int main() {
	char c;
	scanf("%c", &c);
	if ('A' <= c && c <= 'Z') {
		printf("Upper case letter\n");
	}
	else if ('a' <= c && c <= 'z') {
		printf("Lower case letter\n");
	}
	else if ('0' <= c && c <= '9') {
		printf("Digit\n");
	}
	else if (c == ' ' || c == '\t' || c == '\n') {
		printf("White space\n");
	}
	return 0;
}
