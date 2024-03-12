#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* Insert(struct Node* head, int data) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;
    temp->next = NULL;
    if (head == NULL)
        head = temp;
    else {
        struct Node* temp1 = head;
        while (temp1->next != NULL)
            temp1 = temp1->next;
        temp1->next = temp;
    }
    return head;
}

void print(struct Node* p) {
    if (p == NULL)
        return;
    // printf("%d ", p->data);   // printing element of linked list in forward direction
    print(p->next);
    printf("%d ", p->data);   // printing element of linked list in backward direction

}

int main() {
    struct Node* head = NULL;
    head = Insert(head, 2);
    head = Insert(head, 4);
    head = Insert(head, 6);
    head = Insert(head, 8);
    printf("Linked list traversal: ");
    print(head);
    printf("\n");

    // Freeing memory
    struct Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}
