#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node * next;
};
void linked_list_traversal(struct node *head)
{
   struct node *ptr=head;
   do{
    printf("element is %d\n",ptr->data);
    ptr=ptr->next;
   }
   while(ptr!=head);
}
struct node* insertAtFirst(struct node *head, int data)
{
    struct node *ptr=(struct node *)malloc(sizeof(struct node));
    ptr->data=data;

    struct node * p = head->next;
    while(p->next!=head)
    {
        p=p->next;
    }
    p->next=ptr;
    ptr->next=head;
    head=ptr;
    return head;
}
int main()
{
    struct node * head;
    struct node *second;
    struct node *third;
    struct node *fourth;

    head= (struct node *) malloc (sizeof(struct node));
    second= (struct node *) malloc (sizeof(struct node));
    third= (struct node *) malloc (sizeof(struct node));
    fourth= (struct node *) malloc (sizeof(struct node));
    
    head->data=7;
    head->next=second;

    second->data=11;
    second->next=third;

    third->data=34;
    third->next=fourth;

    fourth->data=43;
    fourth->next=head;
    printf("circular linked list before insertion:\n");
    linked_list_traversal(head);
    head=insertAtFirst(head,54);
    head=insertAtFirst(head,55);
    printf("circular linked list after inserting:\n");
    linked_list_traversal(head);
    return 0;
}