/*
    A doubly linked list implementation of Queue data structure. No boundary
    conditions, the list can extend upto infinity.

    The insertion takes place in the last and elimination takes place from
    the left.

    Usage :
        Define a queue with `struct Queue* `.
        Use `INIT_QUEUE()` to initialize the queue.
        Use `ENQUEUE()` and `DEQUEUE` functions for operations on the queue.
        Use `PRINT_QUEUE()` to print out the Queue.

        Example:
        
        ```
        int main() {
            struct Queue* Q;
            Q = INIT_QUEUE();

            ENQUEUE(Q, 1);
            ENQUEUE(Q, 2);
            ENQUEUE(Q, 3);
            DEQUEUE(Q);

            PRINT_QUEUE(Q);
        }
        ```
*/

#ifndef QUEUE_H
#define QUEUE_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// A Queue data structure
struct qNode {
    int data;
    struct qNode *next;
    struct qNode *back;
};

struct Queue {
    struct qNode *first;
    struct qNode *last;
};

// Create empty Queue
struct Queue* INIT_QUEUE();

// Function to remove an element from Queue and return the node
int DEQUEUE(struct Queue* );

// Function to add an element to the Queue
void ENQUEUE(struct Queue* , int);

// Function to print out the queue
void PRINT_QUEUE(struct Queue* );

#endif
