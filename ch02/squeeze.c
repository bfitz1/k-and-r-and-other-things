#include <stdio.h>

void squeeze(char s1[], char s2[]);

int main(void) {
    // Don't think the book went over this yet but this is a quick way of
    // allocating a buffer to fit the given string.
    char test[] = "testingxxxifxyzthiszyxideazzyyxxworks";
    squeeze(test, "xyz");
    printf("%s\n", test);
    return 0;
}

void squeeze(char s1[], char s2[]) {
    for (int i = 0; s2[i] != '\0'; i++) {
        int j = 0;
        char ch = s2[i];
        for (int k = 0; s1[k] != '\0'; k++) {
            if (s1[k] != ch) {
                s1[j++] = s1[k];
            }
        }
        s1[j] = '\0';
    }
}
