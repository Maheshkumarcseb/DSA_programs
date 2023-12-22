#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node * prev;
    struct node * next;
};
void linked_list_traversal(struct node *ptr)
{
    while(ptr != NULL)
    {
        printf("element: %d\n",ptr->data);
        ptr=ptr->next;
    }
}
int main()
{
    struct node * N1;
    struct node * N2;
    struct node * N3;
    struct node * N4;

    N1=(struct node *)malloc(sizeof(struct node));
    N2=(struct node *)malloc(sizeof(struct node));
    N3=(struct node *)malloc(sizeof(struct node));
    N4=(struct node *)malloc(sizeof(struct node));

    N1->next=N2;
    N1->prev=NULL;

    N2->next=N3;
    N2->prev=N1;

    N3->next=N4;
    N3->prev=N2;

    N4->next=N1;
    N4->prev=N3;
    linked_list_traversal(N1);
}