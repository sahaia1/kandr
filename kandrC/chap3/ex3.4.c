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
itoa(int n, char s[]) {
	int i, sign;
	sign = n;
	i = 0;
	do {
		s[i++] = abs(n % 10) + '0';
	} while ((n /= 10) != 0);
	if (sign < 0)
		s[i++] = '-';
	s[i] = '\0';
	reverse(s);
}

int
main() {
	char s[] = "this is a good file";
	reverse(s);
	int c = -2147483648;
	printf("%d\n", abs(c));
	char num[100];
	itoa(c, num);
	printf("%lu\n", sizeof(int));
	return 0;
}