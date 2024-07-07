#include <stdio.h>

void escape(char s[], char t[]);
void unescape(char s[], char t[]);

int main(void) {
    char t[] = "lets\ntry\tthis\n\tok?";
    char s1[64] = {0};
    char s2[64] = {0};

    printf("%s\n", t);
    escape(s1, t);
    printf("%s\n", s1);
    unescape(s2, s1);
    printf("%s\n", s2);

    return 0;
}

void escape(char s[], char t[]) {
    int i = 0;
    int j = 0;
    while (t[j] != '\0') {
        switch (t[j]) {
        case '\n':
            s[i] = '\\';
            s[i+1] = 'n';
            i += 2;
            j += 1;
            break;
        case '\t':
            s[i] = '\\';
            s[i+1] = 't';
            i += 2;
            j += 1;
            break;
        default:
            s[i] = t[j];
            i += 1;
            j += 1;
            break;
        }
    }
    s[i] = '\0';
}

void unescape(char s[], char t[]) {
    int i = 0;
    int j = 0;
    while (t[j] != '\0') {
        switch (t[j]) {
        case '\\':
            switch (t[j+1]) {
            case 'n':
                s[i] = '\n';
                i += 1;
                j += 1;
                break;
            case 't':
                s[i] = '\t';
                i += 1;
                j += 1;
                break;
            default:
                s[i] = '\\';
                i += 1;
                break;
            }
            j += 1;
            break;
        default:
            s[i] = t[j];
            i += 1;
            j += 1;
            break;
        }
    }
    s[i] = '\0';
}
