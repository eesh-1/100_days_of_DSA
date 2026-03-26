#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Tree Node
struct Node {
    int data;
    struct Node *left, *right;
};

// Queue
struct Node* queue[MAX];
int front = 0, rear = 0;

void enqueue(struct Node* node) {
    queue[rear++] = node;
}

struct Node* dequeue() {
    return queue[front++];
}

int isEmpty() {
    return front == rear;
}

// Create new node
struct Node* newNode(int data) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

// Zigzag traversal
void zigzag(struct Node* root) {
    if (!root) return;

    enqueue(root);
    int leftToRight = 1;

    while (!isEmpty()) {
        int size = rear - front;
        int level[MAX];

        for (int i = 0; i < size; i++) {
            struct Node* curr = dequeue();
            level[i] = curr->data;

            if (curr->left) enqueue(curr->left);
            if (curr->right) enqueue(curr->right);
        }

        if (leftToRight) {
            for (int i = 0; i < size; i++)
                printf("%d ", level[i]);
        } else {
            for (int i = size - 1; i >= 0; i--)
                printf("%d ", level[i]);
        }

        leftToRight = !leftToRight;
    }
}

// Build tree from array (level order)
struct Node* buildTree(int arr[], int n) {
    if (n == 0) return NULL;

    struct Node* root = newNode(arr[0]);
    enqueue(root);

    int i = 1;

    while (i < n) {
        struct Node* curr = dequeue();

        if (arr[i] != -1) {
            curr->left = newNode(arr[i]);
            enqueue(curr->left);
        }
        i++;

        if (i < n && arr[i] != -1) {
            curr->right = newNode(arr[i]);
            enqueue(curr->right);
        }
        i++;
    }
    return root;
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    front = rear = 0; // reset queue
    struct Node* root = buildTree(arr, n);

    front = rear = 0; // reset again
    zigzag(root);

    return 0;
}
