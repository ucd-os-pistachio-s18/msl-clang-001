#ifndef KISS_TREE_TREE_H
#define KISS_TREE_TREE_H

/*
 * MODIFIED BY BRIAN SUMNER FROM:
 * https://github.com/ucd-os-pistachio-s18/kiss_tree
 */


typedef struct Node Node;

struct Node {

    struct Node* left_ptr;
    struct Node* right_ptr;

    char* word;
    int count;
};


Node* new_Node(int SHOW_DEBUG);
void destroy_Node(Node*, int SHOW_DEBUG);

Node* insert_node(Node*, char*, int SHOW_DEBUG);
void destroy_tree(Node*, Node*, int SHOW_DEBUG);

void list_tree_inorder_to_file(Node*, FILE*);


void tree_test_driver();



#endif //KISS_TREE_TREE_H
