#include "bfs.h"

/* Function to initialise the attributes of each node */
void init_attributes(struct attributes *nodes, int n) {
	int i;
	for (i = 1; i <= n; i++) {
		nodes[i].parent = NIL;
		nodes[i].distance = INF;
		nodes[i].current_color = WHITE;
	}
}

/* Function to print the value of attributes */
void print_attributes(struct attributes *nodes, int n) {
	int i;
	printf("Node\tParent\tDistance\n");
	for (i = 1; i <= n; i++)
		printf("%4d : %6d\t%7d\n", i, nodes[i].parent, nodes[i].distance);
}

/* Function to implement BFS on a graph 
 * TODO: Replace `nodes` with a more appropriate name
 */
void bfs(struct Graph *graph, struct attributes *nodes, int source) {
	int i;
	struct Queue *Q;
	init_attributes(nodes, graph->V);
	to_list(graph);
	Q = init_queue(Q);
	
	nodes[source].current_color = GRAY;
	nodes[source].distance = 0;
	enqueue(Q, source);
	
	while (Q->first != NULL && Q->last != NULL) {	
		int current_node = dequeue(Q);
		struct node *iter = (graph->list[current_node]).head;
		while (iter != NULL) {
			if(nodes[iter->key].current_color == WHITE)
			{
				(nodes[iter->key]).current_color = GRAY;
				(nodes[iter->key]).distance = (nodes[current_node]).distance + 1;
				(nodes[iter->key]).parent = current_node;
				enqueue(Q, iter->key);
			}
			iter = iter->next;
		}
		nodes[current_node].current_color = BLACK;  	
	}
}
