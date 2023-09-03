#include "binary_trees.h"

/**
 * binary_tree_size - measures the size of a binary tree
 * @tree: pointer to the root node of the tree to measure the size
 * Return: size of the tree, or 0 if tree is NULL
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (binary_tree_size(tree->left) + 1 + binary_tree_size(tree->right));
}

/**
 * binary_tree_is_complete_aux - checks if a binary tree is complete
 * @tree: pointer to the root node of the tree to check
 * @index: index of the node
 * @nodes: number of nodes in the tree
 * Return: 1 if the tree is complete, 0 otherwise
 */
int binary_tree_is_complete_aux(const binary_tree_t *tree,
								size_t index, size_t nodes)
{
	if (tree == NULL)
		return (1);
	if (index >= nodes)
		return (0);
	return (binary_tree_is_complete_aux(tree->left, 2 * index + 1, nodes) &&
			binary_tree_is_complete_aux(tree->right, 2 * index + 2, nodes));
}

/**
 * binary_tree_is_complete - checks if a binary tree is complete
 * @tree: pointer to the root node of the tree to check
 * Return: 1 if the tree is complete, 0 otherwise
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	size_t nodes;

	if (tree == NULL)
		return (0);
	nodes = binary_tree_size(tree);
	return (binary_tree_is_complete_aux(tree, 0, nodes));
}
