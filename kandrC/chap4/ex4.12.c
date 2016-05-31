#include <stdio.h>
#include <stdlib.h>

#define MAXLINE 1000

int position = 0;

void
itoa(int n, char s[]) {
	if (n < 0) {
		s[position++] = '-';
		n = -n;
	}
	if (n / 10)
		itoa(n / 10, s);
	s[position++] = n % 10 + '0';
}

int
main(int argc, char *argv[]) {
	if (argc < 2) {
		printf("provide more arguments\n");
		return 1;
	}
	char s[MAXLINE];
	int num = atoi(argv[1]);
	itoa(num, s);
	s[position] = '\0';
	printf("%s\n", s);
	return 0;
}