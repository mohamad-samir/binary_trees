#include "binary_trees.h"

/**
 * binary_tree_rotate_left -  performs a left-rotation on a binary tree
 * @tree: pointer to binare_tree_t
 * Return: pointer to the new root node of the tree once rotated;
 */
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *aux, *temp;

	if (tree == NULL)
		return (NULL);

/* Check if the right child of the root exists */
	if (tree->right)
	{
/* Perform the left rotation */
		temp = tree->right->left;
		aux = tree->right;
		aux->parent = tree->parent;
		aux->left = tree;
		tree->parent = aux;
		tree->right = temp;
		if (temp)
			temp->parent = tree;
/* Return the new root node after the rotation */
		return (aux);
	}
/* If the right child does not exist, return NULL (no rotation performed) */
	return (NULL);
}
