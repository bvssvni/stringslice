
#include "slice.h"
#include "stringslice.h"

slice_char stringslice_Bracket(char *text, char start, char end)
{
	int s, e;
	int i;
	for (i = 0; text[i] != '\0'; i++) {
		if (text[i] == start) break;
	}
	s = i;
	for (; text[i] != '\0'; i++) {
		if (text[i] == end) break;
	}
	e = i;
	return (slice_char)slice_array(text, s, e+1);
}

slice_char stringslice_Min(slice_char a, slice_char b)
{
	if (a.ptr < b.ptr) {
		int diff = (int)(b.ptr - a.ptr);
		if (a.len < diff) return a;
		return slice(a, 0, diff);
	} else {
		int diff = (int)(a.ptr - b.ptr);
		if (b.len < diff) return b;
		return slice(b, 0, diff);
	}
}

slice_char stringslice_Char(char *text, char c)
{
	int i;
	for (i = 0; text[i] != '\0'; i++) {
		if (text[i] == c) break;
	}
	slice_char a = slice_array(text, i, i+1);
	return a;
}

