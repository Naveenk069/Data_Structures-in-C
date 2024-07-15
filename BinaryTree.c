#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int data;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode *createNode(int value) {
    struct TreeNode *newNode = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct TreeNode *insert(struct TreeNode *root, int value) {
    if (root == NULL) {
        return createNode(value);
    }

    if (root->left == NULL) {
        root->left = insert(root->left, value);
    } else if (root->right == NULL) {
        root->right = insert(root->right, value);
    } else {
        root->left = insert(root->left, value);
    }

    return root;
}

struct TreeNode *findMinValueNode(struct TreeNode *node) {
    struct TreeNode *current = node;
    while (current->left != NULL) {
        current = current->left;
    }
    return current;
}

struct TreeNode *deleteNode(struct TreeNode *root, int value) {
    if (root == NULL) {
        return root;
    }

    if (value < root->data) {
        root->left = deleteNode(root->left, value);
    } else if (value > root->data) {
        root->right = deleteNode(root->right, value);
    } else {
        if (root->left == NULL) {
            struct TreeNode *temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct TreeNode *temp = root->left;
            free(root);
            return temp;
        }

        struct TreeNode *temp = findMinValueNode(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}



void inorder(struct TreeNode *root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

void preorder(struct TreeNode *root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(struct TreeNode *root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}


int main() {
    struct TreeNode *root = NULL;
    int opt, val;

    while (1) {
        printf("\n1.Insert");
        printf("\n2.Inorder");
        printf("\n3.Preorder");
        printf("\n4.Postorder");
        printf("\n5.Delete value");
        printf("\n6.Exit");
        printf("\nEnter option: ");
        scanf("%d", &opt);

        switch (opt) {
            case 1:
                printf("\nEnter value: ");
                scanf("%d", &val);
                root = insert(root, val);
                break;
            case 2:
                printf("\nInorder traversal: ");
                inorder(root);
                printf("\n");
                break;
            case 3:
                printf("\nPreorder traversal: ");
                preorder(root);
                printf("\n");
                break;
            case 4:
                printf("\nPostorder traversal: ");
                postorder(root);
                printf("\n");
                break;
            case 5:
                printf("\nEnter value to delete: ");
                scanf("%d", &val);
                root = deleteNode(root, val);
                break;
            case 6:
                exit(0);
            default:
                printf("\nInvalid option! Please try again.\n");
        }
    }

    return 0;
}
