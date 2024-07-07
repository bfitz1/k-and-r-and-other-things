#include <stdio.h>

void itoa(int n, char s[]);

int main(void) {
    int n = -12345;
    char s[32] = {0};
    itoa(n, s);

    return 0;
}

// The book's itoa version doesn't work for the largest negative number
// (-2^(wordsize-1)) because of this line:
//
// if ((sign = n) < 0
//     n = -n;
//
// At most n can hold 2^(wordsize-1) - 1, so -n goes over and wraps
// back around.
void itoa(int n, char s[]) {
    // Find the number of digits in n so we can properly offset the
    // null byte
    int offset = 0;
    int remain = n;
    // There's always at least one
    do { 
        offset += 1; 
        remain /= 10;
    } while (remain != 0);

    // Additional offset for the minus sign
    int sign = 1;
    if (n < 0) {
        sign = -1;
        offset += 1;
    }
    
    // Trying to handle both the positive and negative case simultaneously
    int i = 0;
    remain = n;
    do {
        s[offset-1-i] = '0' + sign * (remain % (sign * 10));
        remain /= 10;
        i += 1;
    } while (remain != 0);

    if (sign == -1) {
        s[offset-1-i] = '-';
    }
    s[offset] = '\0';
}
