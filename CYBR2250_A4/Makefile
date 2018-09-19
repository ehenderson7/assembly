##################################################
#                                                #
# This is my makefile for CYBR 2250 Program 4    #
#                                                #
# File author: Elisabeth Henderson               #
# Date:        Friday November 17, 2017          #
#                                                #
##################################################

# To make the program for this assignment. It needs itself and function.s
# which has one function written in assembly
words : prog4.c function.s
	    gcc -Wall -pedantic -std=c1x -g -o prog4 prog4.c function.s

# a "clean" option to get rid of all miscellaneous things when done.
clean :
	    -rm ./*.o ./prog4
