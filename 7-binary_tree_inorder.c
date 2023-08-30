#include "binary_trees.h"

/**
 * binary_tree_inorder - Prints a binary tree in inorder order
 * @tree: The binary tree to be printed
 * @func: The user defined binaries that prints the node
 *
 * Return: Nothing
*/
void binary_tree_inorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree && func)
	{
		binary_tree_inorder(tree->left, func);
		func(tree->n);
		binary_tree_inorder(tree->right, func);
	}
}

