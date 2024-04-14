typedef struct list_cell
{
    int vertex;
    struct list_cell *next;
}list_cell;

typedef struct List
{
    int size;
    list_cell *first;
}List;

void insert(List *list, int element);
void start_list(List *list);
void show_list(List *list);

