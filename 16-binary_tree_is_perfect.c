#include "binary_trees.h"

/**
 * depth - Calculate the depth of a binary tree
 * @tree: Pointer to the root node of the tree
 *
 * Return: The depth of the tree
 */
int depth(const binary_tree_t *tree)
{
	int d = 0;

	while (tree != NULL)
	{
		d++;
		tree = tree->left;
	}

	return (d);
}

/**
 * is_perfect - Check if a binary tree is perfect
 * @tree: Pointer to the root node of the tree
 * @d: The depth of the tree
 * @level: The current level of the tree
 *
 * Return: 1 if the tree is perfect, 0 otherwise
 */
int is_perfect(const binary_tree_t *tree, int d, int level)
{
	if (tree == NULL)
		return (1);

	if (tree->left == NULL && tree->right == NULL)
		return (d == level + 1);

	if (tree->left == NULL || tree->right == NULL)
		return (0);

	return (is_perfect(tree->left, d, level + 1) &&
			is_perfect(tree->right, d, level + 1));
}

/**
 * binary_tree_is_perfect - Check if a binary tree is perfect
 * @tree: Pointer to the root node of the tree
 *
 * Return: 1 if the tree is perfect, 0 otherwise
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	int d;

	if (tree == NULL)
		return (0);

	d = depth(tree);

	return (is_perfect(tree, d, 0));
}
