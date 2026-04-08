#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

// Create linked list
struct Node* createList(int n) {
    struct Node *head = NULL, *temp = NULL, *newNode;
    int x;

    for (int i = 0; i < n; i++) {
        scanf("%d", &x);

        newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = x;
        newNode->next = NULL;

        if (head == NULL) {
            head = temp = newNode;
        } else {
            temp->next = newNode;
            temp = newNode;
        }
    }
    return head;
}

// Find intersection (by value)
void findIntersection(struct Node* head1, struct Node* head2) {
    struct Node* temp1 = head1;

    while (temp1 != NULL) {
        struct Node* temp2 = head2;

        while (temp2 != NULL) {
            if (temp1->data == temp2->data) {
                printf("%d\n", temp1->data);
                return;
            }
            temp2 = temp2->next;
        }
        temp1 = temp1->next;
    }

    printf("No Intersection\n");
}

int main() {
    int n, m;

    // First list
    scanf("%d", &n);
    struct Node* head1 = createList(n);

    // Second list
    scanf("%d", &m);
    struct Node* head2 = createList(m);

    // Find intersection
    findIntersection(head1, head2);

    return 0;
}