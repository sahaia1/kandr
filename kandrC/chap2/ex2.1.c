#include <stdio.h>

int
main() {
    printf("int - %lu\n", sizeof(int));
    printf("char - %lu\n", sizeof(char));
    printf("short int - %lu\n", sizeof(short int));
    printf("long int - %lu\n", sizeof(long int));
    printf("signed int - %lu\n", sizeof(signed int));
    printf("unsinged int - %lu\n", sizeof(unsigned int));
    printf("short - %lu\n", sizeof(short));
    printf("float - %lu\n", sizeof(float));
    printf("double - %lu\n", sizeof(double));
    return 0;
}
