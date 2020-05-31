#include <stdio.h>
#include "Graph.h"

int main(){

    //We need a way to represent graphs

    int n = 5;

    Graph *g = buildEmptyGraph(n);
    //addEdge(g,1,1,2);
    fillGraph(g, 0.3);
    printGraph(g);

}