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

    char line[MAX_LINE_LENGTH]= {0};
    fgets(line, MAX_LINE_LENGTH, fp);
    int vertices = 0;
    int edges = 0;
    fflush(stdin);
    sscanf(line, "%d %d", &vertices, &edges);
    printf("%d -> Vertices\n%d -> Arestas\n", vertices, edges);

    int source[edges];
    int target[edges];
    int pointer[vertices+1];
    //Read file input
    for(int i=0; i<edges; i++){
        fflush(stdin);
        fgets(line, MAX_LINE_LENGTH, fp);
        sscanf(line, "%d %d", &source[i], &target[i]);
    }
    //Create pointer array
    create_pointer_array(source, pointer, vertices);

    //tests
    //print the source --> target arrays
    // for(int i=0; i<edges; i++) {
    //     printf("%d: %d --> %d\n", i+1, source[i], target[i]);
    // }

    //print the pointer array.
    // for(int i =0; i<vertices+1; i++){
    //     printf("%d, ",pointer[i]);
    // }

    printf("\ndegree: %d\n",output_degree(vertex, pointer));
    
    int *set = (int *) malloc((pointer[vertex] - pointer[vertex-1]) * sizeof(int));     
    sucessors_set(vertex, pointer, target, set);
    for(int i=0; i<(pointer[vertex] - pointer[vertex-1]); i++){
        printf(" -> %d\n", set[i]);
    }

    return 0;
}

