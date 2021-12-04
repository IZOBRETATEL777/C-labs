#include "Deque.h"
#include <limits.h>
#include <stdio.h>

void debug(Deque* deque) {
	if (deque == NULL) {
		return;
	}
	Node *node = deque->front_tail;
	while (node != NULL) {
		printf("%d->", node->value);
		node = node->next;
	}
	printf("_______\n");
}

bool empty(Deque* deque) {
	return (deque->front_tail == NULL || deque->back_tail == NULL);
}

// pushing to the front means making node front_tail
void push_front(Deque* deque, int n) {
//	debug(deque);
	Node* node = nodeConstructor(n);
	if (empty(deque)) {
		deque->front_tail = node;
		deque->back_tail = node;
	}
	else {
		node->next = deque->front_tail;
		deque->front_tail->prev = node;
		deque->front_tail = node;
	}
//	debug(deque);
}
// pushing to the front means making node back_tail
void push_back(Deque* deque, int n) {
//	debug(deque);
	Node* node = nodeConstructor(n);
	if (empty(deque)) {
		deque->front_tail = node;
		deque->back_tail = node;
	}
	else {
		node->prev = deque->back_tail;
		deque->back_tail->next = node;
		deque->back_tail = node;
	}
//	debug(deque);
}

int front(Deque* deque) {
	return (empty(deque) ? INT_MIN : deque->front_tail->value);
}

int back(Deque* deque) {
	return (empty(deque) ? INT_MIN : deque->back_tail->value);
}
// poping front means making previos element front_tail
int pop_front(Deque* deque) {
//	debug(deque);
	if (empty(deque)) {
		return INT_MIN;
	}
	Node* node = deque->front_tail;
	int val = node->value;
	deque->front_tail = node->next;
	if (deque->front_tail == NULL)
		deque->back_tail = NULL;
	else
		deque->front_tail->prev = NULL;
	free(node);
	debug(deque);
	return val;
}
// poping back means making previos element back_tail
int pop_back(Deque* deque) {
	if (empty(deque)) {
		return INT_MIN;
	}
//	debug(deque);
	Node* node = deque->back_tail;
	int val = node->value;
	deque->back_tail = node->prev;
	if (deque->back_tail == NULL)
		deque->front_tail = NULL;
	else
		deque->back_tail->next = NULL;
	free(node);
//	debug(deque);
	return val;
}

Deque* dequeConstructor() {
	Deque* deque = (Deque*)malloc(sizeof(Deque));
	deque->back_tail = NULL;
	deque->front_tail = NULL;
	deque->pop_back = pop_back;
	deque->pop_front = pop_front;
	deque->back = back;
	deque->front = front;
	deque->push_back = push_back;
	deque->push_front = push_front;
	deque->empty = empty;
	return deque;
}

// Traverse and clean
void dequeDestructor(Deque* deque) {
	if (deque == NULL)
		return;

	Node *cur = deque->front_tail;
	while (cur != NULL) {
		Node *next = cur->next;
		nodeDestructor(cur);
		cur = next;
	}
	free(deque);
}
