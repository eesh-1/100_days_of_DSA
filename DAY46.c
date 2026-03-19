#include <stdio.h>
#include <stdlib.h>

// Tree Node definition
struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

// Queue implementation
#define MAX 1000

struct TreeNode* queue[MAX];
int front = 0, rear = 0;

// Enqueue
void enqueue(struct TreeNode* node) {
    queue[rear++] = node;
}

// Dequeue
struct TreeNode* dequeue() {
    return queue[front++];
}

// Check if queue is empty
int isEmpty() {
    return front == rear;
}

// Level Order Traversal
void levelOrder(struct TreeNode* root) {
    if (root == NULL) return;

    enqueue(root);

    while (!isEmpty()) {
        int size = rear - front;  // number of nodes at current level
        
        for (int i = 0; i < size; i++) {
            struct TreeNode* node = dequeue();
            printf("%d ", node->val);

            if (node->left != NULL)
                enqueue(node->left);
            if (node->right != NULL)
                enqueue(node->right);
        }
        printf("\n"); // new level
    }
}
