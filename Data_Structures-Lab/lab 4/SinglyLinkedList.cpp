//Program to implement a ListADT using a singly linked list

#include <stdio.h>
#include<stdlib.h>

class SinglyLinkedList {
    private: 
        struct Node {
            int data;
            struct Node* next;
        };
        struct Node* head;
    public:
        SinglyLinkedList() {head = NULL;}
        void insertBeginning(int value);
        void insertEnd(int value);
        void insertPosition(int value, int pos);
        void deleteBeginning();
        void deleteEnd();
        void deletePosition(int pos);
        void Search(int value);
        void Display();
        void displayReverse(Node* node);
        void reverseLink();
        Node* gethead() {return head;}
};


int main() {
    SinglyLinkedList list;
    int choice,value,pos,node;

    while(1){
        printf("\nMenu; \n");
        printf("1. Insert beginning\n");
        printf("2. Insert end\n");
        printf("3. Insert position\n");
        printf("4. Delete beginning\n");
        printf("5. Delete end\n");
        printf("6. Delete position\n");
        printf("7. Search\n");
        printf("8. Display\n");
        printf("9. Display reverse\n");
        printf("10. Reverse link\n");
        printf("11. Exit\n");
        printf("Enter your choice: \n");
        scanf("%d", &choice);

        if(choice < 1 || choice > 11){
        printf("Invalid option. Kindly enter valid option (1-11).");
        }

        switch(choice) {
            case 1:
            printf("Enter the value to insert: ");
            scanf("%d", &value);
            list.insertBeginning(value);
            break;

            case 2:
            printf("Enter the value to insert: ");
            scanf("%d", &value);
            list.insertEnd(value);
            break;

            case 3:
            printf("Enter the position to insert: ");
            scanf("%d", &pos);
            printf("Enter the value: ");
            scanf("%d", &value);
            list.insertPosition(pos, value);
            break;

            case 4:
            list.deleteBeginning();
            break;

            case 5:
            list.deleteEnd();
            break;

            case 6:
            printf("Enter the position to delete: ");
            scanf("%d", &pos);
            list.deletePosition(pos);
            break;

            case 7:
            printf("Enter the value to search: ");
            scanf("%d", &value);
            list.Search(value);
            break;

            case 8:
            list.Display();
            break;

            case 9:
            list.displayReverse(list.gethead());
            break;

            case 10:
            list.reverseLink();
            break;

            case 11:
            printf("Exiting the program.\n");
            return 0;

            default:
            printf("Invalid choice. Try again");
            break;
        }
    }
    return 0;
}



// Insert at the beginning
void SinglyLinkedList::insertBeginning(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = head;
    head = newNode;
}

// Display the list
void SinglyLinkedList::Display() {
    Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Insert at the end
void SinglyLinkedList::insertEnd(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;
    if (head == NULL) {
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Insert at a specific position
void SinglyLinkedList::insertPosition(int value, int pos) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    if (pos == 1) {
        newNode->next = head;
        head = newNode;
        return;
    }
    Node* temp = head;
    for (int i = 1; temp != NULL && i < pos - 1; i++) {
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Position out of range.\n");
        free(newNode);
        return;
    }
    newNode->next = temp->next;
    temp->next = newNode;
}

// Delete from the beginning
void SinglyLinkedList::deleteBeginning() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    Node* temp = head;
    head = head->next;
    free(temp);
}

// Delete from the end
void SinglyLinkedList::deleteEnd() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    if (head->next == NULL) {
        free(head);
        head = NULL;
        return;
    }
    Node* temp = head;
    while (temp->next->next != NULL) {
        temp = temp->next;
    }
    free(temp->next);
    temp->next = NULL;
}

// Delete from a specific position
void SinglyLinkedList::deletePosition(int pos) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    Node* temp = head;
    if (pos == 1) {
        head = temp->next;
        free(temp);
        return;
    }
    Node* prev = NULL;
    for (int i = 1; temp != NULL && i < pos; i++) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Position out of range.\n");
        return;
    }
    prev->next = temp->next;
    free(temp);
}

// Search
void SinglyLinkedList::Search(int value) {
    Node* temp = head;
    int index = 1;
    while (temp != NULL) {
        if (temp->data == value) {
            printf("Element %d found at position %d.\n", value, index);
            return;
        }
        temp = temp->next;
        index++;
    }
    printf("Element %d not found.\n", value);
}

// Reverse display
void SinglyLinkedList::displayReverse(Node* node) {
    if (node == NULL) return;
    displayReverse(node->next);
    printf("%d -> ", node->data);
}

// Reverse the linked list
void SinglyLinkedList::reverseLink() {
    Node* prev = NULL;
    Node* current = head;
    Node* next = NULL;
    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;
}



