#include <stdio.h>
#include <time.h>

void wait ( int sec ) {
int a =0;
clock_t end_wait;
end_wait = clock () + sec * CLK_TCK;
while (clock() < end_wait) {

// Your useless calculations.
a++;
}
printf (“%i\n”, a);
}

void waitspeedup ( int sec, int speedupfactor ) {
int num,a = 0;
num = sec / speedupfactor;
printf (“The new wait time is: %i\n”, num);
clock_t end_wait;
end_wait = clock () + num * CLK_TCK;
while (clock() < end_wait) {

// Your useless calculations
a++;
}
// The fake result (because of speedup factor)
printf (“%i\n”, a);
// Multiply result with speedupfactor to get an approximation
// of the actual results.
printf (“%i\n”, a*speedupfactor);
}

int main () {
printf (“Waiting.1….\n”);
// Wait approx. 12 seconds
wait(12);
printf (“Waiting.2….\n”);
// Wait approx. 12 / 2 = 6 seconds
waitspeedup(12,2);
// There are 86400 seconds in a day
// do something like this 86400/1200=72 sec.
return 0;
}