#include "binary_trees.h"

/**
 * bt_is_complete - Checks if a binary tree is complete.
 * @tree: A pointer to the root node of the tree to check.
 * @index: The node index to check.
 * @size: The number of nodes in the tree.
 *
 * Return: 1 if the tree is complete,
 *         0 if the tree is not complete or tree is NULL.
 *
 * This is a helper function used by binary_tree_is_complete. It recursively
 * checks if the binary tree is complete by comparing the current index with
 * the size of the tree. If the index exceeds the size, the tree isn't complete
 * It calls itself on the left and right subtrees to check their completeness.
 */
int bt_is_complete(const binary_tree_t *tree, size_t index, size_t size)
{
	if (!tree)
		return (1);

	if (index >= size)
		return (0);

	return (bt_is_complete(tree->left, 2 * index + 1, size) &&
			bt_is_complete(tree->right, 2 * index + 2, size));
}

/**
 * binary_tree_size - Measures the size of a binary tree.
 * @tree: The tree to measure the size of.
 *
 * Return: The size of the tree,
 *         0 if tree is NULL.
 *
 * This function calculates the size of a binary tree by recursively
 * counting the number of nodes in the left and right subtrees and adding
 * one for the current node.
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (binary_tree_size(tree->left) +
			binary_tree_size(tree->right) + 1);
}

/**
 * binary_tree_is_complete - Checks if a binary tree is complete.
 * @tree: A pointer to the root node of the tree to check.
 *
 * Return: 1 if the tree is complete,
 *         0 if the tree is not complete or tree is NULL.
 *
 * This function checks if a binary tree is complete. A complete binary tree
 * is a b-tree in which every level, except possibly the last, is completely
 * filled, and all nodes are as far left as possible. It calls the helper
 * function to check the completeness of the tree.
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	size_t size;

	if (!tree)
		return (0);
	size = binary_tree_size(tree);

	return (bt_is_complete(tree, 0, size));
}
