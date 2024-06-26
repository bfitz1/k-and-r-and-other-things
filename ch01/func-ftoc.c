#include <stdio.h>

double ftoc(double fahrenheit);
double ctof(double celsius);

int main(void) {
    printf(" F           C   \n"); 
    printf("---       -------\n");
    double step = 20.;
    for (double f = 0.; f <= 300.; f += step) {
        printf("%3.0f <---> %7.2f\n", f, ftoc(f));
    }
    return 0;
}

double ftoc(double fahrenheit) {
    return (fahrenheit - 32.) / 1.8;
}

double ctof(double celsius) {
    return (celsius * 1.8) + 32.;
}
