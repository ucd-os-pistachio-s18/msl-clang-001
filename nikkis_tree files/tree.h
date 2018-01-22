#ifndef TREE_H
#define TREE_H


typedef struct Node{
/* HAS POINTERS */
    /* IS A LEFT POINTER */
    Node* left_ptr;
    /* IS A RIGHT POINTER */
    Node* right_ptr;
    /* IS A PARENT POINTER */
    Node* parent_ptr;

/* HAS DATA */
    /* IS A CHAR ARRAY */
    char* word;
    /* IS AN INTEGER COUNT; INIT 0 */
    int count;
}Node;

/* TREE NODE SIZE (COUNT OF NODES) */
int size = 0;

void destroy_tree(Node*);
void insert(char*, Node*);
char* get_word(Node*);
int get_count(Node*);
void print_tree_inorder(Node*);

#endif // TREE_H
