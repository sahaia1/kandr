#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define abs(x) ((x < 0)? -(x) : (x))

void
reverse(char s[]) {
	int c, i, j;
	for(i = 0, j = strlen(s) - 1; i < j; i++)
		c = s[i], s[i] = s[j], s[j--] = c;
	printf("reverse - %s\n", s);
}

void
itob(int n, char s[], int base) {
	int i = 0;
	int c;
	do {
		c = abs(n % base);
		if (c > 9 && base == 16)
			c = (c % 10) + 'A';
		else
			c = c + '0';
		s[i++] = c;
	} while((n /= base) != 0);
	s[i] = '\0';
	reverse(s);
}

int
main() {
	int c = 2138;
	char num[100];
	itob(c, num, 16);
	//printf("%d\n", 5 % 16);
	return 0;
}