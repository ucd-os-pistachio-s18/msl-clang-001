
/* BINARY TREE IMPLEMENTATION */

#include <malloc.h>
#include <mem.h>
#include <stdio.h>
#include "tree.h"


/* METHODS FOR TREE_H */

/* completely removes the tree from memory */
void destroy_tree(Node* leaf){

    // verify there is a tree before trying to free stuff
    if(leaf != 0)
    {
        destroy_tree(leaf->left_ptr);
        destroy_tree(leaf->right_ptr);
        free (leaf->word);
        leaf->count = 0;
        free( leaf );
    }
}

/* inserts a word into the tree */
void insert(char* new_word, Node* root){

    // this will make a node whether there is a tree already or not
    if( root == 0 )
    {
        new_node(new_word, root);
    }
    else {
        /* determine where the new word goes */
        int i = strcmp(root->word, new_word);
        // new word goes here
        if (i == 0){
            root->count = root->count + 1;
        }
        else if(i < 0){
            insert(new_word, root->left_ptr);
        }
        else if (i > 0){
            insert(new_word, root->right_ptr);
        }
    }
}

void new_node(char* new_word, Node* root){

    Node* node =  (Node*) malloc(sizeof(struct Node));
    /* insert the new word */
    node->word = new_word;
    /* initialize the children to null */
    node->left_ptr = 0;
    node->right_ptr = 0;
    node->parent_ptr = root;
}

char* get_word(Node* node){

    return node->word;
}

int get_count(Node* node){

    return node->count;
}

void print_tree_in_order(Node* root){

    if(root != 0){
        print_tree_in_order(root->left_ptr);
        printf(get_word(root));
        int i = get_count(root);
        char* tmp = " : ";
        tmp = tmp + (char)i;
        print_tree_in_order(root->right_ptr);
    }
}