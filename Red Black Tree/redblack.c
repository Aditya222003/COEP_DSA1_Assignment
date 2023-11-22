#include <stdio.h>
#include <stdlib.h>

enum Color {
    RED,
    BLACK
};

struct Node {
    int data;
    enum Color color;
    struct Node* parent;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->color = RED;
    newNode->parent = NULL;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void insertFix(struct Node* root, struct Node* newNode) {
    while (newNode->parent != NULL && newNode->parent->color == RED) {
        struct Node* grandparent = newNode->parent->parent;
        struct Node* uncle = NULL;
        if (grandparent != NULL) {
            if (newNode->parent == grandparent->left) {
                uncle = grandparent->right;
                if (uncle != NULL && uncle->color == RED) {
                    newNode->parent->color = BLACK;
                    uncle->color = BLACK;
                    grandparent->color = RED;
                    newNode = grandparent;
                } else {
                    if (newNode == newNode->parent->right) {
                        newNode = newNode->parent;
                        // Left-rotation
                        // Case 3: Left-right case
                        // Convert it to a left-left case
                        // Left-rotation is performed on newNode->parent
                        // newNode->parent becomes the new newNode
                        if (newNode->parent != NULL) {
                            struct Node* parent = newNode->parent;
                            parent->left = newNode->right;
                            if (newNode->right != NULL)
                                newNode->right->parent = parent;
                            newNode->right = parent;
                            newNode->parent = parent->parent;
                            parent->parent = newNode;
                            if (newNode->parent != NULL) {
                                if (newNode->parent->left == parent)
                                    newNode->parent->left = newNode;
                                else
                                    newNode->parent->right = newNode;
                            } else {
                                root = newNode;
                            }
                        }
                    }
                    newNode->parent->color = BLACK;
                    grandparent->color = RED;
                    // Right-rotation
                    // Case 3: Left-left case
                    if (grandparent != NULL) {
                        struct Node* parent = grandparent->parent;
                        grandparent->parent = newNode;
                        grandparent->left = newNode->right;
                        if (newNode->right != NULL)
                            newNode->right->parent = grandparent;
                        newNode->right = grandparent;
                        newNode->parent = parent;
                        if (parent != NULL) {
                            if (parent->left == grandparent)
                                parent->left = newNode;
                            else
                                parent->right = newNode;
                        } else {
                            root = newNode;
                        }
                    }
                }
            } else {
                uncle = grandparent->left;
                if (uncle != NULL && uncle->color == RED) {
                    newNode->parent->color = BLACK;
                    uncle->color = BLACK;
                    grandparent->color = RED;
                    newNode = grandparent;
                } else {
                    if (newNode == newNode->parent->left) {
                        newNode = newNode->parent;
                        // Right-rotation
                        // Case 4: Right-left case
                        // Convert it to a right-right case
                        // Right-rotation is performed on newNode->parent
                        // newNode->parent becomes the new newNode
                        if (newNode->parent != NULL) {
                            struct Node* parent = newNode->parent;
                            parent->right = newNode->left;
                            if (newNode->left != NULL)
                                newNode->left->parent = parent;
                            newNode->left = parent;
                            newNode->parent = parent->parent;
                            parent->parent = newNode;
                            if (newNode->parent != NULL) {
                                if (newNode->parent->left == parent)
                                    newNode->parent->left = newNode;
                                else
                                    newNode->parent->right = newNode;
                            } else {
                                root = newNode;
                            }
                        }
                    }
                    newNode->parent->color = BLACK;
                    grandparent->color = RED;
                    // Left-rotation
                    // Case 4: Right-right case
                    if (grandparent != NULL) {
                        struct Node* parent = grandparent->parent;
                        grandparent->parent = newNode;
                        grandparent->right = newNode->left;
                        if (newNode->left != NULL)
                            newNode->left->parent = grandparent;
                        newNode->left = grandparent;
                        newNode->parent = parent;
                        if (parent != NULL) {
                            if (parent->left == grandparent)
                                parent->left = newNode;
                            else
                                parent->right = newNode;
                        } else {
                            root = newNode;
                        }
                    }
                }
            }
        }
    }
    root->color = BLACK;
}

struct Node* insert(struct Node* root, struct Node* newNode) {
    if (root == NULL) {
        root = newNode;
        root->color = BLACK;
        return root;
    }

    struct Node* current = root;
    struct Node* parent = NULL;
    while (current != NULL) {
        parent = current;
        if (newNode->data < current->data)
            current = current->left;
        else
            current = current->right;
    }

    newNode->parent = parent;
    if (newNode->data < parent->data)
        parent->left = newNode;
    else
        parent->right = newNode;

    insertFix(root, newNode);
    return root;
}

void inorderTraversal(struct Node* root) {
    if (root == NULL)
        return;

    inorderTraversal(root->left);
    printf("%d (%s) ", root->data, (root->color == RED) ? "RED" : "BLACK");
    inorderTraversal(root->right);
}

int main() {
    struct Node* root = NULL;
    int values[] = {5, 3, 8, 2, 4, 6, 9, 1, 7};
    int numValues = sizeof(values) / sizeof(values[0]);

    for (int i = 0; i < numValues; i++) {
        struct Node* newNode = createNode(values[i]);
        root = insert(root, newNode);
    }

    printf("Inorder Traversal of the Red-Black Tree: ");
    inorderTraversal(root);

    return 0;
}
