void my_strcat(char s[], char t[]) {
    while (*s != '\0') s += 1;
    while (*t != '\0') {
        *s = *t;
        s += 1;
        t += 1;
    }
    *s = '\0';
}

int my_strend(char s[], char t[]) {
    int i = 0;
    while (s[i] != '\0') i += 1;

    int j = 0;
    while (t[j] != '\0') j += 1;

    while (i >= 0 && j >= 0 && s[i] == t[j]) {
        i -= 1;
        j -= 1;
    }

    return j < 0;
}

char *my_strncpy(char s[], char t[], int n) {
    int i = 0;
    while (i < n && t[i] != '\0') {
        s[i] = t[i];
        i += 1;
    }
    while (i < n) {
        s[i] = '\0';
        i += 1;
    }

    return s;
}

char *my_strncat(char s[], char t[], int n) {
    int i = 0;
    while (s[i] != '\0') i += 1;

    int j = 0;
    while (j < n-1 && t[i] != '\0') {
        s[i+j] = t[j];
        j += 1;
    }
    s[i+j] = '\0';

    return s;
}

int my_strncmp(char s[], char t[], int n) {
    int i = 0;
    while (i < n && s[i] != '\0' && t[i] != '\0' && s[i] == t[i]) i += 1;

    return s[i] - t[i];
}
