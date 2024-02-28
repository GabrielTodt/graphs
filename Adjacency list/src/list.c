#include <stdio.h>
#include "../include/list.h"

/**
 * @brief Returns the out-degree of the vertex.
 * 
 * @param vertex Desired vertex.
 * @param pointer Pointer array of the adjacency list.
 * @return int Out-degree of the vertex.
 */
int output_degree(int vertex, int *pointer) {
    return (pointer[vertex] - pointer[vertex - 1]); // The graph labels aren't zero-indexed.
}

/**
 * @brief Returns the set of successors of a vertex in a graph.
 * 
 * @param vertex Vertex to be searched.
 * @param pointer Pointer array of the adjacency list.
 * @param target Target array of the graph edges.
 * @param set Array where the successors will be stored.
 * @return Returns 0 when the method works or -1 in case of failure.
 */
int successors_set(int vertex, int *pointer, int *target, int *set) {
    if (set == NULL)
        return -1;
    int n = pointer[vertex] - pointer[vertex - 1];
    for (int i = 0; i < n; i++) {
        set[i] = target[pointer[vertex + i]];
    }

    return 0;
}

/**
 * @brief Creates a pointer array object.
 * 
 * @param source Array containing the output vertices of the edges.
 * @param pointer Array where the pointers will be stored.
 * @param vertices Number of vertices in the graph.
 */
void create_pointer_array(int *source, int *pointer, int vertices) {
    int j = 0;
    for (int i = 0; i < vertices + 1; i++) {
        pointer[i] = j + 1;
        while (source[j] == source[j + 1]) {
            j++;
        }
        j++;
    }
}
