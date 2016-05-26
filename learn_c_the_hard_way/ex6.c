#include <stdio.h>

int main(int argc, char *argv[])
{
    int distance = 100;
    float power = 22.345f;
    double super_power = 56789.4532;
    char initial = 'A';
    char first_name[] = "Zed";
    char last_name[] = "Shaw";
    int val;
    char string[] = " ";

    printf("You are %x miles away.\n", distance);
    printf("You have %f %nlevels of power.\n", power, &val);
    printf("the value of val is %d\n", val);
    printf("You have %f awesome super powers.\n", super_power);
    printf("I have an initial %c.\n", initial);
    printf("I have a first name %s.\n", first_name);
    printf("I have a last name %s.\n", last_name);
    printf("My whole name is %s %c. %s.\n",
            first_name, initial, last_name);
    printf("Empty string %s$\n", string);

    return 0;
}