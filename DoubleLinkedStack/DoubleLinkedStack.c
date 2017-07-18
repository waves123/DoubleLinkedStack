#include "DoubleLinkedStack.h"

void createStack(Stack *stack, int datasize)
{
	Node *headNode, *tailNode;

	headNode = (Node *)malloc(sizeof(Node));
	tailNode = (Node *)malloc(sizeof(Node));

	headNode->rlink = headNode;
	headNode->llink = tailNode;
	headNode->data = NULL;

	tailNode->rlink = tailNode;
	tailNode->llink = headNode;
	tailNode->data = NULL;

	stack->head = headNode;
	stack->tail = tailNode;
	stack->length = 0;
	stack->datasize = datasize;
	stack->top = headNode;

	stack->deleteStack = deleteStack;
	stack->push = push;
	stack->pop = pop;
	stack->peak = peak;
}

void deleteStack(Stack *stack)
{
	void *popData = malloc(sizeof(stack->datasize));
	while (stack->pop(stack, popData))
		;
	free(popData);
	free(stack->head);
	free(stack->tail);
	free(stack);
}

void push(Stack *stack, void *data)
{
	Node *newNode = (Node *)malloc(sizeof(Node));
	newNode->data = malloc(stack->datasize);
	memcpy(newNode->data, data, stack->datasize);

	stack->top->rlink = newNode;
	stack->tail->llink = newNode;
	newNode->llink = stack->top;
	newNode->rlink = stack->tail;
	
	stack->top = newNode;
	stack->length++;
}

int pop(Stack *stack, void *popData)
{
	if (stack->top != stack->head) 
	{
		Node *popNode;
		popNode = stack->top;

		memcpy(popData, popNode->data, stack->datasize);

		stack->top = popNode->llink;
		stack->length--;

		popNode->llink->rlink = popNode->rlink;
		popNode->rlink->llink = popNode->llink;
		free(popNode->data);
		free(popNode);

		return TRUE;
	}
	else
	{
		return FALSE;
	}
}

int peak(Stack *stack, void *peakData)
{
	if (stack->top != stack->head)
	{
		memcpy(peakData, stack->top->data, stack->datasize);
		return TRUE;
	}
	else
	{
		return FALSE;
	}
}