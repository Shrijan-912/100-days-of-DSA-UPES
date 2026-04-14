#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

struct Node *front = NULL, *rear = NULL;

// Enqueue
void enqueue(int x) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = x;

    // If queue is empty
    if (front == NULL) {
        front = rear = newNode;
        rear->next = front;  // circular link
    } else {
        rear->next = newNode;
        rear = newNode;
        rear->next = front;  // maintain circular
    }
}

// Dequeue
void dequeue() {
    if (front == NULL) return;

    // Only one node
    if (front == rear) {
        free(front);
        front = rear = NULL;
    } else {
        struct Node* temp = front;
        front = front->next;
        rear->next = front;  // maintain circular
        free(temp);
    }
}

// Display queue
void display() {
    if (front == NULL) return;

    struct Node* temp = front;

    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != front);
}

int main() {
    int n, m, x;

    scanf("%d", &n);

    // Enqueue elements
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        enqueue(x);
    }

    // Number of dequeue operations
    scanf("%d", &m);

    for (int i = 0; i < m; i++) {
        dequeue();
    }

    display();

    return 0;
}