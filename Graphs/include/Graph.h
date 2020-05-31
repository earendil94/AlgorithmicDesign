#include<stdio.h>
#include<stdlib.h>
#include "Node.h"

#define MAX_WEIGHT 100

typedef struct Graph{

    //Adjacency matrix: we will suppose that our weights can be float
    float **M;
    float N; //Number of nodes
    Node *nodes;

} Graph;

Graph * buildEmptyGraph(int n);
void destroyGraph(Graph *g);

//To add an edge to our graph, we will pass the indexes of the edge and its weight.
void addEdge(Graph *g, int i, int j, float w);
void fillGraph(Graph *g, float avDensity);
void printGraph(Graph *g);

//Djikstra Algorithm
void init_SSSP(Graph *g);