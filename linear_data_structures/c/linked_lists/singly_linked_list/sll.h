/* **************************************
	Title:		Singly Linked List
	Author:		Julian Schubel
	Contact:	schubeljulian@gmail.com
************************************** */

#ifndef SINGLY_LINKED_LIST_H
#define SINGLY_LINKED_LIST_H

#include <stdio.h>
#include <stdlib.h>

/* NODE DEFINITION */
struct ListNode {
	int data;
	struct ListNode *next;
};

/* PROTOTYPES  */
void init_sll(struct ListNode *head, int *values, int num_values);
void push_sll(struct ListNode **head, int value);
int pop_sll(struct ListNode **head);
void append_sll(struct ListNode *head, int value);
int delete_node_sll(struct ListNode **head, int index);
void print_sll(struct ListNode *head);
int search_sll(struct ListNode *head, int value);
void destroy_sll(struct ListNode *head);

/* DEFINITIONS */
void init_sll(struct ListNode *head, int *values, int num_values)
{
	int i = 0;
	struct ListNode* cursor = head;
	head->data = values[i++];
	head->next = NULL;
	while(i < num_values)
	{
		struct ListNode* new_node = malloc(sizeof(struct ListNode));
		new_node->data = values[i++];
		new_node->next = NULL;
		cursor->next = new_node;
		cursor = new_node;
	}
}

void print_sll(struct ListNode *head)
{
	if(head != NULL) {
		struct ListNode *cursor = head;
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

void push_sll(struct ListNode **head, int value) 
{
	struct ListNode *new_node = (struct ListNode *) malloc(sizeof(struct ListNode));
	
	new_node->data = value;
	new_node->next = *head;
	*head = new_node;	
}

void append_sll(struct ListNode *head, int value)
{
	struct ListNode *cursor = head;	

	while(cursor->next != NULL) {
		cursor = cursor->next;
	}

	cursor->next = (struct ListNode *)malloc(sizeof(struct ListNode));
	cursor->next->data = value;
	cursor->next->next = NULL;
}

void destroy_sll(struct ListNode *head)
{
	if(head != NULL) {

		while(head->next != NULL)
		{
			struct ListNode * cursor = head;
			head = head->next;
			free(cursor);
		}	
		free(head);
	}
}

/* Returns the index of the provided value, else returns -1.  */
int search_sll(struct ListNode *head, int value)
{
	int index = 0;
	struct ListNode *cursor = head;

	while(cursor->next != NULL && cursor->data != value) {
		cursor = cursor->next;
		index++;
	}
	
	/* If out of while and data != value, we are at the end of the list  */
	if(cursor->data != value) {
		return -1; 
	}	
	return index;
}

/* pop a node from the list, return the value of the popped node, or return -1. */
int pop_sll(struct ListNode **head)
{
	int return_value = -1;
	if(*head == NULL) {
		return return_value;
	}

	struct ListNode *temp = (*head)->next;	
	return_value = (*head)->data; 
	free(*head);	
	*head = temp;
	return return_value;
}

/* Deletes a node, returning its value, else returning -1.  */
int delete_node_sll(struct ListNode **head, int index)
{
	int return_value = -1;
	if(*head == NULL) {
		return return_value;
	}
	
	if(index == 0) {
		return pop_sll(head);
	}

	struct ListNode *cursor = *head;

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
	struct ListNode *temp = cursor->next;
	return_value = temp->data;
	
	/* point the previous node to the next next node*/
	cursor->next = temp->next;

	free(temp);
	return return_value;
}

#endif //SINGLY_LINKED_LIST_H
