#include "common.h"

/* localdecomp:start func_L01_00356C88 */
void func_L01_00356C88(void) {

}
/* localdecomp:end func_L01_00356C88 */

/* localdecomp:start func_L01_00356C90 */
void func_L01_00356C90(void) {

}
/* localdecomp:end func_L01_00356C90 */

INCLUDE_ASM("asm/levels", func_L01_00356C98);

INCLUDE_ASM("asm/levels", func_L01_00357E70);

INCLUDE_ASM("asm/levels", func_L01_00358090);

INCLUDE_ASM("asm/levels", func_L01_00358238);

INCLUDE_ASM("asm/levels", func_L01_00358338);

INCLUDE_ASM("asm/levels", func_L01_003586F8);

/* localdecomp:start func_L01_003589B0 */
typedef int u128_t __attribute__((mode(TI)));
typedef union {
    u128_t q;
    f32 f[4];
} Vec4;

typedef struct {
    Vec4 v;
    u8 *o;
    s32 pad14;
    u8 b18;
    u8 b19;
    u16 h1A;
    u8 pad1C[20];
} S_357DC0;

extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);
extern void func_0038CE20(f32 *, void *, f32);
extern void func_L01_00446760(S_357DC0 *s, u8 *o, s32 a, Vec4 *v, f32 f);
extern s32 func_003D3CB0(s32 a, s32 b, s32 c, u8 *o, S_357DC0 *s);
extern u8 D_001A4BE0[];

s32 func_L01_003589B0(u8 *a0, s32 a1, s32 a2, s32 a3, s32 a4, s32 a5, s32 a6, f32 f12, f32 f13) {
    Vec4 v;
    S_357DC0 s;
    u8 *b;
    u8 *p;
    s32 r;

    if (*(u16 *)(a0 + 52) & 0x100) {
        v.q = *(u128_t *)(a0 + 192);
    } else {
        v.f[0] = func_0038D098(*(f32 *)(a0 + 248));
        v.f[1] = func_0038D0B0(*(f32 *)(a0 + 248));
        v.f[2] = 0.0f;
    }
    func_0038CE20(v.f, v.f, f13);
    v.f[2] = 1.0f;
    v.f[3] = 5627.9248046875f;
    func_L01_00446760(&s, a0, a3, &v, f12);
    b = D_001A4BE0;
    s.b18 = a4;
    s.b19 = a5;
    s.h1A = *(u16 *)(a0 + 170);
    s.o = a0;
    *(s32 *)(*(u8 **)(b + 9664) + 152) = 0;
    r = func_003D3CB0(a1, a2, a6, a0, &s);
    p = *(u8 **)(b + 9664);
    *(s32 *)(p + 152) = *(s32 *)(*(u8 **)(p + 36) + 16);
    return r;
}
/* localdecomp:end func_L01_003589B0 */

INCLUDE_ASM("asm/levels", func_L01_00358B00);

LINKER_REMNANT("asm/levels", func_L01_00359E08);

INCLUDE_ASM("asm/levels", func_L01_00359E10);

/* localdecomp:start func_L01_0035A190 */
void func_L01_0035A190(u8 *p)
{
    *(unsigned long *)(p + 128) = 0xFF9000000260;
    *(unsigned long *)(p + 112) = 0;
    *(f32 *)(p + 80) = 0.0f;
    *(f32 *)(p + 84) = 0.0f;
    *(f32 *)(p + 88) = 1.0f;
    *(f32 *)(p + 92) = 0.0f;
    *(f32 *)(p + 96) = 0.0f;
    *(f32 *)(p + 100) = 1.0f;
    *(f32 *)(p + 104) = 1.0f;
    *(f32 *)(p + 108) = 1.0f;
    *(f32 *)(p + 8) = -1.0f;
    *(f32 *)(p + 24) = 1.0f;
    *(f32 *)(p + 40) = -1.0f;
    *(f32 *)(p + 56) = 1.0f;
    *(f32 *)(p + 4) = -1.0f;
    *(f32 *)(p + 36) = 1.0f;
    *(f32 *)(p + 52) = 1.0f;
    *(f32 *)(p + 0) = 0.0f;
    *(f32 *)(p + 16) = 0.0f;
    *(f32 *)(p + 32) = 0.0f;
    *(f32 *)(p + 48) = 0.0f;
    *(f32 *)(p + 12) = 1.0f;
    *(f32 *)(p + 28) = 1.0f;
    *(f32 *)(p + 20) = -1.0f;
    *(f32 *)(p + 44) = 1.0f;
    *(f32 *)(p + 60) = 1.0f;
}
/* localdecomp:end func_L01_0035A190 */

INCLUDE_ASM("asm/levels", func_L01_0035A218);

INCLUDE_ASM("asm/levels", func_L01_0035A6B0);

INCLUDE_ASM("asm/levels", func_L01_0035AB50);

INCLUDE_ASM("asm/levels", func_L01_0035ABB8);

INCLUDE_ASM("asm/levels", func_L01_0035AC28);

INCLUDE_ASM("asm/levels", func_L01_0035AEB8);

INCLUDE_ASM("asm/levels", func_L01_0035B0A0);

INCLUDE_ASM("asm/levels", func_L01_0035B5A0);
