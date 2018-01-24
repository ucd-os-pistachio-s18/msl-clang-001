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

    int data;
};


Node* new_Node(int key);
void destroy_Node(Node*);

Node* insert_node(Node*, int);
void destroy_tree(Node*, Node*);

void list_tree_inorder(Node*);


void tree_test_driver();



#endif //KISS_TREE_TREE_H
