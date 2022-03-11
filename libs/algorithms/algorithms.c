#include "algorithms.h"

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <time.h>

#define BITS 8
#define EPS 10E-7

void swap(void *a, void *b, size_t size) {
    char *pa = a;
    char *pb = b;
    for (size_t i = 0; i < size; i++) {
        char tmp = *pa;
        *pa = *pb;
        *pb = tmp;
        pa += 1;
        pb += 1;
    }
}

double absf(const double x) {
    return x > 0 ? x : -x;
}

double fastPow(double x, int n) {
    double res = 1;
    while (n != 0) {
        if (n & 1)
            res *= x;
        n >>= 1;
        x *= x;
    }
    return res;
}

double root(const double x, const int n) {
    assert(!(x < 0 && n % 2 != 0));
    assert(n != 0);

    double absX = absf(x);
    double l = 0;
    double r = absX;
    double m = (l + r) / 2;
    double currentResult = fastPow(m, n);
    while (absf(currentResult - absX) > EPS) {
        if (currentResult > absX)
            r = m;
        else
            l = m;

        m = (l + r) / 2;
        currentResult = fastPow(m, n);
    }

    return x > 0 ? m : -m;
}

int abs(const int x) {
    int mask = x >> (sizeof(int) * BITS - 1);

    return (x + mask) ^ mask;
}

int min2(const int x, const int y) {
    return y ^ ((x ^ y) & -(x < y));
}

int max2(const int x, const int y) {
    return x ^ ((x ^ y) & -(x < y));
}

int isDegreeOf2(const int x) {
    return x && !(x & (x - 1));
}

int randit(int a, int b) {
    srand(time(0));

    return rand() % b + a;
}
