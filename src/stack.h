/*
    A doubly linked list implemenentation of the Stack abstract data type.

    Usage :
        Define a stack with `struct Stack* `.
    Operations :
        Use `INIT_STACK()` to initialize the stack.
        Use `PUSH()` to "push" an element to the top of the existing stack.
        Use `POP()` to "pop" the element at the top of the existing stack.
        Use `PRINT_STACK()` to print out the Stack.

    Example:
        ```
        int main() {
            struct Stack* S;
            S = INIT_STACK();

            PUSH(S, 1);
            PUSH(S, 2);
            PUSH(S, 3);
            POP(S);

            PRINT_STACK(S);
            return 0;
        }
		[Out]: 1 2
        ```
*/

#ifndef STACK_H
#define STACK_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Implementing Stack ADT using a doubly-linked list
struct sNode{
	int key;
	struct sNode *next;
	struct sNode *back;
};

struct Stack{
	struct sNode *top;
};

// Function to create an empty Stack
struct Stack* INIT_STACK();

// Function to add an element to the Stack
void PUSH(struct Stack*, int);

// Function to remove an element from the Stack 
int POP(struct Stack*);

// Function to print the Stack
void PRINT_STACK(struct Stack*);

#endif

