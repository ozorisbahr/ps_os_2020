#include "bstree.h"
#include <stdlib.h>
#include <stdio.h>

int main() {
    bstree* tree = bstree_create();
    tree = NULL;
    bstree_insert(tree, 1);

    FILE * output;
    output = fopen("output1.txt", "w");
    bstree_print(tree, output);

    bstree_destroy(tree);

    return EXIT_SUCCESS;
}
