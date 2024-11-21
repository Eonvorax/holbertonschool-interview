#include "binary_trees.h"

/**
 * max - Returns the highest value between two integers
 * @a: integer a
 * @b: integer b
 *
 * Return: a or b, whichever has the highest value
 */
int max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

/**
 * height - Calculates the height of a binary tree
 * @tree: Pointer to the root node of the tree
 *
 * Return: Height of the tree, or 0 if tree is NULL
 */
int height(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (1 + max(height(tree->left), height(tree->right)));
}

/**
 * is_bst - Checks if a binary tree is a valid BST
 * @tree: Pointer to the root node of the tree
 * @min: Minimum value for the current subtree
 * @max: Maximum value for the current subtree
 *
 * Return: 1 if tree is a valid BST, 0 otherwise
 */
int is_bst(const binary_tree_t *tree, const binary_tree_t *min,
	const binary_tree_t *max)
{
	if (tree == NULL)
		return (1);

	/* Make sure current node value is within allowed range */
	if ((min && tree->n <= min->n) || (max && tree->n >= max->n))
		return (0);

	/* Recursion on left and right subtrees */
	return (is_bst(tree->left, min, tree) && is_bst(tree->right, tree, max));
}

/**
 * is_avl - Recursively checks if a binary tree is a valid AVL tree
 * @tree: Pointer to the root node of the tree
 * @height_diff: Pointer to an integer accounting for height difference
 *
 * Return: 1 if tree is a valid AVL tree, 0 otherwise
 */
int is_avl(const binary_tree_t *tree, int *height_diff)
{
	if (tree == NULL)
	{
		*height_diff = 0;
		return (1);
	}

	int left_height = 0, right_height = 0;

	/* Recursively check left and right subtrees */
	if (!is_avl(tree->left, &left_height) ||
		!is_avl(tree->right, &right_height))
		return (0);

	/* Check height balance: is the imbalance higher than 1 ? */
	*height_diff = 1 + max(left_height, right_height);
	if (abs(left_height - right_height) > 1)
		return (0);

	/* Check BST property: are the nodes in order ? */
	return (is_bst(tree, NULL, NULL));
}

/**
 * binary_tree_is_avl - Checks if a binary tree is a valid AVL tree
 * @tree: Pointer to the root node of the tree
 *
 * Return: 1 if tree is a valid AVL tree, 0 otherwise
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	int height_diff = 0;

	return (is_avl(tree, &height_diff));
}
