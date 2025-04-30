//Program to implement HashADT using Seperate Chaining.

#include <cstdio>
#include <list>
#define size 10

class hashtable {
private:
    std::list<int> values[size];

public:
    void insert(int);
    void Delete(int);
    bool search(int);
    void display();
};

int main() {
    hashtable ht;
    int val, ch;
    while (true) {
        printf("\nMENU\n");
        printf("1.Insert\n2.Delete\n3.Search\n4.Display\n5.Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);
        switch (ch) {
            case 1:
                printf("Enter value to be inserted: ");
                scanf("%d", &val);
                ht.insert(val);
                break;
            case 2:
                printf("Enter value to be deleted: ");
                scanf("%d", &val);
                ht.Delete(val);
                break;
            case 3:
                printf("Enter value to search: ");
                scanf("%d", &val);
                if (ht.search(val))
                    printf("Key found.\n");
                else
                    printf("Key not found.\n");
                break;
            case 4:
                printf("The values in the Hash table:\n");
                ht.display();
                break;
            case 5:
                printf("Exiting..\n");
                return 0;
            default:
                printf("Invalid Input! Try Again.\n");
                break;
        }
    }
}

//Function to insert a key into the Hash Table
void hashtable::insert(int key) {
    int index = key % size;
    values[index].push_back(key);
}

//Function to delete a key from Hash Table
void hashtable::Delete(int key) {
    int index = key % size;
    values[index].remove(key);
}

//Function to search for a key in the Hash Table
bool hashtable::search(int key) {
    int index = key % size;
    for (auto it = values[index].begin(); it != values[index].end(); it++) {
        if (*it == key)
            return true;
    }
    return false;
}

//Function to display the Hash Table
void hashtable::display() {
    for (int i = 0; i < size; i++) {
        printf("Bucket %d: ", i);
        for (auto it = values[i].begin(); it != values[i].end(); it++) {
            printf("%d ", *it);
        }
        printf("\n");
    }
}