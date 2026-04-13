#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX 100

char stack[MAX];
int top = -1;

// Push to stack
void push(char x) {
    stack[++top] = x;
}

// Pop from stack
char pop() {
    if (top == -1)
        return -1;
    return stack[top--];
}

// Get precedence
int precedence(char x) {
    if (x == '^') return 3;
    if (x == '*' || x == '/') return 2;
    if (x == '+' || x == '-') return 1;
    return 0;
}

int main() {
    char infix[MAX], postfix[MAX];
    int i, k = 0;

    printf("Enter infix expression: ");
    scanf("%s", infix);

    for (i = 0; i < strlen(infix); i++) {

        // If operand, add to postfix
        if (isalnum(infix[i])) {
            postfix[k++] = infix[i];
        }

        // If '(', push to stack
        else if (infix[i] == '(') {
            push(infix[i]);
        }

        // If ')', pop until '('
        else if (infix[i] == ')') {
            while (stack[top] != '(') {
                postfix[k++] = pop();
            }
            pop(); // remove '('
        }

        // If operator
        else {
            while (top != -1 && precedence(stack[top]) >= precedence(infix[i])) {
                postfix[k++] = pop();
            }
            push(infix[i]);
        }
    }

    // Pop remaining operators
    while (top != -1) {
        postfix[k++] = pop();
    }

    postfix[k] = '\0';

    printf("Postfix expression: %s\n", postfix);

    return 0;
}