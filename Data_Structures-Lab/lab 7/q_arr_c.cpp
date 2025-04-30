//Program to implement Circular QueueADT using array of size 5

#include <stdio.h>
#include <stdlib.h>

#define SIZE 5

class CircularQueue {
private:
    int arr[SIZE];
    int front;
    int rear;

public:
    CircularQueue();          
    void enqueue(int value);  
    int dequeue();           
    int peek();             
};


int main() {
    CircularQueue q;
    int choice, value;

    while (1) {
        printf("\nCircular Queue Operations Menu:\n");
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
CircularQueue::CircularQueue() {
    front = -1;
    rear = -1;
}

//Function to enqueue a number in the queue
//Time complexity - O(1)
void CircularQueue::enqueue(int value) {
    if (((rear + 1) % SIZE) == front) {
        printf("Circular Queue is full! Cannot enqueue %d\n", value);
        return;
    }
    if (front == -1 && rear == -1) {
        front = 0;
    }
    rear = (rear + 1) % SIZE;
    arr[rear] = value;
    printf("%d enqueued successfully\n", value);
}

//Function to dequeue
//Time complexity - O(1)
int CircularQueue::dequeue() {
    if (front == -1 && rear == -1) {
        printf("Circular Queue is empty! Cannot dequeue\n");
        return -1;
    }
    int value = arr[front];
    if (front == rear) {
        front = -1;
        rear = -1;
    } else {
        front = (front + 1) % SIZE;
    }
    printf("Dequeued %d from circular queue\n", value);
    return value;
}

//Function to peek
//Time complexity - O(1)
int CircularQueue::peek() {
    if (front == -1 && rear == -1) {
        printf("Circular Queue is empty! Nothing to peek\n");
        return -1;
    }
    printf("Front element is: %d\n", arr[front]);
    return arr[front];
}