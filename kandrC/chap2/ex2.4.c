#include <stdio.h>
#include <stdlib.h>

void
squeeze(char s[], int c) {
  int i, j;
  for (i = j = 0; s[i] != '\0'; i++)
    if (s[i] != c)
      s[j++] = s[i];
  s[j] = '\0';
}

void
squeeze2(char s[], char t[]) {
  for (int j = 0; t[j] != '\0'; j++)
    squeeze(s, t[j]);
}

int
main() {
  char string[] = "this is a good file\n";
  char t_string[] = "good";
  squeeze2(string, t_string);
  printf("altered string - %s\n", string);
  return 0;
}
