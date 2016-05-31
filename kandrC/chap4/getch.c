#include <stdio.h>
#include <string.h>

#define BUFSIZE 100

char buf[BUFSIZE];
int bufp = 0;

// int
// getch(void) {
// 	;
// }

// void
// ungetch(int c) {
// 	if (bufp >= BUFSIZE)
// 		printf("ungetch: too many characters\n");
// 	else
// 		buf[bufp++] = c;
// }

// Exercise 4.10
int
get_line(char s[], int lim) {
	int c, i;

	for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
		s[i] = c;
	if (c == '\n') {
		s[i] = c;
		++i;
	}
	s[i] = '\0';
	return i;
}

// Exercise 4.7
// void
// ungets(char s[]) {
// 	int i;
// 	for (i = strlen(s) - 1; i >= 0; i--)
// 		ungetch((int)s[i]);
// }

// For testing purposes
// int
// main() {
// 	int c;
// 	char a[] = "this is a string\n";
// 	ungets(a);
// 	while ((c = getch()) != EOF) {
// 		if (c == ' ' || c == '\t' || c == '\n') {
// 			printf("\n");
// 		}
// 		else {
// 			putchar(c);
// 		}
// 	}
// 	if (c == EOF) {
// 		ungetch(c);
// 	}
// 	c = getch();
// 	putchar(c);
// }