#include <stdio.h>
#include <malloc.h>
struct node
{
    int data;
    struct node *left;
    struct node *right;
};
struct node *createNode(int data)
{
    struct node *n;                                 // creating a node pointer
    n = (struct node *)malloc(sizeof(struct node)); // allocating memory in heap
    n->data = data;                                 // setting the data
    n->left = NULL;                                 // setting the left children to NULL
    n->right = NULL;                                // setting the right children to NULL
    return n;                                       // finally returning the created node
}
void inOrder(struct node *root)
{
    if (root != NULL)
    {
        inOrder(root->left);
        printf("%d ", root->data);
        inOrder(root->right);
    }
}
struct node* inOrderPredecessor(struct node* root)
{
    root=root->left;
    while(root->right!=NULL)
    {
        root=root->right;
    }
}
struct node *deleteNode(struct node *root,int value)
{
    struct node* ipre;
    if(root==NULL)
    {
        return NULL;
    }
    if(root->left==NULL &&root->right==NULL){
        free(root);
        return NULL;
    }

    if(value < root->data){
        root->left=deleteNode(root->left,value);
    }
    else if(value>root->data){
        root->right=deleteNode(root->right,value);
    }
    else{
        ipre = inOrderPredecessor(root);
        root->data=ipre->data;
        root->left=deleteNode(root->left,ipre->data);
    }
    return root;
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

    inOrder(p);
    deleteNode(p, 1);
    printf("\n");
    inOrder(p);
    return 0;
}