#include "Node.h"
#include "stdbool.h"
#include <stdlib.h>

/*
f_tail		  b_tail
 	<-------->
*/
struct Deque {
	Node* front_tail; // pointer to the head or front tail
	Node* back_tail;// pointer to the tail or back tail

	bool (*empty)(struct Deque*);
	int (*back)(struct Deque*);
	int (*front)(struct Deque*);
	int (*pop_front)(struct Deque*);
	int (*pop_back)(struct Deque*);
	void (*push_front)(struct Deque*, int);
	void (*push_back)(struct Deque*, int);

};

typedef struct Deque Deque;

Deque* dequeConstructor();	
void dequeDestructor(Deque* deque);

