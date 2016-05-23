#include <stdio.h>

#define MAXLINE 1000
#define TRUE 1
#define FALSE 0

void
escape(char s[], char t[]) {
	int c, i, j;
	for(i = 0, c = s[i], j = 0; c != EOF; c = s[++i]) {
		switch(c) {
			case '\t':
				t[j++] = '\\';
				t[j++] = 't';
				break;
			case '\n':
				t[j++] = '\\';
				t[j++] = 'n';
				break;
			default:
				t[j++] = c;
				break;
		}
	}
	printf("t - %s\n", t);
}

void
reverse_escape(char t[], char s[]) {
	int c, i, j;
	int escape = FALSE;
	for (i = 0, c = t[i], j = 0; c != EOF; c = t[++i]) {
		switch(c) {
			case '\\':
				switch(t[i+1]) {
					case 'n':
						s[j++] = '\n';
						escape = TRUE;
						break;
					case 't':
						s[j++] = '\t';
						escape = TRUE;
						break;
					default:
						s[j++] = '\\';
						break;
				}
				break;
			default:
				switch(escape) {
					case TRUE:
						//printf("escaped - %c", c);
						escape = FALSE;
						break;
					default:
						s[j++] = c;
						break;
				}
				break;
		}
	}
	printf("s - %s\n", s);
}

int
main() {
	char s[MAXLINE], t[MAXLINE], u[MAXLINE];
	int c;
	for(int i = 0; (c = getchar()) != EOF; i++)
		s[i] = c;
	escape(s, t);
	reverse_escape(t, u);
	return 0;
}