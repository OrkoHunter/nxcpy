#include "queue.h"

/* Create empty Queue */
struct Queue *init_queue() {
	struct Queue *Q;
	Q = (struct Queue *)malloc(sizeof(struct Queue));
	Q->head = -1;
	Q->tail = 0;
	return Q;
}

/* Function to remove an element from Queue and return the node */
int dequeue(struct Queue *Q) {
	int to_return=-1;
	if (Q->head == Q->tail) {
		printf("Queue is already empty.\n");
	}
	else {
		if (Q->head == QUEUE_LIMIT-1)
			Q->head = 0;
		else
			++Q->head;
		to_return = Q->arr[Q->head];
	}
	return to_return;
}

/* Function to add an element to the Queue */
void enqueue(struct Queue *Q, int data) {
	Q->arr[Q->tail] = data;
	if (Q->tail==QUEUE_LIMIT-1)
		Q->tail = 0;
	else
		++Q->tail;
}

/* Print out the elements in the queue */
void print_queue(struct Queue *Q) {
	int iter = Q->head + 1;
	while (iter!=Q->tail) {
		printf("%d  ", Q->arr[iter]);
		if (iter==QUEUE_LIMIT-1)
			iter=0;
		else
			++iter;
	}
	printf("\n");
}
    printf("\n");
}
