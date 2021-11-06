//recursive struct
struct Node {
    int data;
    struct Node* next;
};
typedef struct Node Node;


//appends to the end of the recursive structure a new node
Node* append(Node* head, int newValue);

//prints all structure from head to tail
void traverse(Node* head);

//constructs a single node
Node* nodeConstructor(int value);

//for additional practice
void nodeDestructor(Node* head);
