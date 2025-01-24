#include <stdio.h>
#include <stdlib.h>

#define HSIZE 1000
#define STATUSFREE 0
#define STATUSUSED 1
#define STATUSDEL 2

typedef struct bucket {
    int status;
    int key;
    int info;
} Bucket;

typedef Bucket HashTable [HSIZE];

// Hash function using modulo
int hash(int k, int size) {
    return k % size;
}

// Linear probing function to find an index for a key
int find_probe(HashTable h, int k) {
    int index = hash(k, HSIZE);
    int original_index = index;

    while (h[index].status == STATUSUSED && h[index].key != k) {
        index = (index + 1) % HSIZE;

        if (index == original_index) {
            return -1;
        }
    }

    return index;
}

// Update function to insert or update a key-value pair
void update(HashTable h, int k, int info){
    int index = find_probe(h, k);

    if(index == -1){
        printf("Error: Hash table is full\n");

        return;
    }

    h[index].key = k;
    h[index].info = info;
    h[index].status = STATUSUSED;
}

// Lookup function to retrieve a value for a given key
int lookup(HashTable h, int k, int *info){
    int index = hash(k, HSIZE);
    int original_index = index;

    while(h[index].status != STATUSFREE){
        if(h[index].status == STATUSUSED && h[index].key == k){
            *info = h[index].info;

            return 1; // Key found
        }

        index = (index + 1) % HSIZE; // Linear probing

        if(index == original_index){ // Full loop
            break;
        }
    }

    return 0; // Key not found
}

// Initialize the hash table
void initTab(HashTable h){
    for(int i = 0; i < HSIZE; i++){
        h[i].status = STATUSFREE;
    }
}

// Function to remove a key-value pair from the hash table
void removeKey(HashTable h, int k){
    int index = find_probe(h, k);

    if(index != -1){
        h[index].status = STATUSDEL;
        printf("Key %d removed\n", k);
    } else {
        printf("Key %d not found\n", k);
    }
}

// Garbage collection function to remove all deleted cells from the hash table
void garbageCollection(HashTable h){
    HashTable newTable;
    initTab(newTable);

    for(int i=0; i<HSIZE; i++){
        if(h[i].status == STATUSUSED){
            int new_index = hash(h[i].key, HSIZE);

            while(newTable[new_index].status != STATUSFREE){
                new_index = (new_index + 1) % HSIZE;
            }

            newTable[new_index].key = h[i].key;
            newTable[new_index].info = h[i].info;
            newTable[new_index].status = STATUSUSED;
        }
    }

    // Copy back the cleaned table
    for(int i=0; i<HSIZE; i++){
        h[i] = newTable[i];
    }
}

int main(){
    HashTable h;
    initTab(h);

    update(h, 42, 100);
    update(h, 1052, 200);

    int value;

    if(lookup(h, 42, &value)){
        printf("Key 42 found with value %d\n", value);
    } else {
        printf("Key 42 not found\n");
    }

    removeKey(h, 42);

    if(lookup(h, 42, &value)){
        printf("Key 42 found with value %d\n", value);
    } else {
        printf("Key 42 not found\n");
    }

    garbageCollection(h);

    if(lookup(h, 1052, &value)){
        printf("Key 1052 found with value %d\n", value);    
    } else {
        printf("Key 1052 not found\n");
    }

    return 0;
}

