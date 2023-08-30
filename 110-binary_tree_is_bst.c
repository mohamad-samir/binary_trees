#include "binary_trees.h"

/**
 * is_bst_helper - Helper function for binary_tree_is_bst
 * @node: Node to check
 * @min_val: Minimum value allowed in the subtree rooted at 'node'
 * @max_val: Maximum value allowed in the subtree rooted at 'node'
 *
 * Return: 1 if 'node' is part of a valid binary search tree (BST)
 *
 * This is a helper function used by binary_tree_is_bst to recursively check
 * if the binary tree is a valid binary search tree. It ensures that all nodes
 * in the subtree rooted at 'node' satisfy the BST property, which means the
 * value of the 'node' is greater than all values in the left subtree and less
 * than all values in the right subtree. It uses the 'min_val' and 'max_val' to
 * enforce these constraints during the recursive checks.
 */
int is_bst_helper(const binary_tree_t *node, int min_val, int max_val)
{
	if (node == NULL)
		return (1);

	/* Check if the value of 'node' is within the valid range */
	if (node->n <= min_val || node->n >= max_val)
		return (0);

	/* Recursively check the left and right subtrees, enforcing constraints */
	return (is_bst_helper(node->left, min_val, node->n) &&
		   is_bst_helper(node->right, node->n, max_val));
}

/**
 * binary_tree_is_bst - Checks if a binary tree is a binary search tree (BST).
 * @tree: Binary tree to check
 *
 * Return: 1 if 'tree' is a valid BST, 0 otherwise. If 'tree' is NULL, returns
 *          0.
 *
 * This function checks if the given binary tree is a valid binary search tree
 * (BST). A binary search tree is a binary tree where each node has a value,
 * and all the values in the left subtree of a node are less than the value of
 * that node, while all the values in the right subtree are greater. The
 * function calls the is_bst_helper function with initial minimum and maximum
 * values (INT_MIN and INT_MAX) to enforce these constraints during the
 * recursive checks.
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	/* Call the helper function with initial minimum and maximum values */
	return (is_bst_helper(tree, INT_MIN, INT_MAX));
}
