#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// what is "bus error"
typedef unsigned int bool;
#define TRUE 1
#define FALSE 0
#define MAXSIZE 1000

void
free_str(char **str) {
	free(*str);
	*str = NULL;
}


int
main() {
	char *buffer = (char *)malloc(sizeof(char) * MAXSIZE);
	char *line = (char *)malloc(sizeof(char) * MAXSIZE);
	int i, c, line_size, buffer_size;
	i = line_size = buffer_size = 0;
	bool new_word = FALSE;
	bool isSpace = FALSE;
	while ((c = getchar()) != EOF) {
		i = 0;
		if (c == '\t') {
			i = 4;
			if (!isSpace)
				new_word = TRUE;
			isSpace = TRUE;
		}
		else if (c == ' ') {
			i = 1;
			if (!isSpace)
				new_word = TRUE;
			isSpace = TRUE;
		}
		else {
			i = 1;
			isSpace = FALSE;
			new_word = FALSE;
		}
		printf("line - %s buffer size - %d  line size - %d\n", line, buffer_size, line_size);
		if (line_size + buffer_size >= 80) {
			if (isSpace) {
				printf("%s\n", line);
				free_str(&line);
				line = (char *)malloc(sizeof(char) * MAXSIZE);
				line_size = 0;
				sprintf(buffer, "%s%c", buffer, c);
				buffer_size++;
			}
		}
		else if(buffer_size + i > 80 && line_size == 0) {
			// One cont word
			printf("%s%c\n", buffer, c);
			free_str(&buffer);
			buffer = (char *)malloc(sizeof(char) * MAXSIZE);
			buffer_size = 0;
		}
		else if (new_word) {
			// add buffer to line
			sprintf(line, "%s %s ", line, buffer);
			line_size += buffer_size + 1;
			buffer_size = 0;
			free_str(&buffer);
			buffer = (char *)malloc(sizeof(char) * MAXSIZE);
		}
		else {
			sprintf(buffer, "%s%c", buffer, c);
			buffer_size++;
		}

	}
	printf("%s\n", buffer);
	free_str(&buffer);
	return 0;

}