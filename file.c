
/* FILE IO IMPLEMENTATION */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "file.h"


/* FUNCTION:  processFiles
 * RECEIVES:  INPUT FILENAME, OUTPUT FILENAME, BUFFER_SIZE, SHOW DEBUG BOOLEAN
 * RETURNS:   VOID
 * PERFORMS:  OPENS FILES, READS INPUTFILE, POPULATES TREE, WRITES OUTPUTFILE, CLOSES FILES
 */
void processFiles(const char* inputFilename, const char* outputFilename, const int BUFFER_SIZE, const int SHOW_DEBUG)
{

    /* VARIABLE DECLARATIONS: */
    FILE *inputFile_ptr;
    FILE *outputFile_ptr;


    /* TRY TO OPEN INPUT FILE */
    if (SHOW_DEBUG) printf("DEBUG:  Attempting to open input file:   %s \n", inputFilename);
    inputFile_ptr = fopen(inputFilename, "r");

    /* PRINT USAGE AND EXIT IF FILE NOT OPEN */
    if (!inputFile_ptr)
    {
        printUsageStatement();
        exit(1);
    }

    if (SHOW_DEBUG) printf("DEBUG:  Input file opened successfully\n");



    /* TRY TO OPEN OUTPUT FILE */
    if (SHOW_DEBUG) printf("DEBUG:  Attempting to open output file:  %s \n", outputFilename);
    outputFile_ptr = fopen(outputFilename, "w");

    /* PRINT USAGE AND EXIT IF FILE NOT OPEN */
    if (!outputFile_ptr)
    {
        printUsageStatement();
        exit(1);
    }

    if (SHOW_DEBUG) printf("DEBUG:  Output file opened successfully\n");




    /* GET WORDS */
    getWords(inputFile_ptr, BUFFER_SIZE, SHOW_DEBUG);



    /* OUTPUT TREE TO FILE */
    outputTreeToFile(outputFile_ptr, SHOW_DEBUG);



    /* CLOSING FILES */
    if (SHOW_DEBUG) printf("\nDEBUG:  Closing files\n");
    fclose(inputFile_ptr);
    fclose(outputFile_ptr);
    if (SHOW_DEBUG) printf("DEBUG:  File closed successfully \n");


}


/* FUNCTION:  getWords
 * RECEIVES:  INPUTFILE POINTER, BUFFER_SIZE, SHOW DEBUG BOOLEAN
 * RETURNS:   VOID
 * PERFORMS:  READS ENTIRE INPUTFILE AND TOKENIZES TEXT INTO WORDS
 */
void getWords(FILE *file_ptr, const int BUFFER_SIZE, const int SHOW_DEBUG)
{
    /*

    /* VARIABLE DECLARATIONS: */
    int rawChar = 0;
    char* readBuffer[BUFFER_SIZE];

    if (SHOW_DEBUG)  printf("\nDEBUG:  Begin getting words with buffer size:  %d \n", BUFFER_SIZE);

    /* INIT RAW CHAR */
    rawChar = fgetc(file_ptr);

    /* DO WHILE NOT EOF */
    while (rawChar != EOF)
    {
        /* TEST IF RAW CHAR IS NOT ALPHANUMERIC */
        if (!isalnum((char)rawChar))
        {
            rawChar = (int)'_';
        }

        if (SHOW_DEBUG)  printf("%c", (char)rawChar);

        /* GET NEXT RAW CHAR */
        rawChar = fgetc(file_ptr);
    }

    if (SHOW_DEBUG)  printf("\nDEBUG:  Reached end-of-file \n");

}



/* FUNCTION:  sendWordToTree
 * RECEIVES:  TBD, SHOW DEBUG BOOLEAN
 * RETURNS:   TBD
 * PERFORMS:  SENDS WORD TO INSERT IN TREE
 */
void sendWordToTree(int SHOW_DEBUG)
{
    if (SHOW_DEBUG)  printf("\nDEBUG:  Sent word to tree:  \n");
}



/* FUNCTION:  outputTreeToFile
 * RECEIVES:  TBD, OUTPUTFILE POINTER, SHOW DEBUG BOOLEAN
 * RETURNS:   TBD
 * PERFORMS:  LISTS TREE CONTENTS AND STORES IN OUTPUT FILE
 */
void outputTreeToFile(FILE *file_ptr, int SHOW_DEBUG)
{
    if (SHOW_DEBUG) printf("\nDEBUG:  Listing tree to output file \n");
}
