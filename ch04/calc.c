#include <stdio.h>

#define MAXLINE 100

double atof(char buf[]);
int str_getline(char buf[], int bufmax);

int main(void) {
    char line[MAXLINE] = {0};

    double sum = 0;
    while (str_getline(line, MAXLINE) > 0) {
        printf("\t%g\n", sum += atof(line));
    }

    return 0;
}
