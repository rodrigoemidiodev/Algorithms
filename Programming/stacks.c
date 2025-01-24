#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define INIT_SIZE 4 // Initial size of the stack

typedef struct stack {
    int size; // Capacity of the stack
    int *values; // Dynamic array for stack values
    int sp; // Stack pointer (number of elements in the stack)
} Stack;

// Initialize the stack
void initStack (Stack *s) {
    s->size = INIT_SIZE;
    s->values = (int*) malloc(s->size * sizeof(int));
    s->sp = 0;
}

// Halve the size of the stack's array
void halfArray (Stack *s) {
    s->size /= 2;
    s->values = realloc(s->values, s->size);
}

void doubleArray (Stack *s) {
    s->size *= 2;
    s->values = realloc(s->values, s->size);
}

void push(Stack *s, int x) {
    if (s->sp == s->size) {
        doubleArray(s);
    }

    s->values[s->sp++] = x;
}

// Pop an element from the stack
int pop (Stack *s) {
    if (s->sp == 0) {
        return INT_MIN; // Sentinel value to indicate the stack is empty
    }

    int poppedValue = s->values[--s->sp];

    // Reduce array size if only 25% is used
    if (s->sp > 0 && s->sp <= s->size / 4) {
        halfArray(s);
    }

    return poppedValue;
}

int isEmpty (Stack *s) {
    return s->sp == 0;
}

void freeStack (Stack *s) {
    free(s->values);
}

int main () {
    Stack s;
    initStack(&s);

    for(int i=1; i<=5; i++) {
        push(&s, i);
        printf("Pushed %d, size: %d\n", i, s.size);
    }

    while(!isEmpty(&s)) {
        int poppedValue = pop(&s);

        if(poppedValue != INT_MIN) {
            printf("Popped %d, size: %d\n", poppedValue, s.size);
        } 

        else {
            printf("Stack is empty\n");
        }
    }

    freeStack(&s);
    return 0;
}

