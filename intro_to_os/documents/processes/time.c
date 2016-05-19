#include <sys/time.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int
main() {
    for (int i = 0; i < 100; i++) {
        struct timeval *time_val = (struct timeval*)malloc(sizeof(struct timeval));
        if (gettimeofday(time_val, NULL) == 0) {
            printf("Time sec = %ld\n", time_val->tv_sec);
            sleep(1);
        }
        free(time_val);
    }
    return 1;
}

