#include <stdio.h>

#define MAXS 100
typedef int MSetInt [MAXS];

// Initialize a multiset
void initMSet(MSetInt ms) {
    for (int i = 0; i < MAXS; i++) {
        ms[i] = 0;
    }
}

// Search for an element in a multiset
int searchMSet(MSetInt ms, int elem) {
    return ms[elem];
}

// Add an element to a multiset
int addMSet(MSetInt ms, int elem) {
    if(elem >= 0 && elem < MAXS) {
        ms[elem]++;
        
        return 1;
    }

    return 0;
}

// Check if a multiset is empty
int emptyMSet(MSetInt ms) {
    for(int i=0; i<MAXS; i++) {
        if(ms[i]) return 0;
    }

    return 1;
}

// Union of two multisets
void unionMSet(MSetInt ms1, MSetInt ms2, MSetInt ms) {
    for(int i=0; i<MAXS; i++) {
        ms[i] = ms1[i] + ms2[i];
    }
}

// Intersection of two multisets
void intersectionMSet(MSetInt ms1, MSetInt ms2, MSetInt ms) {
    for(int i=0; i<MAXS; i++) {
        ms[i] = ms1[i] < ms2[i]? ms1[i]: ms2[i];
    }
}

// Difference of two multisets
void differenceMSet(MSetInt ms1, MSetInt ms2, MSetInt ms) {
    for(int i=0; i<MAXS; i++) {
        ms[i] = ms1[i] > ms2[i]? ms1[i] - ms2[i]: 0;
    }
}

int main() {
    MSetInt ms1, ms2, ms3;

    initMSet(ms1);
    initMSet(ms2);

    printf("Multiset 1 is empty: %d\n", emptyMSet(ms1));

    addMSet(ms2, 3);
    addMSet(ms2, 3);
    addMSet(ms2, 5);
    addMSet(ms2, 5);
    addMSet(ms2, 5);

    printf("Multiset 2 is empty: %d\n", emptyMSet(ms2));
    printf("Multiset 2 contains 3: %d\n", searchMSet(ms2, 3));
    printf("Multiset 2 contains 8: %d\n", searchMSet(ms2, 8));

    unionMSet(ms1, ms2, ms3);

    printf("Union of ms1 and ms2: ");

    for(int i=0; i<MAXS; i++) {
        if(ms3[i]) printf("%d ", i);
    }

    printf("\n");

    intersectionMSet(ms1, ms2, ms3);

    printf("Intersection of ms1 and ms2: ");

    for(int i=0; i<MAXS; i++) {
        if(ms3[i]) printf("%d ", i);
    }

    printf("\n");

    differenceMSet(ms2, ms1, ms3);

    printf("Difference of ms2 and ms1: ");

    for(int i=0; i<MAXS; i++) {
        if(ms3[i]) printf("%d ", i);
    }

    printf("\n");

    return 0;
}
