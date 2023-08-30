#include "binary_trees.h"

/**
 * bst_insert - Inserts a value into a binary search tree (BST).
 *
 * @tree: A double pointer to the root node of the BST.
 * @value: The value to be inserted.
 *
 * Return: A pointer to the created node, or NULL on failure or if value
 * already exists.
 */
bst_t *bst_insert(bst_t **tree, int value)
{
	if (tree == NULL)
		return (NULL);

	if (*tree == NULL)
	{
		/* Create a new node and make it the root node */
		*tree = binary_tree_node(NULL, value);
		return (*tree);
	}

	/* If the value is less than the current node's value, go left */
	if (value < (*tree)->n)
	{
		if ((*tree)->left)
			return (bst_insert(&((*tree)->left), value));

		/* Create a new node and insert it to the left */
		(*tree)->left = binary_tree_node(*tree, value);
		return ((*tree)->left);
	}
	/* If the value is greater than the current node's value, go right */
	else if (value > (*tree)->n)
	{
		if ((*tree)->right)
			return (bst_insert(&((*tree)->right), value));

		/* Create a new node and insert it to the right */
		(*tree)->right = binary_tree_node(*tree, value);
		return ((*tree)->right);
	}
	/* If the value is equal to the current node's value, just return NULL */
	else if (value == (*tree)->n)
	{
		return (NULL);
	}

	return (*tree);
}
