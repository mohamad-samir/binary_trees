#include "binary_trees.h"

/**
 * binary_tree_height - Measures the height of a binary tree.
 * @tree: A pointer to the root node of the tree to measure the height.
 *
 * Return: The height of the tree. If 'tree' is NULL, returns 0.
 *
 * This function calculates the height of a binary tree by finding the longest
 * path from the root node to any leaf node. It uses recursion to traverse the
 * binary tree and computes the height based on the heights of the left and
 * right subtrees.
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	if (tree)
	{
		int left = 0, right = 0;

		/* Calculate the height of the left subtree */
		if (tree->left)
			left = 1 + binary_tree_height(tree->left);
		/* Calculate the height of the right subtree */
		if (tree->right)
			right = 1 + binary_tree_height(tree->right);

		/* Return the maximum height between left and right subtrees */
		if (left > right)
			return (left);
		else
			return (right);
	}
	else
		return (0);
}

/**
 * binary_tree_size - Measures the size of a binary tree.
 * @tree: A pointer to the root node of the tree to measure the size.
 *
 * Return: The number of nodes in the binary tree. If 'tree' is NULL, returns 0
 *
 * This function calculates the size of a binary tree by counting the number of
 * nodes in the tree. It uses recursion to traverse the binary tree and
 * computes the size based on the number of nodes in the left and right
 * subtrees.
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	size_t n_left, n_right;

	if (tree == NULL)
		return (0);

	/* Calculate the size of the left and right subtrees recursively */
	n_left = binary_tree_size(tree->left);
	n_right = binary_tree_size(tree->right);

	/* Return the total size of the binary tree (current node + left subtree size + right subtree size) */
	return (1 + n_left + n_right);
}

/**
 * binary_tree_is_perfect - Checks if a binary tree is perfect.
 * @tree: A pointer to the root node of the tree to check.
 *
 * Return: 1 if the binary tree is perfect, 0 otherwise. If 'tree' is NULL, returns 0.
 *
 * A binary tree is considered perfect if all levels are fully filled (i.e., all
 * nodes at each level have two children) and the number of nodes in the tree is
 * equal to 2^(height + 1) - 1, where 'height' is the height of the binary tree.
 * This function checks if the given binary tree is perfect using the height and size.
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	size_t h = 0, perfect_size = 0;

	if (tree == NULL)
		return (0);

	/* Calculate the height of the binary tree */
	h = binary_tree_height(tree);

	/* Calculate the perfect size of the binary tree using 2^(height + 1) - 1 formula */
	perfect_size = (1 << (h + 1)) - 1;

	/* Check if the size of the binary tree matches the perfect size to determine if it's perfect */
	if (perfect_size == binary_tree_size(tree))
		return (1);
	else
		return (0);
}
