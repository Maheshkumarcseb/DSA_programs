#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};

// Function to find minimum value node in a tree
struct Node* FindMin(struct Node* root) {
    while (root->left != NULL) {
        root = root->left;
    }
    return root;
}

// Function to search and delete a value from the tree
struct Node* Delete(struct Node *root, int data) {
    if (root == NULL) {
        return root;
    }
    else if (data < root->data) {
        root->left = Delete(root->left, data);
    }
    else if (data > root->data) {
        root->right = Delete(root->right, data);
    }
    else {
        // Node to be deleted is found

        // Case 1: No child or only one child
        if (root->left == NULL) {
            struct Node *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL) {
            struct Node *temp = root->left;
            free(root);
            return temp;
        }

        // Case 2: Node has two children
        struct Node* temp = FindMin(root->right); // Find the inorder successor
        root->data = temp->data; // Copy the inorder successor's content to this node
        root->right = Delete(root->right, temp->data); // Delete the inorder successor
    }
    return root;
}
 
// Function to visit nodes in Inorder
void Inorder(struct Node *root) {
    if (root == NULL) {
        return;
    }

    Inorder(root->left);
    printf("%d ", root->data);
    Inorder(root->right);
}
 
// Function to Insert Node in a Binary Search Tree
struct Node* Insert(struct Node *root, int data) {
    if (root == NULL) {
        root = (struct Node*)malloc(sizeof(struct Node));
        root->data = data;
        root->left = root->right = NULL;
    }
    else if (data <= root->data) {
        root->left = Insert(root->left, data);
    }
    else {
        root->right = Insert(root->right, data);
    }
    return root;
}

int main() {
    // Creating an example tree
    struct Node* root = NULL;
    root = Insert(root, 5);
    root = Insert(root, 10);
    root = Insert(root, 3);
    root = Insert(root, 4);
    root = Insert(root, 1);
    root = Insert(root, 11);
    printf("Inorder before deleting a node:\n");
    Inorder(root);
    printf("\n");
    // Deleting node with value 5
    root = Delete(root, 5);

    // Print Nodes in Inorder
    printf("Inorder after deleting a node: \n");
    Inorder(root);
    printf("\n");

    return 0;
}
