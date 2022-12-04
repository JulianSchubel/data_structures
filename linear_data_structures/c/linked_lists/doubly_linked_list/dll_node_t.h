#ifndef DLL_NODE_T_H
#define DLL_NODE_T_H

typedef struct dll_node {
	int data;
	struct dll_node *next;
	struct dll_node *previous;
} dll_node_t;

#endif //DLL_NODE_T_H
