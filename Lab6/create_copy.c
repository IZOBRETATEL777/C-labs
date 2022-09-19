#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define BUFFERSIZE 6000

int main(int argsNum, char** args) {

	if (argsNum < 3) {
		printf("Too few arguments\n");
		return 0;
	}

	FILE* in = fopen(args[1], "r");
	if (in == NULL) {
		printf("Error while opening sourse file\n");
		exit(1);
	}

	FILE* out = fopen(args[2], "w");
	if (out == NULL) {
		printf("Error while opening destination file\n");
		exit(1);
	}

	char buffer[BUFFERSIZE];

	while (fgets(buffer, sizeof(buffer), in)) {
		fputs(buffer, out);
	}

	fflush(out);

	fclose(in);
	fclose(out);

	printf("Done!\n");
	return 0;
}
