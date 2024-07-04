#include <stdio.h>
#include <string.h>

int any(char s1[], char s2[]);

int main(void) {
    printf("any('crystal', 'aeiou') ==> %d\n", any("crystal", "aeiou"));
    printf("any('flute', 'aeiou') ==> %d\n", any("flute", "aeiou"));
    printf("any('xyz', 'aeiou') ==> %d\n", any("xyz", "aeiou"));
    return 0;
}

int any(char s1[], char s2[]) {
    for (int i = 0; i < strlen(s1); i++) {
        for (int j = 0; j < strlen(s2); j++) {
            if (s1[i] == s2[j]) {
                return i;
            }
        }
    }
    return -1;
}
