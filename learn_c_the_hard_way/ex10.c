#include <stdio.h>
/*
(C99, 5.1.2.2.1p2) "The parameters argc and argv and the strings pointed to 
by the argv array shall be modifiable by the program, and retain their 
last-stored values between program startup and program termination."
*/
int main(int argc, char *argv[])
{
    int i = 0;

    // go through each string in argv
    // why am I skipping argv[0]?
    for(i = 0; i < argc; i++) {
        printf("arg %d: %s\n", i, argv[i]);
    }

    // let's make our own array of strings
    char *states[] = {
        "California", "Oregon",
        "Washington", "Texas"
    };
    int num_states = 5;

    for (int j = 0; j < num_states; j++)
        argv[argc++] = states[j];

    states[0] = argv    [2];

    for(i = 0; i < num_states; i++) {
        printf("state %d: %s\n", i, states[i]);
    }

    return 0;
}