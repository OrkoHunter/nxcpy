/* Breadth First Search Implementation using Adjacency List 
 *	representation of the graph
 *
 * Example:
 *	#include "bfs.h"
 *
 *	int main() {
 *		struct Graph *G;
 *		struct attributes *n;
 *			G = init_graph(4, LIST);
 *			add_edge(G, 1, 2, 1);
 *			add_edge(G, 2, 3, 2);
 *	 		add_edge(G, 2, 4, 3);
 *	 		add_edge(G, 4, 1, 4);
 *	 		bfs(G, n, 1);
 *	 		print_attributes(n, G->V);
 *	}
 *	
 *	[Out] : 
 *		Node	Parent	Distance
 *		   1 :      0	      0
 *		   2 :      1	      1
 *		   3 :      2	      2
 *		   4 :      2	      2
 *
 */

#ifndef BFS_H
#define BFS_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#include "graph.h"
#include "queue.h"

#define NIL 0
#define INF INT_MAX

enum color {WHITE, GRAY, BLACK};

struct attributes {
	int parent;
	int distance;
	enum color current_color;
};

// Function to implement BFS on a graph
void bfs(struct Graph *, struct attributes *, int );

#endif
