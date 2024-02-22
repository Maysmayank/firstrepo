#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#define MAX 10

// Hash Table Structure
struct HashTable {
    int keys[MAX];
    int values[MAX];
    bool occupied[MAX];
};

// Function prototypes
int hashFunction(int key);
void insert(struct HashTable* table, int key, int value);
int search(struct HashTable* table, int key);

int main() {
    struct HashTable hashTable = { {0}, {0}, {false} };
    int key, value, choice;

    do {
        printf("_____________________\n");
        printf("1. Insert\n");
        printf("2. Search\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter key and value to insert: ");
                scanf("%d %d", &key, &value);
                insert(&hashTable, key, value);
                break;
            case 2:
                printf("Enter key to search: ");
                scanf("%d", &key);
                int result = search(&hashTable, key);
                if (result != -1) {
                    printf("Key %d found at index %d\n", key, result);
                } else {
                    printf("Key %d not found\n", key);
                }
                break;
            case 3:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice != 3);

    return 0;
}

int hashFunction(int key) {
    return key % MAX;
}

void insert(struct HashTable* table, int key, int value) {
    int index = hashFunction(key);

    while (table->occupied[index]) {
        index = (index + 1) % MAX;
    }

    table->keys[index] = key;
    table->values[index] = value;
    table->occupied[index] = true;

    printf("Key %d inserted at index %d\n", key, index);
}

int search(struct HashTable* table, int key) {
    int index = hashFunction(key);

    while (table->occupied[index]) {
        if (table->keys[index] == key) {
            return index; // Key found
        }

        index = (index + 1) % MAX;
    }

    return -1; // Key not found
}
