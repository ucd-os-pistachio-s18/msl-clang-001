#ifndef MSL_CLANG_001_FILE_H
#define MSL_CLANG_001_FILE_H

/* FILE IO HEADER */


#include "tree.h"

/* FUNCTION:  processFiles
 * RECEIVES:  INPUT FILENAME, OUTPUT FILENAME, BUFFER SIZE, SHOW DEBUG BOOLEAN
 * RETURNS:   VOID
 * PERFORMS:  OPENS FILES, READS INPUTFILE, POPULATES TREE, WRITES OUTPUTFILE, CLOSES FILES
 */
void processFiles(const char* inputFilename, const char* outputFilename, const int BUFFER_SIZE, const int SHOW_DEBUG);


/* FUNCTION:  getWords
 * RECEIVES:  INPUTFILE POINTER, TREE POINTER, BUFFER_SIZE, SHOW DEBUG BOOLEAN
 * RETURNS:   VOID
 * PERFORMS:  READS ENTIRE INPUTFILE AND TOKENIZES TEXT INTO WORDS
 */
void getWords(FILE*, FILE*,  Tree* tree, const int BUFFER_SIZE, const int SHOW_DEBUG);


/* FUNCTION:  sendWordToTree
 * RECEIVES:  WORD, TREE, SHOW DEBUG BOOLEAN
 * RETURNS:   TBD
 * PERFORMS:  SENDS WORD TO INSERT IN TREE
 */
void sendWordToTree(char* word, FILE* file, Tree* tree, int SHOW_DEBUG);



/* FUNCTION:  outputTreeToFile
 * RECEIVES:  TBD, OUTPUTFILE POINTER, SHOW DEBUG BOOLEAN
 * RETURNS:   TBD
 * PERFORMS:  LISTS TREE CONTENTS AND STORES IN OUTPUT FILE
 */
void outputTreeToFile(FILE *file_ptr, Tree* tree, int SHOW_DEBUG);


void temp_print_nodes_in_order(Node *);
void temp_print_tree_in_order(Tree*);



#endif
