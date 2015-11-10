#include "stack.h"

// Function to initialise a 'sNode' with a given value
struct sNode* __init__snode(int value) {
	struct sNode* newNode;
	newNode = (struct sNode*)malloc(sizeof(struct sNode));
	newNode->key = value;
	newNode->next = NULL;
	newNode->back = NULL;
	return newNode;
}

// Function to create an empty Stack
struct Stack* INIT_STACK() {
	struct Stack* SH;
	SH = (struct Stack*)malloc(sizeof(struct Stack));
	SH->top = NULL;
	return SH;
}

// Function to add an element to the Stack
void PUSH(struct Stack* SH, int value) {
	struct sNode* newNode;
	newNode = __init__snode(value);
	if(SH->top==NULL) {
		SH->top = newNode;
	}
	else {
		SH->top->next = newNode;
		newNode->back = SH->top;
		SH->top = newNode;
	}
}

// Function to remove an element from the Stack 
int POP(struct Stack* SH) {
	if(SH->top==NULL) {
		printf("Stack is empty");//TODO:Raise appropriate error instead of printing
	}
	else {
		int top_value;
		top_value = SH->top->key;
		if(SH->top->back==NULL) {
			SH->top = NULL;
		}
		else {
			SH->top = SH->top->back;
			SH->top->next = NULL;
		}
		return top_value;
	}
}

// Function to print the Stack
void PRINT_STACK(struct Stack* SH) {
	struct sNode* iter;
	iter = SH->top;
	printf("%d ", iter->key);
	while(iter->back!=NULL) {
		iter = iter->back;
		printf("<- %d ", iter->key);
	}
	printf("\n");
}

