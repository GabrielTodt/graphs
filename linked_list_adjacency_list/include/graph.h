typedef struct Cell
{
    int vertex;
    struct Cell *next;
}Cell;

typedef struct Graph
{
    Cell *List;
    int vertices;
} Graph;

void insert_edge(Graph *target,int v, int w);
void start_graph(Graph *target, int vertices);
void print_graph(Graph *target);