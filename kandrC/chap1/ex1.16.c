#include <stdio.h>
#define MAXLINE 10

int get_line(char line[], int maxline);
void copy(char to[], char from[]);

int
main() {
	int len, max, line_length;
	char line[MAXLINE], longest[MAXLINE], last_char;

	line_length = max = 0;
	last_char = '\0';
	longest[0] = '\0';
	while((len = get_line(line, MAXLINE)) > 0) {
		if ((last_char = line[len-1]) != '\n' && len+1 == MAXLINE) {
			if (line_length == 0) {
				copy(longest, line);
			}
			line_length += len;
		}
		else {
			line_length += len;
			if (longest[0] != '\0')
				printf("%d\t%s\n", line_length, longest);
			else
				printf("%d\t%s", line_length, line);
			line_length = 0;
		}
	}

	printf("%1s", "aditya");
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