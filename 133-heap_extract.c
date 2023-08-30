#include "binary_trees.h"

/**
 * heapify_down - restores the max heap property by sifting down the value
 * @root: pointer to the root node of the heap
 */
void heapify_down(heap_t *root)
{
	heap_t *largest;
	int value;

	while (1)
	{
		if (!root->left)
			break;

		if (!root->right || root->left->n > root->right->n)
			largest = root->left;
		else
			largest = root->right;

		if (root->n > largest->n)
			break;

		value = root->n;
		root->n = largest->n;
		largest->n = value;

		root = largest;
	}
}

/**
 * heap_extract - extracts the root node of a Max Binary Heap
 * @root: a double pointer to the root node of the heap
 *
 * Return: the value stored in the root node
 *         0 on failure
 */
int heap_extract(heap_t **root)
{
	int value;
	heap_t *node;

	if (!root || !*root)
		return (0);

	value = (*root)->n;
	if (!(*root)->left && !(*root)->right)
	{
		free(*root);
		*root = NULL;
		return (value);
	}

	node = *root;
	while (node->left || node->right)
	{
		if (!node->right || (node->left && node->left->n >= node->right->n))
		{
			node->n = node->left->n;
			node = node->left;
		}
		else
		{
			node->n = node->right->n;
			node = node->right;
		}
	}

	if (node->parent->left == node)
		node->parent->left = NULL;
	else
		node->parent->right = NULL;

	free(node);
	heapify_down(*root);
	return (value);
}
