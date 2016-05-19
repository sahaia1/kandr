#include <stdio.h>

int
main() {
    float farenheit, celsius;
    int lower, upper, step;

    lower = -200;
    upper = 500;
    step = 20;

    printf("farenheit%13s\n", "celsius");
    printf("====================\n");
    farenheit = upper;
    while (farenheit >= lower) {
    	//farenheit = (9.0)/(5.0) * celsius + 32;
        celsius = (5.0)/(9.0) * (farenheit - 32);
    	printf("%3.0f %10s %6.2f\n", farenheit, " ", celsius);
    	farenheit -= step;
    }

/* 
I use this function to indent my output (for example to print the tree structure). The indent is number of spaces before the string.

void print_with_indent(int indent, char * string)
{
    printf("%*s" "%s", indent, " ", string); 
}
*/
printf("%*s" "%s", 5, "", "hello world\n");
printf("hello world\n");
}
