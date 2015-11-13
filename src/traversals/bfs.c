#include "bfs.h"

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
	printf("Entered BFS.\n");
	fflush(stdout);
	to_list(graph);
	printf("Finished to_list\n");
	fflush(stdout);
	Q = init_queue();

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
