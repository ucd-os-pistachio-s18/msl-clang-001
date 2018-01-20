#ifndef MSL_CLANG_001_TREE_H
#define MSL_CLANG_001_TREE_H

/* BINARY TREE HEADER */

/* THE CLIENT IS ASKING FOR A BALANCED BINARY SEARCH TREE.  WE WILL GIVE THE
 * CLIENT A BALANCED BINARY TREE IF THERE IS TIME, BUT WE BELIEVE THE CLIENT
 * WOULD BE JUST AS HAPPY WITH A DOUBLY-LINKED LIST.  WITH A DOUBLY-LINKED
 * LIST IN PLACE THE PROGRAM WILL FUNCTION PROPERLY, AND WE CAN MODIFY THE
 * DATA STRUCTURE LATER TO ACCOMMODATE THE CORRECT FUNCTIONALITY OF A BINARY
 * SEARCH TREE, AND LATER PROVIDE A BALANCING FUNCTION FOR SUCH.
 */



/* NODE STRUCT: */
/* FOREWARD DECLARATIONS */
typedef struct Node Node;
typedef struct Tree Tree;


struct Node
{
/* HAS POINTERS */
    /* IS A LEFT POINTER */
    Node* left_ptr;
    /* IS A RIGHT POINTER */
    Node* right_ptr;
    /* IS A PARENT POINTER */
        /* AS A LINKED LIST, PARENT POINTER WILL BE SET TO NULL */
    Node* parent_ptr;

/* HAS DATA */
    /* IS A CHAR ARRAY */
    char* word;
    /* IS AN INTEGER COUNT; INIT 0 */
    int count;
};


/* HAS METHODS */
/* NOTE: STRUCTS DO NOT HAVE DIRECT METHODS. STRUCTS HOWEVER CAN BE PASSED TO FUNCTIONS BY REFERENCE */

/* CREATES A NODE IN MEMORY */
Node* newNode(char* word);

/* SETS LEFT POINTER */
void setNodePtrLeft(Node* node_ptr);
/* SETS RIGHT POINTER */
void setNodePtrRight(Node* node_ptr);
/* SETS PARENT POINTER */
void setNodePtrParent(Node* node_ptr);
/* SETS DATA */
void setNodeWord(Node* node_ptr, char* word);
void setNodeCount(Node* node_ptr, int count);
/* INCREMENTS INTEGER COUNT DATA */
void incNodeCount(Node* node_ptr);

/* GETS LEFT POINTER */
Node* getNodePtrLeft(Node* node_ptr);
/* GETS RIGHT POINTER */
Node* getNodePtrRight(Node* node_ptr);
/* GETS PARENT POINTER */
Node* getNodePtrParent(Node* node_ptr);
/* GETS DATA */
char* getNodeWord(Node* node_ptr);
int getNodeCount(Node* node_ptr);

/* REMOVES A NODE FROM MEMORY */
void destroyNode(Node* node_ptr);




/* TREE STRUCT */
struct Tree
{
/* HAS POINTERS */
    /* IS A ROOT POINTER */
        /* AS A LINKED LIST, ROOT POINTER WILL BE SET TO HEAD NODE FOR SIMPLICITY */
    Tree* root_ptr;

/* HAS DATA */
    /* IS AN INTEGER COUNT OF NUMBER OF NODES IN TREE; INIT 0 */
    int size;

};

/* HAS METHODS */
/* NOTE: STRUCTS DO NOT HAVE DIRECT METHODS. STRUCTS HOWEVER CAN BE PASSED TO FUNCTIONS BY REFERENCE */

/* CREATES A TREE */
Tree* newTree();

/* INSERTS A NODE INTO TREE */
/* NOTE: PARAMETERS AND RETURN TYPE TBD */
    /* INCREMENT INTEGER COUNT DATA FOR NODE */
void insertNodeIntoTree(Tree* tree_ptr, Node* node_ptr);
void insertWordIntoTree(Tree* tree_ptr, char* word);

/* SEARCHES A TREE FOR DATA */
Node* isWordInTree(Tree* tree_ptr, char* word);

/* GETS SIZE OF TREE */
int getTreeSize(Tree* tree_ptr);

/* GETS ROOT NODE POINTER */
Node* getRootNodePtr(Tree* tree_ptr);

/* LISTS ALL NODES IN TREE IN ORDER */
/* NOTE: RETURN TYPE AND PROCEDURE TBD */
Node* listNodes(Tree* tree_ptr);

/* REMOVES A NODE FROM TREE */
    /* FIRST THIS NODE MUST BE REMOVED FROM MEMORY */
void removeNodeFromTree(Tree* tree_ptr, Node* node_ptr);

/* REMOVES ITSELF FROM MEMORY */
    /* FIRST ALL NODES HELD BY TREE MUST BE REMOVED FROM MEMORY */
void destroyTree(Tree* tree_ptr);



void testTree();


#endif
