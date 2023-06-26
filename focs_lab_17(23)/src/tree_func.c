#include "../headers/tree_func.h"
#include "../headers/tree.h"


static size_t node_degree(const tree_node * const  node)
{
    if ((node->left == NULL) && (node->right == NULL))
    {
        return ((node->value == (tree_t)0) ? 1 : 0);
    }
    else if (((node->left == NULL) && (node->right != NULL)))
    {
        return node_degree(node->right) + ((node->value == (tree_t)1) ? 1 : 0);
    }
    else if (((node->right == NULL) && (node->left != NULL)))
    {
        return node_degree(node->left) + ((node->value == (tree_t)1) ? 1 : 0);
    }
    else
    {
        return node_degree(node->left) + node_degree(node->right) + (((node->value) == (tree_t)2) ? 1 : 0);
    }
}

size_t whole_tree_degree(const tree * const tree)
{
    return node_degree(tree->root);
}