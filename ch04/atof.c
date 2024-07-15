#include <ctype.h>

double atof(char buf[]);
int atoi(char buf[]);

// This feels like a state machine in disguise; I wonder if there's
// a better way of expressing this kind of pattern. 
double atof(char buf[]) {
    int i = 0;
    while (isspace(buf[i])) {
        i += 1;
    }

    int sign = 1;
    if (buf[i] == '+') {
        i += 1;
    } else if (buf[i] == '-') {
        sign = -1;
        i += 1;
    }
    
    double val = 0;
    while (isdigit(buf[i])) {
        val *= 10;
        val += buf[i] - '0';
        i += 1;
    }

    if (buf[i] == '.') {
        i += 1;
    }

    double power = 1;
    while (isdigit(buf[i])) {
        power *= 10;
        val *= 10;
        val += buf[i] - '0';
        i += 1;
    }

    double ep = 1;
    double en = 1;
    if (buf[i] == 'E' || buf[i] == 'e') {
        i += 1;

        int exp = atoi(buf + i);
        while (exp > 0) {
            ep *= 10;
            exp -= 1;
        }
        while (exp < 0) {
            en *= 10;
            exp += 1;
        }
    }

    return sign * val / power * ep / en;
}

int atoi(char buf[]) {
    return (int) atof(buf);
}
