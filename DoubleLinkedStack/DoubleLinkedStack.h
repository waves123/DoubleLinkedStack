#ifndef __DOUBLE_LINKED_STACK_
#define __DOUBLE_LINKED_STACK_

#define TRUE 1
#define FALSE 0

#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

typedef struct Node Node;
typedef struct Stack Stack;

typedef struct Node {
	Node *rlink;
	Node *llink;
	void *data;
} Node;

typedef struct Stack {
	Node *head;
	Node *tail;
	int length;
	int datasize;
	Node *top;

	void (*deleteStack)(Stack *stack);
	void (*push)(Stack *stack, void *data);
	int (*pop)(Stack *stack, void *popData);
	int(*peak)(Stack *stack, void *peakData);
} Stack;

void createStack(Stack *stack, int datasize);
void deleteStack(Stack *stack);
void push(Stack *stack, void *data);
int pop(Stack *stack, void *popData);
int peak(Stack *stack, void *peakData);
#endif