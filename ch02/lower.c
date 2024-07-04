#include <stdio.h>

void lower(char s[]);

int main(void) {
    return 0;
}

void lower(char s[]) {
    while (*s != '\0') {
        *s = (*s >= 'A' && *s <= 'Z') ? (*s - 'A' + 'a') : *s;
        s++;
    }
}
