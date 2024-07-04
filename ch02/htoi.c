#include <stdio.h>
#include <string.h>

int htoi(char s[]);

int main(void) {
    return 0;
}

int htoi(char s[]) {
    int i = 0;
    if (s[i] == '0' && (s[i+1] == 'x' || s[i+1] == 'X')) {
        i = 2;
    }

    int sum = 0;
    for (; i < strlen(s); i++) {
        sum *= 16;
        if (s[i] >= 'A' && s[i] <= 'F') {
            sum += s[i] - 'A' + 10;
        } else if (s[i] >= 'a' && s[i] <= 'f') {
            sum += s[i] - 'a' + 10;
        } else {
            sum += s[i] - '0';
        }
    }

    return sum;
}
