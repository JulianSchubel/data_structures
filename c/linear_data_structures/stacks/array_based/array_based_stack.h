/* **************************************
	Title:		Array based stack
	Author:		Julian Schubel
	Contact:	schubeljulian@gmail.com
************************************** */

#ifndef ARRAY_STACK_H
#define ARRAY_STACK_H

#include <stdio.h>
#include <stdlib.h>

/* Shift stack values upwards (i.e. leftwords) */
static void shift_up(int **stack, int *size)
{
	int depth = (*size);
	int *new_stack = (int*) calloc(depth-1, (sizeof(int)));
	for(int i = 0; i < depth-1; i++)
	{
		new_stack[i] = (*stack)[i+1];	
	}

	/* Free old stack's allocated memory  */
	free(*stack);

	/* Update stack pointer and size */
	*stack = new_stack;
	*size = depth - 1;
}

/* Shift stack values downwards creating empty slot at index [0] */
static void shift_down(int **stack, int *size)
{
	int depth = (*size);
	int *new_stack = (int*) calloc(depth+1, (sizeof(int)));
	for(int i = 0; i < depth; i++)
	{
		new_stack[i+1] = (*stack)[i];
	}

	/* Free old stack's allocated memory  */
	free(*stack);

	/* Update stack pointer and size */
	*stack = new_stack;
	*size = depth + 1;
}

/* Print the stack */
void print_stack(int *stack, int depth)
{
	for(int i =0; i < depth; i++)
	{
		printf("%d\n", stack[i]);
	}	
	printf("\n");
}

/* Delete the first item in the stack and return it's value, else return -1. */
int pop(int **stack, int *size)
{
	int return_value = -1;
	if((*stack) == NULL)
	{
		return return_value;
	}
	else {
		return_value = (*stack)[0];
		shift_up(stack, size);
	}
	return return_value;
}

/* Pushed the value onto the stack returning the value, else return -1. */
int push(int **stack, int *size, int value)
{
	int return_value = -1;
	if((*stack) == NULL)
	{
		return return_value;
	}
	else {
		shift_down(stack, size);
		*stack[0] = value;
	}
	return value;
}

#endif //ARRAY_STACK_H
