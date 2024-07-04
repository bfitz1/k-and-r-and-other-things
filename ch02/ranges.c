#include <stdio.h>
#include <limits.h>
#include <float.h>

int main(void) {
    printf("Ranges of signed chars: %d - %d\n", SCHAR_MIN, SCHAR_MAX);
    printf("Ranges of unsigned chars: %u - %u\n", 0, UCHAR_MAX);
    printf("Ranges of signed short: %d - %d\n", SHRT_MIN, SHRT_MAX);
    printf("Ranges of unsigned short: %u - %u\n", 0, USHRT_MAX);
    printf("Ranges of signed int: %d - %d\n", INT_MIN, INT_MAX);
    printf("Ranges of unsigned int: %u - %u\n", 0, UINT_MAX);
    printf("Ranges of signed long: %ld - %ld\n", LONG_MIN, LONG_MAX);
    printf("Ranges of unsigned long: %d - %lu\n", 0, ULONG_MAX);
    printf("Ranges of float: %f - %f\n", FLT_MIN, FLT_MAX);
    printf("Ranges of double: %f - %f\n", DBL_MIN, DBL_MAX);
    printf("Ranges of long double: %Lf - %Lf\n", LDBL_MIN, LDBL_MAX);
    return 0;
}
