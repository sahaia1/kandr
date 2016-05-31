#include <stdio.h>

#define MAXLINE 1000

char pattern[] = "ould";

int
get_line(char s[], int lim) {
	int c, i;

	i = 0;
	while(--lim > 0 && (c = getchar()) != EOF && c != '\n')
		s[i++] = c;
	if (c == '\n')
		s[i++] = c;
	s[i] = '\0';
	return i;
}

int
strindex_last(char s[], char t[]) {
	int i, j, k;
	int found = -1;
	for (i = 0; s[i] != '\0'; i++){
		for (j = i, k = 0; t[k] != '\0' && t[k] == s[j]; j++, k++);
		if (k > 0 && t[k] == '\0')
			found = i;
	}
	return found;
}

int
main(int argc, char *argv[]) {
	char line[MAXLINE];
	int found = 0;
	int index;
	while(get_line(line, MAXLINE) > 0)
		if ((index = strindex_last(line, pattern)) >= 0) {
			printf("%s - index - %d\n", line, index);
			found++;
		}
	return found;
}

