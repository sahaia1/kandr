/*
 * If an array of characters is 4 bytes long, and an integer is 4 bytes long, then can you treat the whole name array like it's just an integer? How might you accomplish this crazy hack?
 */
#include <stdio.h>

int main(int argc, char *argv[])
{
    char name[4] = { 'a', 'b', 'c', 'd' };
    int number = (name[0] << 24) + (name[1] << 16) + (name[2] << 8) + name[3];

    printf("number: %d\n", number);

    return 0;
}

