#include <stdio.h>

#define SIZE 6

// Define the queue structure
typedef struct {
    int items[SIZE]; // Array to store queue elements
    int front;       // Index of the front element
    int rear;        // Index of the rear element
} QUEUE;

// Function prototypes
void createAnEmptyQueue(QUEUE* queue);  // Initialize the queue
int isFull(QUEUE* queue);               // Check if the queue is full
void enQueue(QUEUE* queue, int item);   // Add an element to the queue
int isEmpty(QUEUE* queue);              // Check if the queue is empty
void deQueue(QUEUE* queue);             // Remove an element from the queue
void traverse(QUEUE* queue);            // Display all elements of the queue

int main(void) {
    QUEUE queue;
    
    // Initialize the queue
    createAnEmptyQueue(&queue);

    // Enqueue some elements
    enQueue(&queue, 1);
    enQueue(&queue, 2);
    enQueue(&queue, 3);
    enQueue(&queue, 4);
    enQueue(&queue, 5);
    enQueue(&queue, 6);

    // Attempt to enqueue into a full queue
    enQueue(&queue, 7);

    // Display the current queue
    traverse(&queue);

    // Dequeue all elements
    deQueue(&queue);
    deQueue(&queue);
    deQueue(&queue);
    deQueue(&queue);
    deQueue(&queue);
    deQueue(&queue);

    // Attempt to dequeue from an empty queue
    deQueue(&queue);

    // Display the queue after all operations
    traverse(&queue);

    return 0;
}

// Function to initialize an empty queue
void createAnEmptyQueue(QUEUE* queue) {
    queue->front = -1;  // Set front index to -1 (empty)
    queue->rear = -1;   // Set rear index to -1 (empty)
    printf("Queue has been created\n");
}

// Function to check if the queue is full
int isFull(QUEUE* queue) {
    return queue->rear == SIZE - 1;  // Full when rear reaches the last index
}

// Function to add an element to the queue
void enQueue(QUEUE* queue, int item) {
    if (isFull(queue)) {
        printf("The queue is full\n");
    } else {
        if (queue->front == -1) {     // If the queue is empty, initialize front
            queue->front = 0;
        }
        queue->items[++queue->rear] = item; // Increment rear and insert the item
        printf("%i is inserted into the queue\n", item);
    }
}

// Function to check if the queue is empty
int isEmpty(QUEUE* queue) {
    return queue->front == -1;  // Empty when front index is -1
}

// Function to remove an element from the queue
void deQueue(QUEUE* queue) {
    if (isEmpty(queue)) {
        printf("The queue is empty\n");
    } else {
        printf("%i is removed from the queue\n", queue->items[queue->front]);
        queue->front++;  // Increment front index to remove the front element
        if (queue->front > queue->rear) {  // Reset if the queue becomes empty
            queue->front = -1;
            queue->rear = -1;
        }
    }
}

// Function to display all elements of the queue
void traverse(QUEUE* queue) {
    if (isEmpty(queue)) {
        printf("The queue is empty\n");
        return;
    }
    printf("Elements of the queue: ");
    for (int i = queue->front; i <= queue->rear; i++) { // Loop through the queue
        printf("%i ", queue->items[i]);
    }
    printf("\n");
}
