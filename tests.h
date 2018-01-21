#ifndef MSL_CLANG_001_TESTS_H
#define MSL_CLANG_001_TESTS_H

#include "tree.h"

const int test_count = 0;
struct tests{
    int passed;
    int failed;
};

/* note: destructors will be called at the end of each test */
void node_create();
void node_insertion();
void node_get_word();
void node_get_count();
void node_print_inorder();

void tree_create();
void tree_insertion();
void tree_print();

#endif //MSL_CLANG_001_TESTS_H
