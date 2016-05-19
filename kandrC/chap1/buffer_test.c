#include <stdio.h>

int
main() {
	int c;
	c = 'a';
	char *buffer;
	sprintf(buffer, "%c", c);
	printf("%s\n", buffer);
}