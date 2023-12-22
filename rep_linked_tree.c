#include<stdio.h>
#include<malloc.h>
struct node{
    int data;
    struct node * left;
    struct node * right;
};
struct node* createNode(int data)
{
    struct node * n;   // creating a node pointer
    n=(struct node *)malloc(sizeof(struct node));   //allocating memory in heap
    n->data=data;  //setting the data
    n->left=NULL;   //setting the left children to NULL
    n->right=NULL;   //setting the right children to NULL
    return 0;   // finally returning the created node
}
int main()
{
    struct node * p =createNode(2);
    struct node * p1 =createNode(3);
    struct node * p2 =createNode(4);

    //linking the node with left and right children

    p->left=p1;
    p->right=p2;

    printf("%d\n",p1);
    return 0;
}