/* func_L33_003AF098: 129 diff with the file's flags. Retail keeps (s32)f in an FPU register (cvt.w.s then cvt.s.w, no mfc1/mtc1) in all 6 f - (f32)(s32)f sites: needs the disallowed one-instruction asm pair (func_003A4860 pattern), so plain C cannot match. Also float temp is $f20 in retail vs $f1/$f21 here, and retail stores E21xx via $at, mine via $v0. */
INCLUDE_ASM("asm/levels", func_L33_003AF098);

#if 0
typedef int u128_t __attribute__((mode(TI)));
extern f32 func_L03_0034B440(s32, s32, s32, f32, f32, f32);
extern f32 func_003C4088(f32, f32, f32);
extern s32 func_0038DBD8(s32, s32, f32);
__asm__(".extern D_L33_001DEE14, 4");
__asm__(".extern D_L33_001DEE10, 4");
__asm__(".extern D_L33_001DEE0C, 4");
__asm__(".extern D_L33_001DEE08, 4");
__asm__(".extern D_L33_001DEE04, 4");
__asm__(".extern D_L33_001DEE1C, 4");
__asm__(".extern D_L33_001DEE50, 4");
__asm__(".extern D_L33_001DEE4C, 4");
__asm__(".extern D_L33_001DEE5C, 4");
__asm__(".extern D_L33_001DEE58, 4");
__asm__(".extern D_L33_001DEE18, 4");
__asm__(".extern D_L33_001DEE30, 4");
__asm__(".extern D_L33_001DEE2C, 4");
__asm__(".extern D_L33_001DEE28, 4");
__asm__(".extern D_L33_001DEE24, 4");
__asm__(".extern D_L33_001DEE20, 4");
__asm__(".extern D_L33_001DEE44, 4");
__asm__(".extern D_L33_001DEE40, 4");
__asm__(".extern D_L33_001DEE3C, 4");
__asm__(".extern D_L33_001DEE38, 4");
__asm__(".extern D_L33_001DEE34, 4");
extern s32 D_L33_001DF6C0;
extern f32 D_L33_001DEE14;
extern f32 D_L33_001DEE10;
extern f32 D_L33_001DEE0C;
extern f32 D_L33_001DEE08;
extern f32 D_L33_001DEE04;
extern s32 D_L33_001DEE1C;
extern s32 D_L33_001DEE50;
extern s32 D_L33_001DEE4C;
extern s32 D_L33_001DEE5C;
extern s32 D_L33_001DEE58;
extern f32 D_L33_001DEE18;
extern f32 D_L33_001DEE30;
extern f32 D_L33_001DEE2C;
extern f32 D_L33_001DEE28;
extern f32 D_L33_001DEE24;
extern f32 D_L33_001DEE20;
extern f32 D_L33_001DEE44;
extern f32 D_L33_001DEE40;
extern f32 D_L33_001DEE3C;
extern f32 D_L33_001DEE38;
extern f32 D_L33_001DEE34;
extern f32 D_L33_001E21BC[];
extern f32 D_L33_001E21C0[];
extern f32 D_L33_001E21AC[];
extern f32 D_L33_001E21B0[];
extern f32 D_L33_001E21B4[];
extern f32 D_L33_001E21B8[];

void func_L33_003AF098(char *obj) {
    char *p = *(char **)(obj + 0x68);
    u128_t a = *(u128_t *)p;
    u128_t b = *(u128_t *)(p + 0x10);
    f32 f;

    *(u128_t *)(p + 0x30) = a;
    *(u128_t *)(p + 0x40) = b;
    f = *(f32 *)(p + 0xE4) + func_L03_0034B440(0, 0, 5, (f32)D_L33_001DF6C0, D_L33_001DEE14, 1.0f);
    f -= (f32)(s32)f;
    D_L33_001E21BC[0] = func_003C4088(D_L33_001DEE10, D_L33_001DEE0C, f);
    D_L33_001E21C0[0] = func_003C4088(D_L33_001DEE08, D_L33_001DEE04, f);
    f = *(f32 *)(p + 0xE0) + func_L03_0034B440(0, 0, 5, (f32)D_L33_001DF6C0, (f32)D_L33_001DEE1C, 1.0f);
    f -= (f32)(s32)f;
    *(s32 *)(p + 0x50) = func_0038DBD8(D_L33_001DEE50, D_L33_001DEE4C, f);
    *(s32 *)(p + 0x58) = func_0038DBD8(D_L33_001DEE5C, D_L33_001DEE58, f);
    f += D_L33_001DEE18;
    f -= (f32)(s32)f;
    *(s32 *)(p + 0x54) = func_0038DBD8(D_L33_001DEE50, D_L33_001DEE4C, f);
    *(s32 *)(p + 0x5C) = func_0038DBD8(D_L33_001DEE5C, D_L33_001DEE58, f);
    f = *(f32 *)(p + 0xEC) + func_L03_0034B440(0, 0, 5, (f32)D_L33_001DF6C0, D_L33_001DEE30, 1.0f);
    f -= (f32)(s32)f;
    D_L33_001E21AC[0] = func_003C4088(D_L33_001DEE2C, D_L33_001DEE28, f);
    D_L33_001E21B0[0] = func_003C4088(D_L33_001DEE24, D_L33_001DEE20, f);
    f = *(f32 *)(p + 0xEC) + func_L03_0034B440(0, 0, 5, (f32)D_L33_001DF6C0, D_L33_001DEE44, 1.0f);
    f -= (f32)(s32)f;
    D_L33_001E21B4[0] = func_003C4088(D_L33_001DEE40, D_L33_001DEE3C, f);
    D_L33_001E21B8[0] = func_003C4088(D_L33_001DEE38, D_L33_001DEE34, f);
}
#endif
