#include "graph.h"

/* Function to initiate an empty Graph */
struct Graph *init_graph(int n, int flag_type) {
	int i, j;
	struct Graph *graph;
	graph = (struct Graph *)malloc(sizeof(struct Graph));
	graph->V = n;
	graph->flag_type = flag_type;
	if (flag_type == LIST) {
		graph->list = (struct Adjacency_Node *)malloc((n + 1)*sizeof(struct node));
		for (i = 1; i <= n; i++)
			(graph->list)[i].head = NULL;
		graph->matrix = NULL;
	}
	else if (flag_type == MATRIX) {
		graph->matrix = (int **)malloc((n + 1)*sizeof(int *));
		for (i = 1; i <= n; i++)
			(graph->matrix)[i] = (int *)malloc((n + 1)*sizeof(int));
		for (i = 1; i <= n; i++) {
			for (j = 1; j <= n; j++)
				(graph->matrix)[i][j] = 0;
		}
		graph->list = NULL;
	}
	else if (flag_type == BOTH) {
		graph->list = (struct Adjacency_Node *)malloc((n+1)*sizeof(struct node));
		graph->matrix = (int **)malloc((n + 1)*sizeof(int *));
		for (i = 1; i <= n; i++)
			(graph->matrix)[i] = (int *)malloc((n+1)*sizeof(int));
		for (i = 1; i <= n; i++) {
			for(j = 1; j <= n; j++)
				(graph->matrix)[i][j] = 0;
		}
	}
	else {
		/*raise error*/
	}
	return graph;
}

/* Function to add an edge between two nodes with a weight */
void add_edge(struct Graph *graph, int node1, int node2, int weight) {
	int f;
	f = graph->flag_type;
	if (f == LIST) {
		struct node *temp = ((struct node *)malloc(sizeof(struct node)));
		temp->key = node2;
		temp->weight = weight;
		temp->next = (graph->list)[node1].head;
		(graph->list)[node1].head = temp;
	}
	else if (f == MATRIX) {
		(graph->matrix[node1][node2] = weight);
	}
	else {
		struct node *temp = (struct node *)malloc(sizeof(struct node));
		temp->key = node2;
		temp->weight = weight;
		temp->next = (graph->list)[node1].head;
		(graph->list)[node1].head = temp;

		(graph->matrix[node1][node2] = weight);
	}
}

/* Function to implement the Adjacency List representation of the graph */
void to_list(struct Graph *graph) {
	int i, j, f, n;
	f = graph->flag_type;
	n = graph->V;
	if (f == MATRIX) {
		struct node *temp;
		graph->list = (struct Adjacency_Node *)malloc((n + 1)*sizeof(struct node));
		temp = (struct node *)malloc(sizeof(struct node));
		for (i = 1; i <= n; i++)
			(graph->list)[i].head = NULL;
		for (i = 1; i <= n; i++) {
			for (j = 1; j <= n; j++) {
				if ((graph->matrix)[i][j] != 0) {
					temp->key = j;
					temp->weight = (graph->matrix)[i][j];
					if ((graph->list)[i].head == NULL)
						temp->next = NULL;
					else
						temp->next = (graph->list)[i].head;
					(graph->list)[i].head = temp;
					free(temp);
				}
			}
		}
		f = BOTH;
	}
	else {
		return; /* raise error*/
	}
}

/* Function to implement the Adjacency Matrix representation of the graph */
void to_matrix(struct Graph *graph) {
	int i, j, f, n;
	f = graph->flag_type;
	n = graph->V;
	if (f == LIST) {
		graph->matrix = (int **)malloc((n+1)*sizeof(int *));
		for (i = 1; i <= n; i++)
			(graph->matrix)[i] = (int *)malloc((n+1)*sizeof(int));
		for (i = 1; i <= n; i++) {
			for (j = 1; j <= n; j++)
				(graph->matrix)[i][j] = 0;
			}
		struct node *iter;
		for (i = 1; i <= n; i++) {
			iter = (graph->list)[i].head;
			while (iter != NULL) {
				(graph->matrix)[i][iter->key] = iter->weight;
				iter = iter->next;
			}
		}
		f = BOTH;
	}
	else {
		return; /* raise error*/
	}
}

/* Function to print the Graph */
void print_graph(struct Graph *graph) {
	int i, j, n;
	n = graph->V;
	to_matrix(graph);
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= n; j++)
			printf("%d  ", (graph->matrix)[i][j]);
		printf("\n");
	}
	to_list(graph);
	for (i = 1; i <= n; i++) {
		printf("Adjacency List of %d:",i);
		struct node *iter = (graph->list)[i].head;
		while (iter != NULL) {
			printf("->(%d, %d)", iter->key, iter->weight);
			iter = iter->next;
		}
		printf("\n");
	}
}
