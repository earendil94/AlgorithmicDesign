#include <stdio.h>
#include "Graph.h"

int main(){

    //We need a way to represent graphs

    for(size_t i = 2; i <= 1024; i*=2){
        Graph * g = buildDisconnectedGraph(i);
        fillGraph(g, 0.4);
        printf("Average test on dimension %ld, array based: %f\n", i, test(g, 0, djikstra));
        destroyGraph(g);
        //printf("i : %ld\n", i);
    }



}