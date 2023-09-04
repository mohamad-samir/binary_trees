#include "binary_trees.h"

/**
 * bst_find_min - Finds the node with the minimum value in a BST.
 * @node: The root node of the BST.
 *
 * Return: A pointer to the node with the minimum value.
 */
bst_t *bst_inorder_successor(bst_t *node)
{
	bst_t *current = node;

	/* loop down to find the leftmost leaf */
	while (current && current->left != NULL)
		current = current->left;

	return (current);
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
	bst_t *temp;

	if (root == NULL)
		return (NULL);

	/* If the value to be deleted is smaller than the root's value,
	then it lies in left subtree */
	if (value < root->n)
		root->left = bst_remove(root->left, value);

	/* If the value to be deleted is greater than the root's value,
	then it lies in right subtree */
	else if (value > root->n)
		root->right = bst_remove(root->right, value);

	/* if value is same as root's value, then This is the node
	to be deleted */
	else
	{
		/* node with only one child or no child */
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

		/* node with two children: Get the inorder successor
		(smallest in the right subtree) */
		temp = bst_inorder_successor(root->right);

		/* Copy the inorder successor's content to this node */
		root->n = temp->n;

		/* Delete the inorder successor */
		root->right = bst_remove(root->right, temp->n);
	}
	return (root);
}
