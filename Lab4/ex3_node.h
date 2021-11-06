//recursive struct
struct Node {
    int data;
    struct Node *next;
    struct Node* (*append)(struct Node* self, int newValue);
};

typedef struct Node Node;

//constructs a single node
Node* nodeConstructor(int value);

//appends to the end of the recursive structure a new node
//returns a node that was inserted 
Node* append(Node* head, int newValue);

//prints all structure from head to tail
void traverse(Node* head);

// Node* head; [ data = 1, next = Node{ data = 2, next = NULL} ]
// traverse(head) -> print (1) 

//for additional practice
void nodeDestructor(Node* head);
