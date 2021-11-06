#include "ex3_node.h"
#include <stdio.h>
#include <stdbool.h>

int main() {
    printf("Hello! This is the program that will maintain a linked list!\n");
    char cmd;
    int value;
    Node *head = NULL;
    bool run = true;
    while (run) {
        printf("Enter an operation that you want to do:\n");
        printf("[1]Add number\n[2]Show numbers\n[0]Exit\n:");
        scanf(" %c", &cmd); //avoid new line or space character
        switch (cmd)
        {
        case '0':
            printf("Bye!\n");
            run = false;
            nodeDestructor(head);
            break;
        case '1':
            printf("Enter a value: ");
            scanf("%d", &value);
            if (head == NULL) {
                head = nodeConstructor(value);
                printf("Linked list established at %p\n", head);
            }
            else {
                printf("Added to %p\n", append(head, value));
            }
            break;
        case '2':
            traverse(head);
            break;
        default:
            printf("Operation is not found! Try again!\n");
            break;
        }
    }
    

    return 0;
}