#if 0
#!/bin/bash
gcc -o test-stringslice *.c -Wall -Wfatal-errors -O3
if [ "$?" = "0" ]; then
	time ./test-stringslice
fi
exit
#endif

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "slice.h"
#include "stringslice.h"

void test_stringslice_Bracket_1(void)
{
	char *text = "[]";
	slice_char slice = stringslice_Bracket(text, '[', ']');
	assert(slice.ptr == text);
	assert(slice.len == 2);
}

void test_stringslice_Bracket_2(void)
{
	char *text = "[hello]";
	slice_char slice = stringslice_Bracket(text, '[', ']');
	assert(slice.ptr == text);
	assert(slice.len == 7);
}

void test_stringslice_Bracket_3(void)
{
	char *text = "start [hello]";
	slice_char slice = stringslice_Bracket(text, '[', ']');
	assert(slice.ptr == text+6);
	assert(slice.len == 7);
}

void test_stringslice_Min_1(void)
{
	char *text = "start [hello]";
	slice_char a = slice_array(text, 0, strlen(text));
	slice_char b = stringslice_Bracket(text, '[', ']');
	slice_char min = stringslice_Min(a, b);
	assert(min.ptr == text);
	assert(min.len == 6);
}

void test_stringslice_Char_1(void)
{
	char *text = "start, end";
	slice_char comma = stringslice_Char(text, ',');
	assert(comma.ptr == text + 5);
	assert(comma.len == 1);
}

int main(int argc, char *argv[])
{
	test_stringslice_Bracket_1();
	test_stringslice_Bracket_2();
	test_stringslice_Bracket_3();
	test_stringslice_Min_1();
	test_stringslice_Char_1();
	
	return 0;
}