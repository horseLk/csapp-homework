//
// Created by horse on 2023/4/2.
//

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
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

unsigned question63_srl(unsigned x, int k) {
    unsigned xsra = (int) x >> k;
    int int_len = 8 * sizeof(int);
    // 得到最高位
    int f = x >> (int_len - 1);
    int mask = (f << (int_len - 1)) >> (k - 1);
    return xsra ^ mask;
}

int question63_sra(int x, int k) {
    int xsrl = (unsigned) x >> k;
    int int_len = 8 * sizeof(int);
    int f = (unsigned) x >>  (int_len - 1);
    int mask = (f << (int_len - 1)) >> (k - 1);
    return xsrl | mask;
}

int question64_any_odd_one(unsigned x) {
    int mask = 0x55555555;
    int tmp = x & mask;
    return tmp > 0;
}

// x中1的位数为奇数就返回1，否则返回0
int question65_odd_ones(unsigned x) {
    // 这是第一层的处理，对某一位i而言，通过右移了一位，我们就获取到了i前边的那一位，把他们异或后，
    // 得到的位的值为0或者1，1就表示和前边的一位中有奇数个1，0表示有偶数个1.
    // x右移1位，可以获取到前一位，然后再和前一位异或，就可以得到该位和前一位这两位中1的个数是奇数还是偶数
    // 因为自己和前一位相等就会是0，要么全是两位都是0，要么都是1，所以1的个数一定是偶数
    x ^= (x >> 1);

    // 经过上边的处理后呢，x中每一位的值的意义就不同了，他表示该位和它前边的位1的个数是奇数还是偶数
    //  此时我们再右移2位，就获得了i前边的前边的值j，这个值j表示j和前边一位1的个数是奇数还是偶数
    //  异或后的值就是到j前边，一共四位1的个数是奇数还是偶数
    x ^= (x >> 2);

    // 后面的都是按照上边的原理依次类推的

    x ^= (x >> 4);
    x ^= (x >> 8);
    x ^= (x >> 16);
    return x & 1;
}


int question66_leftmost_one(unsigned x) {
    // 1. 使用或加上移位使得第一个1后面全是1
    x = x | (x >> 1);
    x = x | (x >> 2);
    x = x | (x >> 4);
    x = x | (x >> 8);
    x = x | (x >> 16);
    // 2. 取非后右移一位再清除前面的1即可
    return x & (~x >> 1);
}

// If the value of the right operand is negative or is greater than or equal to the width of the promoted left operand, the behavior is undefined
int question67_int_size_is_32_B() {
    int set_msb = 1 << 31;
    int beyond_msb = set_msb << 1;

    return set_msb && !beyond_msb;
}

int question67_int_size_is_32_C() {
    int set_msb = 1 << 15 << 15 << 1;
    int beyond_msb = set_msb << 1;

    return set_msb && !beyond_msb;
}

int question68_lower_one_mask(int n) {
    unsigned m = sizeof(int) * 8;
    n = m - n;
    unsigned x = -1;
    return x >> n;
}

unsigned question69_rotate_left(unsigned x, int n) {
    int w = sizeof(int) * 8;
    unsigned t = -1;
    t = t >> n;
    unsigned k = ~t;
    unsigned left = x & k;
    unsigned right = x & t;

    right = right << n;
    left = left >> (w - n);
    return left | right;

}

// 如果x的二进制可以用n位表示就返回1，
int question70_fits_bits(int x, int n) {
    int w = sizeof(int) << 3;
    x >>= n - 1;
    /*
     * !(x >> 1) 用于判断x大于0的情况
     * !~x 用于判断x小于0的情况
     */
    return !(x >> 1) || !~x;
}


int xbyte(packed_t word, int bytenum) {
    unsigned x = word >> (bytenum << 3) & 0xFF;
    int m = ((1 << 7) & x) << 1;
    return x - m;
}


void copy_int(int val, void *buf, int maxbytes) {
    if (maxbytes >= (int)sizeof(val)) {
        memcpy(buf, (void*)&val, sizeof(val));
    }
}