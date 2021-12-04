
// Element of a deque that ressemble to the double linked list
struct Node {
	int value;
	struct Node* prev; // previos element
	struct Node* next; // next
};

typedef struct Node Node;

Node* nodeConstructor(int val);
void nodeDestructor(Node* node);

