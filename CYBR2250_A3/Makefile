##################################################
# This is my makefile for CYBR 2250 Program 3    #
#                                                #
# File author: Elisabeth Henderson               #
# Date:        Friday November 3, 2017           #
#                                                #
##################################################

# To make the program for this assignment. It only needs itself and the 
# functions.s file that has the asssmebly code
table : tablecrypt.c functions.s
	        gcc -Wall -pedantic -std=c1x -g -o tablecrypt tablecrypt.c functions.s

# a "clean" option to get rid of all miscellaneous things when done.
clean :
	        -rm ./*.o ./tablecrypt


