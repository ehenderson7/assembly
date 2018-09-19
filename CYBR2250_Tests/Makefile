##################################################
#
# This is my makefile for CYBR 2250
#
# Fine author: The 2250 Class
# Date:        Wednesday!
#
##################################################

# Let's define some things.
GCC=gcc
CFLAGS=-Wall -pedantic -std=c1x
ALL=mon wed sales memcpy_gcc memcpy_my buggy mono andor scan

# To make everything in the directory...  The "make" command will - by
# default - do whatever is listed first.  So you can see the results
# we'll make sure the permissions are right as well while we are at it.
all :	$(ALL)
	chmod 644 *.c *.s
	chmod 755 $(ALL)


# To make the C code we messed with on Monday.  Since mon.c includes
# myfile.h, myfile,h is a dependency.  

mon :	mon.c myfile.h
	gcc -pedantic -std=c1x -o mon mon.c

# To make the C/S code we'll mess with on Wednesday.
wed :	wed.c f_a_func.o
	gcc -Wall -pedantic -std=c1x -o wed wed.c f_a_func.o


# Assemble some source into an object; '-c' says to stop when you get
# to object code. Otherwise GCC will try to make this the main program.
# When that happens it will fail because there is no "main" function.
f_a_func.o :	f_a_func.s
	gcc -c f_a_func.s


# Let's show another thing with the Makefile. FOr compiling "sales" we
# will use a built-in "make" way of doing it; $@ is a variable that is
# "the name of the program without the suffix" and $< is "the name of
# the program with the suffix still on it"
sales :	sales.c
	$(GCC) $(CFLAGS) -o $@ $<


# Here we are going to make several verisons of something like memcpy.
# memcpy_gcc is with the original GCC generated my_memcpy, but
# memcpy_my is one where I wrote the assembly myself. GCC with 
# optimization on does a better job than me, by the way.
# Also, $^ is "all prerequisites" not "first prerequisite".
memcpy_gcc :	memcpy_test.o memcpy_gcc_version.s
	$(GCC) $(CFLAGS) -o $@ $^

memcpy_my :	memcpy_test.o memcpy_my_version.s
	$(GCC) $(CFLAGS) -o $@ $^

memcpy_test.o :	memcpy_test.c
	$(GCC) $(CFLAGS) -c $<


# Make a buggy program so we can demo GDB. To debug you will need the -g option.
buggy :	buggy.c
	$(GCC) $(CFLAGS) -g -o $@ $<

# A program to show simple pointers to characters
mono :	mono.c
	$(GCC) $(CFLAGS) -g -o $@ $<

# Demo linking assembly, passing param's, etc.
andor :	andor.c work.s
	$(GCC) $(CFLAGS) -g -o $@ $^

# Demo some assembly that deals with arrays.
# We'll just put the assembly in the same "work.s" file as before.
scan :	scan.c work.s
	$(GCC) $(CFLAGS) -g -o $@ $^

# A "clean" option will get rid of miscellaneous things when you're done.
# The "miscellaneous things" are any old object files or temporary editor files.
# We will also remove the actual execut's so that a "make" will recreate 'em.
clean :	
	-rm $(ALL) ./*.o *~

# Don't read this, whatever you do. And certainly don't make it.
# f_a_func.s :	temp.c
#	gcc -S -masm=intel temp.c
#	sed 's/temp.c/f_a_func.s/g' <temp.s >f_a_func.s
#	rm temp.s
