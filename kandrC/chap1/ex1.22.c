#include <stdio.h>

int
main() {
	int c, i, num_char;
	num_char = i = 0;

	while ((c = getchar()) != EOF) {
		i++;
		if (i >= 79) {
			putchar('\n');
			i = 0;
		}
		else if (c == '\n')
			i = 0;
		putchar(c);
	}
	return 0;
}