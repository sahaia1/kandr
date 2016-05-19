#include <stdio.h>

int
main() {
	int c;
	if ((c = getchar()) == EOF)
		printf("(%d)\n", c);

	printf("EOF - %d\n", EOF);
	return 0;
}