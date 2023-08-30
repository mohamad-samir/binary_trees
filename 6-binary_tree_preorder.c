#include "binary_trees.h"

/**
 * binary_tree_preorder - Prints a binary tree in preorder order
 * @tree: The binary tree to be printed
 * @func: The user defined binaries that prints the node
 *
 * Return: Nothing
*/
void binary_tree_preorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree && func)
	{
		func(tree->n);
		binary_tree_preorder(tree->left, func);
		binary_tree_preorder(tree->right, func);
	}
}
