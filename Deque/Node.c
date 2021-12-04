#include <stdlib.h>
#include "Node.h"

Node* nodeConstructor(int val) {
	Node *node = (Node* )malloc(sizeof(Node));
	node->next = NULL;
	node->prev = NULL;
	node->value = val;
	return node;
}

void nodeDestructor(Node* node) {
	if (node != NULL) {
		free(node);
	}
}
