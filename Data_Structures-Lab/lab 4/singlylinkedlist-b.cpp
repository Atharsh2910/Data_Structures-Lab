#include <stdio.h>
#include <stdlib.h>
#include "head.h"

int main() {
    List list1, list2, list3;
    int choice, value;

    do {
        printf("1. Insert into List1\n");
        printf("2. Insert into List2\n");
        printf("3. Merge into List3\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter value to insert in List1: ");
                scanf("%d", &value);
                list1.insertAscending(value);
                break;
            case 2:
                printf("Enter value to insert in List2: ");
                scanf("%d", &value);
                list2.insertAscending(value);
                break;
            case 3:
                list3 = List::mergeLists(list1, list2);
                printf("Lists merged successfully.\n");
                break;
            case 4:
                printf("List1: ");
                list1.display();
                printf("List2: ");
                list2.display();
                printf("List3 (Merged): ");
                list3.display();
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Try again.\n");
        }
    } while (choice != 5);

    return 0;
}

// Constructor initializes head to NULL
List::List(){
    head = NULL;
} 

// Destructor clears the free space
List::~List() {
    Node* current = head;
    while (current) {
        Node* temp = current;
        current = current->next;
        free(temp);
    }
} 

// Get head function for getting the address of each head of the list
List::Node* List::getHead() const {
    return head;
}

// Inserting all the values only in ascending order
void List::insertAscending(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;

    if (!head || head->data >= value) {  
        newNode->next = head;
        head = newNode;
        return;
    }

    Node* current = head;
    while (current->next && current->next->data < value) {
        current = current->next;
    }

    newNode->next = current->next;
    current->next = newNode;
}

// Displaying the values of the list
void List::display() {
    Node* current = head;
    while (current) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

// Merges two lists into a third list
List List::mergeLists(const List& list1, const List& list2) {
    List mergedList;
    Node* l1 = list1.getHead();
    Node* l2 = list2.getHead();

    while (l1) {
        mergedList.insertAscending(l1->data);
        l1 = l1->next;
    }

    while (l2) {
        mergedList.insertAscending(l2->data);
        l2 = l2->next;
    }

    return mergedList;
}
