#include <ctype.h>
#include <stdio.h>

#define MAXSIZE 100

int getch(void);
void ungetch(int);

// getint
int
getint(int *pn) {
	int c, sign;

	while(isspace(c = getch()))
		;
	// printf("%c\n", c);
	if (!isdigit(c) && c != EOF && c != '+' && c != '-') {
		ungetch(c);
		return 0;
	}
	sign = (c == '-') ? -1 : 1;
	if (c == '+' || c == '-') {
		c = getch();
		if (!isdigit(c)) { // Exercise 5.1
			ungetch(c);
			return 0;
		}
	}
	for(*pn = 0; isdigit(c); c = getch())
		*pn = 10 * *pn + (c - '0');
	*pn *= sign;
	if (c != EOF)
		ungetch(c);
	return c;
 }

 int
 main() {
 	int n, array[MAXSIZE], getint(int *);
 	array[0] = 1;

 	for(n = 0; n < MAXSIZE && getint(&array[n]) != EOF; n++)
 		;
 	//printf("n = %d\n", n);
 	for (int i = 0; i < n; i++)
 		printf("%d\n", array[i]);
 	return 0;
 }