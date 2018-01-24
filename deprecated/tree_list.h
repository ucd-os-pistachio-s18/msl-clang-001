#ifndef MSL_CLANG_001_TREE_LIST_H
#define MSL_CLANG_001_TREE_LIST_H



Tree* new_tree_list();
void destroy_tree_list(Tree*);
void destroy_node_list(Node *);
void tree_list_insert(char*, Tree*);
void insert_list(char*, Node*);
Node* new_node_list(char*, Node*);
char* get_word_list(Node*);





#endif //MSL_CLANG_001_TREE_LIST_H
