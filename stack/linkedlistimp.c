#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

// Stack structure
typedef struct {
    int data[MAX_SIZE];
    int top;
} Stack;

// Initialize stack
void initialize(Stack *stack) {
    stack->top = -1;
}

// Check if stack is empty
int is_empty(Stack *stack) {
    return stack->top == -1;
}

// Check if stack is full
int is_full(Stack *stack) {
    return stack->top == MAX_SIZE - 1;
}

// Add element to stack
void push(Stack *stack, int value) {
    if (is_full(stack)) {
        printf("Stack overflow.\n");
        return;
    }
    stack->data[++stack->top] = value;
}

// Remove and return top element of stack
int pop(Stack *stack) {
    if (is_empty(stack)) {
        printf("Stack underflow.\n");
        return -1;
    }
    return stack->data[stack->top--];
}

// Return top element of stack
int peek(Stack *stack) {
    if (is_empty(stack)) {
        printf("Stack is empty.\n");
        return -1;
    }
    return stack->data[stack->top];
}

int main() {
    Stack stack;
    initialize(&stack);

    // Push elements onto the stack
    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);

    // Print top element of the stack
    printf("Top element is: %d\n", peek(&stack));

    // Print elements present in the stack
    printf("Elements present in the stack: ");
    while (!is_empty(&stack)) {
        printf("%d ", pop(&stack));
    }
    printf("\n");

    return 0;
}