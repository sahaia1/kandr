#include <stdio.h>
#include <string.h>

#define TRUE 1
#define FALSE 0
#define MAXSIZE 1000
typedef unsigned int bool;

void
expand(char s1[], char s2[]) {
	char stack[MAXSIZE];
	bool push = TRUE;
	bool exp_hyp = FALSE;
	int i, j, k;
	char c1, c2;
	int length = strlen(s1);
	for(i = 0, j = 0, k = 0; i <= strlen(s1); i++) {
		switch(s1[i]) {
			case '-':
				//Push the next char
				if (exp_hyp)
					push = TRUE;
				else {
					if (k > 0)
						for(int u = 0; u < k; u++)
							s2[j++] = stack[u];
						k = 0;
					s2[j++] = '-';
				}
				break;
			default:
				printf("i - %c push - %d\n", s1[i], push);
				if (push) {
					stack[k++] = s1[i];
					printf("%s\n", stack);
					push = FALSE;
					exp_hyp = TRUE;
					break;
				}
				else if (!push) {
					// Pop
					if (s1[i] == '-') {
						exp_hyp = FALSE;
						break;
					}
					c1 = stack[--k];
					c2 = stack[--k];
					printf("char c1 - %c c2 - %c\n", c1, c2);
					while (c2 <= c1)
						s2[j++] = c2++;
					if (i < length && s1[i])
						stack[k++] = s1[i];
					break;
				}
		}
	}
	s2[j] = '\0';
	printf("%s\n", s2);
}

int
main() {
	char range[] = "a-b-c";
	char val[MAXSIZE];
	expand(range, val);
	return 0;
}