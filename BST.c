#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    int year;
    char company[50];
    char type[50];
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int year, const char* company, const char* type) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->year = year;
    strcpy(newNode->company, company);
    strcpy(newNode->type, type);
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to insert a new node into the BST
struct Node* insert(struct Node* root, int year, const char* company, const char* type) {
    if (root == NULL) {
        return createNode(year, company, type);
    }

    if (year < root->year) {
        root->left = insert(root->left, year, company, type);
    }
    else if (year > root->year) {
        root->right = insert(root->right, year, company, type);
    }

    return root;
}

struct Node* findMin(struct Node* root) {
    while (root->left != NULL) {
        root = root->left;
    }
    return root;
}

struct Node* deleteNode(struct Node* root, int year) {
    if (root == NULL) {
        return root;
    }

    if (year < root->year) {
        root->left = deleteNode(root->left, year);
    }
    else if (year > root->year) {
        root->right = deleteNode(root->right, year);
    }
    else {
        if (root->left == NULL) {
            struct Node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct Node* temp = root->left;
            free(root);
            return temp;
        }

        struct Node* temp = findMin(root->right);

        root->year = temp->year;
        strcpy(root->company, temp->company);
        strcpy(root->type, temp->type);

        root->right = deleteNode(root->right, temp->year);
    }

    return root;
}

void inorderTraversal(struct Node* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("Year: %d, Company: %s, Type: %s\n", root->year, root->company, root->type);
        inorderTraversal(root->right);
    }
}

void preorderTraversal(struct Node* root) {
    if (root != NULL) {
        printf("Year: %d, Company: %s, Type: %s\n", root->year, root->company, root->type);
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }
}

void postorderTraversal(struct Node* root) {
    if (root != NULL) {
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        printf("Year: %d, Company: %s, Type: %s\n", root->year, root->company, root->type);
    }
}

void freeBST(struct Node* root) {
    if (root != NULL) {
        freeBST(root->left);
        freeBST(root->right);
        free(root);
    }
}

int main() {
    struct Node* root = NULL;

    root = insert(root, 2010, "Toyota", "seadan");
    root = insert(root, 2015, "Honda", "city");
    root = insert(root, 2020, "Ford", "Truck");
    root = insert(root, 2005, "Chevrolet", "mini cooper");
    root = insert(root, 2018, "Nissan", "Gran Turismo");

    printf("Inorder Traversal:\n");
    inorderTraversal(root);

    printf("\nPreorder Traversal:\n");
    preorderTraversal(root);

    printf("\nPostorder Traversal:\n");
    postorderTraversal(root);

    int yearToDelete = 2015;
    root = deleteNode(root, yearToDelete);
    printf("\nAfter deleting the node with year %d:\n", yearToDelete);
    inorderTraversal(root);

    freeBST(root);

    return 0;
}
