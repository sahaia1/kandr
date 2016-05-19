#include <stdio.h>

int
main() {
    float farenheit, celsius;
    int lower, upper, step;

    lower = -200;
    upper = 500;
    step = 20;

    printf("celsius\tfarenheit\n");
    printf("====================\n");
    celsius = lower;
    while (celsius <= upper) {
    	farenheit = (9.0)/(5.0) * celsius + 32;
    	printf("%3.0f\t%6.2f\n", celsius, farenheit);
    	celsius += step;
    }

//     // printing value of -32
//     float f = (9.0)/(5.0) * (-32) + 32;
//     printf("neutal value = %6.2f\n", f);
}
