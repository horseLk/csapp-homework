#include <stdio.h>
#include <stdbool.h>
#include <limits.h>
#include "chapter2/chapter2.h"

int main() {
    int res = singned_high_prod(INT_MAX, 128);
    printf("%x\n", res);
}
