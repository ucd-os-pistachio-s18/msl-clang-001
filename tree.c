#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tree.h"
#include "file.h"

/*
 * MODIFIED BY BRIAN SUMNER FROM:
 * https://github.com/ucd-os-pistachio-s18/kiss_tree
 */


Node* new_Node(int SHOW_DEBUG)
{
    // ALLOCATE MEMORY
    Node* node_ptr;
    node_ptr = (Node*)malloc(sizeof(struct Node));

    // INIT DATA
    node_ptr->left_ptr = NULL;
    node_ptr->right_ptr = NULL;
    node_ptr->word = NULL;
    node_ptr->count = 0;

    if (SHOW_DEBUG) printf("DEBUG:  Created new empty node\n\n");

    return node_ptr;
}


void destroy_Node(Node *node_ptr, int SHOW_DEBUG)
{
    if (node_ptr->left_ptr != NULL || node_ptr->right_ptr != NULL)
    {
        if (SHOW_DEBUG) printf("ERROR:  NODE HAS ACTIVE CHILDREN\n");
    }
    else
        if (SHOW_DEBUG) printf("DEBUG:  Destroying node with word:  %s \n", node_ptr->word);

    // DESTROY DATA
    node_ptr->count = 0;
    free(node_ptr->word);

    // DEALLOCATE NODE
    free(node_ptr);

    if (SHOW_DEBUG) printf("DEBUG:  DESTROYED NODE.\n\n");
}


Node* insert_node(Node *root_ptr, char* word, int SHOW_DEBUG)
{
    // DO NOT DEREFERENCE DATA BEFORE CHECKING IF ROOT IS NULL!
    if (root_ptr == NULL)
    {
        // CASE: NO NODE EXISTS AT ROOT; MAKE A NEW NODE WITH WORD
        if (SHOW_DEBUG) printf("DEBUG:  Unable to find word:  %s\n", word);
        root_ptr = new_Node(SHOW_DEBUG);

        root_ptr->word = (char*)malloc(sizeof(word));
        strcpy(root_ptr->word, word);
        ++root_ptr->count;

        // RECURSION IS COMPLETE.  RETURN NODE ADDRESS
    }
    else if (root_ptr->count == 0)
    {
        // CASE: NODE EXISTS AT ROOT WITHOUT DATA; SET DATA TO ROOT NODE
        root_ptr->word = (char*)malloc(sizeof(word));
        strcpy(root_ptr->word, word);
        ++root_ptr->count;

        // RECURSION IS COMPLETE.  RETURN NODE ADDRESS
    }
    else
    {
        // CASE: TREE EXISTS

        // COMPARE WORDS
        int strcmpResult;
        strcmpResult = strcmp(word, root_ptr->word);

//        if (word == root_ptr->word)
        if (strcmpResult == 0)
        {
            // CASE: WORD FOUND IN THE ROOT NODE

            /* DO STUFF HERE */
            if (SHOW_DEBUG) printf("DEBUG:  Found word in tree:  %s \n\n", root_ptr->word);
            ++root_ptr->count;

            // RECURSION IS COMPLETE.  RETURN NODE ADDRESS
        }
//        else if (word < root_ptr->count)
        else if (strcmpResult < 0)
        {
            // CASE: WORD IS LESS THAN THE ROOT NODE DATA
            if (SHOW_DEBUG) printf("DEBUG:  Searching left branch of node:  %s  for word:  %s \n", root_ptr->word, word);

            // RECURSIVELY SEARCH THE LEFT BRANCH
            root_ptr->left_ptr = insert_node(root_ptr->left_ptr, word, SHOW_DEBUG);
        }
//        else if (word > root_ptr->count)
        else if (strcmpResult > 0)
        {
            // CASE: INPUT DATA IS GREATER THAN THE ROOT NODE DATA
            if (SHOW_DEBUG) printf("DEBUG:  Searching right  branch of node:  %s  for word:  %s \n", root_ptr->word, word);

            // RECURSIVELY SEARCH THE RIGHT BRANCH
            root_ptr->right_ptr = insert_node(root_ptr->right_ptr, word, SHOW_DEBUG);
        }
    }

    // RETURN THE POINTER TO THE NODE WHERE THE DATA WAS FOUND OR INSERTED
    return root_ptr;
}


void destroy_tree(Node *node_ptr, Node *parent_ptr, int SHOW_DEBUG)
{
    if (SHOW_DEBUG) printf("DEBUG:  Attempting to destroy node with word:  %s \n", node_ptr->word);

    if (node_ptr->left_ptr != NULL)
    {
        if (SHOW_DEBUG) printf("DEBUG:  Going left of node with word:  %s \n", node_ptr->word);
        destroy_tree(node_ptr->left_ptr, node_ptr, SHOW_DEBUG);
    }

    if (node_ptr->right_ptr != NULL)
    {
        if (SHOW_DEBUG) printf("DEBUG:  Going right of node with word:  %s \n", node_ptr->word);
        destroy_tree(node_ptr->right_ptr, node_ptr, SHOW_DEBUG);
    }

    if (parent_ptr != NULL)
    {
        if (parent_ptr->left_ptr != NULL)
            parent_ptr->left_ptr = NULL;
        else if (parent_ptr->right_ptr != NULL)
            parent_ptr->right_ptr = NULL;
        else
        if (SHOW_DEBUG) printf("ERROR:  UNABLE TO SET CHILDREN NULL IN PARENT\n");
    }

    // BOTH CHILDREN NOW NULL; DELETE NODE
    if (SHOW_DEBUG) printf("\nDEBUG:  Initiating destruction of node with word:  %s \n", node_ptr->word);
    destroy_Node(node_ptr, SHOW_DEBUG);
    node_ptr = NULL;
}


void list_tree_inorder_to_file(Node* root_ptr, FILE* outputFile_ptr)
{
    if (root_ptr != NULL)
    {
        // GO LEFT
        if (root_ptr->left_ptr != NULL)
            list_tree_inorder_to_file(root_ptr->left_ptr, outputFile_ptr);

        // DO STUFF
//        printf("OUTPUT:  Node count:  %d \n", root_ptr->count);
        if (root_ptr->count != 0)
            outputDataToFile(root_ptr->word, root_ptr->count, outputFile_ptr);

        // GO RIGHT
        if (root_ptr->right_ptr != NULL)
            list_tree_inorder_to_file(root_ptr->right_ptr, outputFile_ptr);
    }
}


// UNUSED TEST CODE
/*
void tree_test_driver()
{
    Node* root_ptr;
    int newKey;

//    int intArray[] = {3, 1, 2, 7, 6, 9, 8, 11};
//    int intArray[] = {50, 10, 20, 15, 18, 16, 17};
    int intArray[] = {4,2,1,3,6,5,7};
//    int intArray[] = {4,2,1,3};
//    int intArray[] = {5,5,5,5};

    root_ptr = new_Node();
    root_ptr->count = intArray[0];

    int index;
    int max = (sizeof(intArray)/ sizeof(newKey));
    for (index = 1; index < max; ++index)
    {
        newKey =  intArray[index];
        printf("DEBUG:  Inserting key:  %d \n", newKey);
//        insert_node(root_ptr, newKey);
    }

    printf("\nDEBUG:  Outputting tree in order: \n\n");
//    list_tree_inorder_to_file(root_ptr);

    printf("\nDEBUG:  Destroying tree...\n\n");
    destroy_tree(root_ptr, NULL);
}
*/