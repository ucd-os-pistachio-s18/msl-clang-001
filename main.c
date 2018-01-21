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

int main(int argc, char** argv)
{
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
