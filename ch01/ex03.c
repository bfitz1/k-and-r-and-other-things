#include <stdio.h>

// Convert Fahrenheit to Celsius using <degrees-C> = (5/9)(<degrees-F> - 32)
int main(void) {
    float lower = 0.;
    float upper = 300.;
    float step = 20.;

    printf(" F \t   C   \n");
    printf("---\t-------\n");
    float fahr = lower;
    while (fahr <= upper) {
        float celsius = (5./9.) * (fahr - 32.);
        printf("%3.0f\t%6.1f\n", fahr, celsius);
        fahr = fahr + step;
    }

    return 0;
}
