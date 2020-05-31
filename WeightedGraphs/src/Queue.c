#include "Queue.h"

Queue * buildQueue(ListOfNodes *l,int n){

    Queue *q;
    q = malloc(sizeof(Queue));

    q->size = n;  
    q->v = l; //Shallow copy
    q->n_elem = n; //Queue is full at the beginning
    
    return q;
}

void destroyQueue(Queue *q){

    free(q);
}

int isEmpty(Queue *q){

    if(q->n_elem == 0)
        return 1;
    
    return 0;
}

ListOfNodes * extractMin(Queue *q){

    ListOfNodes *tmp_min = &(q->v[0]);

    for(size_t i = 1; i < q->n_elem; ++i){
        if(q->v[i].head->d < tmp_min->head->d) //TODO:here's the comparison
            tmp_min = &(q->v[i]);
    }

    //printf("Min d: %f\n", tmp_min->head->d);

    swapLists(tmp_min, &(q->v[q->n_elem-1]));
    q->n_elem--;

    return &(q->v[q->n_elem]);
    //return tmp_min;
}