#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// defines a max and min number so we can easily change it later if we want
#define NUM_MAX 999
#define NUM_MIN -999

// function prototypes for the two functions used in the program
void findPrintSolutions(int, int, int);
int segments(int);

/* ===============================================================
   main
   main function of the program.
Inputs: number of arguments and (hopefully) a filename
Outputs: Reads the file and calls some methods to do some of the outputs
Returns: 0 if all ran correctly, 1 otherwise
Author: Elisabeth Henderson
=============================================================== */

int main(int argc, char **argv) {
    FILE *fileptr;      // file pointer to point to a file so it can be read

    // if there are not enough inputs into the program (ie there is no filename)
    // print an error message and quit out of the program
    if (argc != 2) {
        puts("You must enter a file name.");
        return (1);
    }

    // if the file cannot be found/opened to read, print an error message and 
    // quit out of the program
    if ((fileptr = fopen(argv[1], "r")) == NULL) {
        puts("File could not be opened.");
        return (1);
    }

    // int variables to assist in reading values from the file
    int x = 0;
    int y = 0;
    int z = 0;

    // more int variable to store the number of segments in the values read 
    // the file
    int segx = 0;
    int segy = 0;
    int segz = 0;

    // while the fileptr is not at the end of the file, read through the file
    // and read it line by line. If a value on a line it out of range, just 
    // skip it, if a line is invalid (ie not enough varaibles or random strings)
    // quit out of the program and report and error
    while (!feof(fileptr)) {
        // check to make sure enough data is read
        if ((fscanf(fileptr, "%d %d %d", &x, &y, &z) == 3)) { 
            // check to ensure all number are in range, continue if they are 
            // out of range
            if ( x > NUM_MAX || y > NUM_MAX || z > NUM_MAX ||
                    x < NUM_MIN || y < NUM_MIN || z < NUM_MIN) {
                continue;
            }
            else {
                // divide all numbers by 5 to get the number of segments lit up
                // for each number
                segx = x / 5;
                segy = y / 5;
                segz = z / 5;

                // call method to find and print all solutions to the console
                findPrintSolutions(segx, segy, segz);
            }
        }
        else {
            // if x == 0, we have reach the end of the file
            if (x == 0) {
                return (0);
            }
            // if something is wrong so print an error message and break 
            // out of loop
            else {
                //        printf("%d, %d, %d\n", x, y,z);
                puts("Error. Terminating program.");
                break;
            }
        }
    }

    // return 0 if all is good
    return (0);
} // end main()


/* ===============================================================
   findPrintSolutions
   Goes through all possible numbers in the ranges, finds those with the same
   number of segments as passed, and then check to see if any found x and y
   equal z with any given operator
Inputs: int segx - the number of segments in the first operator 
int segy - the number of segments in the second operator
int segz - the number of segments in the result
Outputs: The operation if x * or / or + or - y = z. Also the total number
of solutions
Returns: None
Author: Elisabeth Henderson
=============================================================== */
void findPrintSolutions(int segx, int segy, int segz) {
    int numSol = 0; // int variable to count the number of solutions found

    // thses for loops will go through all possible combinations of solutions
    // to the given set of numbers, in total it is a triple for loop, each
    // for going from -999 to 999
    for (int i = NUM_MIN; i < NUM_MAX; i++) {

        // int varaible to store the number of segment in i a possible operator
        // calls and assembly method
        int segi = segments((i));

        // if the number of segments in i does not equal the passed value
        // go onto the next interation of this loop
        if (segi != segx) 
            continue;
        for (int j = NUM_MIN; j < NUM_MAX; j++) {

            // int variable to store the number of segments in j a possible 
            // second operator, calls and assembly method
            int segj = segments((j));

            // if the number of segments in j does not equal the passed value
            // for the second operator, skip to the next iteration of this loop
            if (segj != segy) 
                continue;
            for (int k = NUM_MIN; k < NUM_MAX; k++) {

                // int variable to stopre the number of segments in k, a 
                // possible result, calls an assemby method
                int segk = segments((k));

                // if the number of segments in k is not equal to the passed
                // value, skip to the next iteration of this loop
                if (segk != segz)
                    continue;
                // check all possible mathimatical operations, print it and 
                // add one to numSol if it works
                
                if ((i + j) == k) { 
                    printf("%d + %d = %d\n", i, j, (i + j));
                    numSol++;
                }
                if ((i - j) == k) {
                    printf("%d - %d = %d\n", i, j, (i - j));
                    numSol++;
                }
                if ((i * j) == k) {
                    printf("%d * %d = %d\n", i, j, (i * j));
                    numSol++;
                }
                if ((i / j) == k) {
                    printf("%d / %d = %d\n", i, j, (i / j)); 
                    numSol++;
                }
            }
        }
    }

    // if the number of solutions is 0, print none
    if (numSol == 0) {
        puts("None.");
    }
    // if it is one, print 1 solution
    else if (numSol == 1) {
        puts("1 solution.");
    }
    // else just print the number of solutions
    else {
        printf("%d solutions.\n", numSol);
    }
} // end findPrintSolutions()
