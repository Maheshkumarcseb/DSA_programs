#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
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

// struct node * deleteFirst(struct node *head)
// {
//     struct node * ptr=head;
//     head=head->next;
//     free(ptr);
//     return head;
// }

// struct node * deleteAtIndex(struct node * head, int index)
// {
//     struct node *p=head;
//     struct node *q=head->next;
//     while(q->next !=NULL)
//     {
//         p=p->next;
//         q=q->next;
//     }
//     p->next=q->next;
//     free(q);
//     return head;
// }


// struct node * deleteAtLast(struct node *  head)
// {
//     struct node *p=head;
//     struct node *q=head->next;
    // while(q->next !=NULL)
//     {
//         p=p->next;
//         q=q->next;
//     }
//     p->next=NULL;
//     free(q);
//     return head;
// }
struct node * deleteByValue(struct node * head,int value)
{
    struct node *p =head;
    struct node *q=head->next;
    while(q->data!=value && q->next!=NULL)
    {
        p=p->next;
        q=q->next;
    }
    if(q->data ==value)
    {
        p->next=q->next;
        free(q);
    }
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
    fourth->next=NULL;
    
    printf("linked list before deletion;\n");
    linked_list_traversal(head);

    printf("linked list after deletion:\n");
    // head=deleteFirst(head);
    // head=deleteFirst(head);
    // head=deleteAtIndex(head,3);
    // head=deleteAtLast(head);
    head=deleteByValue(head,11);
    linked_list_traversal(head);
    
    return 0;
}