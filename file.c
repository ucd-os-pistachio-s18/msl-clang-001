
/* FILE IO IMPLEMENTATION */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "file.h"
#include "old_tree.h"


/* FUNCTION:  processFiles
 * RECEIVES:  INPUT FILENAME, OUTPUT FILENAME, BUFFER_SIZE, SHOW DEBUG BOOLEAN
 * RETURNS:   VOID
 * PERFORMS:  OPENS FILES, READS INPUTFILE, POPULATES TREE, WRITES OUTPUTFILE, CLOSES FILES
 */
void processFiles(const char* inputFilename, const char* outputFilename, const int BUFFER_SIZE, const int SHOW_DEBUG)
{

    /* VARIABLE DECLARATIONS: */
    FILE* inputFile_ptr;
    FILE* outputFile_ptr;

    /* ALLOCATE TREE */
    Tree* tree;
    tree = new_tree();


    /* TRY TO OPEN INPUT FILE */
    if (SHOW_DEBUG) printf("DEBUG:  Attempting to open input file:   %s \n", inputFilename);
    inputFile_ptr = fopen(inputFilename, "r");

    /* PRINT USAGE AND EXIT IF FILE NOT OPEN */
    if (!inputFile_ptr)
    {
        printUsageStatement();
        exit(1);
    }

    if (SHOW_DEBUG) printf("DEBUG:  Input file opened successfully. \n");



    /* TRY TO OPEN OUTPUT FILE */
    if (SHOW_DEBUG) printf("DEBUG:  Attempting to open output file:  %s \n", outputFilename);
    outputFile_ptr = fopen(outputFilename, "w");

    /* PRINT USAGE AND EXIT IF FILE NOT OPEN */
    if (!outputFile_ptr)
    {
        printUsageStatement();
        exit(1);
    }

    if (SHOW_DEBUG) printf("DEBUG:  Output file opened successfully. \n");




    /* GET WORDS */
    getWords(inputFile_ptr, outputFile_ptr, tree, BUFFER_SIZE, SHOW_DEBUG);



    /* OUTPUT TREE TO FILE */
    outputTreeToFile(outputFile_ptr, tree, SHOW_DEBUG);



    /* CLOSING FILES */
    if (SHOW_DEBUG) printf("\nDEBUG:  Closing files... \n");
    fclose(inputFile_ptr);
    fclose(outputFile_ptr);
    if (SHOW_DEBUG) printf("DEBUG:  Files closed successfully. \n");


    /* DESTROY TREE */
    if (SHOW_DEBUG) printf("\nDEBUG:  Destroying tree... \n");
    destroy_tree(tree);

}


/* FUNCTION:  getWords
 * RECEIVES:  INPUTFILE POINTER, TREE POINTER, BUFFER_SIZE, SHOW DEBUG BOOLEAN
 * RETURNS:   VOID
 * PERFORMS:  READS ENTIRE INPUTFILE AND TOKENIZES TEXT INTO WORDS
 */
