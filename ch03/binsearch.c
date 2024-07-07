#include <stdio.h>

int binsearch(int x, int v[], int n);

int main(void) {
    int v[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    return 0;
}

// Not 100% confident this doesn't break in some weird way.
int binsearch(int x, int v[], int n) {
    int low = 0;
    int high = n - 1;

    int mid;
    while (low <= high) {
        mid = low + (high - low)/2;
        if (x < v[mid]) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    if (x == v[low]) {
        return low;
    } else if (x == v[mid]) {
        return mid;
    } else if (x == v[high]) {
        return high;
    } else {
        return -1;
    }
}
