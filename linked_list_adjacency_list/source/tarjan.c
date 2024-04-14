#include <stdlib.h>
#include <stdio.h>

#include "../include/tarjan.h"
#include "../include/graph.h"




void insert(List *list, int element){
    list_cell *tmp = malloc(sizeof(list_cell));
    tmp->vertex = element;
    tmp->next = list->first->next;
    list->first->next = tmp;
}

void start_list(List *list){
    list->first = (list_cell*) malloc(sizeof(list_cell));
    list->first->next = NULL;
    list->first->vertex = -1;
    list->size = 0;
}

void show_list(List *list){
    printf("Articulations: {");
    for(list_cell *i = list->first->next; i != NULL; i = i->next){
        if(i->next != NULL){
            printf("%d,", i->vertex);
        }   
        else{
            printf("%d}\n", i->vertex);
        }
    }
}

void find_articulations(Graph *g1){
    
}

