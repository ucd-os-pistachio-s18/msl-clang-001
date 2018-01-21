#ifndef MSL_CLANG_001_TESTS_H
#define MSL_CLANG_001_TESTS_H

typedef struct tests tests;

const int tests_count = 8;

struct tests{
    int passed;
    double rate;
};

void pass_fail_rate(tests* test){
    int i = test->passed;
    test->rate = i / tests_count;
}

/* note: destructors will be called at the end of each test */
void node_create(tests*);
void node_insertion(tests*);
void node_get_word(tests*);
void node_get_count(tests*);
void node_print_inorder(tests*);

void tree_create(tests*);
void tree_insertion(tests*);
void tree_print(tests*);

#endif //MSL_CLANG_001_TESTS_H
