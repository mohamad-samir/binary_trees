#include "binary_trees.h"

/**
 * bst_search - Searches for a value in a Binary Search Tree (BST).
 * @tree: A pointer to the root node of the BST to search.
 * @value: The value to search for in the tree.
 *
 * Return: A pointer to the node containing an int equal to 'value',
 *         NULL if 'tree' is NULL,
 *         NULL if no match is found.
 *
 * This function searches for a given value in a binary search tree (BST).
 * If 'tree' is NULL, it returns NULL.
 * The function uses a while loop to traverse the BST based on the comparison
 * of the value to be searched with the current node's value. If the value is
 * equal to the current node's value, it returns a pointer to the node.
 * If the value is less than the current node's value, it continues the search
 * in the left subtree. If the value is greater than the current node's value,
 * it continues the search in the right subtree.
 */
bst_t *bst_search(const bst_t *tree, int value)
{
	bst_t *node = (bst_t *)tree;

	if (!tree)
		return (NULL);

	while (node)
	{
		if (value == node->n)
			return (node);

		if (value < node->n)
			node = node->left;
		else if (value > node->n)
			node = node->right;
	}

	return (NULL);
}
