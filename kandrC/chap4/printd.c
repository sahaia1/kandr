#include <stdio.h>
#include <stdlib.h>

void
printd(int n) {
	if (n < 0) {
		putchar('-');
		n = -n;
	}

	if (n/10)
		printd(n/10);
	putchar(n % 10 + '0');
}

int
main(int argc, char *argv[]) {
	if (argc < 2) {
		printf("provide number to print\n");
		return 1;
	}
	printd(atoi(argv[1]));
	return 0;
}