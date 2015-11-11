/*	A Graph is an ordered set of vertices and edges.
 *	Both, the Adjacency List and Adjacency Matrix implementation of
 *	a graph are supported.
 *
 *	Usage :
 *		Define a graph with 'struct Graph *'
 *
 *	Operations :
 *		`INIT_GRAPH()`: Initiate an empty graph
 *		`ADD_EDGE()`: Adds an edge between two nodes with a weight
 *		`TO_LIST()`: List implementation of the graph
 *		`TO_MATRIX()`: Matrix implementation of the graph
 *
 *	Example :
 *	#include "graph.h"
 *
 *	int main() {
 *		struct Graph *G;
 *		G = init_graph(4, LIST);
 *		add_edge(G, 1, 2, 1);
 *		add_edge(G, 2, 3, 2);
 *		add_edge(G, 2, 4, 3);
 *		add_edge(G, 4, 1, 4);
 *		print_graph(G);
 *	}
*/

#ifndef GRAPH_H
#define GRAPH_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

enum flag {LIST, MATRIX, BOTH};

struct node {
	int key;
	int weight;
	struct node *next;
};

struct Adjacency_Node {
	struct node *head;
};

struct Graph {
	int V;
	enum flag flag_type;
	struct Adjacency_Node *list;
	int **matrix;
};

/* Function to initiate an empty Graph */
struct Graph *init_graph(int , int );

/* Function to add an edge between two nodes with a weight */
void add_edge(struct Graph *, int , int , int );

/* Function to implement the Adjacency List representation of the graph */
void to_list(struct Graph *);

/* Function to implement the Adjacency Matrix representation of the graph */
void to_matrix(struct Graph *);

/* Function to print the Graph */
void print_graph(struct Graph *);

#endif
