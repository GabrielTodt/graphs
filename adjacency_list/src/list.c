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
    return (pointer[vertex+1]-pointer[vertex]);
}
/**
 * @brief Retrieves the number of edges incident on the vertex. The search is performed
 * linearly since the forward star data structure is used.
 * 
 * @param vertex Desired vertex.
 * @param target Graph's destination vector.
 * @param target_size Size of the target vector.
 * @return int Outdegree of the vertex.
 */
int input_degree(int vertex, int *target, int target_size){
    int degree = 0;
    for(int i=1; i<target_size;i++){
        if (target[i] == vertex)
            degree++;
    }
    return degree;
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
int sucessors_set(int vertex, int *pointer, int *target, int *set) {
    if (set == NULL)
        return -1;
    int n = pointer[vertex+1];
    int count = 0;
    for(int i = pointer[vertex]; i<n; i++){
        set[count++] = target[i];
    }
    return 0;
}
/**
 * @brief Searches for the set of predecessors of a vertex in a graph.
 * Since the structure used is a forward star adjacency list,
 * this method is not efficient. To improve efficiency, a reverse star
 * list should be used.
 * 
 * @param vertex Vertex to be searched.
 * @param pointer Array of pointers to the adjacency list.
 * @param pointer_size Size of the pointer array.
 * @param target Adjacency list destination vector.
 * @param set Vector where the set will be written.
 * @return Returns 0 on success or -1 on failure.
 */
int predecessors_set(int vertex, int *pointer,int pointer_size, int *target, int *set){
    if (set == NULL){
        return -1;
    }
    int count = 0;
    for(int i=1; i < pointer_size-1; i++){
        int n = pointer[i+1];
        for(int j=pointer[i]; j<n; j++){
            if(target[j] == vertex){
                set[count++] = i;
            }
        }
    }
    return 0;
}



/**
 * @brief Creates a pointer array. Each element poits to the target array index.
 * 
 * @param source Array containing the output vertices of the edges.
 * @param pointer Array where the pointers will be stored.
 * @param vertices Number of vertices in the graph.
 */
void create_pointer_array(int *source, int *pointer, int vertexes) {
    int j = 1;
    for (int i = 1; i <= vertexes+1; i++) {
        pointer[i] = j;
        while (source[j] == source[j + 1]) {
            j++;
        }
        j++;
    }
}


/**
 * @brief Implements a sorting algorithm to sort an array 'source' and simultaneously rearrange
 *        the corresponding elements in the 'target' array based on a median of three approach.
 *
 * @param source Pointer to the array to be sorted.
 * @param target Pointer to the corresponding array whose elements are to be rearranged along with 'source'.
 * @param start The starting index of the current partition.
 * @param end The ending index of the current partition.
 */
void sort_by_source_private(int *source, int *target, int start, int end){
    int pivo = source[start]; 
    int left = start;
    int righ = end;
    while (left<=righ){
        while (source[left] < pivo)
            left++;
        while (source[righ] > pivo)
            righ--;
        if (left<=righ){
            int tmp = source[left];
            source[left] = source[righ];
            source[righ] = tmp;
            //Target swap
            tmp = target[left];
            target[left] = target[righ];
            target[righ] = tmp;
            left++;
            righ--;
        }
    }
    if(start<righ)
        sort_by_source_private(source, target, start, righ);
    if(left<end)
        sort_by_source_private(source, target, left, end);
}


/**
 * @brief Provides an interface for sorting an array 'source' and rearranging the corresponding
 *        elements in 'target'.
 *
 * @param source Pointer to the array to be sorted.
 * @param target Pointer to the corresponding array whose elements are to be rearranged along with 'source'.
 * @param size The size of the arrays.
 *
 * @note Calls the private sorting function with appropriate initial parameters.
 */
void sort_by_source(int *source, int *target, int size){
    sort_by_source_private(source, target, 1, size-1);
}


