/* BINARY TREE IMPLEMENTATION */

#include <malloc.h>
#include <mem.h>
#include <stdio.h>
#include "tree.h"


/* METHODS FOR TREE_H */

/* completely removes the tree from memory */
void destroy_tree(Node* root){

    // verify there is a tree before trying to free stuff
    if(root != 0)
    {
        /* first destroy left subtree */
        destroy_tree(root->left_ptr);
        /* next destroy right subtree */
        destroy_tree(root->right_ptr);
        /* lastly free the root node */
        free (root->word);
        leaf->count = 0;
        free( root );
    }

    printf("the tree is now gone");
}

/* inserts a word into the tree */
void insert(char* new_word, Node* root){

    // this will make a node whether there is a tree already or not
    if( root == 0 ){
        root = (*Node)malloc(sizeof(Node));
        root->word = new_word;
        /* set left and right children to null */
        root->left_ptr = NULL;
        root->right_ptr = NULL;
        root->count = 1;
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
    printf("a word was inserted into the tree");
}

char* get_word(Node* node){
    printf("printing a word");
    /* simply returns the word this node points to */
    return node->word;
}

int get_count(Node* node){
    printf("printing a count");
    /* simply returns the count this node points to */
    return node->count;
}

void print_tree_inorder(Node* root){

    /* prints the tree in an inorder traversal so it's lexically in order */
    if(root != 0){
        print_tree_inorder(root->left_ptr);
        printf(get_word(root));
        int i = get_count(root);
        char* tmp = " : ";
        tmp = tmp + (char)i;
        print_tree_in_order(root->right_ptr);
    }
}
