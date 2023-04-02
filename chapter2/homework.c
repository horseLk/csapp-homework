//
// Created by horse on 2023/4/2.
//

#include <stdio.h>
#include <stdbool.h>
#include "chapter2.h"

void question55_show_pc_byte() {
    int x = 0x12345678;
    show_int(x);
}

void question56_show_byte_with_diff_value() {
    int x = 356173;
    float f = 19748239.342423f;
    char ch = '1';
    char *pCh = &ch;

    show_int(x);
    show_float(f);
    show_pointer(pCh);
}

void question57_other_type() {
    // 实现short\long\double的字节展示
    // 代码见show-byte.c
    short s = 0x1234;
    long l = 64319457L;
    double d = 123443.8439843;

    show_short(s);
    show_long(l);
    show_double(d);
}

int question58_is_little_endian() {
    int x = 0x01234567;
    char* ch = &x;
    if (*ch == 0x67) {
        return 1;
    }
    return 0;
}

void* question59_generate_word(void* x, void *y) {
    long xl = x;
    long yl = y;
    long res_long = (xl & 0xFF) | (yl & (0xFFFFFFFFFFFFFFFF << 8));
    return (void*)res_long;
}

unsigned question60_replace_byte(unsigned x, int i, unsigned char b) {
    if (i < 0) {
        return x;
    }
    unsigned tmp = ~(0xFF << (i * 8));
    unsigned target = ((unsigned)b) << (i * 8);
    return x & tmp | target;
}

int question61_judge_int(int x) {
    printf("x is %d\n", x);
    int tmp = 0xFF << ((sizeof(int) - 1) * 8);
    int all_one = -1;
    return !((x & 0xFF) ^ 0xFF) || !((x & tmp) ^ 0) || !(x ^ 0) || !(x ^ all_one);
}

int question62_int_shift_are_arithmetic() {
    int x = (-1 >> (sizeof(int) * 8 - 1)) >> 1;
    printf("%x\n", x);
    return x & 1;
}