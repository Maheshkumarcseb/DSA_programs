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
struct node * searchIter(struct node * root,int key)
{
    while(root!=NULL){
        if(key=root->data){
            return root;
        }
        else if(key<root->data)
        {
            root=root->left;
        }
        else{
            root=root->right;
        }
    }
    return NULL;
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

    struct node * n=searchIter(p,5);
    if(n!=NULL){
        printf("found: %d",n->data);
    }
    else{
        printf("Element not found");
    }
    return 0;
}