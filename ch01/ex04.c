#include <stdio.h>

int main(void) {
    float step = 7.0;
    float low = -20.0;
    float high = 100.0;

    printf(" C \t   F   \n");
    printf("---\t-------\n");
    for (float celsius = low; celsius < high; celsius += step) {
        float fahrenheit = celsius * (9.0/5.0) + 32.0;
        printf("%3.0f\t%7.1f\n", celsius, fahrenheit);
    }
    return 0;
}
