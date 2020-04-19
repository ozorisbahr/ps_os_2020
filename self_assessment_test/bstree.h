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
    int data; //node will store an integer
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
    if(t!=NULL) {
        bstree_destroy(t->leftChild);
        bstree_destroy(t->rightChild);
        free(t);
    }
}

/**
 * Inserts the given number 'd' into tree 't'.
 * if the number is already in 't', no changes are made.
 */
void bstree_insert(bstree* t, int d) {
    if(t == NULL) {
        t=malloc(sizeof(t));
        t->data=d;
        t->leftChild=NULL;
        t->rightChild=NULL;
    }
    else if(d <= t->data) {
        bstree_insert(t->leftChild,d);
        //t->leftChild->data = d;
    }
    else  {
        //t->rightChild->data = d;
        bstree_insert(t->rightChild,d);
    }
}

/**
 * Removes the given number 'd' from tree 't'.
 */
void bstree_remove(bstree* t, int d){
    struct bstree* temp = NULL;
    if(t == NULL) { //Nothing to remove
    } else if(d>t->data) {
        bstree_remove(t->rightChild,d);
    } else if (d<t->data) {
        bstree_remove(t->leftChild,d);
    } else {
        if(t->leftChild == NULL && t->rightChild == NULL) {
            free(t);
            //return NULL;
        } else if (t->leftChild == NULL || t->rightChild == NULL) { //one child

            if(t->leftChild == NULL) {
                temp = t->rightChild;
            } else {
                temp = t->leftChild;
            }
            free(t);
            //return temp;
        } else { //two children
            //temp->data = bstree_minimum(t->rightChild);
            //t->data = temp->data;
            bstree_remove(t->rightChild, temp->data);
        }
    }
    //return t;
}

/**
 * Returns the smallest number in tree 't'.
*/
int bstree_minimum(const bstree* t){
    if(t == NULL) {
        return t->data;
    } else if(t->leftChild != NULL) { //node with minimum value will have no left child
        return bstree_minimum(t->leftChild); //left most element will be minimum
    }
    return t->data;
}

/**
 * Returns the largest number in tree 't'.
 */
int bstree_maximum(const bstree* t){
    if(t == NULL) {
        return t->data;
    } else if(t->rightChild != NULL) { //node with maximum value will have no right child
        return bstree_maximum(t->rightChild); //right most element will be maximum
    }
    return t->data;
}

/**
 * Returns true if the given tree 't' contains 'd', false otherwise.
 */
bool bstree_contains(const bstree* t, int d){

    bool found = false;

    while(!found) {
        if (d == t->data) {
            found = true;
            return true;
        } else if (d <= t->data) {
            t = t->leftChild;
        } else {
            t = t->rightChild;
        }

        if (t == NULL) {
            break;
        }
    }
    return false;
}

/**
 * Returns the number of elements of the given bstree 't'.
 * NOTE: should complete in O(1) time.
 */
size_t bstree_size(const bstree* t) {

    int counter = 0;

    while(1) {
        if(t->leftChild != NULL) {
            counter++;
            t = t->leftChild;
        } else if(t->rightChild != NULL) {
            counter++;
            t = t->rightChild;
        }

        if (t == NULL) {
                break;
        }
    }
    return (size_t)counter;
}

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
