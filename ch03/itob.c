#include <stdio.h>

void itob(int n, char s[], int b);

int main(void) {
    int n = 12345;
    char s[16] = {0};
    int b = 10;
    itob(n, s, b);

    return 0;
}

// There's some weirdness when it comes to representing negative numbers
// in other bases. It seems to work out if you compute it, though.
void itob(int n, char s[], int b) {
    // Compute the offset for the null byte
    // Start by reserving space for digits
    int offset = 0;
    int remain = n;
    do {
        offset += 1;
        remain /= b;
    } while (remain != 0);

    // Reserve space for a minus sign if needed
    int sign = 1;
    if (n < 0) {
        sign = -1;
        offset += 1;
    }

    // Reserve space for some extra symbols if needed
    if (b == 2 || b == 8 || b == 16) {
        offset += 2;
    }

    // This does assume that the user would never ask for a base larger
    // than hexadecimal.
    char digits[] = "0123456789abcdef";
    int i = 0;
    remain = n;
    do {
        s[offset-1-i] = digits[sign * (remain % (sign * b))];
        remain /= b;
        i += 1;
    } while (remain != 0);

    // 0b (binary), 0o (octal), and 0x (hex) symbols precede the digits
    if (b == 2 || b == 8 || b == 16) {
        s[offset-2-i] = '0';
        s[offset-1-i] = b == 2 ? 'b' : b == 8 ? 'o' : 'x';
        i += 2;
    }
    
    // The minus sign (if it exists) precedes everything
    if (sign == -1) {
        s[offset-1-i] = '-';
    }

    s[offset] = '\0';
}
