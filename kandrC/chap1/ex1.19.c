#include <stdio.h>
#define MAXLINE 1000


int get_line(char line[], int maxline);
void copy(char to[], char from[]);
void reverse(char string[], int len);

int
main() {
	int len, max;
	char line[MAXLINE], longest[MAXLINE];

	max = 0;
	while((len = get_line(line, MAXLINE)) > 0)
		reverse(line, len);
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

void reverse(char s[], int len) {
	int i = len - 2;
	while (i >= 0)
		printf("%c", s[i--]);
	printf("\n");
}