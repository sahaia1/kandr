#include <stdio.h>
#define MAXLINE 1000


int get_line(char line[], int maxline);
void copy(char to[], char from[]);
void trim(char string[], int len);

int
main() {
	int len, max;
	char line[MAXLINE], longest[MAXLINE];

	max = 0;
	while((len = get_line(line, MAXLINE)) > 0)
		trim(line, len);
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

void trim(char s[], int len) {
	int i, j;
	i = j = 0;
	char c;
	while ((c = s[i]) != '\0') {
		if (c == ' ' || c == '\t')
			j++;
		else if (c != '\n')
			j = 0;
		i++;
	}
	for (i = 0; i < (len - j - 1); i++) {
		printf("%c", s[i]);
	}
	printf("$\n");
}