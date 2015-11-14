/*	A doubly linked list implementation of Queue data structure. No boundary
 *	conditions, the list can extend upto infinity.
 *
 *	The insertion takes place in the last and elimination takes place from
 *	the left.
 *
 *	Usage :
 *		Define a queue with `struct Queue *`.
 *
 *	Operations :
 *		Use `INIT_QUEUE()` to initialize the queue.
 *		Use `ENQUEUE()` and `DEQUEUE()` functions for operations on
 * 		the queue.
 *		Use `PRINT_QUEUE()` to print out the Queue.
 *
 *	Example :
 *		```
 *		#include "queue.h"
 *
 *		void main() {
 *			struct Queue *Q = init_queue();
 *			enqueue(Q, 1);
 *			enqueue(Q, 2);
 *			enqueue(Q, 3);
 *			dequeue(Q);
 *			print_queue(Q);
 *		}
 *		```
 *		Output :
 *			2 -> 3
 */

#ifndef QUEUE_H
#define QUEUE_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/* A Queue data structure */
struct qNode {
	int data;
	struct qNode *next;
	struct qNode *back;
};

struct Queue {
	struct qNode *first;
	struct qNode *last;
};

/* Create empty Queue */
struct Queue *init_queue(void);

/* Function to remove an element from Queue and return the node */
int dequeue(struct Queue *);

/* Function to add an element to the Queue */
void enqueue(struct Queue *, int);

/* Function to print out the queue */
void print_queue(struct Queue *);

#endif
