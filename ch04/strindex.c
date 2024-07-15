#include <stdio.h>

// Helper function that makes strindex and strrindex easier to implement
int strisprefix(char buf[], char find[]) {
    int i = 0;
    for (; buf[i] != '\0' && find[i] != '\0'; i += 1) {
        if (buf[i] != find[i]) {
            return 0;
        }
    }
    return find[i] == '\0';
}

int strindex(char buf[], char find[]) {
    for (int i = 0; buf[i] != '\0'; i += 1) {
        if (strisprefix(buf + i, find)) {
            return i;
        }
    }
    return -1;
}

int strrindex(char buf[], char find[]) {
    int result = strindex(buf, find);
    if (result == -1) {
        return -1;
    }

    int next = strindex(buf + result + 1, find);
    while (next > -1) {
        result += next + 1;
        next = strindex(buf + result + 1, find);
    }

    return result;
}
