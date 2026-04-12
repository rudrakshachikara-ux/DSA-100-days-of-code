#include <stdio.h>
#include <stdlib.h>

#define EMPTY -1

typedef struct {
    int size;
    int *table;
} HashTable;

int hash(int key, int size) {
    return key % size;
}

HashTable* createTable(int size) {
    HashTable* ht = (HashTable*)malloc(sizeof(HashTable));
    ht->size = size;
    ht->table = (int*)malloc(size * sizeof(int));
    for (int i = 0; i < size; i++) {
        ht->table[i] = EMPTY;
    }
    return ht;
}

void insert(HashTable* ht, int key) {
    int base = hash(key, ht->size);
    for (int i = 0; i < ht->size; i++) {
        int pos = (base + i * i) % ht->size;
        if (ht->table[pos] == EMPTY) {
            ht->table[pos] = key;
            return;
        }
    }
    // Table full, insertion fails silently
}

int search(HashTable* ht, int key) {
    int base = hash(key, ht->size);
    for (int i = 0; i < ht->size; i++) {
        int pos = (base + i * i) % ht->size;
        if (ht->table[pos] == EMPTY) {
            return 0; // Not found
        }
        if (ht->table[pos] == key) {
            return 1; // Found
        }
    }
    return 0;
}

int main() {
    int m, q;
    scanf("%d", &m); // table size
    scanf("%d", &q); // number of operations

    HashTable* ht = createTable(m);

    for (int i = 0; i < q; i++) {
        char op[10];
        int key;
        scanf("%s %d", op, &key);

        if (op[0] == 'I') { // INSERT
            insert(ht, key);
        } else if (op[0] == 'S') { // SEARCH
            if (search(ht, key))
                printf("FOUND\n");
            else
                printf("NOT FOUND\n");
        }
    }

    free(ht->table);
    free(ht);
    return 0;
}

