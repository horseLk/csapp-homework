//
// Created by horse on 2023/4/2.
//

#ifndef UNTITLED_CHAPTER2_H
#define UNTITLED_CHAPTER2_H

#endif //UNTITLED_CHAPTER2_H

typedef unsigned packed_t;
typedef unsigned float_bits;

void show_int(int x);
void show_float(float x);
void show_pointer(void *x);
void show_short(short x);
void show_long(long x);
void show_double(double x);

void question55_show_pc_byte();
void question56_show_byte_with_diff_value();
void question57_other_type();
int question58_is_little_endian();
void* question59_generate_word(void* x, void *y);
unsigned question60_replace_byte(unsigned x, int i, unsigned char b);
int question61_judge_int(int x);
int question62_int_shift_are_arithmetic();
unsigned question63_srl(unsigned x, int k);
int question63_sra(int x, int k);
int question64_any_odd_one(unsigned x);
int question65_odd_ones(unsigned x);
int question66_leftmost_one(unsigned x);
int question67_int_size_is_32_B();
int question67_int_size_is_32_C();
int question68_lower_one_mask(int n);
unsigned question69_rotate_left(unsigned x, int n);
int question70_fits_bits(int x, int n);
int question71_xbyte(packed_t word, int bytenum);
void question72_copy_int(int val, void *buf, int maxbytes);
int question73_saturating_add(int x, int y);
int question74_tsub_ok(int x, int y);
unsigned question75_unsigned_hign_prod(unsigned x, unsigned y);
int singned_high_prod(int x, int y);
void *question76_myCalloc(size_t nmemb, size_t size);
void *myMalloc(size_t size);
void *myMemset(void *s, int c, size_t n);
int question78_divide_power2(int x, int y);
int question79_multi3divi4(int x);
int question80_threefourths(int x);
int question81_A(int k);
int question81_B(int j, int k);
int question84_float_le(float x, float y);
float_bits question92_float_negate(float_bits f);
float_bits question93_float_absval(float_bits f);
float_bits question94_float_twice(float_bits f);
float_bits question95_float_half(float_bits f);
float_bits question96_float_f2i(float_bits f);
float_bits question97_float_i2f(int i);
int bits_length(int i);
unsigned my_bits_mask(int l);