#include <stdio.h>
#include <stdlib.h>

#define TABLE_SIZE 10

// Special value indicating an empty slot in the hash table
#define EMPTY -1

// Hash table with keys and values
int keys[TABLE_SIZE];
int values[TABLE_SIZE];

// Hash function 1
int hash1(int key) {
    return key % TABLE_SIZE;
}

// Hash function 2 (should not return 0)
int hash2(int key) {
    // Ensure that the result is not 0, as it would cause an infinite loop
    return (key % (TABLE_SIZE - 1)) + 1;
}

// Function to insert a key-value pair using double hashing
void insert(int key, int value) {
    int index = hash1(key);
    int step = hash2(key);

    // Handle collisions using double hashing
    while (keys[index] != EMPTY) {
        index = (index + step) % TABLE_SIZE;
    }

    // Insert the key-value pair at the found index
    keys[index] = key;
    values[index] = value;
}

// Function to retrieve the value associated with a key from the hash table
int get(int key) {
    int index = hash1(key);
    int step = hash2(key);

    // Search for the key using double hashing
    while (keys[index] != EMPTY) {
        if (keys[index] == key) {
            return values[index]; // Found the key, return its associated value
        }
        index = (index + step) % TABLE_SIZE;
    }

    return -1; // Key not found
}

int main() {
    // Initialize the keys and values array
    for (int i = 0; i < TABLE_SIZE; ++i) {
        keys[i] = EMPTY;
        values[i] = EMPTY;
    }

    // Example usage
    insert(5, 42);
    insert(10, 99);
    insert(15, 7);

    printf("Value for key 5: %d\n", get(5));
    printf("Value for key 10: %d\n", get(10));
    printf("Value for key 15: %d\n", get(15));

    return 0;
}
