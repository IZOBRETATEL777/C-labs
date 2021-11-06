#include "ex3_node.h"
#include <stdlib.h>
#include <stdio.h>

Node* append(Node* head, int newValue) {
    Node* newNode = nodeConstructor(newValue);
    while (head->next != NULL) {
        head = head->next;
    }
    head->next = newNode;
    return newNode;
}

Node* nodeConstructor(int value) {

    Node *node = (Node* )malloc(sizeof(Node));
    
    node->data = value;
    node->next = NULL;
    node->append = append;

    return node;
}

void traverse(Node* head) {
    while (head != NULL) {
        printf("Node at %p with value %d; Next node at %p\n", head, head->data, head->next);
        head = head->next;
    }
    
}

void nodeDestructor(Node* head) {
    if (head == NULL) {
        return;
    }
    nodeDestructor(head->next);
    free(head);
}
