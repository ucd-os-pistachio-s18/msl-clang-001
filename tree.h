#ifndef MSL_CLANG_001_TREE_H
#define MSL_CLANG_001_TREE_H

/* BINARY TREE WITH NODE-s
 * THIS BINARY TREE WILL HOLD POINTERS TO ITS PARENT
 * ITS LEFT CHILD AND ITS RIGHT CHILD
 * THE DATA HELD WILL BE CHAR ARRAY WHICH CAN ALSO BE
 * CAST TO INT */
typedef struct Node Node;
typedef struct Tree Tree;

struct Node {
/* HAS POINTERS */
    /* IS A LEFT POINTER */
    struct Node* left_ptr;
    /* IS A RIGHT POINTER */
    struct Node* right_ptr;
    /* IS A PARENT POINTER */
    struct Node* parent_ptr;
/* HAS DATA */
    /* IS A CHAR ARRAY */
    char* word;
    /* IS AN INTEGER COUNT; INIT 0 */
    int count;
};

/* TREE STRUCT COMPOSED OF NODES WITH INCORPORATED COUNT*/
struct Tree {
/* HAS POINTERS */
    /* IS A ROOT POINTER */
    Node* root_ptr;
/* HAS DATA */
    /* IS AN INTEGER COUNT OF NUMBER OF NODES IN TREE*/
    int size;
};

int new_node(char*, Node*);
void destroy_node(Node *);
int insert(char*, Node*);
char* get_word(Node*);
int get_count(Node*);
void print_nodes_in_order(Node *);

Tree* new_tree();
void destroy_tree(Tree*);
int tree_insert(char*, Tree*);
void print_tree_in_order(Tree*);


/* TEMPORARY FUNCTIONS */
Tree* temp_new_tree();
void temp_tree_insert(char* word, Tree* tree);
void temp_destroy_tree(Tree* tree);

#endif
