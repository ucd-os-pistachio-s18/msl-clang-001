/*
 * COLLABORATORS:  BRIAN SUMNER, NIKKI YESALUSKY
 * GROUP: UCD-OS-PISTACHIO-S18
 *
 * UCDENVER CSCI 3453
 * SPRING 2018
 *
 * C PROGRAMMING ASSIGNMENT 1
 * https://github.com/ucd-os-pistachio-s18/msl-clang-001
 *
 */



/*
 * REFERENCE MATERIAL CITED:
 *
 * File I/O:
 * https://www.codingunit.com/c-tutorial-file-io-using-text-files
 * https://cboard.cprogramming.com/c-programming/16069-getword.html
 *
 * Usage statements:
 * http://courses.cms.caltech.edu/cs11/material/c/mike/misc/c_style_guide.html
 *
 * String tools:
 * https://www.tutorialspoint.com/c_standard_library/string_h.htm
 * http://en.cppreference.com/w/c/string/byte
 *
 * Structs:
 * https://www.codingunit.com/c-tutorial-structures-unions-typedef
 * https://stackoverflow.com/questions/3988041/how-to-define-a-typedef-struct-containing-pointers-to-itself
 * https://www.cprogramming.com/
 * https://www.gnu.org/software/gnu-c-manual/gnu-c-manual.html
 *
 * Tree traversal:
 * https://www.geeksforgeeks.org/tree-traversals-inorder-preorder-and-postorder/
 */



/*
 * Detailed Instructions
 *
 * Input
 * The input will be a file containing a single line (i.e. no new lines) of
 * all-lower-case English words. You need to read it in to sort them. The
 * file will be in the same directory as your executable and will appear as
 * the first argument when your program is run. To test input files are
 * provided for you. A much larger file will be used in addition to test your
 * program.
 *
 * Output
 * For each input file input01.txt, generate an output file in the same
 * directory, called myoutput01.txt. Use the provided output01.file to
 * compare against. The output should be an alphabetized list of unique words
 * and their counts in the file, as follows:
 * one: 4
 * three: 5
 * years: 23
 *
 * Data structures
 * You should use a binary tree to keep the running count for words and keep
 * them in alphabetical order. This means that if you have four words, say
 * one, two, three, go, one, that come in this order, you will end up with a
 * tree that looks like:
 *
 *    one(2)
 *  /     \
 * go(1)  two(1)
 *        /
 *     three(1)
 *
 * Think what traversal you need to print the words in the tree in
 * alphabetical order.
 *
 * The tree has to be a self-referential C struct, containing a dynamically
 * allocated word, its integer count, and pointers to the left and right
 * subtrees. In other words, a tree is equivalent to a single node of the
 * tree.
 *
 * Functionality
 * 1.  Read words from the file. Don't read in the whole file and then
 *     process it. Read it in chunks using a buffer.
 * 2.  Tree lookup for the next word in the input.
 * 3.  If a word is in the tree, increment the count; if it isn't,
 *     dynamically allocate a new node; position and link it properly, and
 *     initialize the count to 1.
 * 4.  When you are done with the input, you should have a complete tree. Use
 *     it to print out the output file.
 * 5.  Destroy the tree, making sure you free() dynamic structures in the
 *     proper order.
 * 6.  Your tree functions should be recursive.
 */



#include <stdio.h>
#include <stdlib.h>
#include "tree.h"
#include "file.h"

/* GLOBAL CONSTANT DEFINITIONS: */
const char* USAGE_STATEMENT = "\n\n\nPROGRAM USAGE:  msl-clang-001.exe inputfile.txt <outputfile.txt> \n"
                              "\nNOTE:  If none is specified, the default outputfile will be: ";

const char* DEFAULT_OUTPUTFILENAME = "myoutput01.txt";

const int BUFFER_SIZE = 127;  /* THIS IS A DECIDEDLY EXCESSIVE SIZE */

const int SHOW_DEBUG = 1; /* 1 TURNS ON DEBUG MESSAGES; 0 TURNS OFF DEBUG MESSAGES */


/* FUNCTION DECLARATIONS */
void printUsageStatement();

int main(int argc, char **argv)
{

    /* TASKS: */

    /* PRINT USAGE STATEMENT IF ARGUMENTS ARE INVALID */
    /* ACCEPT INPUT FILE AS COMMANDLINE ARGUMENT */
        /* TEST IF FILE EXISTS */
            /* IF FILE DOES NOT EXIST, PRINT USAGE STATEMENT AND EXIT */
        /* OPEN FILE */
    /* READ FILE WORD-BY-WORD INTO BUFFER */
        /* BUILD TREE RECURSIVELY WHILE COUNTING WORD INSTANCES */
    /* PRINT TREE RECURSIVELY TO OUTPUT FILE */
    /* DESTROY TREE */
    /* CLOSE FILES */


    /* IMPLEMENTATION: */


    /* VARIABLE DECLARATIONS: */
    FILE *inputFile_ptr;
    FILE *outputFile_ptr;


    /* PRINT USAGE STATEMENT IF ARGUMENTS ARE INVALID */
    switch (argc)
    {
        case 2:
            if (SHOW_DEBUG) printf("DEBUG:  There is 1 commandline argument:\n");
            if (SHOW_DEBUG) printf("DEBUG:  %s %s \n\n", argv[0], argv[1]);

            processFiles((const char*)argv[1], DEFAULT_OUTPUTFILENAME, BUFFER_SIZE, SHOW_DEBUG);
            break;

        case 3:
            if (SHOW_DEBUG) printf("DEBUG:  There are 2 commandline arguments:\n");
            if (SHOW_DEBUG) printf("DEBUG:  %s %s %s \n\n", argv[0], argv[1], argv[2]);

            processFiles((const char*)argv[1], (const char*)argv[2], BUFFER_SIZE, SHOW_DEBUG);
            break;

        default:
            printUsageStatement();
            exit(1);
    }



    if (SHOW_DEBUG)  printf("\nDEBUG:  Program execution complete. \n");
    exit(0);

}

void printUsageStatement()
{

    printf("%s %s \n\n\n", USAGE_STATEMENT, DEFAULT_OUTPUTFILENAME);

}
