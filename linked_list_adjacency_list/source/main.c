#include <stdlib.h>
#include <stdio.h>

#include "../include/graph.h"
#include "../include/disjointed_paths.h"
#include "../include/tarjan.h"


int main(int argc, char const *argv[]){
    // int sorce, target;
    // FILE *file;
    // file = fopen("/home/gabriel/PUC_Trabalhos/graphs/linked_list_adjacency_list/data/test_graph.txt","r");
    // Graph g1;
    // start_graph(&g1, 5);
    // while (fscanf(file, "%d %d", &sorce, &target) == 2) {
    //     insert_edge(&g1, sorce, target);
    // }
    // printf("%d\n", has_two_disjoint_paths(&g1, 0, 4));
    // print_graph(&g1);
    List l1;
    start_list(&l1);
    for(int i = 0; i < 10000; i++){
        insert(&l1, i);
    }
    show_list(&l1);
    return 0;
}
