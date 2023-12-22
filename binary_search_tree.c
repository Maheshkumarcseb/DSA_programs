#include <stdio.h>
#include <malloc.h>
struct node
{
    int data;
    struct node *left;
    struct node *right;
};
void inOrder(struct node *root)
{
    if (root != NULL)
    {
        inOrder(root->left);
        printf("%d ", root->data);
        inOrder(root->right);
    }
}
struct node *createNode(int data)
{
    struct node *n;                                 // creating a node pointer
    n = (struct node *)malloc(sizeof(struct node)); // allocating memory in heap
    n->data = data;                                 // setting the data
    n->left = NULL;                                 // setting the left children to NULL
    n->right = NULL;                                // setting the right children to NULL
    return n;                                       // finally returning the created node
}


int isBST(struct node *root)
{
    static struct node *prev = NULL;
    if (root != NULL)
    {
        if (!isBST(root->left))
        {
            return 0;
        }
        if (prev != NULL && root->data <= prev->data)
        {
            return 0;
        }
        prev = root;
        return isBST(root->right);
    }
    else
    {
        return 1;
    }
}
int main()
{
    struct node *p  =  createNode(4);
    struct node *p1 = createNode(1);
    struct node *p2 = createNode(6);
    struct node *p3 = createNode(5);
    struct node *p4 = createNode(2);

    p->left = p1;
    p->right = p2;
    p1->left = p3;
    p1->right = p4;
    // printf("pre-Order traversal are:\n");
    // preOrder(p);
    // printf("\n");
    // printf("post-Order traversal are:\n");
    // postOrder(p);
    printf("In-Order traversal are:\n");
    inOrder(p);
    printf("\n");
    printf("%d\n", isBST(p));
    return 0;
}