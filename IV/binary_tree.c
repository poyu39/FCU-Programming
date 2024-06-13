#include <stdio.h>

struct node {
    int data;
    struct node *left;
    struct node *right;
};
typedef struct node Node;

Node *create_node(int data) {
    Node *new_node = (Node *)malloc(sizeof(Node));
    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

Node *insert_node(Node *root, int data) {
    if (root == NULL) {
        root = create_node(data);
    } else {
        if (data < root->data) {
            root->left = insert_node(root->left, data);
        } else {
            root->right = insert_node(root->right, data);
        }
    }
    return root;
}

void display_node(Node *root) {
    if (root != NULL) {
        display_node(root->left);
        printf("%d ", root->data);
        display_node(root->right);
    }
}

void preorder(Node *root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void inorder(Node *root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

void postorder(Node *root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

int main() {
    Node *root = NULL;
}