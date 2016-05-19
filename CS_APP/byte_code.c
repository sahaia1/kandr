#include <stdio.h>

typedef unsigned char *byte_pointer;

void
show_bytes(byte_pointer start, int len) {
    int i;
    for (i = 0; i < len; i++) {
        printf(" %.2x", start[i]);
    }
    printf("\n");
}

void
show_int(int x) {
    show_bytes((byte_pointer) &x, sizeof(int));
}

void
show_float(float x) {
    show_bytes((byte_pointer) &x, sizeof(float));
}

void
show_pointer(void *pointer) {
    show_bytes((byte_pointer) &pointer, sizeof(void *));
}

int
main() {
    int i = 240;
    float f = 22.2;
    show_int(i);
    show_float(f);
    show_pointer(&f);
    return 0;
}


