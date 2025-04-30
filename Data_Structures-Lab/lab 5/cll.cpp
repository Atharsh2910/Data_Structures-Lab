//Program to implement a ListADT using a circular linked list. 

#include <stdio.h>
#include <stdlib.h>

class list
{
private:
    struct node
    {
        int data;
        struct node *next;
    } *head;

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
    list cll;
    while (!stop)
    {
        printf("\nMENU :\n");
        printf("1. Insertion in Beginning\n");
        printf("2. Insertion in End\n ");
        printf("3. Insertion at Position\n");
        printf("4. Deletion in Beginning\n");
        printf("5. Deletion in End\n");
        printf("6. Deletion at Position\n");
        printf("7. Search in List\n");
        printf("8. Display List\n");
        printf("9. Exit\n");
        printf("Enter choice : ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter value to insert : ");
            scanf("%d", &num);
            cll.insertBeg(num);
            printf("Insertion Successful.\n");
            break;

        case 2:
            printf("Enter value to insert : ");
            scanf("%d", &num);
            cll.insertEnd(num);
            printf("Insertion Successful.\n");
            break;

        case 3:
            printf("Enter value to insert : ");
            scanf("%d", &num);
            printf("Enter position to insert : ");
            scanf("%d", &pos);
            if (cll.insertPos(num, pos))
            {
                printf("Insertion Successful.\n");
            }
            else
            {
                printf("Invalid Position. Insertion Failed.\n");
            }
            break;

        case 4:
            num = cll.deleteBeg();
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
            num = cll.deleteEnd();
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
            num = cll.deletePos(pos);
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
            printf("\nEnter element to search for : ");
            scanf("%d", &num);
            pos = cll.search(num);
            if (pos == -1)
            {
                printf("Search failed. Element not found.\n");
            }
            else
            {
                printf("Search successful.\nElement found at index : %d\n", pos);
            }
            break;

        case 8:
            cll.display();
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
    return 0;
}

// Constructor function to initialize head to NULL
list::list()
{
    head = NULL;
}

// Function to display the circularly linked list
void list::display()
{
    if (head == NULL)
    {
        printf("List is empty.\n");
        return;
    }
    node *temp = head;
    do
    {
        printf("%d --> ", temp->data);
        temp = temp->next;
    } while (temp != head);

    printf("%d (HEAD)\n", head->data);
}

// Function to insert a given element at the beginning
void list::insertBeg(int num)
{
    node *newnode = (node *)malloc(sizeof(node));
    newnode->data = num;
    if (head == NULL)
    {
        head = newnode;
        head->next = head;
        return;
    }
    node *temp = head;
    while (temp->next != head)
    {
        temp = temp->next;
    }
    temp->next = newnode;
    newnode->next = head;
    head = newnode;
}

// Function to insert a given element at the end
void list::insertEnd(int num)
{
    node *newnode = (node *)malloc(sizeof(node));
    newnode->data = num;
    if (head == NULL)
    {
        head = newnode;
        head->next = head;
        return;
    }
    node *temp = head;
    while (temp->next != head)
    {
        temp = temp->next;
    }
    temp->next = newnode;
    newnode->next = head;
}

// Function to insert a given element at a given position
bool list::insertPos(int num, int pos)
{
    if (pos <= 0)
    {
        return false;
    }
    node *newnode = (node *)malloc(sizeof(node));
    newnode->data = num;
    if (pos == 1)
    {
        insertBeg(num);
        return true;
    }
    if (head == NULL)
    {
        printf("List is empty.\n");
        return false;
    }
    node *temp = head;
    for (int i = 1; i < pos - 1; i++)
    {
        temp = temp->next;
        if (temp == head)
        {
            printf("Invalid position.\n");
            return false;
        }
    }
    newnode->next = temp->next;
    temp->next = newnode;
    return true;
}

// Function to delete an element from the beginning
int list::deleteBeg()
{
    if (head == NULL)
    {
        printf("List is empty. Deletion failed.\n");
        return -1;
    }
    node *temp = head;
    int num = temp->data;
    if (head->next == head)
    {
        free(head);
        head = NULL;
        return num;
    }
    while (temp->next != head)
    {
        temp = temp->next;
    }
    temp->next = head->next;
    head = head->next;
    return num;
}

// Function to delete an element from the end
int list::deleteEnd()
{
    if (head == NULL)
    {
        printf("List is empty. Deletion failed.\n");
        return -1;
    }
    node *temp = head;
    node *prev = NULL;
    int num;
    if (head->next == head)
    {
        num = head->data;
        free(head);
        head = NULL;
        return num;
    }
    while (temp->next != head)
    {
        prev = temp;
        temp = temp->next;
    }
    num = temp->data;
    prev->next = head;
    free(temp);
    return num;
}

// Function to delete an element from a given position
int list::deletePos(int pos)
{
    if (head == NULL)
    {
        printf("List is empty. Deletion failed.\n");
        return -1;
    }
    if (pos <= 0)
    {
        printf("Invalid position. Deletion failed.\n");
        return -1;
    }
    node *temp = head;
    node *prev = NULL;
    int num;
    if (pos == 1)
    {
        return deleteBeg();
    }
    for (int i = 1; i < pos; i++)
    {
        prev = temp;
        temp = temp->next;
        if (temp == head)
        {
            printf("Invalid position. Deletion failed.\n");
            return -1;
        }
    }
    num = temp->data;
    prev->next = temp->next;
    free(temp);
    return num;
}

// Function to search for an element in the list
int list::search(int num)
{
    if (head == NULL)
    {
        printf("List is empty.\n");
        return -1;
    }
    node *temp = head;
    int pos = 1;
    do
    {
        if (temp->data == num)
        {
            return pos;
        }
        temp = temp->next;
        pos++;
    } while (temp != head);
    return -1;
}