
/* BINARY TREE IMPLEMENTATION */

#include <stdio.h>
#include <malloc.h>
#include <mem.h>
#include "tree.h"

/* CREATES A NODE IN MEMORY */
Node* newNode(char* word){
    Node* new_node = (Node*)malloc(sizeof(Node));
    if(new_node == NULL){
        fprintf(stderr, "out of memory (newNode)\n");
        exit(1);
    }
    new_node->word = word;
    new_node->count = 1;
    new_node->right_ptr = NULL;
    new_node->left_ptr = NULL;
    return new_node;
}

/* SETS LEFT POINTER */
/* this function is not needed */
/* void setNodePtrLeft(Tree* tree_ptr, Node* node_ptr){
        tree_ptr->root_ptr->left_ptr = node_ptr;
}
 */

/* SETS RIGHT POINTER */
/* this function is not needed */
/* void setNodePtrRight(Node* node_ptr){
        tree_ptr->root_ptr->right_ptr = node_ptr;
}
 */

/* SETS PARENT POINTER */
/* this function is not needed */
/* void setNodePtrParent(Node* node_ptr){
        tree_ptr->root_ptr->parent_ptr = node_ptr;
}
 */

/* SETS WORD */
/* this function is not needed */
/* void setNodeWord(Node* node_ptr, char* word){
    node_ptr->word = word;
}
*/

/* SETS COUNT */
/* this function is not needed */
/* void setNodeCount(Node* node_ptr, int count){
    node_ptr->count = count;
}
 */

/* INCREMENTS INTEGER COUNT DATA */
void incNodeCount(Node* node_ptr){
    node_ptr->count = node_ptr->count +1;
}

/* GETS LEFT POINTER */
/* this function is not needed */
/* Node* getNodePtrLeft(Node* node_ptr){
    return node_ptr->left_ptr;
}
 */

/* GETS RIGHT POINTER */
/* this function is not needed */
/* Node* getNodePtrRight(Node* node_ptr){
    return node_ptr->right_ptr;
}
 */

/* GETS PARENT POINTER */
/* this function is not needed */
/* Node* getNodePtrParent(Node* node_ptr){
    return node_ptr->parent_ptr;
}
 */

/* GETS WORD */
/* this function is not needed */
/* char* getNodeWord(Node* node_ptr){
    return node_ptr->word;
}
 */

/* GETS COUNT */
/* this function is not needed */
/* int getNodeCount(Node* node_ptr){
    return node_ptr->count;
}
 */

/* REMOVES A NODE FROM MEMORY */
void destroyNode(Node* node_ptr){
    /* this is the leaf destructor */
    node_ptr->count = 0;
    node_ptr->word = NULL;
    free (node_ptr);
}

/* CREATES A TREE */
Tree* newTree(){
    Tree* new_tree = (Tree*)malloc(sizeof(Tree));
    if(new_tree == NULL){
        fprintf(stderr, "out of memory (newTree)\n");
        exit(1);
    }
    new_tree->root_ptr = NULL;
    new_tree->size = 0;
    return new_tree;
}

/* INSERTS A NODE INTO TREE */
/* INCREMENT INTEGER COUNT DATA FOR NODE */
/* this function is not needed
void insertNodeIntoTree(Tree* tree_ptr, Node* node_ptr){
    if(tree_ptr->root_ptr == NULL){
        tree_ptr->root_ptr = node_ptr;
        incNodeCount(tree_ptr->root_ptr);
    }
}
*/

/* INSERTS A WORD INTO A TREE */
void insertWordIntoTree(Tree* tree_ptr, char* word){
    /* this will call the helper function newNode and incNodeCount */
    if(tree_ptr->root_ptr == NULL){
        tree_ptr->root_ptr = newNode(word);
        tree_ptr->size = tree_ptr->size + 1;
    }
    else{
        /* the tree has leaves - check strcmp */
        int i = strcmp(tree_ptr->root_ptr->word, word);
        if(i == 0){
            incNodeCount(tree_ptr->root_ptr);
        }
        else if (i < 0){
            insertWordIntoTree(tree_ptr->root_ptr->left_ptr, word);
        }
        else if (i > 0){
            insertWordIntoTree(tree_ptr->root_ptr->right_ptr, word);
        }
    }
}

/* SEARCHES A TREE FOR DATA */
int isWordInTree(Tree* tree_ptr, char* word){
    /* returns an integer value (boolean) that represents success or failure of finding the word */
    if(tree_ptr->root_ptr == NULL)
        return 0;
    if(tree_ptr->root_ptr->word == NULL)
        return 0;
    int i = strcmp(tree_ptr->root_ptr->word, word);
    if(i == 0){
        incNodeCount(tree_ptr->root_ptr);
    }
    else if(i < 0){
        isWordInTree(tree_ptr->root_ptr->left_ptr, word);
    }
    else if(i > 0){
        isWordInTree(tree_ptr->root_ptr->right_ptr, word);
    }
}

/* GETS SIZE OF TREE */
int getTreeSize(Tree* tree_ptr){
    return tree_ptr->size;
}

/* GETS ROOT NODE POINTER */
/* this function is not needed */
/* Node* getRootNodePtr(Tree* tree_ptr){} */

/* LISTS ALL NODES IN TREE IN ORDER */
/* NOTE: RETURN TYPE AND PROCEDURE TBD */
/* Node* listNodes(Tree* tree_ptr) */
void listNodes(Tree* tree_ptr){
    /* this will be an inorder traversal of the tree */
    if(tree_ptr->root_ptr != NULL){
        if(tree_ptr->root_ptr->left_ptr != NULL){
            listNodes(tree_ptr->root_ptr->left_ptr);
        }
        if(tree_ptr->root_ptr->word != NULL){
            char* tmp_word = tree_ptr->root_ptr->word;
            int tmp_int = tree_ptr->root_ptr->count;
            printf("%s: %d\n", tmp_word, tmp_int);
        }
        if(tree_ptr->root_ptr->right_ptr != NULL){
            listNodes(tree_ptr->root_ptr->right_ptr);
        }
    }
}

/* REMOVES A NODE FROM TREE */
/* FIRST THIS NODE MUST BE REMOVED FROM MEMORY */
/* this function is not needed */
/* void removeNodeFromTree(Tree* tree_ptr, Node* node_ptr){
        /* this will be implemented when we move to a balanced tree */
        /* there is currently no time for it now */
/*}*/

/* REMOVES ITSELF FROM MEMORY */
/* THIS IS A POSTORDER TRAVERSAL FOR DESTRUCTION */
void destroyTree(Tree* tree_ptr){

    /* only need to destroy trees if they exist */
    if(tree_ptr != NULL){
        if(tree_ptr->root_ptr != NULL){
            if(tree_ptr->root_ptr->left_ptr != NULL){
                destroyTree(tree_ptr->root_ptr->left_ptr);
            }
            if(tree_ptr->root_ptr->right_ptr != NULL){
                destroyTree(tree_ptr->root_ptr->right_ptr);
            }
            if(tree_ptr->root_ptr->word != NULL){
                destroyNode(tree_ptr->root_ptr);
            }
        }
    }
}

void testTree()
{
    printf("DEBUG:  tree.c linked successfully. \n");
}

