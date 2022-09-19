#include <stdio.h>
#include <stdbool.h>
#include "stack.h"

int main() {
    Stack* stack = construcStack();
    bool go = true;
    printf("Welcome to stack manipulating program!\n");
    while (go) {
        int cmd, n;
        printf("Enter a command to continue.\n 1 - push a number to the stack\n 2 - pop\n 3 - print top\n 4 - print size\n 0 - exit\n");
        scanf("%d", &cmd);
        switch (cmd) {
            case 0:
                go = false;
                break;
            case 1:
                printf("Enter a number: ");
                scanf("%d", &n);
                stack->push(stack, n);
                break;
            case 2:
                stack->isEmpty(stack) ?
                printf("Stack is empty!\n") :
                printf("Stack was poped! Value %d removed\n", stack->pop(stack));
                break;
            case 3:
                stack->isEmpty(stack) ?
                printf("Stack is empty!\n") :
                printf("Number %d is on the top of the stack\n", stack->top(stack));
                break;
            case 4:
                printf("Size of the stack is %d\n", stack->size);
                break;
            default:
                printf("I don't know\n");
        }
    }
    destroyStack(stack);
    return 0;
}
