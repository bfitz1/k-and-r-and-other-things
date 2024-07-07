#include <stdio.h>

void expand(char s1[], char s2[]);
int expand_aux(char left, char right, char s[], int j);

int main(void) {
    return 0;
}

void expand(char s1[], char s2[]) {
    int i = 0;
    int j = 0;
    s2[j] = '\0';
    while (s1[i] != '\0') {
        switch (s1[i]) {
        case '-':
            if (i == 0 || s1[i+1] == '\0') { // Leading/Trailing dash
                s2[j] = '-';
                i += 1;
                j += 1;
            } else {
                j = expand_aux(s1[i-1], s1[i+1], s2, j);
                i += 2;
            }
            break;
        default:
            s2[j] = s1[i];
            i += 1;
            j += 1;
            break;
        }
    }
    s2[j] = '\0';
}

int expand_aux(char left, char right, char s[], int j) {
    left += 1;
    while (left <= right) {
        s[j] = left;
        j += 1; 
        left += 1;
    }
    return j;
}
