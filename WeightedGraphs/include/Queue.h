#ifndef __QUEUE_H__
#define __QUEUE_H__

#include "Node.h"

#define NEXTNODE(v, n) (v+n * sizeof(Node))

typedef struct Queue{

    ListOfNodes *v; //This and not nodes otherwise I have no way to collect 
    int size;
    int n_elem;

} Queue;

Queue * buildQueue(ListOfNodes *l, int n);
void destroyQueue(Queue *q);
ListOfNodes * extractMin(Queue *q);
int isEmpty(Queue *q);


#endif