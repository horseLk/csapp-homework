#include <stdio.h>
#include <stdbool.h>
#include "chapter2/chapter2.h"

int main() {
    int res = xbyte(0xAABBCCDD, 1);
    printf("%x\n", res);
}
