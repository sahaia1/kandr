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

unsigned invert(unsigned x, int p, int n) {
    unsigned a = ~(getbits(x, p, n));
    unsigned b = getbits(x, (p - n), (p + 1 -n));
    x = x >> (p + 1 -n);
    x = x >> n;
    x = x << n;
    x = x | a;
    x = x << (p + 1 - n);
    x = x | b;
    return x;
}

unsigned invert(unsigned x, int p, int n) {
    unsigned a = ~(getbits(x, p, n));
    return setbits(x, p, n, a);
}

int
main() {
	printf("%d\n", invert(182, 5, 3));
	return 0;
}
