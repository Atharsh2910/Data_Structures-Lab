//Program to implement HashADT using Quadratic Probing

#include <cstdio>
#define size 10

class hashtable {
private:
    int values[size];
    int occupied[size];

    int hashfunction(int key) {
        return key % size;
    }

public:
    hashtable() {
        for (int i = 0; i < size; i++) {
            values[i] = -1;
            occupied[i] = false;
        }
    }

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
    int index = hashfunction(key);
    int i = 0;

    while (values[(index + i * i) % size] != -1 && occupied[(index + i * i) % size]) {
        i++;
        if (i == size) {
            printf("Hash Table is Full!!\n");
            return;
        }
    }
    int newindex = (index + i * i) % size;
    values[newindex] = key;
    occupied[newindex] = true;
}

//Function to delete a key from the Hash Table
void hashtable::Delete(int key) {
    int index = hashfunction(key);
    int i = 0;

    while (values[(index + i * i) % size] != key && occupied[(index + i * i) % size]) {
        i++;
        if (i == size) {
            printf("Key not found.\n");
            return;
        }
    }
    if (values[(index + i * i) % size] == key) {
        values[(index + i * i) % size] = -1;
        occupied[(index + i * i) % size] = false;
    }
}

//Function to search for a key in the Hash Table
bool hashtable::search(int key) {
    int index = hashfunction(key);
    int i = 0;

    while (occupied[(index + i * i) % size]) {
        if (values[(index + i * i) % size] == key)
            return true;
        i++;
        if (i == size) {
            return false;
        }
    }
    return false;
}

//Function to display the Hash Table
void hashtable::display() {
    for (int i = 0; i < size; i++) {
        if (occupied[i] == false) {
            printf("Empty\n");
        } else {
            printf("%d\n", values[i]);
        }
    }
}
