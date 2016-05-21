#include <stdio.h>

void squeeze(char s[], int c) {
  int i, j;
  for (i = j = 0; s[i] != '\0'; i++)
    if (s[i] != c)
      s[j++] = s[i];
  s[j] = '\0';
}


int
main() {
  char *string = "this is a good file";
  int c = 'o';
  squeeze(string, c);
  //printf("altered string - %s\n", string);
  return 0;
}
