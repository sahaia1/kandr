#include <stdio.h>

int
main() {
	printf("%d\n", -(char)((unsigned char)~0 >> 1));
	int a = 2147483647;
	printf("a = %d\n", a);
	int b = 2147483648;
	printf("b = %d\n", b);
	int c = 255; 
	int d = 00177;
	printf("c & d = %d\n", c & d);
	return 0;
}