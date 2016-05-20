#include <stdio.h>

unsigned getbits(unsigned x, int p, int n) {
	unsigned a = (x >> (p + 1 - n));
	unsigned b = ~(~0 << n);
	return a & b;
}

unsigned setbits(unsigned x, int p, int n, unsigned y) {
	unsigned a = getbits(x, (p - n), (p + 1 - n));
	x = x >> (p + 1 - n);
//	printf("1 x - %d\n", x);
	unsigned b = getbits(y, n-1, n);
//	printf("2 b - %d\n", b);
	x = x >> n;
//	printf("3 x - %d\n", x);
	x = x << n;
//	printf("4 x - %d\n", x);
	x = x | b;
//	printf("5 x - %d\n", x);
	x = x << (p + 1 - n);
//	printf("6 x - %d\n", x);
	x = x | a;
//	printf("7 x - %d\n", x);
	return x;
}

// K and R solution does not work. why?
unsigned setbits2(unsigned x, int p, int n, unsigned y) {
	return x & ~(~(~0 << n) << (p + n - 1)) |
			(y & ~(~0 << n)) << (p + n - 1); 
}

int
main() {
	printf("answer for 134 = %d\n", getbits(134, 2, 3));
	printf("%d\n", setbits(166, 7, 8, 87));
	printf("setbits2 = %d\n", setbits2(166, 7, 8, 87));
	printf("%lu\n", sizeof(unsigned));
	return 0;
}