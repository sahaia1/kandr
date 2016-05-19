#include <stdio.h>

#define TRUE 1
#define FALSE 0

typedef unsigned int bool;

int
main() {
	int c;
	bool isComment = FALSE, checkForComment = FALSE, isMultilineComment = FALSE, checkForCloseMultiline = FALSE;
	while ((c = getchar()) != EOF) {
		if (!isComment) {
			if (c == '/' && !checkForComment)
				checkForComment = TRUE;
			else if(c == '/' && checkForComment)
				isComment = TRUE;
			else if (checkForComment) {
				putchar('/');
				putchar(c);
				checkForComment = FALSE;
				isComment = FALSE;
			}
			else 
				putchar(c);
		}
		else
			if (c == '\n')
				isComment = checkForComment = FALSE;
	}
	return 0;
}