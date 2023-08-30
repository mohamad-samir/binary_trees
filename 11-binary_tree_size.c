#include "binary_trees.h"

/**
 * count_nodes - Recursively counts the number of nodes on all levels of a
 *				binary tree
 * @tree: A pointer to a tree node
 * @size: A pointer to the variable holding the number of nodes
 *
 * This is a helper function used by binary_tree_size to traverse the binary
 * tree recursively and count the number of nodes on all levels. It updates the
 * 'size' variable by incrementing it for each node encountered during
 * traversal.
 */
void count_nodes(const binary_tree_t *tree, size_t *size)
{
	if (tree)
	{
		(*size)++; /* Increment the node count for each node */

		/* Recursively traverse the left and right subtrees */
		count_nodes(tree->left, size);
		count_nodes(tree->right, size);
	}
}

/**
 * binary_tree_size - Measures the number of nodes on all levels of a binary
 *				tree.
 * @tree: A pointer to the root node of the binary tree
 *
 * Return: The number of nodes. If 'tree' is NULL, returns 0.
 *
 * This function measures the number of nodes in a binary tree, including the
 * root node. It does this by calling the count_nodes function, which traverses
 * the binary tree and updates the 'size' variable accordingly.
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	size_t size = 0;

	if (tree == NULL)
		return (size);

	count_nodes(tree, &size);

	return (size);
}
