#include <stdio.h>

#define MAX 1000 // Maximum size of the priority queue

typedef struct prQueue {
    int values[MAX]; // Array to store the heap
    int size; // Number of elements in the heap
} PriorityQ;

// Initialize the priority queue
void empty(PriorityQ *q) {
    q->size = 0;
}

// Check if the priority queue is empty
int isEmpty(PriorityQ *q) {
    return q->size == 0;
}

// Helper function: bubble up to maintain min-heap property
void bubbleUp(int i, int h[]) {
    while(i > 0){
        int parent = (i-1)/2;

        if(h[i] < h[parent]){
            int temp = h[i];
            h[i] = h[parent];
            h[parent] = temp;
            i = parent;
        } else {
            break;
        }
    }
}

// Add an element to the priority queue
int add(int x, PriorityQ *q) {
    if(q->size == MAX) {
        return 0; // Queue is full
    }

    q->values[q->size] = x;
    bubbleUp(q->size, q->values);
    q->size++;

    return 1; // Success
}

// Helper function: bubble down to maintain min-heap property
void bubbleDown(int i, int h[], int N){
    while(2 * i + 1 < N){
        int leftChild = 2 * i + 1;
        int rightChild = 2 * i + 2;
        int smallest = i;

        if(leftChild < N && h[leftChild] < h[smallest]){
            smallest = leftChild;
        }

        if(rightChild < N && h[rightChild] < h[smallest]){
            smallest = rightChild;
        }

        if(smallest != i){
            int temp = h[i];
            h[i] = h[smallest];
            h[smallest] = temp;
            i = smallest;
        } else {
            break;
        }
    }
}

// Remove the next element from the priority queue
int removeNext(PriorityQ *q, int *rem){
    if(q->size == 0){
        return 0; // Queue is empty
    }

    *rem = q->values[0]; // Get the root (minimum element)
    q->values[0] = q->values[--q->size]; // Replace root with the last element
    bubbleDown(0, q->values, q->size); // Restore min-heap property

    return 1; // Success
}

int main(){
    PriorityQ q;
    empty(&q);

    add(10, &q);
    add(20, &q);
    add(5, &q);
    add(7, &q);
    add(3, &q);

    printf("Priority queue contents: \n");

    for(int i=0; i<q.size; i++){
        printf("%d ", q.values[i]);
    }

    printf("\n");

    printf("\nRemoving elements:\n");
    
    int removed;

    while(!isEmpty(&q)){
        removeNext(&q, &removed);
        printf("Removed: %d\n", removed);
    }

    return 0;
}


