#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// function prototypes for the two functions used in this program besides main
void rotate (char [][4]);
char encrypt (char, char [][4]);

/* ===============================================================
   main
   main function of the program. 
Inputs: None
Outputs: Prints encrypted text and table used to encrypt the text to a file
Returns: 0 if all ran correctly, 1 otherwise
Author: Elisabeth Henderson
=============================================================== */
int main() {

    char table[4][4];   // char[][] to store the table which will be used to 
                        // encrypt the text
    int ch;             // ch variable to store the current character

    char String[16];    // String to validate the data

    // read in the character representation of the table from the file into
    // a char 2d array to validate the data 
    scanf("%s", String); 

    // check to insure data is valid. if not print an error message and quit
    if (strlen(String) != 16) {
        printf("Error. Table is not large enough.\n");
        return 1;
    }

    // if the data is valid, copy it into the table, and print it to the file
    strncpy(table[0], String, sizeof(char)*17);
    printf("%s\n", table[0]);

    // get extra ch then get the first character of the file
    getchar();
    ch = getchar();

    // while there is still more to read, encrypt and print the current 
    // character, get a new one, and rotate the table
    while (ch != EOF) {
        putchar(encrypt(ch, table));
        ch = getchar();
        rotate(table);
    }

    return 0;
} // end main()

/* ===============================================================
   rotate
   Takes in one input, the table to be rotated. Then rotates the table 
   90 degress counterclockwise stores that rotation back into table and returns
   nothing
Inputs: table, the table to rotate
Outputs: None
Returns: None
Author: Elisabeth Henderson
=============================================================== */
void rotate (char table[][4]) {
    char temp[4][4];  // temp table to help in the rotation

    // go through the passed table and rotate it
    for (int c = 3; c >= 0; c--) {
        for (int r = 0; r < 4; r++) { 
            temp[3-c][r] = table[r][c];
        }
    }

    // reset all values in table to the corresponding ones in the rotated table
    for (int r = 0; r < 4; r++) { 
        for (int c = 0; c < 4; c++) { 
            table[r][c] = temp[r][c];
        }
    }
} // end rotate()

/* ===============================================================
   encrypt
   Takes in two inputs, the character to encrypt and the table by which it 
   should be done. Encryptes the character based on the table passed and 
   returns an encrypted character. 
Inputs: ch, the character to encrypt
table, the table to encrypt with
Outputs: None
Returns: char, the encrypted character
Author: Elisabeth Henderson
=============================================================== */
char encrypt(char ch, char table[][4]) {
    int scale = 128;  // int variable to access the current bit
    int scale2 = 64;  // int variable to access the other current bit
    int rowCh = 0;    // int variable to store data while encrypting
    int finaleCh = 0;  // int variable to store more data while encrypting

    // go through all the rows and columns and if the character is S swap the
    // bits
    for (int col = 0; col < 4; col++) {
        // set newCh to the passed character
        rowCh = ch; // mov r10, qword ptr[rbp-4]
        for (int row = 0; row < 4; row++) {
            if (table[row][col] == 'S') {
                // left and right denote the two current bits. &ing them with
                // the scale "gets" the bit at the current position, shifting
                // by one does the first part of the swap
                int left = (rowCh & scale) >> 1; // r9, mov/and/shr
                int right = (rowCh & scale2) << 1;

                // adding them together and storing them into a new variable 
                // does the last part of the swap
                rowCh = left + right;
            }
        }
        // shift the scales by 2 so they can be properly alligned for the next
        // bits
        scale = scale >> 2;
        scale2 = scale2 >> 2;

        // add the final result of the row encipherment into a new variable
        // to keep the integrity of the following bits
        finaleCh += rowCh;
    }

    // return the final product
    return finaleCh;
} // end encrypt()
