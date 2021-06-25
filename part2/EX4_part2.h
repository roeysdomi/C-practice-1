#include <stdbool.h>

typedef struct Node{struct Node* next; char letter;} Node;
void add(Node* node);
void push(char letter);
bool pop(char letter);
bool isStringBalanced(char** sentence,int size);
Node* newNode(char data);

