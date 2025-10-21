#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *l, *r;
} Node;

Node* insert(Node* n, int v) {
    if (!n) {
        Node* t = malloc(sizeof(Node));
        t->data = v; t->l = t->r = NULL;
        return t;
    }
    if (v < n->data) n->l = insert(n->l, v);
    else n->r = insert(n->r, v);
    return n;
}

void inorder(Node* n) { if (n) { inorder(n->l); printf("%d ", n->data); inorder(n->r); } }
void preorder(Node* n) { if (n) { printf("%d ", n->data); preorder(n->l); preorder(n->r); } }
void postorder(Node* n) { if (n) { postorder(n->l); postorder(n->r); printf("%d ", n->data); } }

int main() {
    int a[] = {9,4,8,1,7,0,3,2,5,6}, n = 10;
    Node* root = NULL;
    for (int i = 0; i < n; i++) root = insert(root, a[i]);

    printf("In: "); inorder(root); printf("\n");
    printf("Pre: "); preorder(root); printf("\n");
    printf("Post: "); postorder(root); printf("\n");
}
