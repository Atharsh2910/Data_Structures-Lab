//Function to implement QueueADT using array of size 5.

#include <stdio.h>
#include <stdlib.h>

#define SIZE 5

class Queue {
private:
    int arr[SIZE];
    int front;
    int rear;

public:
    Queue();              // Constructor
    void enqueue(int value);  // Add element to queue
    int dequeue();        // Remove and return element from queue
    int peek();          // Return front element without removing it
};


int main() {
    Queue q;
    int choice, value;

    while (1) {
        printf("\nQueue Operations Menu:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Peek\n");
        printf("4. Exit\n");
        printf("Enter your choice (1-4): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to enqueue: ");
                scanf("%d", &value);
                q.enqueue(value);
                break;

            case 2:
                q.dequeue();
                break;

            case 3:
                q.peek();
                break;

            case 4:
                printf("Exiting program...\n");
                exit(0);

            default:
                printf("Invalid choice! Please enter a number between 1 and 4\n");
        }
    }

    return 0;
}

//Constructor
Queue::Queue() {
    front = -1;
    rear = -1;
}

//Function to enqueue 
//Time complexity - O(1)
void Queue::enqueue(int value) {
    if (rear == SIZE - 1) {
        printf("Queue is full! Cannot enqueue %d\n", value);
        return;
    }
    if (front == -1 && rear == -1) {
        front = 0;
    }
    rear++;
    arr[rear] = value;
    printf("%d enqueued successfully\n", value);
}

//Function to dequeue
//Time complexity - O(1)
int Queue::dequeue() {
    if (front == -1 && rear == -1) {
        printf("Queue is empty! Cannot dequeue\n");
        return -1;
    }
    int value = arr[front];
    if (front == rear) {
        front = -1;
        rear = -1;
    } else {
        front++;
    }
    printf("Dequeued %d from queue\n", value);
    return value;
}

//Function to peek
//Time complexity - O(1)
int Queue::peek() {
    if (front == -1 && rear == -1) {
        printf("Queue is empty! Nothing to peek\n");
        return -1;
    }
    printf("Front element is: %d\n", arr[front]);
    return arr[front];
}