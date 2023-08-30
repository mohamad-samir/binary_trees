#include "binary_trees.h"

/**
 * binary_tree_is_full - Checks if a binary tree is full.
 * @tree: A pointer to the root node of the tree to check.
 *
 * Return: 1 if the binary tree is full, 0 otherwise.
 *			If 'tree' is NULL, returns 0.
 *
 * A binary tree is considered full if every node has either zero or two
 * children. In other words, every non-leaf node must have two children (left
 * and right), and all leaf nodes should have no children (both left and right
 * are NULL). This function recursively checks if the given binary tree is full
 */
int binary_tree_is_full(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	if (tree->left != NULL && tree->right != NULL)
		return (binary_tree_is_full(tree->left) && binary_tree_is_full(tree->right));

	if (tree->left == NULL && tree->right == NULL)
		return (1);

	return (0);
}
