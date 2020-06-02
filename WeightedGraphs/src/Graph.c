#include "Graph.h"
#include "binheap.h"

//Adjacency list representation is necessary to achieve the desired complexity
Graph * buildDisconnectedGraph(int n)
{

    Graph *g = (Graph*) malloc(sizeof(Graph));
    g->N = n;

    Node *V = buildNodes(n);

    g->adjacencyList = buildList(V,n,0, NULL);

    return g;

}

void destroyGraph(Graph *g){

    destroyList(g->adjacencyList, g->N);

    free(g);
}

//To add an edge to our graph, we will pass the indexes of the edge and its weight.
void addEdge(Graph *g, int i, int j, float w){

    ListOfNodes *tmp;

    tmp = &(g->adjacencyList[i]);

    while(tmp->next != NULL)
        tmp = tmp->next;

    tmp->next = buildList(g->adjacencyList[j].head, 1, w, &(g->adjacencyList[j])); //Add node j to adjacency list of node i
}

void fillGraph(Graph *g, float avDensity){

    if(avDensity < 0 || avDensity > 1){
        printf("Please provide a density in between [0,1]\n");
        exit(-1);
    }

    srand(10);
    for(size_t i = 0; i < g->N; ++i){
        for(size_t j = 0; j < g->N; ++j){
            float tmp = rand() % MAX_WEIGHT;

            if(tmp > (1-avDensity)*MAX_WEIGHT)
                addEdge(g, i, j, tmp);
        }
    }

}

void printGraph(Graph *g){

    ListOfNodes *tmp;

    for(size_t i = 0; i < g->N; ++i){

        tmp = &(g->adjacencyList[i]);
        printf("%d", tmp->head->id);

        while(tmp->next != NULL){
            printf(" -> (%d,%f) ", tmp->next->head->id, tmp->next->weight);
            tmp = tmp->next;
        }

        printf("\n\n");
    }
}

//The following two are auxiliary functions for Djikstra's algorithm

void init_SSSP(Graph *g){

    for(size_t i = 0; i < g->N; ++i){
        
        //In our representation N*MAX_WEIGHT + 1 is equivalent to infinity since every minimum path from a node
        //to another node contains every node of the graph at most once, therefore the max distance 
        //achievable for a minimum path is N*MAX_WEIGHT  
        g->adjacencyList[i].head->d = g->N*MAX_WEIGHT + 1; 
        g->adjacencyList[i].head->pred = NULL;
    }
}

// //This is actually done on a queue
void relax(Node *u, Node * v, float w){
    if(u->d + w < v->d){
        updateDistance(v, u->d + w);
        v->pred = u;
    }
}

void djikstra(Graph *g, int s){

    init_SSSP(g);
    g->adjacencyList[s].head->d = 0;

    Queue *q = buildQueue(g->adjacencyList, g->N);
    
    while(!isEmpty(q)){

        ListOfNodes *min = extractMin(q);
        ListOfNodes *tmp = min;

        while(tmp->next != NULL){
            tmp = tmp->next;
            relax(min->head, tmp->head, tmp->weight); //Relax between the extracted node and its neighbour on the queue
        }
    }

    destroyQueue(q);

}

void djikstraHeap(Graph *g, int s){

    init_SSSP(g);
    g->adjacencyList[s].head->d = 0;

    binheap_type *h = build_heap((void *) g->adjacencyList, g->N, g->N, sizeof(ListOfNodes), (total_order_type) compareListsLeq );

    while(!is_heap_empty(h)){

        ListOfNodes *min = (ListOfNodes *) extract_min(h);
        ListOfNodes *tmp = min;
        
        while (tmp->next != NULL)
        {
            tmp = tmp->next;
            relax(min->head, tmp->head, tmp->weight);
        }
        
    }

}

void printDistances(Graph *g){

    for(size_t i = 0; i < g->N; ++i){

        printf("(%d: %f)\t", g->adjacencyList[i].head->id, g->adjacencyList[i].head->d);
    }
    printf("\n");
}

float test(Graph *g, int k, void (*djik)(Graph *, int)){

    struct timespec start, end;

    clock_gettime(CLOCK_REALTIME, &start);
    for(size_t i = 0; i < REPS; ++i ){
        djik(g, k);
    }

    clock_gettime(CLOCK_REALTIME, &end);

    return ((end.tv_sec - start.tv_sec) +
          (end.tv_nsec - start.tv_nsec) / 1E9 ) / REPS;

}