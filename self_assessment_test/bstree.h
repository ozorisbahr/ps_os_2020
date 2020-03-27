#ifndef _BSTREE_H_
#define _BSTREE_H_

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * Stores a binary, sorted tree of integers, in which each element may only
 * occur once.
 */
struct bstree;
typedef struct bstree {
    int data;
    struct bstree* leftChild;
    struct bstree* rightChild;
} bstree;

/**
 * Creates and returns a new binary tree.
 * Must be deallocated by bstree_destroy.
 */
bstree* bstree_create(){
    bstree* newTree = (bstree*)malloc(sizeof(newTree));
    newTree->data = 0;
    newTree->leftChild = NULL;
    newTree->rightChild = NULL;
    return newTree;
}

/**
 * Destroys and deallocates all memory for the given tree 't'
 */
void bstree_destroy(bstree* t) {
    if(bstree!=NULL) {
        bstree_destroy(bstree->left);
        bstree_destroy(bstree->right);
        free(bstree);
    }
}

/**
 * Inserts the given number 'd' into tree 't'.
 * if the number is already in 't', no changes are made.
 */
void bstree_insert(bstree* t, int d) {
    if(t == NULL) {
        bstree_create();
    }
    else if(d <= t->data) {
        t->leftChild->data = d;
    }
    else  {
        t->rightChild->data = d;
    }
}

/**
 * Removes the given number 'd' from tree 't'.
 */
void bstree_remove(bstree* t, int d);

/**
 * Returns the smallest number in tree 't'.
*/
int bstree_minimum(const bstree* t);

/**
 * Returns the largest number in tree 't'.
 */
int bstree_maximum(const bstree* t);

/**
 * Returns true if the given tree 't' contains 'd', false otherwise.
 */
bool bstree_contains(const bstree* t, int d);

/**
 * Returns the number of elements of the given bstree 't'.
 * NOTE: should complete in O(1) time.
 */
size_t bstree_size(const bstree* t);

/**
 * Prints the given bstree 't' to the supplied output stream 'out'
 * output format: ([LEFT], VAL, [RIGHT]) : [SIZE]
 * example empty: ( NIL ) : 0
 * example 3,4,7 in a balanced tree: ((3), 4, (7)) : 3
 */
void bstree_print(const bstree* t, FILE* out) {
    fprintf(out, "%d \n", t->data);
}

#endif // _BSTREE_H_
