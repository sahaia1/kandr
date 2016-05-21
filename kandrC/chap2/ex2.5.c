#include <stdio.h>

int
any(char s1[], char s2[]) {
	int ret_val = -1;
	for (int j = 0; s2[j] != '\0'; j++)
		for(int i = 0; s1[i] != '\0'; i++)
			if (s2[j] == s1[i])
				return i;
	return ret_val;
}

int
main() {
	char a[] = "this is a good file";
	char b[] = "z";
	printf("position - %d\n", any(a, b));
}