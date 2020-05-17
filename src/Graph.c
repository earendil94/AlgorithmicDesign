#include "Graph.h"

Graph * buildEmptyGraph(int n)
{

    Graph *g = (Graph*) malloc(sizeof(Graph));
    g->N = n;
    g->nodes = buildNodes(n);
    g->M = (float**) malloc(sizeof(float*) *n);

    for(size_t i = 0; i < n; ++i)
        g->M[i] = (float*) malloc(sizeof(float) * n);

    return g;

}

void destroyGraph(Graph *g){

    for(size_t i = 0; i < g->N; ++i)
        free(g->M[i]);

    free(g->M);

    freeNode(g->nodes);

}

//To add an edge to our graph, we will pass the indexes of the edge and its weight.
void addEdge(Graph *g, int i, int j, float w){

    g->M[i][j] = w;
}

void fillGraph(Graph *g, float avDensity){

    srand(10);
    for(size_t i = 0; i < g->N; ++i){
        for(size_t j = 0; j < g->N; ++j){
            float tmp = rand() % MAX_WEIGHT;

            if(tmp > (1-avDensity)*MAX_WEIGHT)
                g->M[i][j] = tmp;
        }
    }

}

void printGraph(Graph *g){

    for(size_t i = 0; i < g->N; ++i){
        for(size_t j = 0; j < g->N; ++j)
            printf("%f\t", g->M[i][j]);
        
        printf("\n\n");
    }
}

//The following are all auxiliary function for Djikstra's algorithm

void init_SSSP(Graph *g){

    for(size_t i = 0; i < g->N; ++i){
        
        //In our representation N*MAX_WEIGHT + 1 is equivalent to infinity since every minimum path from a node
        //to another node contains at most once every node of the graph, therefore having distance n*max_weight 
        g->nodes[i].d = g->N*MAX_WEIGHT + 1; 
        g->nodes[i].pred = NULL;
    }
}

//This is actually done on a queue
void relax(Queue *q, Node *u, Node * v, float w){
    if(u->d + w < v->d){
        updateDistance(v, u->d + w);
        v->pred = u;
    }
}

void djikstra(Graph *g, int s){

    init_SSSP(g);
    g->nodes[s].d = 0;

    Queue *q = buildQueue(g->nodes);
    
    while(!isEmpty(q)){

        Node *tmp = extractMin(q);
        for()
    }

}