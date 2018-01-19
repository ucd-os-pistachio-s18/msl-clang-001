#ifndef MSL_CLANG_001_FILE_H
#define MSL_CLANG_001_FILE_H

/* FILE IO HEADER */


/* FUNCTION:  processFiles
 * RECEIVES:  INPUT FILENAME, OUTPUT FILENAME
 * RETURNS:   VOID
 * PERFORMS:  OPENS FILES, READS INPUTFILE, POPULATES TREE, WRITES OUTPUTFILE, CLOSES FILES
 */
void processFiles(const char* inputFilename, const char* outputFilename);


/* FUNCTION:  openFile
 * RECEIVES:  FILE POINTER, FILENAME, IO MODE
 * RETURNS:   VOID
 * PERFORMS:  TRIES TO OPEN FILE; PRINTS USAGE AND EXITS IF FILE NOT OPEN
 * NOTE:      DO NOT USE THIS FUNCTION
 */
void openFile(FILE *file_ptr, char* fileName, char* ioType);


/* FUNCTION:  closeFile
 * RECEIVES:  FILE POINTER
 * RETURNS:   VOID
 * PERFORMS:  CLOSES FILE
 * NOTE:      CRASHES.  DO NOT USE THIS FUNCTION
 */
void closeFile(FILE *file_ptr);





#endif
