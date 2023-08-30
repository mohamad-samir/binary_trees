#include "binary_trees.h"

/**
 * binary_tree_depth - measures the depth of a node in a binary tree.
 *@tree: pointer to the node to measure the depth.
 * Return: if tree is NULL, function must return 0.
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	else
		return (1 + binary_tree_depth(tree->parent));
}
/**
 * binary_trees_ancestor - finds the lowest common ancestor of two nodes
 * @first: first node
 * @second: second node
 * Return: lowest common ancestor
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
				     const binary_tree_t *second)
{
	size_t height_f = 0, height_s = 0;
	const binary_tree_t *aux = NULL;

/* Calculate the depth of the first and second nodes */
	height_f = binary_tree_depth(first);
	height_s = binary_tree_depth(second);

/* Check if both nodes exist in the binary tree */
	if (height_f && height_s)
	{
/* If the height of the first node is greater, swap first and second */
		if (height_f > height_s)
		{
			aux = first;
			first = second;
			second = aux;
		}
/* Iterate upwards from the first node to find the lowest common ancestor */
		while (first)
		{
			aux = second;
/* Iterate upwards from the second node */
			while (aux)
			{
/* If a common ancestor is found, return it as the LCA */
				if (first == aux)
					return ((binary_tree_t *)first);
				aux = aux->parent;
			}
			first = first->parent;
		}
	}
	else
	{
    /* If either of the nodes doesn't exist, return NULL (no LCA) */
		return (NULL);
	}
    /* If no common ancestor is found, return NULL (no LCA) */
	return (NULL);
}
