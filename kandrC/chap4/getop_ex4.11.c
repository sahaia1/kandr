#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include "calc.h"


typedef unsigned int bool;
char line[BUFSIZE];
int j = 0;

// getop
int
getop(char s[]) {
	int i, c, a;
	static int lastc = 0;

	while ((s[0] = c = getch()) == ' ' || c == '\t')
		;
	s[1] = '\0';
	if (islower(c)) {
		while((lastc == 0 ? islower(s[++i] = c = getch()) : islower(s[++i] = c = lastc)))
			;
		s[i] = '\0';
		if (c != EOF)
			lastc = c;
		if (strlen(s) > 1)
			return NAME;
		else
			return c;
	}
	if (isupper(c))
		return c;
	if (!isdigit(c) && c != '.' && c != '-')
		return c;
	if (c == '-') {
		if (lastc == 0 ? ((c = getch()) == ' ' || c == '\t' || c == '\n') : ((c = lastc) == ' ' || c == '\t' || c == '\n'))
			return '-';
		else 
			lastc = c;
	}
	i = 0;
	if (isdigit(c))
		while (isdigit(s[++i] = c = getch()))
			;
	if (c == '.')
		while (isdigit(s[++i] = c = getch()))
			;
	s[i] = '\0';
	if (c != EOF)
		lastc = c;
	return NUMBER;
}
