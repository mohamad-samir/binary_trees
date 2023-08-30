#include "binary_trees.h"

/**
 * count_nodes - Recursively counts the number of nodes in a binary tree
 * @node: A pointer to a tree node
 * @nodes: A pointer to the variable holding the number of nodes
 *
 * This is a helper function used by binary_tree_nodes to traverse the binary
 * tree recursively and count the number of nodes that have at least one child.
 * It updates the 'nodes' variable by incrementing it for each non-leaf node.
 */
void count_nodes(const binary_tree_t *node, size_t *nodes)
{
	if (node)
	{
		if (node->left || node->right)
			(*nodes)++; /* Increment the node count for non-leaf nodes */

		/* Recursively traverse the left and right subtrees */
		count_nodes(node->left, nodes);
		count_nodes(node->right, nodes);
	}
}

/**
 * binary_tree_nodes - Counts the number of nodes in a binary tree that have
 *                     at least one child.
 * @tree: A pointer to the root node of the binary tree
 *
 * Return: The number of nodes in the binary tree that have at least one child.
 *         If 'tree' is NULL or a leaf node, it returns 0.
 *
 * This function measures the number of nodes in a binary tree that have at
 * least one child (non-leaf nodes). It does this by calling the count_nodes
 * function, which traverses the binary tree and updates the 'nodes' variable
 * accordingly.
 */
size_t binary_tree_nodes(const binary_tree_t *tree)
{
	size_t nodes = 0;

	if (tree)
		if (tree->left || tree->right)
			count_nodes(tree, &nodes);

	return (nodes);
}
