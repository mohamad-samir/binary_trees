#include "binary_trees.h"

/**
 * count_leaves - Recursively counts the number of leaves in a binary tree
 * @node: A pointer to a tree node
 * @leaves: A pointer to the variable holding the number of leaves
 *
 * This is a helper function used by binary_tree_leaves to traverse the binary
 * tree recursively and count the number of leaf nodes. It updates the 'leaves'
 * variable by incrementing it for each leaf node encountered during traversal.
 */
void count_leaves(const binary_tree_t *node, size_t *leaves)
{
	if (node)
	{
		if (node->left == NULL && node->right == NULL)
		{
			(*leaves)++; /* Increment the leaf count for each leaf node */
		}
		else
		{
			/* Recursively traverse the left and right subtrees */
			count_leaves(node->left, leaves);
			count_leaves(node->right, leaves);
		}
	}
}

/**
 * binary_tree_leaves - Counts the number of leaves in a binary tree.
 * @tree: A pointer to the root node of the binary tree
 *
 * Return: The number of leaves in the tree. If 'tree' is NULL, returns 0.
 *
 * This function measures the number of leaves in a binary tree. A leaf node is
 * defined as a node that has no children (left and right child are NULL). It
 * does this by calling the count_leaves function, which traverses the binary
 * tree and updates the 'leaves' variable accordingly.
 */
size_t binary_tree_leaves(const binary_tree_t *tree)
{
	size_t leaves = 0;

	if (tree)
	{
		if (tree->left || tree->right)
			count_leaves(tree, &leaves);
		else
			/* If the tree has only one node (root), consider it as a leaf. */
			leaves++;
	}

	return (leaves);
}
