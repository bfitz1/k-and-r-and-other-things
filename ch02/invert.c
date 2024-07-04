#include <stdio.h>

int invert(int x, int p, int n);

int main(void) {
    return 0;
}

int invert(int x, int p, int n) {
    int mask = (1 << n) - 1;
    mask <<= p;
    return x ^ mask;
}
