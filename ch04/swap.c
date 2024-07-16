#include <stdio.h>

#define swap(t,x,y) { t temp = x; x = y; y = temp; }

int main(void) {
    int x = 1;
    int y = 2;
    printf("Before swapping: (x, y) = (%d, %d)\n", x, y);
    swap(int, x, y);
    printf("After swapping: (x, y) = (%d, %d)\n", x, y);

    return 0;
}
