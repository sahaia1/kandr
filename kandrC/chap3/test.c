#include <stdio.h>

int
main() {
	int a = 'a';
	while (a <= 'z')
		printf("%c ", a++);
	printf("\n");
	return 0;
}