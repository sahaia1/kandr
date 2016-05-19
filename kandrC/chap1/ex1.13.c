#include <stdio.h>

int
main() {
	int c;

	while ((c = getchar()) != EOF) {
		if (c == ' ' || c == '\t' || c == '\n')
			printf("\n");
		else
			putchar('=');
	}
	return 0;
}