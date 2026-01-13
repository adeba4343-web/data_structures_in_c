#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *left;
    struct node *right;
    int height;
};

int max(int a, int b) {
    return (a > b) ? a : b;
}

int height(struct node *n) {
    if (n == NULL) return 0;
    return n->height;
}

struct node* createNode(int x) {
    struct node* n = (struct node*)malloc(sizeof(struct node));
    n->data = x;
    n->left = NULL;
    n->right = NULL;
    n->height = 1;
    return n;
}

struct node* rightRotate(struct node* y) {
    struct node* x = y->left;
    struct node* T2 = x->right;
    x->right = y;
    y->left = T2;
    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;
    return x;
}

struct node* leftRotate(struct node* x) {
    struct node* y = x->right;
    struct node* T2 = y->left;
    y->left = x;
    x->right = T2;
    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;
    return y;
}

int getBalance(struct node* n) {
    if (n == NULL) return 0;
    return height(n->left) - height(n->right);
}

struct node* insert(struct node* node, int key) {
    if (node == NULL) return createNode(key);
    if (key < node->data) node->left = insert(node->left, key);
    else if (key > node->data) node->right = insert(node->right, key);
    else return node;

    node->height = 1 + max(height(node->left), height(node->right));
    int balance = getBalance(node);

    if (balance > 1 && key < node->left->data) return rightRotate(node);
    if (balance < -1 && key > node->right->data) return leftRotate(node);
    if (balance > 1 && key > node->left->data) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }
    if (balance < -1 && key < node->right->data) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

void inorder(struct node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

void display(struct node* root) {
    printf("Inorder: ");
    inorder(root);
    printf("\n");
}

int main() {
    struct node* root = NULL;
    int arr[] = {10, 20, 30, 40, 50, 25};
    for(int i=0; i<6; i++)
        root = insert(root, arr[i]);

    display(root);
    return 0;
}
