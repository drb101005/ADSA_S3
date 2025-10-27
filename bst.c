#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

struct Node* newNode(int val) {
    struct Node* n = malloc(sizeof(struct Node));
    n->data = val;
    n->left = n->right = NULL;
    return n;
}

struct Node* insert(struct Node* root, int val) {
    if (!root) return newNode(val);
    (val < root->data) ? (root->left = insert(root->left, val)) : (root->right = insert(root->right, val));
    return root;
}

void inorder(struct Node* root) {
    if(root){
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

void preorder(struct Node* root) {
    if(root){
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(struct Node* root) {
    if(root){
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

int main() {
    struct Node* root = NULL;
    int n, val;
    printf("Enter number of nodes: ");
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        printf("Enter value %d: ", i+1);
        scanf("%d", &val);
        root = insert(root, val);
    }
    printf("Inorder: ");
    inorder(root);
    printf("\nPreorder: ");
    preorder(root);
    printf("\nPostorder: ");
    postorder(root);
    return 0;
}