// mainly there are four types of linked_list insertion
// -insert at the beginning
// -insert at between
// -insert at the end
// -insert after a node


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


// struct node * insertAtFirst(struct node *head,int data)
// {
//     struct node * ptr = (struct node *) malloc (sizeof(struct node));
//     ptr->next=head;
//     ptr->data=data;
//     return ptr;
// }




// struct node * insert_between_list (struct node *head,int data,int index)
// {
//     struct node * ptr = (struct node *) malloc (sizeof(struct node));
//     struct node * p=head;
//     int i=0;
//     while(i!=index-1)
//     {
//         p=p->next;
//         i++;
//     } 
//     ptr->data=data;
//     ptr->next=p->next;
//     p->next = ptr;
//     return head;
// }



// struct node *insertAtEnd(struct node *head,int data)
// {
//    struct node * ptr = (struct node *) malloc (sizeof(struct node));
//    ptr->data= data;
//    struct node * p = head;

//    while(p->next!=NULL)
//    {
//     p=p->next;
//    } 
//    p->next=ptr;
//    ptr->next=NULL;
//    return head; 
// }

struct node * insertAfterNode(struct node * head,struct node *prevnode,int data){
  struct node * ptr = (struct node *) malloc (sizeof(struct node));
  ptr->data=data;

  ptr->next=prevnode->next;
  prevnode->next=ptr;
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

    printf("linked list before insertion:\n");
    linked_list_traversal(head);

     printf("linked list after insertion:\n");
    // head=insertAtFirst(head,45);
    // head=insertAtEnd(head,43);
    head = insert_between_list (head, 56,2); 
    // head = insertAfterNode(head, second, 46); 
    
    linked_list_traversal(head);

    
    return 0;
}