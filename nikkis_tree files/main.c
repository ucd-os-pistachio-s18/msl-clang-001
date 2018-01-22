#include <stdio.h>
#include <stdlib.h>

#include "tree.h"

int main(){

    /* testing a tree */
    node* tree1;
    insert("cat", tree1);
    get_word(tree1);
    get_count(tree1);
    print_tree_inorder(tree1);
    destroy_tree(tree1);
    exit(0);
}
