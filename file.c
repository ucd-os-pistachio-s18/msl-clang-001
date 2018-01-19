
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



/* FUNCTION:  openFile
 * RECEIVES:  FILE POINTER, FILENAME, IO MODE
 * RETURNS:   VOID
 * PERFORMS:  TRIES TO OPEN FILE; PRINTS USAGE AND EXITS IF FILE NOT OPEN
 * NOTE:      DO NOT USE THIS FUNCTION
 */
void openFile(FILE *file_ptr, char* fileName, char* ioMode)
{

    printf("DEBUG:  Attempting to open file:  %s  as type:  %s \n", fileName, ioMode);


    /* TRY TO OPEN FILE */
    file_ptr = fopen(fileName, ioMode);


    /* PRINT USAGE AND EXIT IF FILE NOT OPEN */
    if (!file_ptr)
    {
        printUsageStatement();
        exit(1);
    }

    printf("DEBUG:  File opened successfully\n");


}

/* FUNCTION:  closeFile
 * RECEIVES:  FILE POINTER
 * RETURNS:   VOID
 * PERFORMS:  CLOSES FILE
 * NOTE:      CRASHES.  DO NOT USE THIS FUNCTION
 */
void closeFile(FILE *file_ptr)
{

    printf("DEBUG:  Closing file\n");


    /* CLOSE FILE */
    fclose(file_ptr);
}
