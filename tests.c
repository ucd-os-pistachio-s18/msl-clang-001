#include <stdio.h>
#include "tests.h"
#include "tree.h"

char* word1 = "cat";
char* word2 = "dog";
char* word3 = "elephant";
char* word4 = "supercalifragilisticexpealidocious";
char* word5 = "a very simple input file for you to test your code it really does not matter how big the file is as long as it is not too big to fit in memory your code should work with any size that fits so do not try to read the whole file in one gulp";
char* debug_message;

void node_create(tests* test){
    debug_message = "The node was not able to be created";
    Node* node_root = 0;
    Node* node_tmp;
    int i = new_node(word1, node_root);
    if (i == 0){
        printf("%s/n", debug_message);
    }
    else{
        printf("The node was created.");
        test->passed = test->passed + 1;
        destroy_node(node_root);
    }
}
void node_insertion(tests* test){
    debug_message = "The word was not able to be inserted";
    Node* node_root = 0;
    Node* node_tmp;
    int i = new_node(word1, node_root);
    if (i == 0){
        printf("%s/n", debug_message);
    }
    else{
        printf("The word was inserted.");
        test->passed = test->passed + 1;
        destroy_node(node_root);
    }
}

//void node_get_word(tests* test){}
//void node_get_count(tests* test){}
//void node_print_inorder(tests* test){}
//
//void tree_create(tests* test){}
//void tree_insertion(tests* test){}
//void tree_print(tests* test){}