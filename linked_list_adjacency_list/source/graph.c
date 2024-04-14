#include <stdlib.h>
#include <stdio.h>

#include "../include/graph.h"
void start_graph(Graph *target, int vertices){
    target->List = (Cell *) malloc(vertices*(sizeof(Cell)));
    target->vertices = vertices;
    for(int i = 0; i < vertices; i++){
        target->List[i].vertex = i;
        target->List[i].next = NULL;
    }
}

void insert_edge(Graph *target,int v, int w){
    Cell *tmp = malloc(sizeof(Cell));
    tmp->vertex = w;
    tmp->next = target->List[v].next;
    target->List[v].next = tmp;

    Cell *tmp1 = malloc(sizeof(Cell));
    tmp1->vertex = v;
    tmp1->next = target->List[w].next;
    target->List[w].next = tmp1;
}

void print_graph(Graph *target){
    printf("Number of vertices: %d\n",target->vertices);
    for(int i = 0; i < target->vertices; i++){
        printf("%d -> {", target->List[i].vertex);
        for(Cell *j = target->List[i].next; j!=NULL; j = j->next){
            if(j->next == NULL){
                printf("%d}",j->vertex);    
            }
            else{
                printf("%d,",j->vertex);
            }
        }
        printf("\n");
    }
}