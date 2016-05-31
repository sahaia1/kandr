#include <stdio.h>
#include <ctype.h>
#include <math.h>

#define MAXSIZE 100

int getch(void);
void ungetch(int);

int
getfloat(float *pn) {
	int c, decimal, sign;
	decimal = 0;

	for(c = getch(); isspace(c); c = getch())
		; // skip spaces
	if (!isdigit(c) && c != EOF && c != '+' && c != '-') {// Not a digit 
		ungetch(c);
		return 0;
	}
	sign = (c == '-') ? -1 : 1;
	if (c == '-' || c == '+')
		c = getch();
	for(*pn = 0; isdigit(c); c = getch())
		*pn = *pn * 10 + (c - '0');
	if (c == '.')
		c = getch();
	for(;isdigit(c); c = getch()) {
		*pn = *pn * 10 + (c - '0');
		decimal++;
	}
	*pn *= sign;
	*pn /= pow(10, decimal);
	if (c != EOF)
		ungetch(c);
	return c;
}

int
main() {
	 int n, getint(int *);
	 float array[MAXSIZE];

 	for(n = 0; n < MAXSIZE && getfloat(&array[n]) != EOF; n++)
 		;
 	//printf("n = %d\n", n);
 	for (int i = 0; i < n; i++)
 		printf("%f\n", array[i]);
 	return 0;
}