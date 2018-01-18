/* AUTHOR(S):  BRIAN SUMNER
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
 * Detailed Instructions
 *
 * Input
 *
 * The input will be a file containing a single line (i.e. no new lines) of
 * all-lower-case English words. You need to read it in to sort them. The
 * file will be in the same directory as your executable and will appear as
 * the first argument when your program is run. To test input files are
 * provided for you. A much larger file will be used in addition to test your
 * program.
 *
 * Output
 *
 * For each input file input01.txt, generate an output file in the same
 * directory, called myoutput01.txt. Use the provided output01.file to
 * compare against. The output should be an alphabetized list of unique words
 * and their counts in the file, as follows:
 *
 * one: 4
 * three: 5
 * years: 23
 *
 * Data structures
 *
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
 *
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
 *
 *
 */



#include <stdio.h>
#include <stdlib.h>

#include "tree.h"
#include "file.h"


int main(int argc, char **argv)
{

    printf("\n\nDEBUG:  Program has compiled successfully\n");
    testFileClass();
    testTreeClass();



    /* TODO: */

    /* INCLUDE DATA STRUCTURE HEADER AND IMPLEMENTATION */
    /* INCLUDE FILE IO HEADER AND IMPLEMENTATION */

    /* ACCEPT INPUT FILE AS COMMANDLINE ARGUMENT */
    /* READ FILE WORD-BY-WORD INTO BUFFER */
    /* BUILD TREE RECURSIVELY WHILE COUNTING WORD INSTANCES */
    /* PRINT TREE RECURSIVELY TO OUTPUT FILE */
    /* DESTROY TREE */

    exit(0);

}