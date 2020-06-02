#include <stdio.h>
#include "Graph.h"

int main(){

    Graph * g = buildDisconnectedGraph(10);
    fillGraph(g, 0.5);
    printGraph(g);
    destroyGraph(g);

    Graph *f;

    printf("*** Execution time test of the Djikstra algorithm ***\n\n");
    printf("Dimension\tArray Based\t\tHeap Based\n");

    for(size_t i = 2; i <= 1024; i*=2){
        g = buildDisconnectedGraph(i);
        f = buildDisconnectedGraph(i);
        fillGraph(g, 0.4);
        fillGraph(f, 0.4);
        printf("%ld\t\t%f\t\t%f\n", i, test(g, 0, djikstra), test(f, 0, djikstraHeap));
        destroyGraph(g);
        destroyGraph(f);
    }

}