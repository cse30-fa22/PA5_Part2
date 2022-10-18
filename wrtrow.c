#include <stdio.h>
#include "wrtrow.h"

/*
 * wrtrow
 *
 * usage:   given an array of pointers to columns and an array of columns to
 *          ouput and a count of output columns
 *          output those columns specified in the output array (contents are
 *          index numbers of the input array)
 * args:
 *  ptab    points at array of pointers each element points at a data field
 *  coltab  points array of ints each element is an index in ptab in print order
 *  outcols number of elements in array coltab
 *  outdelim the output field delimiter to use
 */
void
wrtrow(char **ptab, int *coltab, int outcols, char outdelim)
{
    /*
     * PA5part2 action: delete this comment
     * Hint
     * print all the columns execept the last one with a trailing delimiter
     * last column has a \n as the trailing delimiter
     */
}
