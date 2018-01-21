
/* BINARY TREE IMPLEMENTATION */

#include <malloc.h>
#include <mem.h>
#include <stdio.h>
#include "tree.h"


/* METHODS FOR TREE_H */

/* completely removes the tree from memory */
void destroy_node(Node *leaf){

    // verify there is a tree before trying to free stuff
    if(leaf != 0)
    {
        destroy_node(leaf->left_ptr);
        destroy_node(leaf->right_ptr);
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

/* creates a new node with a word */
void new_node(char* new_word, Node* root){

    Node* node =  (Node*) malloc(sizeof(struct Node));
    /* insert the new word */
    node->word = new_word;
    /* initialize the children to null */
    node->left_ptr = 0;
    node->right_ptr = 0;
    node->parent_ptr = root;
}

/* retrieves the word stored in the node */
char* get_word(Node* node){

    return node->word;
}

/* retrieves the count stored in the node */
int get_count(Node* node){

    return node->count;
}

/* prints the tree in order */
void print_tree_in_order(Node* root){

    // if there is no tree, don't print anything
    if(root != 0){
        print_tree_in_order(root->left_ptr);
        printf(get_word(root));
        int i = get_count(root);
        char* tmp = " : ";
        tmp = tmp + (char)i;
        print_tree_in_order(root->right_ptr);
    }
}

/* creates a new tree with a word */
Tree* new_tree(char* word_ptr){
    Tree* tree = (Tree*) malloc(sizeof(struct Tree));
    insert(word_ptr, tree->root_ptr);
    return tree;
}

/* removes a tree from memory, merely calls destroy_node */
void destroy_tree(Tree* tree){
    destroy_node(tree->root_ptr);
    tree->size = 0;
    free (tree);
}



Tree* temp_new_tree()
{
    Tree* tree = (Tree*) malloc(sizeof(struct Tree));
    return tree;
}


void temp_tree_insert(char* word, Tree* tree)
{
    insert(word, tree->root_ptr);
}

