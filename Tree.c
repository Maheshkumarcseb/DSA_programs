#include<stdio.h>
#include<malloc.h>
struct node{
    int data;
    struct node * left;
    struct node * right;
};
int main()
{
    //constructing the root node
    struct node * p;
    p=(struct node *)malloc(sizeof(struct node));
    p->data=5;
    p->left=NULL;
    p->right=NULL;

    //constructing the second node
    struct node * p1;
    p1=(struct node *)malloc(sizeof(struct node));
    p1->data=7;
    p1->left=NULL;
    p1->right=NULL;

    struct node * p2;
    p2=(struct node *)malloc(sizeof(struct node));
    p2->data=98;
    p2->left=NULL;
    p2->right=NULL;

    struct node * p3;
    p3=(struct node *)malloc(sizeof(struct node));
    p3->data=43;
    p3->left=NULL;
    p3->right=NULL;

    //linking the root node with chidren
    p->left=p1;
    p->right=p2;

    
    printf("%d\n",p->data);
    printf("%d\n",p1->data);
    printf("%d\n",p2->data);
    printf("%d\n",p3->data);
    return 0;

}