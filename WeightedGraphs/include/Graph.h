#ifndef __GRAPH_H_
#define __GRAPH_H_

#include <stdio.h>
#include <stdlib.h>
#include "Node.h"
#include "Queue.h"
#include <time.h>

#define MAX_WEIGHT 10 //An upper bound for the weights of the graphs
#define REPS 10 //Number of repetitions of our test algorithm.


/**********************************************************************
 * An implementation of the Graph data structure.
 *
 * This struct implements the graph as an adjacency list
 * 
 **********************************************************************/
typedef struct Graph{

    float N; //Number of nodes
    ListOfNodes *adjacencyList; //This will be an array of lists of nodes

} Graph;

/**********************************************************************
 * A constructor for the Graph struct.
 *
 * This allocates in the heap and returns an empty Graph structure.
 * 
 * @param n is the number of vertices in the graph 
 **********************************************************************/
Graph * buildDisconnectedGraph(int n);

/**********************************************************************
 * A destructor for the Graph struct.
 *
 * This will free the memory of a graph built using buildDisconnectedGraph
 * 
 * @param g is the graph to be destroyed
 **********************************************************************/
void destroyGraph(Graph *g);

/**********************************************************************
 * A function to add an edge to a specific Graph.
 *
 * This function is used in order to add a single edge in between to vertices of a 
 * given graph assigning a weight to it.
 * 
 * @param g is the graph on which we want to add an edge
 * @param i is the source vertex of the edge
 * @param j is the destination vertex of the edge
 * @param w is the weight of the edge
 **********************************************************************/
void addEdge(Graph *g, int i, int j, float w);

/**********************************************************************
 * A function to build random edges on a specific Graph.
 *
 * This function is used to generate random edges in between the vertices
 * of a given graph. It is possible to choose the average quantity of 
 * edges that will be created
 * 
 * @param g is the graph on which we want to add edges
 * @param avDensity has to be a number in between [0,1] which
 * acts as a filling rate for the graph. The lower, the sparser the graph.
 **********************************************************************/
void fillGraph(Graph *g, float avDensity);

/**********************************************************************
 * A function to print a specific Graph.
 *
 * This function prints the given graph as an adjacency list on the
 * terminal window.
 * 
 * @param g is the graph to be printed.
 **********************************************************************/
void printGraph(Graph *g);

/**********************************************************************
 * A function to print distances stored in the vertices of a graph.
 *
 * This function is possibily used after an execution of the Djikstra
 * algorithm so that distances from a given source vertex have been updated.
 * 
 * @param g is the graph for which we want to print distances.
 **********************************************************************/
void printDistances(Graph *g);

//Djikstra Algorithm section

/**********************************************************************
 * A function used as initialization for the Djikstra algorithm.
 *
 * This function SHOULD NOT BE CALLED in the main, it is an auxiliary
 * function for the Djikstra procedure
 * 
 * @param g is the graph for which we want to print distances.
 **********************************************************************/
void init_SSSP(Graph *g);

/**********************************************************************
 * A function used to update distances in the Djikstra algorithm.
 *
 * This function SHOULD NOT BE CALLED in the main, it is an auxiliary
 * function for the Djikstra procedure
 * 
 * @param u is the source node.
 * @param v is the destination node.
 * @param w is the weight of the edge (u,v).
 **********************************************************************/
void relax(Node *u, Node * v, float w);

/**********************************************************************
 * An implementation of the array based Djikstra Algorithm.
 *
 * This function implements the Djikstra algorithm in order to find the 
 * SSSP from a given source vertex. The queue data structure described
 * in the meta-algorithm is implemented using arrays.
 * 
 * @param g is the graph on which to call the Djikstra Algorithm
 * @param s is the index of the node to be used as source.
 **********************************************************************/
void djikstra(Graph *g, int s);

/**********************************************************************
 * An implementation of the heap based Djikstra Algorithm.
 *
 * This function implements the Djikstra algorithm in order to find the 
 * SSSP from a given source vertex. The queue data structure described
 * in the meta-algorithm is implemented using binary heaps.
 * 
 * @param g is the graph on which to call the Djikstra Algorithm
 * @param s is the index of the node to be used as source.
 **********************************************************************/
void djikstraHeap(Graph *g, int s);

/**********************************************************************
 * A function used to test the execution time of the implementations of
 * the Djikstra algorithm.
 *
 * This function computes the average execution time of the given
 * implementation of the Djikstra Algorithm, computed on a number of
 * repetitions equal to the one defined by the macro @REPS.
 * 
 * @param g is the graph on which to test the Djikstra algorithm.
 * @param k is the index of the source node needed by Djikstra
 * @param djik is the specific implementation of the Djikstra
 * algorithm (currently available: array based and heap based).
 **********************************************************************/
float test(Graph *g, int k, void (*djik)(Graph *, int));

#endif