#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *left;
    struct node *right;
};

struct node *root = NULL;

struct node* insert(struct node *root, int x) {
    if (root == NULL) {
        struct node *newnode = (struct node *)malloc(sizeof(struct node));
        newnode->data = x;
        newnode->left = NULL;
        newnode->right = NULL;
        return newnode;
    }
    if (x < root->data)
        root->left = insert(root->left, x);
    else if (x > root->data)
        root->right = insert(root->right, x);
    return root;
}

struct node* findMin(struct node *root) {
    while (root->left != NULL)
        root = root->left;
    return root;
}

struct node* deleteNode(struct node *root, int x) {
    if (root == NULL)
        return root;

    if (x < root->data)
        root->left = deleteNode(root->left, x);
    else if (x > root->data)
        root->right = deleteNode(root->right, x);
    else {
        if (root->left == NULL) {
            struct node *temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct node *temp = root->left;
            free(root);
            return temp;
        }
        struct node *temp = findMin(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

void display(struct node *root) {
    if (root != NULL) {
        display(root->left);
        printf("%d ", root->data);
        display(root->right);
    }
}

int main() {
    int ch, x;

    while (1) {
        printf("1.Insert 2.Delete 3.Display 4.Exit\n");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                scanf("%d", &x);
                root = insert(root, x);
                break;
            case 2:
                scanf("%d", &x);
                root = deleteNode(root, x);
                break;
            case 3:
                display(root);
                printf("\n");
                break;
            case 4:
                return 0;
        }
    }
}
