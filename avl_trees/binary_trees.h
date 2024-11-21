#ifndef BINARY_TREES_H
#define BINARY_TREES_H
#include <stdlib.h>
#include <stddef.h>

/**
 * struct binary_tree_s - Binary tree node
 *
 * @n: Integer stored in the node
 * @parent: Pointer to the parent node
 * @left: Pointer to the left child node
 * @right: Pointer to the right child node
 */
struct binary_tree_s
{
	int n;
	struct binary_tree_s *parent;
	struct binary_tree_s *left;
	struct binary_tree_s *right;
};

typedef struct binary_tree_s binary_tree_t;

binary_tree_t *binary_tree_node(binary_tree_t *parent, int value);

void binary_tree_print(const binary_tree_t *);

int binary_tree_is_avl(const binary_tree_t *tree);
int max(int a, int b);
int height(const binary_tree_t *tree);
int is_bst(const binary_tree_t *tree, const binary_tree_t *min,
	const binary_tree_t *max);
int is_avl(const binary_tree_t *tree, int *height_diff);

#endif
