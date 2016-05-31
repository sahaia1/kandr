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
	if (line[j] == '\0') {
		if(get_line(line, BUFSIZE) == 0)
			return EOF;
		else
			j = 0;
	}
	while((s[0] = c = line[j++]) == ' ' || c == '\t')
		;
	s[1] = '\0';
	if (islower(c)) {
		while(islower(s[++i] = c = line[j++]))
			;
		s[i] = '\0';
		if (c != EOF)
			j--;
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
		if ((c = line[j++] == ' ' || c == '\t' || c == '\n'))
			return '-';
		else 
			j--;
	}
	i = 0;
	if (isdigit(c))
		while (isdigit(s[++i] = c = line[j++]))
			;
	if (c == '.')
		while (isdigit(s[++i] = c = line[j++]))
			;
	s[i] = '\0';
	j--;
	return NUMBER;

	// while ((s[0] = c = getch()) == ' ' || c == '\t')
	// 	;
	// s[1] = '\0';
	// if (islower(c)) {
	// 	while(islower(s[++i] = c = getch()))
	// 		;
	// 	s[i] = '\0';
	// 	if (c != EOF)
	// 		ungetch(c);
	// 	if (strlen(s) > 1)
	// 		return NAME;
	// 	else
	// 		return c;
	// }
	// if (isupper(c))
	// 	return c;
	// if (!isdigit(c) && c != '.' && c != '-')
	// 	return c;
	// if (c == '-') {
	// 	if ((c = getch()) == ' ' || c == '\t' || c == '\n')
	// 		return '-';
	// 	else {
	// 		is_negative = TRUE;
	// 		ungetch(c);
	// 	}
	// }
	// i = 0;
	// if (isdigit(c))
	// 	while (isdigit(s[++i] = c = getch()))
	// 		;
	// if (c == '.')
	// 	while (isdigit(s[++i] = c = getch()))
	// 		;
	// s[i] = '\0';
	// if (c != EOF)
	// 	ungetch(c);
	// return NUMBER;
}
