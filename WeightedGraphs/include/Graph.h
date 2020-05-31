#ifndef __GRAPH_H_
#define __GRAPH_H_

#include <stdio.h>
#include <stdlib.h>
#include "Node.h"
#include "Queue.h"
#include <time.h>

#define MAX_WEIGHT 10
#define REPS 10

typedef struct Graph{

    //Adjacency matrix: we will suppose that our weights can be float
    float N; //Number of nodes
    ListOfNodes *adjacencyList; //This will be an array of lists of nodes

} Graph;

Graph * buildDisconnectedGraph(int n);
void destroyGraph(Graph *g);

//To add an edge to our graph, we will pass the indexes of the edge and its weight.
void addEdge(Graph *g, int i, int j, float w);
void fillGraph(Graph *g, float avDensity);
void printGraph(Graph *g);
void printDistances(Graph *g);

//Djikstra Algorithm
void init_SSSP(Graph *g);
void relax(Node *u, Node * v, float w);
void djikstra(Graph *g, int s);
void djikstraHeap(Graph *g, int s);

float test(Graph *g, int k, void (*djik)(Graph *, int));

#endif