#include "binary_trees.h"

/**
 * bst_find_min - Finds the node with the minimum value in a BST.
 * @root: The root node of the BST.
 *
 * Return: A pointer to the node with the minimum value.
 */
bst_t *bst_find_min(bst_t *root)
{
	while (root && root->left)
		root = root->left;
	return (root);
}

/**
 * bst_remove - Removes a node from a Binary Search Tree (BST).
 * @root: A pointer to the root node of the BST.
 * @value: The value to be removed.
 *
 * Return: A pointer to the new root node of the tree after removing the value.
 */
bst_t *bst_remove(bst_t *root, int value)
{
	bst_t *min_right, *temp;

	if (root == NULL)
		return (NULL);

	if (value < root->n)
		root->left = bst_remove(root->left, value);
	else if (value > root->n)
		root->right = bst_remove(root->right, value);
	else
	{
		/* Node with only one child or no child */
		if (root->left == NULL)
		{
			temp = root->right;
			free(root);
			return (temp);
		}
		else if (root->right == NULL)
		{
			temp = root->left;
			free(root);
			return (temp);
		}

		/* Node with two children: get the (smallest in the right subtree) */
		min_right = bst_find_min(root->right);
		root->n = min_right->n;
		root->right = bst_remove(root->right, min_right->n);
	}
	return (root);
}
