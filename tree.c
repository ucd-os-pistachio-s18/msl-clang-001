#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

/*
 * MODIFIED BY BRIAN SUMNER FROM:
 * https://github.com/ucd-os-pistachio-s18/kiss_tree
 */


Node* new_Node(int key)
{
    // ALLOCATE MEMORY
    Node* node_ptr;
    node_ptr = (Node*)malloc(sizeof(struct Node));

    // INIT DATA
    node_ptr->left_ptr = NULL;
    node_ptr->right_ptr = NULL;
    node_ptr->data = key;

    printf("DEBUG:  Created new node with key:  %d \n\n", key);

    return node_ptr;
}


void destroy_Node(Node *node_ptr)
{
    if (node_ptr->left_ptr != NULL || node_ptr->right_ptr != NULL)
    {
        printf("ERROR:  NODE HAS ACTIVE CHILDREN\n");
    }
    else
        printf("DEBUG:  Destroying node with key:  %d \n", node_ptr->data);

    // DESTROY DATA
    node_ptr->data = 0;

    // DEALLOCATE NODE
    free(node_ptr);

    printf("DEBUG:  DESTROYED NODE.\n\n");
}


Node* insert_node(Node *root_ptr, int key)
{
    if (root_ptr == NULL)
    {
        // CASE: NO NODE EXISTS AT ROOT; MAKE A NEW NODE WITH KEY
        printf("DEBUG:  Unable to find key:  %d\n", key);
        root_ptr = new_Node(key);

        // RECURSION IS COMPLETE.  RETURN NODE ADDRESS
    }
    else
    {
        // CASE: TREE EXISTS
        if (key == root_ptr->data)
        {
            // CASE: KEY FOUND IN THE ROOT NODE

            /* DO STUFF HERE */
            printf("DEBUG:  Found key in tree:  %d \n\n", key);

            // RECURSION IS COMPLETE.  RETURN NODE ADDRESS
        }
        else if (key < root_ptr->data)
        {
            // CASE: KEY IS LESS THAN THE ROOT NODE DATA
            printf("DEBUG:  Searching left branch of node:  %d  for key:  %d \n", root_ptr->data, key);

            // RECURSIVELY SEARCH THE LEFT BRANCH
            root_ptr->left_ptr = insert_node(root_ptr->left_ptr, key);
        }
        else if (key > root_ptr->data)
        {
            // CASE: INPUT DATA IS GREATER THAN THE ROOT NODE DATA
            printf("DEBUG:  Searching right  branch of node:  %d  for key:  %d \n", root_ptr->data, key);

            // RECURSIVELY SEARCH THE RIGHT BRANCH
            root_ptr->right_ptr = insert_node(root_ptr->right_ptr, key);
        }
    }

    // RETURN THE POINTER TO THE NODE WHERE THE DATA WAS FOUND OR INSERTED
    return root_ptr;
}


void destroy_tree(Node *node_ptr, Node *parent_ptr)
{
    printf("DEBUG:  Attempting to destroy node with key:  %d \n", node_ptr->data);

    if (node_ptr->left_ptr != NULL)
    {
        printf("DEBUG:  Going left of node with key:  %d \n", node_ptr->data);
        destroy_tree(node_ptr->left_ptr, node_ptr);
    }

    if (node_ptr->right_ptr != NULL)
    {
        printf("DEBUG:  Going right of node with key:  %d \n", node_ptr->data);
        destroy_tree(node_ptr->right_ptr, node_ptr);
    }

    if (parent_ptr != NULL)
    {
        if (parent_ptr->left_ptr != NULL)
            parent_ptr->left_ptr = NULL;
        else if (parent_ptr->right_ptr != NULL)
            parent_ptr->right_ptr = NULL;
        else
            printf("ERROR:  UNABLE TO SET CHILDREN NULL IN PARENT\n");
    }

    // BOTH CHILDREN NOW NULL; DELETE NODE
    printf("\nDEBUG:  Initiating destruction of node with key:  %d \n", node_ptr->data);
    destroy_Node(node_ptr);
    node_ptr = NULL;
}


void list_tree_inorder(Node *root_ptr)
{
    if (root_ptr != NULL)
    {
        // GO LEFT
        if (root_ptr->left_ptr != NULL)
            list_tree_inorder(root_ptr->left_ptr);

        // DO STUFF
        printf("OUTPUT:  Node data:  %d \n", root_ptr->data);

        // GO RIGHT
        if (root_ptr->right_ptr != NULL)
            list_tree_inorder(root_ptr->right_ptr);
    }
}


void tree_test_driver()
{
    Node* root_ptr;
    int newKey;

//    int intArray[] = {3, 1, 2, 7, 6, 9, 8, 11};
//    int intArray[] = {50, 10, 20, 15, 18, 16, 17};
    int intArray[] = {4,2,1,3,6,5,7};
//    int intArray[] = {4,2,1,3};
//    int intArray[] = {5,5,5,5};

    root_ptr = new_Node(intArray[0]);

    int index;
    int max = (sizeof(intArray)/ sizeof(newKey));
    for (index = 1; index < max; ++index)
    {
        newKey =  intArray[index];
        printf("DEBUG:  Inserting key:  %d \n", newKey);
        insert_node(root_ptr, newKey);
    }

    printf("\nDEBUG:  Outputting tree in order: \n\n");
    list_tree_inorder(root_ptr);

    printf("\nDEBUG:  Destroying tree...\n\n");
    destroy_tree(root_ptr, NULL);
}
