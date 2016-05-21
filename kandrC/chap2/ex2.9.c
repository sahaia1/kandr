#include <stdio.h>

int
bitcount1(unsigned x) {
	int b;
	for(b = 0; x != 0; x >>= 1) {
		unsigned c = x & 1;
		printf("c = %d\n", c);
		if (x & 1)
			b++;
	}
	return b;
}

int
bitcount2(unsigned x) {
	int b = 0;
	// while ((x &= (x - 1)) != 0)
	// 	b++;
	for (b = 0; x != 0; x &= (x-1))
		b++;
	return b;

}

int
main() {
	printf("153 - %d\n", bitcount2(153));
	// for (int i = 150; i < 160; i++)
	// 	printf("%d\n", (i & (i-1)));
	return 0;
}