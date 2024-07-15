#include <stdio.h>
#include <stdlib.h>

#define TABLE_SIZE 11

int hash(int key, int i) {
    return (key + i) % TABLE_SIZE;
}

void insert(int table[], int key) {
    int i = 0;
    int index;

    while (i < TABLE_SIZE) {
        index = hash(key, i);
        if (table[index] == -1) {
            table[index] = key;
            printf("Inserted key %d at index %d\n", key, index);
            return;
        }
        i++;
    }

    printf("Error: Unable to insert key %d. Table is full.\n", key);
}

void display(int table[]) {
    printf("Hash Table: ");
    for (int i = 0; i < TABLE_SIZE; i++) {
        if (table[i] != -1) {
            printf("%d ", table[i]);
        } else {
            printf("- ");
        }
    }
    printf("\n");
}

int main() {
    int hashTable[TABLE_SIZE];

    for (int i = 0; i < TABLE_SIZE; i++) {
        hashTable[i] = -1;
    }

    insert(hashTable, 7);
    insert(hashTable, 18);
    insert(hashTable, 29);
    insert(hashTable, 40);
    insert(hashTable, 51);

    display(hashTable);

    return 0;
}
