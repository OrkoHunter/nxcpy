cdef extern from "ADTs/graph.h":
    enum flag:
        LIST
        MATRIX
        BOTH

    struct node:
        int key
        int weight
        node *next

    struct Adjacency_Node:
        node *head

    struct Graph:
        int V
        flag flag_type
        Adjacency_Node *list
        int **matrix


cdef extern from "traversals/bfs.h":
    enum color:
        WHITE
        GRAY
        BLACK

    struct attributes:
        int parent
        int distance
        color current_color

    void bfs(Graph *, attributes *, int)
