#include "binary_trees.h"

/**
 * binary_tree_rotate_right -  performs a right-rotation on a binary tree
 * @tree: pointer to binare_tree_t
 * Return: pointer to the new root node of the tree once rotated;
 */
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t *aux, *temp;

	if (tree == NULL)
		return (NULL);

/* Check if the left child of the root exists */
	if (tree->left)
	{
/* Perform the right rotation */
		temp = tree->left->right;
		aux = tree->left;
		aux->parent = tree->parent;
		aux->right = tree;
		tree->parent = aux;
		tree->left = temp;
		if (temp)
			temp->parent = tree;
/* Return the new root node after the rotation */
		return (aux);
	}
/* If the left child does not exist, return NULL (no rotation performed) */
	return (NULL);
}
