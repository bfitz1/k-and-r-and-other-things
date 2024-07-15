#include <ctype.h>

static char *digits = "0123456789abcdef";

static char *itoa_rec(int n, char buf[], int base) {
    int div = n / base;
    int mod = n % base;
    if (div) {
       buf = itoa_rec(div, buf, base); 
    }

    buf[0] = digits[mod];
    buf[1] = '\0';

    return buf + 1;
}

void itoa(int n, char buf[], int base) {
    if (n < 0) {
        buf[0] = '-';
        itoa(-n, buf + 1, base);
        return;
    }
    
    switch (base) {
    case 2:
        buf[0] = '0';
        buf[1] = 'b';
        itoa_rec(n, buf + 2, base);
        break;
    case 8:
        buf[0] = '0';
        buf[1] = 'o';
        itoa_rec(n, buf + 2, base);
        break;
    case 16:
        buf[0] = '0';
        buf[1] = 'x';
        itoa_rec(n, buf + 2, base);
        break;
    default:
        itoa_rec(n, buf, base);
        break;
    }
}
