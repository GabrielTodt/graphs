#include <stdio.h>
#include <stdlib.h>

#include "../include/graph.h"
#include "../include/disjointed_paths.h"



void deep_first_search(Graph *graph, int source, int target,int *time, int *found, int discovery[]){
    printf("testing: %d\n", source);
    if(source == target){
        printf("found\n");
        *found = 1;
        return;
    }
    *time +=1;

    discovery[source] = *time;
    for(Cell *i = graph->List[source].next; i != NULL && *found != 1; i = i->next){
        if(discovery[i->vertex] == 0){
            deep_first_search(graph, i->vertex, target, time, found, discovery);
        }
    }
    *time +=1;
}

int has_two_disjoint_paths(Graph *graph, int source, int target){
    int time = 0;
    int found = 0;
    int discovery[graph->vertices];    
    for(int i = 0; i < graph->vertices; i++){
        discovery[i] = 0;
    }
    deep_first_search(graph, source, target, &time, &found, discovery);
    if(found != 1){
        printf("got here\n");
        return -1;
    }
    discovery[source] = 0;
    found = 0;
    deep_first_search(graph, source, target, &time, &found, discovery);  
    if(found != 1){
        printf("Got here 2\n");
        return -1;
    }
    for(int i = 0; i< graph->vertices; i++){
        printf("%d, ", discovery[i]);
    }
    printf("\n");
    return 1;

}
