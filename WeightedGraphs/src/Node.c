#include "Node.h"

Node * buildNodes(int n){

    Node *k = malloc(sizeof(Node)*n); //Builds a possible array of nodes
    
    for(size_t i = 0; i < n; ++i)
        k[i].id = i;

    return k;
}

Node * copyNode(Node * n){

    Node *new = malloc(sizeof(Node));

    new->d = n->d;
    new->id = n->id;
    new->pred = n->pred;

    return new;
}

void swapNodes(Node *n1, Node *n2){

    Node *tmp = copyNode(n1);
    *n1 = *copyNode(n2);
    *n2 = *copyNode(tmp);
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

ListOfNodes * buildList(Node *k, int n, float weight, ListOfNodes *actHead){

    ListOfNodes *l = malloc(sizeof(ListOfNodes)*n);

    for(size_t i = 0; i < n; ++i){
        l[i].head = &(k[i]);
        l[i].weight = weight;
        l[i].next = NULL;
        l[i].actualHead = actHead;
    }

    return l;
}

void destroyList(ListOfNodes *l, int n){

    int k;

    ListOfNodes *tmp, *tmp2;

    //This is a bit cumbersome: since I am attaching the same memory storing nodes as "next" elements of the adjacency lists, then
    //I need just to free the nodes once at the end, but I need to free up the space for all the ListOfNodes created in between
    //And this is what is one in the inside while loop: the two tmps are used to both keep the pointer to the next element to free of the list
    //And to the actual element to free.

    for(size_t i = 0; i < n; ++i){
        if(l[i].head->id == 0)
            k = i;

        tmp = l[i].next;
        while(tmp != NULL){
            tmp2 = tmp;
            tmp = tmp->next;
            free(tmp2);          
        }
    }
    


    freeNode(l[k].head);
    free(l);

}

void addNext(ListOfNodes *l, ListOfNodes *n){

    l->next = n;
}

void swapLists(ListOfNodes *l1, ListOfNodes *l2){

    ListOfNodes *tmp = malloc(sizeof(ListOfNodes));

    *tmp = *l2;
    *l2 = *l1;
    *l1 = *tmp;

    free(tmp);
}


//Function needed/useful to work with heaps
int compareListsLeq(void *a, void *b){

    //This only works with list of nodes due to the explicit cast here
    ListOfNodes al = *((ListOfNodes *) a);
    ListOfNodes bl = *((ListOfNodes *) b);

    return (al.head->d < bl.head->d );

}


void printList(const void *a){

    ListOfNodes *al = (ListOfNodes *) a;

    printf("%d", al->head->id);

    while(al->next != NULL){
        printf(" -> %d", al->next->head->id);
        al = al->next;
    }
    printf("\n");
}