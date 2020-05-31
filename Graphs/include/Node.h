typedef struct Node{

    float d;
    void *content;
    Node *pred;

} Node;

Node * buildNodes(int n);
void freeNode(Node *n);
void updatePred(Node *n, Node *new_pred);
void updateDistance(Node *n, float new_d);

