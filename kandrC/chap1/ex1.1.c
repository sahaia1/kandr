#include <stdio.h>

int
main () {
    printf("hello, world\n");
}
/* 
 * The standard signatures for main are either
 *
 * int main(void)
 * or
 *
 * int main(int argc, char **argv)
 * Your compiler is simply enforcing the standard.
 *
 * Note that an implementation may support void main(), but it must be explicitly documented, otherwise the behavior is undefined. Like dandan78 says, a large number of books and online references get this wrong.
 */
