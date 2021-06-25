typedef struct Node{int data; struct Node* next; struct Node* prev; int place;}Node;

int take(int num);
void add(Node* node);
Node* newNode(int data);
void updateMid();
void updatePlaces(Node* tmp);
int take2(int num);

