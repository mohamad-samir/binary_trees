#include <stdlib.h>
#include "binary_trees.h"

/**
 * heapify_up - Helper function to maintain Max Heap property after insertion.
 * @new_node: The newly inserted node.
 *
 * Return: A pointer to the new_node if needed, NULL otherwise.
 */
heap_t *heapify_up(heap_t *new_node)
{
    while (new_node->parent && new_node->n > new_node->parent->n)
    {
        int temp_value = new_node->n;
        new_node->n = new_node->parent->n;
        new_node->parent->n = temp_value;

        new_node = new_node->parent;
    }

    return (new_node);
}

/**
 * heap_insert - Inserts a value into a Max Binary Heap.
 * @root: A double pointer to the root node of the Heap.
 * @value: The value to store in the node to be inserted.
 *
 * Return: A pointer to the created node, or NULL on failure.
 */
heap_t *heap_insert(heap_t **root, int value)
{
    heap_t *new_node, *parent;

    new_node = binary_tree_node(NULL, value);
    if (!new_node)
        return (NULL);

    if (!*root)
    {
        *root = new_node;
        return (new_node);
    }

    parent = *root;

    while (parent->left || parent->right)
    {
        if (!parent->left || (parent->right && parent->left->n < parent->right->n))
        {
            parent = parent->right;
        }
        else
        {
            parent = parent->left;
        }
    }

    if (!parent->left)
    {
        parent->left = new_node;
    }
    else
    {
        parent->right = new_node;
    }

    new_node->parent = parent;

    return (heapify_up(new_node));
}
