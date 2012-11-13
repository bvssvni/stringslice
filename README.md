stringslice
===========

Extract tokens from C strings.

BSD license.

This library depends on "slice" macroes.

##How to run test

The test program uses Bash script at the beginning to compile and run.
GCC compiler is used, you can modify it to run on your platform.

    bash test-stringslice.c
    
##How to use it

The point is to find the first occurence of a slice in a string.
In a typical parser, you want to split the text into tokens.

###Min

The "Min" function returns the first slice of A or B.
If A and B overlap, the "Min" function returns a cut of the first slice.

###Bracket

The "Bracket" function returns the slice starting at a character
and ending at another.

