#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "old_tree.h"
#include "tree_list.h"


/* creates a new tree list */
Tree* new_tree_list()
{
    Tree* tree = (Tree*) malloc(sizeof(struct Tree));
    tree->root_ptr = NULL;
    tree->size = 0;
    return tree;
}

/* removes a tree from memory, merely calls destroy_node */
void destroy_tree_list(Tree* tree)
{

    if(tree->root_ptr != NULL)
    {
        destroy_node_list(tree->root_ptr);
    }
    tree->size = 0;
    free (tree);
}


void destroy_node_list(Node *leaf)
{

    /* verify there is a tree before trying to free stuff */
    /* do no use this code
    if(leaf != NULL)
    {
        destroy_node(leaf->left_ptr);
        destroy_node(leaf->right_ptr);
        free (leaf->word);
        leaf->count = 0;
        free( leaf );
    }
     */
}


/* inserts a word into a tree */
void tree_list_insert(char* new_word, Tree* tree)
{
    if (tree->root_ptr == NULL)
    {
        /* CREATE ROOT NODE */
        tree->root_ptr = new_node_list(new_word, NULL);
        printf("DEBUG:  Created root node:  %s  with count:  %d \n", tree->root_ptr->word, tree->root_ptr->count);
    }
    else
    {
        printf("DEBUG:  Tree says root node exists:  %s  with count:  %d \n", tree->root_ptr->word, tree->root_ptr->count);
        printf("DEBUG:  Inserting word into existing tree:  %s \n", new_word);
        insert_list(new_word, tree->root_ptr);
    }

}


/* inserts a word into the tree */
void insert_list(char* new_word, Node* root)
{

    int result;

    /*
    if( root->right_ptr == NULL )
    {
        printf("DEBUG:  insert_list root->right_ptr is NULL \n");
        Node* new_ptr = new_node_list(new_word, root);
        if (root->parent_ptr != NULL)
        {
            root->parent_ptr->right_ptr = new_ptr;
        }
    }

    else {*/
        /* determine where the new word goes */
        printf("DEBUG:  insert_list comparing:  %s  to:  %s  \n", root->word,  new_word);

        result = strcmp(root->word, new_word);
        // new word goes here
        if (result == 0)
        {
            /* WORD FOUND */
            root->count = root->count + 1;
            printf("DEBUG:  insert_list found existing word:  %s  ; count is now:  %d \n", root->word,  root->count);
        }
/*        else if(i < 0){
            insert(new_word, root->left_ptr);
        }
        else if (i > 0){
            insert(new_word, root->right_ptr);
        }
*/
        else
        {
            printf("DEBUG:  insert_list root->right_ptr is not NULL \n");
            insert_list(new_word, root->right_ptr);
        }


}



/* creates a new node with a word */
Node* new_node_list(char* new_word, Node* parent)
{

    Node* node =  (Node*) malloc(sizeof(struct Node));
    /* insert the new word */
    node->word = new_word;

    printf("DEBUG:  Creating new node with word:  %s \n", node->word);

    node->count = 1;
    /* initialize the children to null */
    node->left_ptr = NULL;
    node->right_ptr = NULL;
    node->parent_ptr = parent;
    /* root = node; */
    int i = node->count;
    return node;
}


/* retrieves the word stored in the node */
char* get_word_list(Node* node)
{
    return node->word;
}