void getWords(FILE *inputFile_ptr, FILE* outputFile_ptr, Tree* tree, const int BUFFER_SIZE, const int SHOW_DEBUG)
{
    /* VARIABLE DECLARATIONS: */
    int rawChar = 0;
    int wordLength = 0;
    char readBuffer[BUFFER_SIZE + 1]; /* NOTE: Last index = BUFFER_SIZE */

    /* INIT BUFFER */
    memset(readBuffer, (int)'\0', BUFFER_SIZE + 1); /* NOTE: This is the actual size of the buffer space */


    /* getWords WILL HANDLE THE FOLLOWING INPUT CASES:
     *
     * 1.  EMPTY FILE - INIT RAWCHAR IS EOF
     * 2.  NON-EMPTY FILE WITH NO ALPHANUM WORDS
     * 3.  FILE HAS WORD(S) WITH NON-ALPHANUM PRECEDING EOF
     * 4.  FILES HAS WORD(S) WITH ALPHANUM PRECEDING EOF
     *
     *
     * USING THE FOLLOWING TECHNIQUES:
     *
     * 1.  DO NOTHING.  WHILE LOOP WILL NOT RUN.
     * 2.  DO NOTHING.  WORDLENGTH WILL NEVER EXCEED 0.
     * 3.  SEND LAST WORD INSIDE WHILE LOOP.  LOOP WILL EXIT WITH WORDLENGTH == 0.
     * 4.  SEND LAST WORD AFTER WHILE LOOP.  LOOP WILL EXIT WITH WORDLENGTH > 0.
     *
     */


    if (SHOW_DEBUG)  printf("\nDEBUG:  Getting words from input file with buffer size:  %d \n", BUFFER_SIZE);

    /* INIT RAW CHAR */
    rawChar = fgetc(inputFile_ptr);

    /* DO WHILE NOT EOF */
    while (rawChar != EOF)
    {
        /* TEST IF RAW CHAR IS ALPHANUMERIC (PART OF A WORD) */
        if (isalnum((char)rawChar))
        {
            /* RAW CHAR IS PART OF A WORD: */


            /* DO NOT OVERWRITE FINAL \0 AT readBuffer[BUFFER_SIZE] */
            if (wordLength < BUFFER_SIZE)
            {
                /* USE wordLength AS INDEX - FIRST CHAR IN WORD IS ALWAYS INDEX 0 */
                readBuffer[wordLength] = (char)rawChar;

                /* INCREMENT WORD LENGTH */
                ++wordLength;
            }
        }
        else
        {
            /* RAW CHAR IS NOT PART OF A WORD: */


            /* TEMPORARY STATEMENT; NOT FOR FINAL PRODUCT */
            /* rawChar = (int)'_'; */


            /* TEST IF A WORD IS STORED IN BUFFER */
            if (wordLength > 0)
            {
                /* BUFFER DOES HOLD A WORD */

                /* SEND WORD TO TREE */
                sendWordToTree(readBuffer, outputFile_ptr, tree, SHOW_DEBUG);

                /* RESET BUFFER AND WORDLENGTH */
                memset(readBuffer, (int) '\0', BUFFER_SIZE + 1); /* NOTE: This is the actual size of the buffer space */
                wordLength = 0;
            }
        }

        /* EARLY REVISION DEBUG STATEMENT; NOT FOR FINAL PRODUCT */
        /* if (SHOW_DEBUG)  printf("%c", (char)rawChar); */


        /* GET NEXT RAW CHAR IN FILE */
        rawChar = fgetc(inputFile_ptr);

    /* END WHILE LOOP */
    }


    /* TEST IF LAST WORD IS STORED IN BUFFER */
    if (wordLength > 0)
    {
        /* BUFFER DOES HOLD A WORD */

        /* SEND WORD TO TREE */
        sendWordToTree(readBuffer, outputFile_ptr, tree, SHOW_DEBUG);

        /* RESET BUFFER AND WORDLENGTH (UNNECESSARY BUT DO IT ANYWAY) */
        memset(readBuffer, (int) '\0', BUFFER_SIZE + 1); /* NOTE: This is the actual size of the buffer space */
        wordLength = 0;
    }



    if (SHOW_DEBUG)  printf("DEBUG:  Reached END-OF-FILE for input file. \n");

}



/* FUNCTION:  sendWordToTree
 * RECEIVES:  WORD, TREE, SHOW DEBUG BOOLEAN
 * RETURNS:   TBD
 * PERFORMS:  SENDS WORD TO INSERT IN TREE
 */
void sendWordToTree(char* word, FILE* file, Tree* tree, int SHOW_DEBUG)
{
    int count = 1;


    tree_insert(word, tree);

    if (SHOW_DEBUG)  printf("DEBUG:  Sent word to tree:  %s \n", word);

    /* SEND TO OUTPUT FILE */
    fprintf(file, "%s: %d \n", word, count);
}



/* FUNCTION:  outputTreeToFile
 * RECEIVES:  OUTPUTFILE POINTER, TREE, SHOW DEBUG BOOLEAN
 * RETURNS:   TBD
 * PERFORMS:  LISTS TREE CONTENTS AND STORES IN OUTPUT FILE
 */
void outputTreeToFile(FILE *file_ptr, Tree* tree, int SHOW_DEBUG)
{
    if (SHOW_DEBUG) printf("\nDEBUG:  Printing tree in order... \n");

    print_tree(tree);

    if (SHOW_DEBUG) printf("DEBUG:  Finished printing tree in order. \n");

}




/* temporary version of prints the tree in order */
/*
 * void temp_print_nodes_in_order(Node *root){

    printf("DEBUG:  Printing nodes starting at root:  %d. \n", root);
    /* if there is no tree, don't print anything *
    if(root != 0){
        temp_print_nodes_in_order(root->left_ptr);
        printf("%s", get_word(root));
        int i = get_count(root);
        char* tmp = " : ";
        tmp = tmp + (char)i;
        temp_print_nodes_in_order(root->right_ptr);
    }
}

/* prints a tree in order *
void temp_print_tree_in_order(Tree* tree){
    temp_print_nodes_in_order(tree->root_ptr);
}
*/