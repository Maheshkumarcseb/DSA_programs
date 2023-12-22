#include <stdio.h>
#include <stdlib.h>
struct node
{
    int key;
    struct node *left;
    struct node *right;
    int height;
};
int getHeight(struct node *n)
{
    if (n == NULL)
        return 0;
    return n->height;
}
struct node *createNode(int key)
{
    struct node *node = (struct node *)malloc(sizeof(struct node));
    node->key = key;
    node->left = NULL;
    node->right = NULL;
    node->height = 1;
    return node;
}
int max(int a, int b)
{
    return a > b ? a : b;
}
int getBalanceFactor(struct node *n)
{
    if (n == NULL)
    {
        return 0;
    }
    return getHeight(n->left) - getHeight(n->right);
}
struct Node *rightRotate(struct node *y)
{
    struct node *x = y->left;
    struct node *T2 = x->left;

    x->right = y;
    y->left = T2;

    y->height = max(getHeight(y->right), getHeight(y->left)) + 1;
    x->height = max(getHeight(x->right), getHeight(x->left)) + 1;
    return x;
}
struct Node *leftRotate(struct node *y)
{
    struct node *y = x->left;
    struct node *T2 = y->left;

    y->left = x;
    x->right = T2;

    y->height = max(getHeight(y->right), getHeight(y->left)) + 1;
    x->height = max(getHeight(x->right), getHeight(x->left)) + 1;
    return x;
}

struct node *insert(struct Node * node, int key)
{
    if (node == NULL)
        return (createNode(key));
    if (key < node->key)
    {
        node->left = insert(node->left, key)
    }
    else if (key > node->key)
    {
        node->right = insert(node->right, key);
    }
    // return node;
    node->height = 1 + max(getHeight(node->left), getHeight(node->right));
    int bf = getBalanceFactor(node);

    if (bf > 1 && key < node->left->key)
    {
        return rightRotate(node);
    }
    if (bf < -1 && key > node->right->key)
    {
        return leftRotate(node);
    }
    if (bf > 1 && key > node->left->key)
    {
        node->left = leftRotate(node->left);
        return leftRotate(node);
    }
    if (bf < -1 && key > node->right->key)
    {
        node->right = rightRotate(node->right);
        return rightRotate(node);
    }
    return node;
}
int main()
{
    struct Node *node = NULL;
    root = insert(root, 1);
    root = insert(root, 2);
    root = insert(root, 3);
    root = insert(root, 4);
    root = insert(root, 5);
    root = insert(root, 5);
    preOrder(root);
  

    return 0;
}
