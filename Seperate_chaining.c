#include <stdio.h>
#include <stdlib.h>

// Define a structure for a value and a link to the next element in the chain
struct ValueNode {
    int value;
    struct ValueNode* next; // Pointer to the next element in the chain
};

// Define the hash table
#define TABLE_SIZE 7
struct ValueNode* hashTable[TABLE_SIZE];

// Hash function
int hash(int value) {
    return value % TABLE_SIZE;
}

// Function to insert a value into the hash table
void insert(int value) {
    int index = hash(value);

    // Create a new value node
    struct ValueNode* newValueNode = (struct ValueNode*)malloc(sizeof(struct ValueNode));
    newValueNode->value = value;
    newValueNode->next = NULL;

    // If the index is not yet occupied, insert the new node
    if (hashTable[index] == NULL) {
        hashTable[index] = newValueNode;
    } else {
        // If the index is already occupied, add the new node to the beginning of the chain
        newValueNode->next = hashTable[index];
        hashTable[index] = newValueNode;
    }
}

// Function to print the hash table with separate chaining
void printHashTable() {
    printf("Hash Table with Separate Chaining:\n");
    for (int i = 0; i < TABLE_SIZE; ++i) {
        struct ValueNode* current = hashTable[i];
        printf("Index %d: ", i);
        while (current != NULL) {
            printf("%d ", current->value);
            current = current->next;
        }
        printf("\n");
    }
}

int main() {
    // Example usage
    insert(42);
    insert(99);
    insert(7);
    insert(14);

    // Print the entire hash table with separate chaining
    printHashTable();

    // Clean up: Free allocated memory
    for (int i = 0; i < TABLE_SIZE; ++i) {
        struct ValueNode* current = hashTable[i];
        while (current != NULL) {
            struct ValueNode* next = current->next;
            free(current);
            current = next;
        }
        hashTable[i] = NULL;
    }

    return 0;
}
