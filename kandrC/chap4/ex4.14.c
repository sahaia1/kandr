#include <stdio.h>

#define swap(t, x, y) \
t _c = (x);\
(x) = (y); \
(y) = _c

int
main() {
	char a = 'a';
	char b = 'b';
	printf("a - %c \t b - %c\n", a, b);
	swap(int, a, b);
	printf("a - %c \t b - %c\n", a, b);
	return 0;
}