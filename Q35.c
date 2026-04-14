#include <stdio.h>
#include <stdlib.h>

// Define Node structure
struct Node {
    int data;
    struct Node* next;
};

// Initialize front and rear
struct Node* front = NULL;
struct Node* rear = NULL;

// Enqueue operation
void enqueue(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    
    newNode->data = value;
    newNode->next = NULL;

    // If queue is empty
    if (rear == NULL) {
        front = rear = newNode;
        return;
    }

    // Add at the end
    rear->next = newNode;
    rear = newNode;
}

// Display queue
void display() {
    struct Node* temp = front;

    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

int main() {
    int n, x;

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        enqueue(x);
    }

    display();

    return 0;
}