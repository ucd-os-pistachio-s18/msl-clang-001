
/* BINARY TREE IMPLEMENTATION */

#include <malloc.h>
#include <mem.h>
#include <stdio.h>
#include <stdlib.h>
#include "old_tree.h"


/* METHODS FOR TREE_H */

/* completely removes the tree from memory */
void destroy_node(Node *leaf){

    /* verify there is a tree before trying to free stuff */
    if(leaf != NULL)
    {
        destroy_node(leaf->left_ptr);
        destroy_node(leaf->right_ptr);

        printf("DEBUG:  Destroying node with word:  %s \n", leaf->word);

        free (leaf->word);
        leaf->count = 0;
        free( leaf );

    }
}

/* inserts a word into the tree */
Node* insert(char* new_word, Node* root){

    int result;
    Node* return_node_ptr = root;

    /* this will make a node whether there is a tree already or not */
    if( root == NULL )
    {
        return_node_ptr = new_node(new_word, root);
    }
    else {
        /* determine where the new word goes */
        result = strcmp(root->word, new_word);
        // new word goes here
        if (result == 0){
            root->count = root->count + 1;
            printf("DEBUG:  Word already in tree; new count:  %d \n", root->count);

        }
        else if(result < 0){
            insert(new_word, root->left_ptr);
        }
        else if (result > 0){
            insert(new_word, root->right_ptr);
        }
    }
    return return_node_ptr;
}

/* creates a new node with a word */
Node* new_node(char* new_word, Node* root){

    Node* node =  (Node*) malloc(sizeof(struct Node));
    /* insert the new word */
    node->word = new_word;
    node->count = 1;
    /* initialize the children to null */
    node->left_ptr = NULL;
    node->right_ptr = NULL;
    node->parent_ptr = root;
    root = node;
    int i = node->count;

    printf("DEBUG:  Tree created node with word:  %s \n", new_word);

    return node;
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
void print_nodes_in_order(Node *root){

    /* if there is no tree, don't print anything */
    if(root != NULL){
        print_nodes_in_order(root->left_ptr);
        char* tmp_word = get_word(root);
        int tmp_int = get_count(root);
        printf("%s: %d/n", tmp_word, tmp_int);
        print_nodes_in_order(root->right_ptr);
    }
    else
    {
        printf("DEBUG:  Error:  root == NULL; No tree to print. \n");
    }
}

/* creates a new tree with a word */
Tree* new_tree(){
    Tree* tree = (Tree*) malloc(sizeof(struct Tree));
    if(new_tree == NULL){
        fprintf(stderr, "out of memory (newTree)\n");
        exit(1);
    }
    tree->root_ptr = NULL;
    tree->size = 0;
    return tree;
}

/* removes a tree from memory, merely calls destroy_node */
void destroy_tree(Tree* tree){

    if(tree->root_ptr != NULL) {
        destroy_node(tree->root_ptr);
    }
    else
    {
        printf("DEBUG:  Error:  root == NULL; No tree to destroy. \n");
    }
    tree->size = 0;
    free (tree);
}

/* inserts a word into a tree */
void tree_insert(char* new_word, Tree* tree){
    printf("\nDEBUG:  Tree is inserting word:  %s \n", new_word);
    if (tree->root_ptr == NULL)
    {
        printf("DEBUG:  Node is first node... \n");
        tree->root_ptr = insert(new_word, tree->root_ptr);
    }
    else
    {

        insert(new_word, tree->root_ptr);
    }
    printf("DEBUG:  Root node is word:  %s \n", tree->root_ptr->word);
}

/* prints a tree in order */
void print_tree(Tree* tree){
    printf("DEBUG:  Tree is now printing... \n");
    print_nodes_in_order(tree->root_ptr);
}

