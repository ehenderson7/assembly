#include <stdio.h>
#include <stdlib.h>

// function prototypes for the functions used in the program
int calcTax(double, char);
void printMoney(int);


/* ===============================================================
   main
   main function of the program. Prompts the user for input, an income amount
   and a worker type, takes in that input and saves it to variables. Then calls
   a function to calculate the tax the user owes. The function saves that and
   passes it to other to print out the amount in "check format". This will 
   continue until an end-of-file character is inputed by the user. 
Inputs: None
Outputs: Prints some information to the console
Returns: 0 if all run correctly, 1 otherwise
Author: Elisabeth Henderson
=============================================================== */
int main() {

    int payD = 0;      // int variable to store the dollar amount of the income
    int payC = 0;      // int variable to store the change amount of the income
    char type = 'c';   // char variable to store the worker type

    // promt to user for input
    printf("What is the amount of pay? ");

    // while an end-of-file character is not inputed prompt the user for input
    // and print information to the console based on that input
    while(scanf("%d.%d", &payD, &payC) != -1){

        // if the pay is out of range, break out of the loop / program
        if (payD <= 0 && payC <= 0) {
            printf("Error. You made no money!\n");
            break;
        }

        // prompt the user for the workter type
        printf("What is the worker type? ");
        scanf("%s", &type); // %s to deal with that new line character

        // if the worker type is invalid print an error message
        if (type != 'G' && type != 'O' && type != 'T' ) {
            printf("Error. That type does not exist!\n");
            break;
        }

        // add the dollars and cents into one variable to calculate the tax
        double total = payD + ((double)payC/100);

        // call calcTax to calculate the tax value and save it into t variable
        // so it can be printed later
        int toPrint = calcTax(total, type);

        // print a tab
        printf("\t");
        
        // call print money and pass it toPrint / 100, which is the dollar 
        // amount of the tax
        printMoney(toPrint/100);

        // print "dollars and" for formatting
        printf("dollars and ");

        // if there are no cents, print no
        // if there there are cents call printMoney and pass it toPrint % 100,
        // the cent part of the tax
        if (toPrint%100 == 0) { 
            printf("no ");
        }
        else {
            printMoney(toPrint%100);
        }

        // print "cents"
        printf("cents\n");

        // reprompt the user for input
        printf("What is the amount of pay? ");
    } // end while

    // print a new line for nice output
    printf("\n");

    // return 0 if all is good
    return (0);
} // end main()

/* ===============================================================
   calcTax
   Takes in two inputs, the pay and the type of worker. Calculates the the tax
   based on that information and the specifications given in the assignment.
   Then returns the tax.
Inputs: pay, the income inputed by the user
type, the char indicating the worker type
Outputs: None
Returns: int, the calculated tax value
Author: Elisabeth Henderson
=============================================================== */
int calcTax(double pay, char type) {

    double retValue = 0;   // value to return

    // check the worker type and calculate the tax based on that value
    if (type == 'G') {
        retValue = ((pay * .15));
    }
    else if (type == 'O') {
        if (pay > 5000) {
            retValue = 500;
            pay -= 5000;
        }
        retValue += pay * .20;
    }
    else if (type == 'T') {
        retValue = 800 + ((pay / 3));
    }

    // return a casted return value, mutlipled by 100 to save the cent parts
    return (int)(retValue*100);
} // end calcTax()

/* ===============================================================
   printMoney
   Takes in the tax money owed and used a while loop and switch statement to 
   print the amout in "check format". 
Inputs: pay, the tax amount to be printed to the screen
Outputs: prints the money amount in "check format" to the console
Returns: None
Author: Elisabeth Henderson
=============================================================== */
void printMoney(int pay) {

    int power = 10000;    // int variable to keep track of the power and divide
    // the tax value down
    int p = 1;            // int value to keep track of when to print thousand
    // and hundred

    // while loop to divide pay and print the value in "check format"
    while (power > 0) {
        int check = pay / power; // int variable to use in the switch statment

        // if statements to ensure numbers like 12 and 40 print correctly
        // internal if are to ensure teens and larger number print as they
        // should, the separate cases are needed becuse of how english works
        if (power == 10000) {
            if (check == 1) {
                check = pay / 1000;
                power /= 10;
            }
            else {
                check *= 10;
            }
        }
        if (power == 10) {
            if (check == 1) {
                check = pay;
                power /= 10;
            }
            else {
                check *= 10;
            }
        }

        // reduce pay down to ensure all of the number is printed
        pay = pay % power;

        // switch to print the int value in words
        switch (check) {
            case 1:
                printf("one ");
                break;
            case 2:
                printf("two ");
                break;
            case 3:
                printf("three ");
                break;
            case 4:
                printf("four ");
                break;
            case 5:
                printf("five ");
                break;
            case 6:
                printf("six ");
                break;
            case 7:
                printf("seven ");
                break;
            case 8:
                printf("eight ");
                break;
            case 9:
                printf("nine ");
                break;
            case 10:
                printf("ten ");
                break;
            case 11:
                printf("eleven ");
                break;
            case 12:
                printf("twelve ");
                break;
            case 13:
                printf("thirteen ");
                break;
            case 14:
                printf("fourteen ");
                break;
            case 15:
                printf("fifteen ");
                break;
            case 16:
                printf("sixteen ");
                break;
            case 17:
                printf("seventeen ");
                break;
            case 18:
                printf("eighteen ");
                break;
            case 19:
                printf("nineteen ");
                break;
            case 20:
                printf("twenty ");
                break;
            case 30:
                printf("thirty ");
                break;
            case 40:
                printf("forty ");
                break;
            case 50:
                printf("fifty ");
                break;
            case 60:
                printf("sixty ");
                break;
            case 70:
                printf("seventy ");
                break;
            case 80:
                printf("eighty ");
                break;
            case 90:
                printf("ninety ");
                break;
            default:
                p = 0;
        } // end switch

        // depending on what p and power equal, print hundred or thousand 
        if (p == 1) {
            if (power == 1000) 
                printf("thousand ");
            if (power == 100) 
                printf("hundred ");
        }

        // reset p
        p = 1;

        // decrement power to ensure the while does not continue forever
        power /= 10;
    } // end while
} // end printMoney()
