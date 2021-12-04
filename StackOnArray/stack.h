#include <stdbool.h>

struct Stack {
	int size; // indicator that points to size or last_element_inedx+1
	int reseverd; // alloocated space
	int* storage; // array itselt
	bool (*push)(struct Stack*, int);
	int (*pop)(struct Stack*);
	int (*top)(struct Stack*);
	bool (*isEmpty)(struct Stack*);
};

typedef struct Stack Stack;

Stack* construcStack();
void destroyStack(Stack* stack);

