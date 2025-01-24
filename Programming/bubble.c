#include <stdio.h>

// Bubble up to maintain the min-heap property
void bubbleUp(int i, int h[]) {
    while(i > 0) {
        int parent = (i - 1) / 2; // Parent index

        // Swap the current element with its parent
        if(h[i] < h[parent]) {
            int tmp = h[i];
            h[i] = h[parent];
            h[parent] = tmp;

            // Move to the parent's index
            i = parent;
        } 
        
        else {
            // Min-heap property satisfied, stop
            break;
        }
    }
}

// Bubble down to fix the min-heap property after removing the root
void bubbleDown(int i, int h[], int N){
    while(2 * i + 1 < N){ // While the left child exists
        int leftChild = 2 * i + 1;
        int rightChild = 2 * i + 2;
        int smallest = i;

        // Compare with the left child
        if(leftChild < N && h[leftChild] < h[smallest]){
            smallest = leftChild;
        }

        // Compare with the right child
        if(rightChild < N && h[rightChild] < h[smallest]){
            smallest = rightChild;
        }

        if(smallest != i){
            // Swap the current element with the smallest child
            int tmp = h[i];
            h[i] = h[smallest];
            h[smallest] = tmp;

            // Move to the smallest child's index
            i = smallest;
        }

        else{
            // Min-heap property satisfied, stop
            break;
        }
    }   
} 

void printHeap(int h[], int N){
    for(int i = 0; i < N; i++){
        printf("%d ", h[i]);
    }

    printf("\n");
}

int main(){
    int heap[100];
    int N = 0;

    // Adding elements using bubbleUp
    printf("Inserting elements: \n");

    int elements[] = {10, 15, 20, 17, 25, 30, 5};

    for(int i=0; i<7; i++){
        heap[N] = elements[i];
        bubbleUp(N, heap);
        N++;
        printHeap(heap, N);
    }

    // Removing elements using bubbleDown
    printf("\nRemoving elements: \n");

    while(N > 0){
        printf("Removing root: %d\n", heap[0]);
        heap[0] = heap[--N];
        bubbleDown(0, heap, N);
        printHeap(heap, N);
    }

    return 0;
}