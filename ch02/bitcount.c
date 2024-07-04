#include <stdio.h>

int bitcount(unsigned x);

int main(void) {
    return 0;
}

// There's a couple things happening here.
// First note that (1) x & x == x, and that (2) x & ~0 = x as well.
// Say that bit n is the rightmost set bit in x. Then x - 1 sets every
// bit from position 0 to n-1 until it reaches n. The nth bit is cleared.
// So what's left is the bitwise-and operation. The left of bit n is
// originally x, so we recover the left per (1). The right side of bit n
// is all 1s, so we also recover the right per (2). Finally, bit n is 0,
// so that gets turned off.
//
// The new version of bitcount takes advantage of this by only looping as
// many times as there are set bits in x, and not for how wide x may be.
int bitcount(unsigned x) {
    int b = 0;
    while (x > 0) {
        b += 1;
        x &= x - 1;
    }
    return b;
}
