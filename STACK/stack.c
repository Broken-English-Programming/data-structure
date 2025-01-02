#include <stdio.h>

#define MAX 9 // Define the maximum capacity of the stack

typedef struct {
    int items[MAX]; // Array to store stack elements
    int top;        // Variable to keep track of the top element in the stack
} stack;

// Function prototypes define the stack structure with its methods
void createNewStack(stack *); 
void push(stack *, int);
int isFull(stack *);
void pop(stack *);
int isEmpty(stack *);
void traverse(stack *); 

int main(void) {
    stack s; // Declare a stack variable
    createNewStack(&s); // Initialize the stack

    // Push elements onto the stack
    push(&s, 0);
    push(&s, 1);
    push(&s, 2);
    push(&s, 3);
    push(&s, 4);
    push(&s, 5);
    push(&s, 6);
    push(&s, 7);
    push(&s, 8);

    traverse(&s); // Display the contents of the stack

    // Pop elements from the stack
    pop(&s);
    pop(&s);
    pop(&s);
    pop(&s);
    pop(&s);
    pop(&s);
    pop(&s);
    pop(&s);
    pop(&s);
    pop(&s); // Attempt to pop beyond the stack's elements

    traverse(&s); // Display the contents of the stack
    traverse(&s); // Display the stack again to demonstrate stability

    return 0;
}

// Function to initialize the stack
void createNewStack(stack * s) {
    s->top = -1; // Set top to -1, indicating an empty stack
    printf("The Stack is created\n");
}

// Function to add an element to the stack
void push(stack * s, int item) {
    if(isFull(s)) { // Check if the stack is full
        printf("The stack is full\n");
    }
    else {
        s->items[++s->top] = item; // Increment top and add the item
        printf("%i is inserted\n", item);
    }
}

// Function to check if the stack is full
int isFull(stack * s) {
    return s->top == MAX - 1; // Returns true if top equals MAX-1
}

// Function to remove an element from the stack
void pop(stack * s) {
    if(isEmpty(s)) { // Check if the stack is empty
        printf("The stack is empty\n");
    }
    else {
        printf("%i is removed\n", s->items[s->top]); // Display the removed item
        s->top--; // Decrement top to remove the item
    }
}

// Function to check if the stack is empty
int isEmpty(stack * s) {
    return s->top == -1; // Returns true if top equals -1
}

// Function to display the contents of the stack
void traverse(stack* s) {
    printf("["); // Start of stack display
    for (int i = 0; i <= s->top; i++) {
        if(i == s->top) // For the last item, avoid trailing space
            printf("%i", s->items[i]);
        else 
            printf("%i ", s->items[i]);
    }
    printf("]"); // End of stack display
    printf("\n");
}
