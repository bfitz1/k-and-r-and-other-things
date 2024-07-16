#include <stdio.h>

int main(void) {
    double getfloat(double *);
    double x = 0;

    printf("Before getfloat call: %g\n", x);
    getfloat(&x);
    printf("After getfloat call: %g\n", x);

    return 0;
}
