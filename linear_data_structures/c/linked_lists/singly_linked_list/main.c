#include "sll.h"
#include <stdio.h>

int main(void)
{
	struct ListNode * head = (struct ListNode*) malloc(sizeof(struct ListNode));
    
    int array[] = {1,2};
    init_sll(head, array, 2);
	
	append_sll(head, 0);
	print_sll(head);

	printf("Index: %d\n",search_sll(head, 0));

	delete_node_sll(&head, search_sll(head, 1));
	print_sll(head);

	destroy_sll(head);
	return 0;
}
