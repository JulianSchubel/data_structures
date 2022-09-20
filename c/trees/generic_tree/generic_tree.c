/*  
 *  Implementation of a generic tree structure
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct node_t {
    int data;
    struct node_t *left;
    struct node_t *right;
} node_t;

node_t *create_node(int value) 
{
    node_t * new_node = malloc(sizeof(node_t));
    if(new_node != NULL) {
        new_node->data = value;
        new_node->left = NULL;
        new_node->right = NULL;
    }
    return new_node;
}

/* print_tabs: prints n tabs to stdout */
void print_tabs(int n)
{
    for(int i=0; i < n; ++i) {
        printf("\t");
    }
}

/* print_tree: recursively prints out a formatted text representation of the tree */
void print_tree_recursive(node_t *root, int depth)
{
    if(root == NULL) {
        print_tabs(depth);
        printf("---empty---\n");
        return;
    }
    print_tabs(depth);
    printf("value = %d\n", root->data);    

    print_tabs(depth);
    printf("left\n");    
    print_tree_recursive(root->left, depth + 1);

    print_tabs(depth);
    printf("right\n");    
    print_tree_recursive(root->right, depth + 1);
}

void print_tree(node_t *root) 
{
    print_tree_recursive(root, 0);
}

int main(int argc, char **argv)
{
    node_t *n1 = create_node(10);       
    node_t *n2 = create_node(11);       
    node_t *n3 = create_node(12);       
    node_t *n4 = create_node(13);       
    node_t *n5 = create_node(14);       

    n1->left = n2;
    n1->right = n3;
    n3->left = n4;
    n3->right = n5;

    print_tree(n1);

    free(n1);
    free(n2);
    free(n3);
    free(n4);
    free(n5);
    return 0;
}
