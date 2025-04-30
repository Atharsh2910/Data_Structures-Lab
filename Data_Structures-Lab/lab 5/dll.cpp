#include<stdio.h>
#include<stdlib.h>

class list
{
private:
    struct node
    {
        struct node *prev;
        int data;
        struct node *next;
    } *head, *tail;

public:
    list();
    void display();
    void insertBeg(int);
    void insertEnd(int);
    bool insertPos(int, int);
    int deleteBeg();
    int deleteEnd();
    int deletePos(int);
    int search(int);
};

int main()
{
    int choice, stop = 0;
    int pos, num;
    list dll;
    while (!stop)
    {
        printf("\n\nMENU :");
        printf("1. Insertion in Beginning\n");
        printf("2. Insertion in End\n");
        printf("3. Insertion at Position\n");
        printf("4. Deletion in Beginning\n");
        printf("5. Deletion in End\n");
        printf("6. Deletion at Position\n");
        printf("7. Search in List \n");
        printf("8. Display List\n");
        printf("9. Exit\n");
        printf("Enter choice : ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter value to insert : ");
            scanf("%d", &num);
            dll.insertBeg(num);
            printf("Insertion Successful.\n");
            break;

        case 2:
            printf("Enter value to insert : ");
            scanf("%d", &num);
            dll.insertEnd(num);
            printf("Insertion Successful.\n");
            break;

        case 3:
            printf("Enter value to insert : ");
            scanf("%d", &num);
            printf("Enter position to insert : ");
            scanf("%d", &pos);
            if (dll.insertPos(num, pos))
            {
                printf("Insertion Successful.\n");
            }
            else
            {
                printf("Invalid Position. Insertion Failed.\n");
            }
            break;

        case 4:
            num = dll.deleteBeg();
            if (num != -1)
            {
                printf("Deletion Successful. Deleted value : %d\n", num);
            }
            else
            {
                printf("Deletion failed.\n");
            }
            break;

        case 5:
            num = dll.deleteEnd();
            if (num != -1)
            {
                printf("Deletion Successful. Deleted value : %d\n", num);
            }
            else
            {
                printf("Deletion failed.\n");
            }
            break;

        case 6:
            printf("Enter position to delete : ");
            scanf("%d", &pos);
            num = dll.deletePos(pos);
            if (num != -1)
            {
                printf("Deletion Successful. Deleted value : %d\n", num);
            }
            else
            {
                printf("Deletion failed.\n");
            }
            break;

        case 7:
            printf("Enter element to search for : ");
            scanf("%d", &num);
            pos = dll.search(num);
            if (pos == -1)
            {
                printf("Search failed.\n");
            }
            else
            {
                printf("Search successful.\nElement found at index : %d\n", pos);
            }
            break;

        case 8:
            dll.display();
            break;

        case 9:
            stop = 1;
            printf("Exiting code.\n");
            break;

        default:
            printf("Invalid choice. Enter again.\n");
            break;
        }
    }
}

// Constructor function to iniialize head and tail to NULL
list::list()
{
    head = NULL;
    tail = NULL;
}

// Function to display the doubly linked list (both forward and backward)
// Time complexity = O(n)
void list::display()
{
    if (head == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    printf("\nForward :\nNULL <--> ");
    node *temp = head;
    while (temp != NULL)
    {
        printf("%d <--> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");

    printf("Backward :\nNULL <--> ");
    temp = tail;
    while (temp != NULL)
    {
        printf("%d <--> ", temp->data);
        temp = temp->prev;
    }
    printf("NULL\n");
}

// Function to insert a given element at the beginning of a doubly linked list
// Time complexity = O(1)
void list::insertBeg(int num)
{
    node *newnode = (node *)malloc(sizeof(node));
    newnode->prev = NULL;
    newnode->data = num;
    newnode->next = head;
    if (head == NULL)
    {
        head = newnode;
        tail = newnode;
        return;
    }
    head->prev = newnode;
    head = newnode;
}

// Function to insert a given element at the end of a doubly linked list
// Time complexity = O(1)
void list::insertEnd(int num)
{
    node *newnode = (node *)malloc(sizeof(node));
    newnode->prev = tail;
    newnode->data = num;
    newnode->next = NULL;
    if (tail == NULL)
    {
        tail = newnode;
        head = newnode;
        return;
    }
    tail->next = newnode;
    tail = newnode;
}

// Function to insert a given element at a given position in a doubly linked list
// Time complexity = O(n)
bool list::insertPos(int num, int pos)
{
    if (pos < 0)
    {
        return 0;
    }
    if (pos == 0)
    {
        insertBeg(num);
        return 1;
    }
    node *newnode = (node *)malloc(sizeof(node));
    newnode->data = num;
    node *temp = head;
    while (temp != NULL && pos > 1)
    {
        temp = temp->next;
        pos--;
    }
    if (temp == NULL)
    {
        return 0;
    }
    newnode->next = temp->next;
    newnode->prev = temp;
    temp->next = newnode;
    if (newnode->next == NULL)
    {
        tail = newnode;
    }
    else
    {
        newnode->next->prev = newnode;
    }
    return 1;
}

// Function to delete the first element of a doubly linked list
// Time complexity = O(1)
int list::deleteBeg()
{
    if (head == NULL)
    {
        printf("List is empty.\n");
        return -1;
    }
    int value = head->data;
    node *temp = head;
    head = head->next;
    if (head == NULL)
    {
        tail = NULL;
    }
    else
    {
        head->prev = NULL;
    }
    free(temp);
    return value;
}

// Function to delete the last element of a doubly linked list
// Time complexity = O(1)
int list::deleteEnd()
{
    if (head == NULL)
    {
        printf("List is empty.\n");
        return -1;
    }
    int value = tail->data;
    node *temp = tail;
    tail = tail->prev;
    if (tail == NULL)
    {
        head = NULL;
    }
    else
    {
        tail->next = NULL;
    }
    free(temp);
    return value;
}

// Function to delete the element at a given position in a doubly linked list
// Time complexity = O(n)
int list::deletePos(int pos)
{
    if (pos < 0 || head == NULL)
    {
        printf("Invalid position or list is empty.\n");
        return -1;
    }
    node *temp = head;
    while (temp != NULL && pos > 0)
    {
        temp = temp->next;
        pos--;
    }
    if (temp == NULL)
    {
        printf("Position out of range.\n");
        return -1;
    }
    int value = temp->data;
    if (temp->prev != NULL)
        temp->prev->next = temp->next;
    if (temp->next != NULL)
        temp->next->prev = temp->prev;
    if (temp == head)
        head = temp->next;
    if (temp == tail)
        tail = temp->prev;
    free(temp);
    return value;
}

// Function to search for an element in a doubly linked list
// Time complexity = O(n)
int list::search(int num)
{
    int index = 0;
    node *temp = head;
    while (temp != NULL)
    {
        if (temp->data == num)
        {
            return index;
        }
        temp = temp->next;
        index++;
    }
    return -1;
}
