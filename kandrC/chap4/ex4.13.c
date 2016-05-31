#include <stdio.h>
#include <string.h>

void reverse(char s[], int i, int j) {
	if(i < j) {
		reverse(s, i+1, j-1);
		char c;
		c = s[i], s[i] = s[j], s[j] = c;
	}
}

int
main(int argc, char *argv[]) {
	if (argc < 2) {
		printf("No arguments provided\n");
		return 1;
	}
	// char s[] = argv[1];
	int len = strlen(argv[1]);
	reverse(argv[1], 0, len - 1);
	argv[1][len] = '\0';
	printf("%s\n", argv[1]);
	return 0;
}