#include "binary_trees.h"

/**
 * binary_tree_postorder - Prints a binary tree in postorder order
 * @tree: The binary tree to be printed
 * @func: The user defined binaries that prints the node
 *
 * Return: Nothing
*/
void binary_tree_postorder(const binary_tree_t *tree, void (*func) (int))
{
	if (tree && func)
	{
		binary_tree_postorder(tree->left, func);
		binary_tree_postorder(tree->right, func);
		func(tree->n);
	}
}
