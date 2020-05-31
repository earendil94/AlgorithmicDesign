#include "Node.h"

Node * buildNodes(int n){

    Node *k = malloc(sizeof(Node)*n);
    return k;

}

void freeNode(Node *n){

    free(n);
}

void updatePred(Node *n, Node *new_pred){
    n->pred = new_pred;
}

void updateDistance(Node *n, float new_d){
    n->d = new_d;
}