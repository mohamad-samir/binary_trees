#include "binary_trees.h"

/**
 * count_height - Recursively measures the height of a binary tree
 * @tree: A pointer to the parent node of the current subtree
 * @height: The current height of the tree being traversed
 * @max: A pointer to the maximum height found so far
 *
 * This helper function traverses the binary tree recursively, keeping track of
 * the current height. It updates the 'max' value with the maximum height found
 * as it reaches leaf nodes. It is called by the binary_tree_height function.
 */
void count_height(const binary_tree_t *tree, size_t height, size_t *max)
{
	if (tree)
	{
		if (tree->left == NULL && tree->right == NULL)
		{
			/* If it's a leaf node and the current height is greater */
			if (height > *max)
			{ /* Update max */
				*max = height;
			}
		}
		else
		{
			/* Recursively traverse left and right subtrees, updating height */
			count_height(tree->left, height + 1, max);
			count_height(tree->right, height + 1, max);
		}
	}
}

/**
 * binary_tree_height - Measures the height of a binary tree.
 * @tree: A pointer to the root node of the tree to measure the height.
 *
 * Return: The height of the tree. If 'tree' is NULL, returns 0.
 *
 * This function calculates the height of a binary tree by finding the longest
 * path from the root node to any leaf node. It does this by calling the
 * count_height function recursively, which updates the 'max_height' variable.
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t max_height = 0;

	count_height(tree, 1, &max_height);

	return (max_height);
}

/**
 * binary_tree_balance - Measures the balance factor of a binary tree.
 * @tree: A pointer to the root node of the tree to measure the balance factor.
 *
 * Return: The balance factor of the tree. If 'tree' is NULL, returns 0.
 *
 * The balance factor of a binary tree is defined as the difference between the
 * heights of its left and right subtrees. It calculates the height of the left
 * and right subtrees by calling the binary_tree_height function.
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	size_t left_height = 0;
	size_t right_height = 0;

	if (tree)
	{
		/* If the tree is not a leaf node */
		if (tree->left || tree->right)
		{
			left_height = binary_tree_height(tree->left);
			right_height = binary_tree_height(tree->right);
		}
	}

	return (left_height - right_height);
}
