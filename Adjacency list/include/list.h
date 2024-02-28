void create_pointer_array(int source[], int pointer[], int vertexes);
int output_degree(int vertex, int *pointer);
int input_degree(int vertex, int *target, int target_size);
int sucessors_set(int vertex, int *pointer, int *target, int *set);
int predecessors_set(int vertex, int *pointer, int pointer_size,int *target, int *set);