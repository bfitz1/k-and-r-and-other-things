#include <stdio.h>

int rightrot(int x, int n);

int main(void) {
    return 0;
}

// Note that right shift is arithmetic and not logical, i.e. brings
// in copies of the leftmost bit if it's set.
//
// Is this a bug? I dunno lmao this problem's pretty vague.
int rightrot(int x, int n) {
    int m = sizeof (int) * 8; 
    int mask = (1 << n) - 1;
    int rightside = x & mask;
    return (x >> n) | (rightside << (m - n));
}
