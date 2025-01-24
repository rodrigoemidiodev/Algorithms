#include <stdio.h>
#include <stdlib.h>

#define HSIZE 1000

typedef struct bucket {
    int key;
    int info;
    struct bucket *next;
} *Bucket;

typedef Bucket HTChain[HSIZE];

// Hash function: simple modulo operation
int hash(int k, int size){
    return k % size;
}

// Lookup function: searches for key k in the hash table
int lookup(HTChain h, int k, int *i){
    int index = hash(k, HSIZE);
    Bucket current = h[index];

    while(current != NULL){
        if(current->key == k){
            *i = current->info;

            return 1; // Key found
        }
    }

    return 0; // Key not found
}

// Function to insert a key-value pair into the hash table
void insert(HTChain h, int k, int info){
    int index = hash(k, HSIZE);

    // Create a new bucket
    Bucket newBucket = (Bucket)malloc(sizeof(struct bucket));
    newBucket->key = k;
    newBucket->info = info;
    newBucket->next = h[index];
    h[index] = newBucket;
}

// Function to initialize the hast table
void initTab(HTChain h){
    for(int i=0; i<HSIZE; i++){
        h[i] = NULL;
    }
}

int main(){
    HTChain hashTable;
    initTab(hashTable);

    insert(hashTable, 42, 100);
    insert(hashTable, 142, 200);

    int value;

    if(lookup(hashTable, 42, &value)){
        printf("Key 42 found with value %d\n", value);
    } else {
        printf("Key 42 not found\n");
    }

    if(lookup(hashTable, 180, &value)){
        printf("Key 180 found with value %d\n", value);
    } else {
        printf("Key 180 not found\n");
    }

    return 0;
}

