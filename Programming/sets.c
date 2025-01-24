#include <stdio.h>

#define MAXS 100
typedef int SetInt [MAXS];

// Initialize a set
void initSet (SetInt s) {
    for (int i = 0; i < MAXS; i++) {
        s[i] = 0;
    }
}

// Search for an element in a set
int searchSet (SetInt s, int elem) {
    return s[elem] != 0;
}

// Add an element to a set
int addSet (SetInt s, int elem) {
    if(elem >= 0 && elem < MAXS) {
        s[elem] = 1;
        return 1;
    }

    return 0;
}

// Check if a set is empty
int emptySet (SetInt s) {
    for(int i=0; i<MAXS; i++) {
        if(s[i]) return 0;
    }

    return 1;
}

// Union of two sets
void unionSet (SetInt s1, SetInt s2, SetInt s) {
    for(int i=0; i<MAXS; i++) {
        s[i] = s1[i] || s2[i];
    }
}

// Intersection of two sets
void intersectionSet (SetInt s1, SetInt s2, SetInt s) {
    for(int i=0; i<MAXS; i++) {
        s[i] = s1[i] && s2[i];
    }
}

// Difference of two sets
void differenceSet (SetInt s1, SetInt s2, SetInt s) {
    for(int i=0; i<MAXS; i++) {
        s[i] = s1[i] && !s2[i];
    }
}

int main () {
    SetInt s1, s2, s3;

    initSet(s1);
    initSet(s2);

    printf("Set 1 is empty: %d\n", emptySet(s1));

    addSet(s2, 3);
    addSet(s2, 5);
    addSet(s2, 7);

    printf("Set 2 is empty: %d\n", emptySet(s2));
    printf("Set 2 contains 3: %d\n", searchSet(s2, 3));
    printf("Set 2 contains 8: %d\n", searchSet(s2, 8));

    unionSet(s1, s2, s3);
    printf("Union of s1 and s2: ");

    for(int i=0; i<MAXS; i++) {
        if(s3[i]) printf("%d ", i);
    }

    printf("\n");

    intersectionSet(s1, s2, s3);
    printf("Intersection of s1 and s2: ");

    for(int i=0; i<MAXS; i++) {
        if(s3[i]) printf("%d ", i);
    }

    printf("\n");

    differenceSet(s2, s1, s3);
    printf("Difference of s2 and s1: ");

    for(int i=0; i<MAXS; i++) {
        if(s3[i]) printf("%d ", i);
    }

    printf("\n");

    return 0;
}