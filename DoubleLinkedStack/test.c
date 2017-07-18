#include "DoubleLinkedStack.h"

int main() {

	int data[5] = { 0, 1, 2, 3, 4 };
	char *str[3] = { "aa", "bb", "cc" };
	void *popData = (char *)malloc(sizeof(char));
	void *peakData = (char *)malloc(sizeof(char));

	Stack *intStack = (Stack *)malloc(sizeof(Stack));
	Stack *strStack = (Stack *)malloc(sizeof(Stack));

	createStack(intStack, sizeof(int));
	
	intStack->push(intStack, &data[0]);
	printf("Push data : %d\n", *(int *)(intStack->top->data));
	printf("length : %d\n", intStack->length);
	intStack->push(intStack, &data[1]);
	printf("Push data : %d\n", *(int *)(intStack->top->data));
	printf("length : %d\n", intStack->length);
	intStack->push(intStack, &data[2]);
	printf("Push data : %d\n", *(int *)(intStack->top->data));
	printf("length : %d\n", intStack->length);
	printf("\n");

	if (intStack->pop(intStack, popData))
	{
		printf("Pop data : %d\n", *(int *)(popData));
		printf("length : %d\n", intStack->length);
	}
	if (intStack->pop(intStack, popData))
	{
		printf("Pop data : %d\n", *(int *)(popData));
		printf("length : %d\n", intStack->length);
	}
	if (intStack->pop(intStack, popData))
	{
		printf("Pop data : %d\n", *(int *)(popData));
		printf("length : %d\n", intStack->length);
	}
	if (intStack->pop(intStack, popData))
	{
		printf("Pop data : %d\n", *(int *)(popData));
		printf("length : %d\n", intStack->length);
	}
	printf("\n");

	intStack->deleteStack(intStack);

	createStack(strStack, sizeof(char *));
	
	strStack->push(strStack, &str[0]);
	printf("Push data : %s\n", *(char **)(strStack->top->data));
	printf("length : %d\n", strStack->length);
	strStack->push(strStack, &str[1]);
	printf("Push data : %s\n", *(char **)(strStack->top->data));
	printf("length : %d\n", strStack->length);
	printf("\n");

	if (strStack->peak(strStack, peakData))
	{
		printf("Peak data : %s\n", *(char **)peakData);
		printf("length : %d\n", strStack->length);
	}
	if (strStack->peak(strStack, peakData))
	{
		printf("Peak data : %s\n", *(char **)peakData);
		printf("length : %d\n", strStack->length);
	}
	if (strStack->peak(strStack, peakData))
	{
		printf("Peak data : %s\n", *(char **)peakData);
		printf("length : %d\n", strStack->length);
	}
	strStack->deleteStack(strStack);


}