/* **************************************
	Title:		Doubly linked list
	Author:		Julian Schubel
	Contact:	schubeljulian@gmail.com
************************************** */

#ifndef DLL_H
#define DLL_H

#include "./dll_node_t.h"
#include <stdio.h>
#include <stdlib.h>

/* Outputs the list to stdout.  */
void print_dll(dll_node_t * head);
/* Outputs the list to stdout in revers order. */
void print_reverse_dll(dll_node_t * head);
/* Prepends a node to the head of the list with the value provided. */
void push_dll(dll_node_t **head, int value);
/* Appends a node to the tail of the list with the value provided. */
void append_dll(dll_node_t * head, int value);
/* Removes the first node and returns the nodes value, else returns -1. */
int pop_dll(dll_node_t **head);
/* Search the list for a value and return the index associated with the first node containing the provided value, else return -1. */
int search_dll(dll_node_t *head, int value);
/* Deletes a node at a given index, returning its value, else returning -1.  */
int delete_node_dll(dll_node_t **head, int index);
/* Deallocates all nodes in the list. */
void deallocate_dll(dll_node_t *head);

/* Outputs the list to stdout.  */
void print_dll(dll_node_t *head)
{
	if(head != NULL) {
		dll_node_t *cursor = head;
		while(cursor->next != NULL) {
			printf("%d\n", cursor->data);
			cursor = cursor->next;
		}
		printf("%d\n", cursor->data);
	}
	else {
		printf("Empty list\n");
	}
}

/* Outputs the list to stdout in revers order. */
void print_reverse_dll(dll_node_t *head)
{
	if(head != NULL) {
		dll_node_t *cursor = head;

		while(cursor->next != NULL) {
			cursor = cursor->next;
		}
		
		while(cursor->previous != NULL) {
			printf("%d\n", cursor->data);
			cursor = cursor->previous;
		}
		printf("%d\n", cursor->data);
	}
	else {
		printf("Empty list \n");
	}
}

/* Prepends a node to the head of the list with the value provided. */
void push_dll(dll_node_t **head, int value)
{
	dll_node_t *new_node = (dll_node_t*) malloc(sizeof(dll_node_t));
	new_node->data = value;
	new_node->next = *head;
	new_node->previous = NULL;
	
	(*head)->previous = new_node;
	*head = new_node;
}

/* Appends a node to the tail of the list with the value provided. */
void append_dll(dll_node_t *head, int value)
{
	dll_node_t *cursor = head;
	dll_node_t *new_node = (dll_node_t*) malloc(sizeof(dll_node_t));	
	new_node->data = value;
	new_node->next = NULL;
	new_node->previous = NULL;
	
	while(cursor->next != NULL) {
		cursor = cursor->next;		
	}

	cursor->next = new_node;
	new_node->previous = cursor;
}

/* Removes the first node and returns the nodes value, else returns -1. */
int pop_dll(dll_node_t **head)
{
	int return_value = -1;
	if(*head == NULL) {
		return return_value;
	}
	(*head)->next->previous = (*head)->previous;
	return_value = (*head)->data;	
	dll_node_t *temp = (*head)->next;
	free(*head);
	*head = temp;
	return return_value;
}

/* Deallocates all nodes in the list. */
void deallocate_dll(dll_node_t *head) 
{
	if(head != NULL) {
		while(head->next != NULL) {
			head = head->next;
			free(head->previous);
		}
		free(head);
	}
	if(head == NULL) {
		;
	}
}

/* Search the list for a value and return the index associated with the first node containing the provided value, else return -1. */
int search_dll(dll_node_t *head, int value)
{
	int error_value = -1;	
	if(head != NULL) {
		int index = 0;
		dll_node_t *cursor = head;

		while((cursor->next != NULL) & (cursor->data != value)) {
			cursor = cursor->next;
			index++;
		}
		if(cursor->data == value) {
			return index;	
		}
		else {
			return error_value;
		}
	}
	return error_value;
}

/* Deletes a node at the given index, returning its value, else returning -1.  */
int delete_node_dll(dll_node_t **head, int index)
{
    int return_value = -1;
    if(*head == NULL) {
        return return_value;
    }

	/* Handle edge case that the node is the first  */
    if(index == 0) {
        return pop_dll(head);
    }

    dll_node_t *cursor = *head;

    /* Loop to the preceding node in the list  */
    for(int i = 0; i < index-1; ++i) {
        if(cursor->next == NULL) {
            return return_value;
        }
        cursor = cursor->next;
    }

    if(cursor->next == NULL) {
        return return_value;
    }

    /* temp is the node to delete  */
    dll_node_t *temp = cursor->next;
    return_value = temp->data;
	
	/* Handle the edge case that the node is the last. */
	/* Using this structure as it makes the behaviour more explicit.  */
	if(temp->next == NULL) {
		;
	}
	else {
		temp->next->previous = cursor;		
	}

    /* point the previous node to the next next node*/
    cursor->next = temp->next;

    free(temp);
    return return_value;
}


#endif //DLL_H, 

