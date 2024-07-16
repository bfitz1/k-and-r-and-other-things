#include <stdio.h>

int main(void) {
    int getint(int *);
    int x = 0;

    printf("Before getint call: %d\n", x);
    getint(&x);
    printf("After getint call: %d\n", x);

    return 0;
}
