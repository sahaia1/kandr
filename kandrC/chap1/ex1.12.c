#include <stdio.h>

int
main() {
	int c, state;
	state = OUT;

	while ((c = getchar()) != EOF) {
		if (c == ' ' || c == '\t' || c == '\n') {
			printf("\n");
		}
		else {
			putchar(c);
		}

	}
} 