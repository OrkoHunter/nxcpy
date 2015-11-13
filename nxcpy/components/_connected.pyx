from _api.connected cimport Graph, attributes, bfs, MATRIX, BLACK, WHITE
from cpython.mem cimport PyMem_Malloc, PyMem_Free

import networkx as nx

__all__ = [
        'is_connected'
]


def is_connected(A):
    cdef Graph *G
    G = <Graph*> PyMem_Malloc(sizeof(Graph))
    adj_iter = A.adjacency_iter()
    cdef int V = len(list(adj_iter))
    G.V = V
    G.flag_type = MATRIX
    cdef int i
    G.matrix = <int **> PyMem_Malloc((G.V+1)*sizeof(int *))
    for i in range(G.V+1):
        G.matrix[i] = <int *> PyMem_Malloc((G.V+1)*sizeof(int))
    G.list = NULL
    cdef int j
    for i in range(1, G.V+1):
        for j in range(1, G.V+1):
            G.matrix[i][j] = 0

    for key, nbrs in nx.to_dict_of_lists(A).items():
        for i in nbrs:
            G.matrix[key][i] = 1

    cdef attributes *attr
    attr = <attributes*> PyMem_Malloc(sizeof(attributes) * (G.V+1))

    # init_attr
    for i in range(1, G.V+1):
        attr[i].parent = 0
        attr[i].distance = 2147483647
        attr[i].current_color = WHITE

    bfs(G, attr, 1)

    print("Printing attributes : ")
    for i in range(1, G.V+1):
        print(attr[i].current_color)

#    PyMem_Free(G)
#    PyMem_Free(G.matrix)
#    PyMem_Free(attr)
