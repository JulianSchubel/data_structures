#include "./dll.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char * argv[])
{
	dll_node_t *head = (dll_node_t*) malloc(sizeof(dll_node_t));
	head->data = 0;
	head->next = NULL;
	head->previous = NULL;
	
	append_dll(head, 1);
	append_dll(head, 2);
	print_dll(head);

	delete_node_dll(&head, search_dll(head, 1));
	print_dll(head);

    reverse(&head);
    print_dll(head);
	deallocate_dll(head);
	return 0;
}
