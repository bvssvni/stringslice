
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
	int diff = b.ptr - a.ptr;
	int len = 0;
	char *ptr;
	if (diff == 0) {
		ptr = a.ptr;
		len = b.len < a.len ? b.len : a.len;
	} else if (diff > 0) {
		ptr = a.ptr;
		len = diff < a.len ? diff : a.len;
	} else {
		ptr = b.ptr;
		len = -diff < b.len ? -diff : b.len;
	}
	return (slice_char)slice_array(ptr, 0, len);
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

