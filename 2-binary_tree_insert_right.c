#include "binary_trees.h"

/**
 * binary_tree_insert_right - Inserts a node as the right child of another node
 * @parent: Pointer to the node to insert the right-child in
 * @value: The value to store in the new node
 *
 * Return: Pointer to the created binary tree node or NULL on failure or if
 *         parent is NULL
*/
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *former_right_child = NULL;
	binary_tree_t *new_right_child = NULL;

	/* If parent is null then we can't insert any node */
	if (parent == NULL)
		return (NULL);

	/* Create the new node to be inserted */
	new_right_child = binary_tree_node(parent, value);
	if (new_right_child == NULL)
		return (NULL);

	/* If parent already has a right-child, have a pointer to the child */
	if (parent->right != NULL)
		former_right_child = parent->right;

	parent->right = new_right_child;
	if (former_right_child)
	{
		new_right_child->right = former_right_child;
		former_right_child->parent = new_right_child;
	}

	return (new_right_child);
}

