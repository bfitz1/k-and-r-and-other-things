#include <stdio.h>

int setbits(int x, int p, int n, int y);

int main(void) {
    return 0;
}

int setbits(int x, int p, int n, int y) {
    int pmask = (1 << p) - 1;
    int nmask = (1 << n) - 1;
    int pnmask = (~0 << (p + n)) | pmask;
    int ybits = y & nmask;
    return (x & pnmask) | (ybits << p);
}
