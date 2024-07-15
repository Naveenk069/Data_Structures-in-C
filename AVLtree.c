#include <stdio.h>
#include <stdlib.h>

struct node {
    struct node *lc;
    int data;
    int height;
    struct node *rc;
};

struct node *root = NULL;

struct node *newnode(int val) {
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    temp->lc = temp->rc = NULL;
    temp->data = val;
    temp->height = 0;
    return temp;
}

int maximum(int a, int b) {
    return (a > b) ? a : b;
}

int height(struct node *t) {
    if (t == NULL)
        return -1;
    else
        return t->height;
}

struct node *RR(struct node *K2) {
    struct node *K1 = K2->lc;
    K2->lc = K1->rc;
    K1->rc = K2;
    K2->height = maximum(height(K2->lc), height(K2->rc)) + 1;
    K1->height = maximum(height(K1->lc), height(K1->rc)) + 1;
    return K1;
}

struct node *LL(struct node *K2) {
    struct node *K1 = K2->rc;
    K2->rc = K1->lc;
    K1->lc = K2;
    K2->height = maximum(height(K2->lc), height(K2->rc)) + 1;
    K1->height = maximum(height(K1->lc), height(K1->rc)) + 1;
    return K1;
}

void RL(struct node *K3) {
    K3->rc = RR(K3->rc);
    K3 = LL(K3);
}

void LR(struct node *K3) {
    K3->lc = LL(K3->lc);
    K3 = RR(K3);
}

struct node *bsinsert(struct node *root, int val) {
    if (root == NULL)
        return newnode(val);

    if (root->data > val)
        root->lc = bsinsert(root->lc, val);
    else if (root->data < val)
        root->rc = bsinsert(root->rc, val);

    root->height = maximum(height(root->lc), height(root->rc)) + 1;

    int balance = height(root->lc) - height(root->rc);

    if (balance > 1 && val < root->lc->data)
        return RR(root);
    if (balance > 1 && val > root->lc->data) {
        LR(root);
        return (root);
    }
    if (balance < -1 && val > root->rc->data)
        return LL(root);
    if (balance < -1 && val < root->rc->data) {
        RL(root);
        return (root);
    }

    return root;
}

void inorder(struct node *root) {
    if (root != NULL) {
        inorder(root->lc);
        printf("%d ", root->data);
        inorder(root->rc);
    }
}

void preorder(struct node *root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorder(root->lc);
        preorder(root->rc);
    }
}

void postorder(struct node *root) {
    if (root != NULL) {
        postorder(root->lc);
        postorder(root->rc);
        printf("%d ", root->data);
    }
}

int main() {
    int opt, val;
    while (1) {
        printf("\n1.Insert\n2.Inorder\n3.Postorder\n4.Preorder\n5.Exit\n");
        printf("Enter the option: ");
        scanf("%d", &opt);

        switch (opt) {
        case 1:
            printf("\nEnter value: ");
            scanf("%d", &val);

            if (root == NULL)
                root = newnode(val);
            else
                root = bsinsert(root, val);

            break;
        case 2:
            if (root == NULL)
                printf("No values to display\n");
            else
                inorder(root);
            printf("\n");
            break;
        case 3:
            if (root == NULL)
                printf("No values to display\n");
            else
                postorder(root);
            printf("\n");
            break;
        case 4:
            preorder(root);
            break;
        case 5:
            return 0;
        }
    }
}
