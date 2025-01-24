#include <stdio.h>
#include <stdlib.h>

#define LEFT -1
#define RIGHT 1
#define BAL 0

typedef struct avl {
    int bal;
    int key, info;
    struct avl *left, *right;
} *AVL;

// Create a new node
AVL createNode(int k, int i){
    AVL newNode = (AVL)malloc(sizeof(struct avl));

    if(newNode != NULL){
        newNode->key = k;
        newNode->info = i;
        newNode->left = newNode->right = NULL;
    }

    return newNode;
}

// Returns 0 if key already existed
int updateAVL(AVL *a, int k, int i){
    if(*a == NULL){
        *a = createNode(k, i);
        
        return 1; // New node created
    }

    if(k == (*a)->key){
        (*a)->info = i; // Update existing key

        return 0;
    } else if(k < (*a)->key){
        return updateAVL(&(*a)->left, k, i);
    } else {
        return updateAVL(&(*a)->right, k, i);
    }
}

// In-order traversal and print the tree contents
void inOrderTraversal(AVL a){
    if(a != NULL){
        inOrderTraversal(a->left);
        printf("Key: %d, Info: %d\n", a->key, a->info);
        inOrderTraversal(a->right);
    }
}

// Free memory of the AVL tree
void freeAVL(AVL a){
    if(a != NULL){
        freeAVL(a->left);
        freeAVL(a->right);
        free(a);
    }
}

AVL rotateRight(AVL a){
    if (a == NULL || a->left == NULL){ 
        return a; // Cannot rotate if left child doesn't exist
    }

    AVL b = a->left; // New root of the subtree
    a->left = b->right; // Move b's right subtree to a's left
    b->right = a; // Make a the right child of b

    return b; // Return the new root
}

// Print tree structure
void printTree(AVL root, int level){
    if(root == NULL) return;

    printTree(root->right, level + 1);

    for(int i = 0; i < level; i++){
        printf("   ");
    }

    printf("%d\n", root->key);

    printTree(root->left, level + 1);
}

int main(){
    AVL a1 = NULL;
    AVL a2 = NULL;

    updateAVL(&a1, 42, 100);
    updateAVL(&a1, 142, 200);
    updateAVL(&a1, 62, 300);

    printf("A1 tree in-order traversal:\n");
    inOrderTraversal(a1);

    updateAVL(&a1, 42, 400);
    printf("\nAfter updating key 42:\n");
    inOrderTraversal(a1);

    updateAVL(&a2, 30, 100);
    updateAVL(&a2, 20, 200);
    updateAVL(&a2, 10, 300);

    printf("\nA2 tree before rotation:\n");
    printTree(a2, 0);

    a2 = rotateRight(a2);
    printf("\nA2 tree after rotation:\n");
    printTree(a2, 0);

    freeAVL(a1);
    freeAVL(a2);

    return 0;
}

