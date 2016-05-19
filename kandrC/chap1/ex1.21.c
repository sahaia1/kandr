#include <stdio.h>
#define MAXLINE 1000
#define TABSTOP 4

int get_line(char line[], int maxline);
void copy(char to[], char from[]);
void entab(char string[], int len);

int
main() {
	int len, max;
	char line[MAXLINE], longest[MAXLINE];

	max = 0;
	while((len = get_line(line, MAXLINE)) > 0)
		entab(line, len);
	return 0;
}

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

void
copy (char to[], char from[]) {
	int i = 0;
	while ((to[i] = from[i]) != '\0')
		++i;
}

void
entab(char s[], int len) {
	int i = 0, count = 0;
	char c;
	int num_tabs, spaces;
	while ((c = s[i++]) != '\0') {
		if (c == ' ' && count < TABSTOP) {
			count++;
		}
		else if (count == TABSTOP) {
			printf("$\t");
			count = 0;
		}
		else {
			if (count > 0)
				for (int j = 0; j < count; j++)
					printf(" ");
			printf("%c", c);
			count = 0;
		}
	}
}