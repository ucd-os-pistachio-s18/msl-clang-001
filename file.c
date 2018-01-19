
/* FILE IO IMPLEMENTATION */

#include <stdio.h>
#include <stdlib.h>
#include "file.h"


/* FUNCTION:  processFiles
 * RECEIVES:  INPUT FILENAME, OUTPUT FILENAME
 * RETURNS:   VOID
 * PERFORMS:  OPENS FILES, READS INPUTFILE, POPULATES TREE, WRITES OUTPUTFILE, CLOSES FILES
 */
void processFiles(const char* inputFilename, const char* outputFilename)
{

    /* VARIABLE DECLARATIONS: */
    FILE *inputFile_ptr;
    FILE *outputFile_ptr;

    printf("DEBUG:  Attempting to open input file:   %s \n", inputFilename);
    printf("DEBUG:  Attempting to open output file:  %s \n", outputFilename);

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
