#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// define a wordsize so that if we want to change it later it is easier
#define WORDSIZE 20

// function prototypes for the four functions used in this program 
void fillWithWords(char (*)[WORDSIZE], FILE *);
void printWords( char(*)[WORDSIZE], int);
void mylower( char[][20], int n);
int cmpfunc(const void*, const void*);

/* ===============================================================
    main
    main function of the program.
    Inputs: number of arguments and (hopefully) a filename
    Outputs: Calls a method to do the outputs
    Returns: 0 if all ran correctly, 1 otherwise
    Author: Elisabeth Henderson
=============================================================== */
int main (int argc, char **argv) {
    FILE *fileptr;      // file pointer to point to a file so it can be read
    int wordCount = 0;  // int variable to store the number of words 
    char ch = 'c';      // char variable to help find the number of words

    // if there are not enough input into the proram (ie there is no filename)
    // print an error message and quit out of the program
    if (argc != 2) {
        puts("You must enter a file name.");
        return (1);
    }

    // if the file cannot be found/opened to read, print an error message and
    // quit out of the program
    if ((fileptr = fopen(argv[1], "r")) == NULL) {
        puts("File could not be found.");
        return (1);
    }

    // while the fileptr is not at the end of the file, go through all the 
    // characters, if the character is a space or newline add one to wordCount
    // because those characters imply a new word
    while (!feof(fileptr)) {
        ch = fgetc(fileptr);
        if (ch == '\n' || ch == ' ') {
            wordCount++;
        }
    }

    // create an array to store the words and malloc the right amount of space
    // for it
    char *words;
    words = malloc(wordCount * WORDSIZE);
    
    // rewind the file so we can fill the array with words
    rewind(fileptr);

    // call the method fillWithWords to fill the array with words, it takes
    // the array to be filled, and the fileptr
    fillWithWords( (char(*)[WORDSIZE]) words, fileptr);

    // call qsort, it takes the array to be sorted, the number of items, the
    // size of each item, and the compare function
    qsort(words, wordCount, WORDSIZE, cmpfunc);
    
    // close the fileptr
    fclose(fileptr);

    // call mylower, which is an assembly function that takes the array and 
    // the number of elements in the array
    mylower((char(*) [WORDSIZE]) words, wordCount);

    // call print words to print all the words in the array
    printWords( (char(*)[WORDSIZE]) words, wordCount);

    // return 0 if everything is good
    return (0);
}

/* ===============================================================
    fillWithWords
    Takes an array and a fileptr and fills the array with the words in the file
    Inputs: char[][] words - the array to be filled
            file *ptr - the pointer to the file
    Outputs: None
    Returns: None
    Author: Elisabeth Henderson
=============================================================== */
void fillWithWords( char words[][WORDSIZE], FILE *ptr) {
    int i = 0;              // int i for counting
    char word[WORDSIZE];    // temp char array to store a word
    
    // while there are more words to scan, scan a word and store it into word
    while (fscanf(ptr, "%s", word) == 1) {
        // then store word into words[i] and increment i
        strcpy(words[i], word);
        i++;
    }
}

/* ===============================================================
    printWords
    Prints the words in the array using a for loop
    Inputs: char [][] words - the array to be printed
            int count - the number of elements in the array
    Outputs: Prints the array to stdout
    Returns: None
    Author: Elisabeth Henderson
=============================================================== */
void printWords( char words[][WORDSIZE], int count) {
    for (int i = 0; i < count; i++) {
        printf("%s\n", words[i]);
    }
}

/* ===============================================================
    cmpfunc
    The function used for camparison for qsort, just does some typecasting so
    utimately strcmp can be called
    Inputs: const void *a 
            const void *b
    Outputs: None
    Returns: The result of strcmp when called with the two passed parameters, 
             afterthey have been cast
    Author: Elisabeth Henderson
=============================================================== */
int cmpfunc(const void *a, const void *b) {
    char *one = (char*)a;
    char *two = (char*)b;
    return strcmp(one, two);
}
