#include <stdio.h>
#include <stdlib.h>

#include "../include/list.h"

#define MAX_LINE_LENGTH 25

int main(int argc, char const *argv[])
{   
    const char *file_path = argv[1];
    int vertex = atoi(argv[2]);

    FILE *fp = fopen(file_path, "r");
    if (fp == NULL){
        return -1;
    }    
    char line[MAX_LINE_LENGTH] = {0};
    fgets(line, MAX_LINE_LENGTH, fp);
    int num_vertexes = 0;
    int edges = 0;
    fflush(stdin);
    sscanf(line, "%d %d", &num_vertexes, &edges);
    const int source_target_size = edges+1;
    const int pointer_size = num_vertexes+2;
    int source[source_target_size];
    int target[source_target_size];
    int pointer[pointer_size];
    //Read file input
    for(int i=1; i<=edges; i++){
        fflush(stdin);
        fgets(line, MAX_LINE_LENGTH, fp);
        sscanf(line, "%d %d", &source[i], &target[i]);
    }
    //Create pointer array
    create_pointer_array(source, pointer, num_vertexes);

    int output_dg = output_degree(vertex, pointer);
    int input_dg = input_degree(vertex, target, source_target_size);
    int *sucessors = (int *) malloc(output_dg*sizeof(int));   
    int *predecessors = (int *) malloc(input_dg*sizeof(int));
    sucessors_set(vertex, pointer, target, sucessors);
    predecessors_set(vertex, pointer, pointer_size, target, predecessors);

    printf("Vertex: %d\n", vertex);
    printf("Output degree: %d\n", output_dg);
    printf("Input degree: %d\n", input_dg);
    printf("Sucessors set: [ ");
    for(int i=0; i<output_dg; i++){
        printf("%d ", sucessors[i]);
    }
    printf("]\n");
    printf("Predecessors set: [ ");
    for(int i=0; i<input_dg; i++){
        printf("%d ", predecessors[i]);
    }
    printf("]\n");

    
    return 0;
}


