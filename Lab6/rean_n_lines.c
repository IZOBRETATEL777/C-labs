#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define BUFFERSIZE 6000


void head(FILE* in, int numberOfLines) {
	char buffer[BUFFERSIZE];
	while (fgets(buffer, sizeof(buffer), in) != NULL && numberOfLines -->0) {
		fputs(buffer, stdout);
	}
	if (numberOfLines > 1) {
		printf("Cannot find more lines :(\n");
	}

}

void tail(FILE* in, int numberOfLines) {
	char buffer[BUFFERSIZE];
	fseek(in, 0, SEEK_END);
	int last = ftell(in);
	while (last-- && numberOfLines >= 0) {
		fseek(in, last, SEEK_SET);
		if (fgetc(in) == '\n') {
			numberOfLines--;
		}
	}
	while(fgets(buffer, sizeof(buffer), in)) {
		fputs(buffer, stdout);
	}
	if (numberOfLines > 0) {
		printf("Cannot find more lines :(\n");
	}


}

int main(int argsNum, char** args) {

	if (argsNum < 4) {
		printf("Too few arguments\n");
		return 0;
	}

	FILE* in = fopen(args[1], "r");
	if (in == NULL) {
		printf("Error while opening sourse file\n");
		exit(1);
	}
	int numberOfLines = atoi(args[2]);
	char* strategy = args[3];

	if (strcmp(strategy, "first") == 0) {
		head(in, numberOfLines);
	}
	else if (strcmp(strategy, "last") == 0) {
		tail(in, numberOfLines);
	}
	else {
		printf("The last parametes is unknown\n");
	}

	fclose(in);
	printf("Done!\n");
	return 0;

}

