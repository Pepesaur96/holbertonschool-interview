#include "binary_trees.h"
#include <stdio.h>

/**
 * heapify_up - Restores the Max Heap property by swapping the inserted node
 * up the tree as needed.
 * @node: Pointer to the newly inserted node.
 *
 * Return: Pointer to the node after heapify.
 */
heap_t *heapify_up(heap_t *node)
{
    int temp;

    while (node->parent && node->n > node->parent->n)
    {
        temp = node->n;
        node->n = node->parent->n;
        node->parent->n = temp;
        node = node->parent;
    }

    return (node);
}

/**
 * insert_at_end - Inserts a new node at the first available position
 * in level-order.
 * @root: Pointer to the root node of the heap.
 * @value: Value to insert in the node.
 *
 * Return: Pointer to the newly inserted node.
 */
heap_t *insert_at_end(heap_t *root, int value)
{
    heap_t *new_node;
    heap_t *queue[1024];
    int head = 0, tail = 0;

    if (root == NULL)
        return (binary_tree_node(NULL, value));

    queue[tail++] = root;

    while (head < tail)
    {
        heap_t *current = queue[head++];

        if (current->left)
            queue[tail++] = current->left;
        else
        {
            new_node = binary_tree_node(current, value);
            current->left = new_node;
            return (new_node);
        }

        if (current->right)
            queue[tail++] = current->right;
        else
        {
            new_node = binary_tree_node(current, value);
            current->right = new_node;
            return (new_node);
        }
    }

    return (NULL);
}

/**
 * heap_insert - Inserts a value into a Max Binary Heap.
 * @root: Double pointer to the root node of the heap.
 * @value: Value to insert in the node.
 *
 * Return: Pointer to the inserted node.
 */
heap_t *heap_insert(heap_t **root, int value)
{
    heap_t *new_node;

    if (root == NULL)
        return (NULL);

    if (*root == NULL)
    {
        *root = binary_tree_node(NULL, value);
        return (*root);
    }

    new_node = insert_at_end(*root, value);
    if (new_node == NULL)
        return (NULL);

    return (heapify_up(new_node));
}
