#include <stdio.h>
#include <stdbool.h>
#include <limits.h>
#include "chapter2/chapter2.h"

int main() {
    int x = 12346;
    float_bits res = question97_float_i2f(x);
    float* f = (&res);
    printf("%f\n", f);
}
