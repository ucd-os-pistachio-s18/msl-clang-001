#ifndef MSL_CLANG_001_TREE_H
#define MSL_CLANG_001_TREE_H

/* BINARY TREE HEADER */

/* THE CLIENT IS ASKING FOR A BALANCED BINARY SEARCH TREE.  WE WILL GIVE THE
 * CLIENT A BALANCED BINARY TREE IF THERE IS TIME, BUT WE BELIEVE THE CLIENT
 * WOULD BE JUST AS HAPPY WITH A DOUBLY-LINKED LIST.  WITH A DOUBLY-LINKED
 * LIST IN PLACE THE PROGRAM WILL FUNCTION PROPERLY, AND WE CAN MODIFY THE
 * DATA STRUCTURE LATER TO ACCOMMODATE THE CORRECT FUNCTIONALITY OF A BINARY
 * SEARCH TREE, AND LATER PROVIDE A BALANCING FUNCTION FOR SUCH.
 */


/* TODO: */

/* NODE STRUCT: */
    /* HAS POINTERS */
        /* IS A LEFT POINTER */
        /* IS A RIGHT POINTER */
        /* IS A PARENT POINTER */
            /* AS A LINKED LIST, PARENT POINTER WILL BE SET TO NULL */
    /* HAS DATA */
        /* IS AN INTEGER COUNT; INIT 0 */
        /* IS A CHAR ARRAY */
    /* HAS METHODS */
    /* NOTE: STRUCTS DO NOT HAVE DIRECT METHODS. STRUCTS HOWEVER CAN BE PASSED TO FUNCTIONS BY REFERENCE */
        /* CREATES A NODE IN MEMORY */
        /* SETS LEFT POINTER */
        /* SETS RIGHT POINTER */
        /* SETS PARENT POINTER */
        /* SETS DATA */
        /* INCREMENTS INTEGER COUNT DATA */
        /* REMOVES A NODE FROM MEMORY */

/* TREE STRUCT */
    /* HAS POINTERS */
        /* IS A ROOT POINTER */
            /* AS A LINKED LIST, ROOT POINTER WILL BE SET TO HEAD NODE FOR SIMPLICITY */
    /* HAS DATA */
        /* IS AN INTEGER COUNT OF NUMBER OF NODES IN TREE; INIT 0 */
    /* HAS METHODS */
    /* NOTE: STRUCTS DO NOT HAVE DIRECT METHODS. STRUCTS HOWEVER CAN BE PASSED TO FUNCTIONS BY REFERENCE */
        /* CREATES A TREE */
        /* INSERTS A NODE INTO TREE */
            /* INCREMENT INTEGER COUNT DATA FOR NODE */
        /* SEARCHES A TREE FOR DATA */
        /* LISTS ALL NODES IN TREE IN ORDER */
        /* REMOVES A NODE FROM TREE */
            /* FIRST THIS NODE MUST BE REMOVED FROM MEMORY */
        /* REMOVES ITSELF FROM MEMORY */
            /* FIRST ALL NODES HELD BY TREE MUST BE REMOVED FROM MEMORY */

void testTree();


#endif
