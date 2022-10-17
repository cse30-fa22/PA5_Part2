/*
 * Programming assignment 4 sample solution
 */ 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include "token.h"
#include "wrtrow.h"

/*
 * main
 */ 
int 
main(int argc, char **argv)
{
    char **ptable;              /* array of pointers to column starts */
    int  *coltab;               /* array of column indexes to print */
    char buf[BUFSZ];            /* input buffer */       
    unsigned long linecnt = 0;  /* input line counter */
    unsigned long dropcnt = 0;  /* number of input lines dropped counter */
    int incols = 0;             /* number of columns in the input */
    int outcols = 0;            /* number of columns in the output */
    char *ptr;                  /* pointer for use by strtoul() */
    int opt;                    /* option flag returns by getopt */
    char indelim = INDELIM;     /* input delimter set to default */
    char outdelim = OUTDELIM;   /* ouput delimter set to default */
    int  *colptr;               /* pointer to coltab  */


    /*
     * parse the options with getopt
     */
    while ((opt = getopt(argc, argv, "c:i:o:")) != -1) {
        switch (opt) {
        case 'c':
            /*
             * number of columns in dsv file must be greater than MINCOL
             */

             /* PA5 action: delete this comment and complete this section
              * use the following error message and return with EXIT_FAILURE
              * fprintf(stderr, "%s: improper input column count\n", *argv);
              */
            break;
        case 'i':
            /*
             * set the input delimiter
             */
             /* PA5 action: delete this comment and complete this section
              * use the following error message and return with EXIT_FAILURE
              * fprintf(stderr, "%s: -i operand must be a single char\n", *argv);
              */
            break;
        case 'o':
            /*
             * set the output delimiter
             */
             /* PA5 action: delete this comment and complete this section
              * use the following error message and return with EXIT_FAILURE
              * fprintf(stderr, "%s: -o operand must be a single char\n", *argv);
              */
            break;
        case '?':
            /* FALL THROUGH */
        default:
            fprintf(stderr,
                "Usage: %s -c count [-i inputdelim] [-o outputdelim] col [..]\n",
                *argv);
            return EXIT_FAILURE;
            /* NOT REACHED */
        }
    }

    /*
     * check that we saw the -c flag
     */

    /* PA5 action: delete this comment and complete this section
     * use the following error message and return with EXIT_FAILURE 
     * fprintf(stderr,
     *     "Usage: %s -c count [-i inputdelim] [-o outputdelim] col [..]\n", *argv);
     */

    /*
     * make sure there is at least one output colmn specified
     */
    if ((outcols = argc - optind) <= 0) {
        fprintf(stderr,"%s: at least one output column required\n", *argv);
        return EXIT_FAILURE;
    }

    /*
     * allocate space for the input pointer table using incols
     * if unable to allocate, return with EXIT_FAILURE
     */
    /* PA5 action: delete this comment and complete this section
     * use the following error message and return with EXIT_FAILURE 
     * fprintf(stderr, "%s: malloc() failed input table\n", *argv);
     */

    /*
     * allocate space for the output table, an array of index offsets
     * into ptable using outcols
     */
    /* PA5 action: delete this comment and complete this section
     * use the following error message and return with EXIT_FAILURE 
     * fprintf(stderr, "%s: malloc() failed output index table\n", *argv);
     */

    /*
     * fill in the index table
     * and check that the columns specified are valid
     * 1 or greater and less than equal to incols)
     */
    /* PA5 action: delete this comment and complete this section
     * use the following error message and return with EXIT_FAILURE 
     * fprintf(stderr, "%s: improper output column value\n", *argv);
     */

    /*
     * read the input one line at a time, break into tokens and write out the
     * selected columns
     */
    while (fgets(buf, BUFSZ, stdin)  != NULL) {
        linecnt++;

        /*
         * break the input into data fields pointed at by array ptable
         */
        if (token(buf, indelim, incols, ptable, linecnt, *argv) != 0)
            dropcnt++;        /* count the dropped rows */
        else
           wr_row(ptable, coltab, outcols, outdelim);
    }

    /*
     * free buffers to keep valgrind happy
     */
    /* PA5 action: delete this comment and complete this section */

    /*
     * write summary
     */
    fprintf(stderr, "%s: %lu records input, %lu dropped\n", *argv,
            linecnt, dropcnt);
    if (dropcnt > 0)
        return EXIT_FAILURE;
    return EXIT_SUCCESS;
}
