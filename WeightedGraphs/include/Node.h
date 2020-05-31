#ifndef __NODE__H_
#define __NODE__H_

#include<stdio.h>
#include<stdlib.h>
#include "binheap.h"

#define NEXTLIST(L, n) (L+n * sizeof(ListOfNodes))

typedef struct Node{

    float d;
    int id;
    struct Node *pred;

} Node;

typedef struct ListOfNodes{

    Node *head;
    float weight;
    struct ListOfNodes *next;
    struct ListOfNodes *actualHead; //I still don't clearly get why, but this arrow seems important
    

} ListOfNodes;

Node * buildNodes(int n);
void freeNode(Node *n);
Node * copyNode(Node *n);
void swapNodes(Node *n1, Node *n2);
void updatePred(Node *n, Node *new_pred);
void updateDistance(Node *n, float new_d);

ListOfNodes * buildList(Node *k, int n, float weight, ListOfNodes *actHead); //Build a list out of an already existing array of nodes
void destroyList(ListOfNodes *l, int n);
//ListOfNodes * copyList(ListOfNodes *l);
void swapLists(ListOfNodes *l1, ListOfNodes *l2);
void addNext(ListOfNodes *l, ListOfNodes * n); //Add a node to a single list

int compareListsLeq(void *a, void *b);
void printList(const void *a);

#endif