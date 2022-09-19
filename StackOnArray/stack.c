#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <limits.h>
#include "stack.h"

bool push(Stack* stack, int n) {
	if (stack->size == stack->reseverd) {
		// increase capacity by 2 (more optimal)
		int newSize = stack->reseverd * 2; // temp array for storing current array + new element
		int *storage = (int*)malloc(newSize * sizeof(int));
		stack->reseverd = 2 * stack->size;
		if (storage == NULL) {
			// increase capacity on 1 if there is no free memory
			newSize = stack->reseverd + 1;
			storage = (int*)malloc(newSize * sizeof(int));
			if (storage == NULL) {
				return 0;
			}
		}
		// clean from memory old array and start to use a new one
		memcpy(storage, stack->storage, stack->size * sizeof(stack->storage));
		free(stack->storage);
		stack->storage = storage;
	}
	stack->storage[stack->size] = n;
	stack->size++;
	return 1;
}

int pop(Stack* stack) {
	if (stack->size == 0 ) {
		return INT_MIN;
	}
	stack->size--; // shitf the indicator of the last element
	return stack->storage[stack->size];
}

int top(Stack* stack) {
	return stack->storage[stack->size - 1];
}

bool isEmpty(Stack* stack) {
	if (stack->size == 0)
		return true;
	else
		return false;
}

Stack* construcStack() {
	Stack* stack = (Stack* )malloc(sizeof(Stack));
	stack->size = 0;
	stack->reseverd = 1;
	stack->storage = (int* )malloc(sizeof(int));
	stack->pop = pop;
	stack->push = push;
	stack->top = top;
	stack->isEmpty = isEmpty;
	return stack;
}

void destroyStack(Stack* stack) {
	free(stack->storage);
	free(stack);
}

