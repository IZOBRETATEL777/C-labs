#include <stdio.h>
#include <stdbool.h>
#include "Deque.h"

int main() {
    Deque* deque = dequeConstructor();	
    bool go = true;
    printf("Welcome to doubled-queue manipulating program!\n");
    while (go) {
        int cmd, n;
        printf("Enter a command to continue.\n 1 - push a number to the front of deque\n 2 - pop from the front\n 3 - print front\n 4 - push to the back of deque\n 5 - pop from the back\n 6 - print back\n 0 - exit\n");
        scanf("%d", &cmd);
        switch (cmd) {
            case 0:
                go = false;
                break;
            case 1:
                printf("Enter a number: ");
                scanf("%d", &n);
                deque->push_front(deque, n);
                break;
            case 2:
                deque->empty(deque) ?
                printf("Deque is empty!\n") :
                printf("Deque was poped from the front! Value %d removed\n", deque->pop_front(deque));
                break;
            case 3:
                deque->empty(deque) ?
                printf("Deque is empty!\n") :
                printf("Number %d is on the front of deque\n", deque->front(deque));
                break;
            case 4:
                printf("Enter a number: ");
                scanf("%d", &n);
                deque->push_back(deque, n);
                break;
            case 5:
                deque->empty(deque) ?
                printf("Deque is empty!\n") :
                printf("Deque was poped from the back! Value %d removed\n", deque->pop_back(deque));
                break;
            case 6:
                deque->empty(deque) ?
                printf("Deque is empty!\n") :
                printf("Number %d is on the back of deque\n", deque->back(deque));
                break;
            default:
                printf("I don't know\n");
        }
    }
    dequeDestructor(deque);
    return 0;
}
