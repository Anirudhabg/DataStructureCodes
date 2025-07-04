#include <stdio.h>
#include <stdlib.h>

// Define the node structure
typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

// Create a new node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Inorder traversal: Left, Root, Right
void inorder(Node* root) {
    if (root == NULL) return;

    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

// Preorder traversal: Root, Left, Right
void preorder(Node* root) {
    if (root == NULL) return;

    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

// Postorder traversal: Left, Right, Root
void postorder(Node* root) {
    if (root == NULL) return;
    
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}

// Level Order traversal: using queue
void levelOrder(Node* root) {
    if (root == NULL) return;

    Node* queue[100];
    int front = 0, rear = 0;

    queue[rear++] = root;

    while (front < rear) {
        Node* temp = queue[front++];

        printf("%d ", temp->data);

        if (temp->left)
            queue[rear++] = temp->left;
        if (temp->right)
            queue[rear++] = temp->right;
    }
}

// Main function
int main() {
    // Constructing the following tree:
    //         1
    //       /   \
    //      2     3
    //     / \   / \
    //    4   5 6   7

    // Node* root = createNode(1);
    // root->left = createNode(2);
    // root->right = createNode(3);
    // root->left->left = createNode(4);
    // root->left->right = createNode(5);
    // root->right->left = createNode(6);
    // root->right->right = createNode(7);


    // Constructing the following tree:
    //         40
    //       /    \
    //      30    50
    //     / \    / \
    //    25 35  45 60
    //    / \       / \
    //   15 28     55 70

    // Node * root = createNode(40);
    // root->left = createNode(30);
    // root->right = createNode(50);
    // root->left->left = createNode(25);
    // root->left->right = createNode(35);
    // root->right->left = createNode(45);
    // root->right->right = createNode(60);
    // root->left->left->left = createNode(15);
    // root->left->left->right = createNode(28);
    // root->right->right->left = createNode(55);
    // root->right->right->right = createNode(70);

    // Constructing the following tree:
    //         1
    //       /   \
    //      2     3
    //     / \   / \
    //    4   5 6   7
    //       /     / \
    //      8     9  10

    // Node* root = createNode(1);
    // root->left = createNode(2);
    // root->right = createNode(3);
    // root->left->left = createNode(4);
    // root->left->right = createNode(5);
    // root->right->left = createNode(6);
    // root->right->right = createNode(7);
    // root->left->right->left = createNode(8);
    // root->right->right->left = createNode(9);
    // root->right->right->right = createNode(10);

    // Constructing the following tree:
    //         1
    //       /   \
    //      2     3
    //     / \     \
    //    4   5     6
    //   /           \
    //  7             8
    //  \
    //   9

    Node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    root->right->right = createNode(6);
    root->left->left->left = createNode(7);
    root->left->left->left->right = createNode(9);
    root->right->right->right = createNode(8);

    // Constructing the following tree:
    //         1
    //       /   \
    //      2     3
    //     / \   / \
    //    4   5 6   7
   //   / \     \  / \
    //  8   9  10 11 12
    // Node* root = createNode(1);
    // root->left = createNode(2);
    // root->right = createNode(3);
    // root->left->left = createNode(4);
    // root->left->right = createNode(5);
    // root->right->left = createNode(6);
    // root->right->right = createNode(7);
    // root->left->left->left = createNode(8);
    // root->left->left->right = createNode(9);
    // root->right->left->right = createNode(10);
    // root->right->right->left = createNode(11);
    // root->right->right->right = createNode(12);
    // Print all traversals
    printf("Inorder Traversal: ");
    inorder(root);
    printf("\n");

    printf("Preorder Traversal: ");
    preorder(root);
    printf("\n");

    printf("Postorder Traversal: ");
    postorder(root);
    printf("\n");

    printf("Level Order Traversal: ");
    levelOrder(root);
    printf("\n");

    return 0;
}
