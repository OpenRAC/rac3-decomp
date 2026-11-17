#include "common.h"
#include "vu0.h"

typedef int u128_t __attribute__((mode(TI)));
typedef union {
    u128_t q;
    f32 f[4];
} Vec4;
typedef int s128 __attribute__((mode(TI)));

INCLUDE_ASM("asm/levels", func_L01_002FEA20);

/* localdecomp:start func_L01_002FFBC8 */
extern u8 *func_003C24B0(s32, s32);
extern void func_L01_0043B9E8(u8 *, s32, s32, s32);
extern void func_003C2F58(u8 *, s32, u8 *);
extern void func_003C3A10(u8 *, s32, s32, s32);
extern void func_003C7C38(u8 *);
u8 *func_L01_002FFBC8(u8 *src, f32 f12) {
    u8 *m;
    u8 *pv;
    m = func_003C24B0(209, 128);
    if (m != 0) {
        pv = *(u8 **)(m + 104);
        *(u8 **)pv = src;
        *(f32 *)(pv + 4) = f12;
        m[49] = 0;
        m[48] = 255;
        *(s16 *)(m + 50) = 255;
        func_L01_0043B9E8(m, 128, 128, 128);
        func_003C2F58(src, 0, m + 16);
        *(u128_t *)(m + 192) = *(u128_t *)(src + 192);
        *(u128_t *)(m + 208) = *(u128_t *)(src + 208);
        *(u128_t *)(m + 224) = *(u128_t *)(src + 224);
        if (m[67] != 0)
            func_003C3A10(m, 0, 0, 8);
        func_003C7C38(m);
        m[32] = 0;
        *(u16 *)(m + 52) |= 5;
        m[49] = 0;
    }
    return m;
}
/* localdecomp:end func_L01_002FFBC8 */

INCLUDE_ASM("asm/levels", func_L01_002FFCA8);

INCLUDE_ASM("asm/levels", func_L01_002FFF00);

LINKER_REMNANT("asm/levels", func_L01_002FFFE8);

/* localdecomp:start func_L01_002FFFF0 */
extern u8 *func_003C4D58(u8 *);
extern void func_0038D328(void *, void *);
extern void func_0038D5B0(void *, void *);
extern void func_0038D000(void *, void *, void *);
extern void func_0038D5F0(void *, void *, void *);
void func_L01_002FFFF0(u8 *a, u8 *b) {
    u8 m0[64];
    u8 m1[64];
    u8 m2[64];
    u8 *r;
    r = func_003C4D58(b);
    if (r != 0) {
        func_0038D328(m0, r);
        vec_add_ba(a + 16, a + 16, r + 16);
        vec_sub_ab(a + 16, a + 16, b + 16);
        if (*(s32 *)(r + 60) & 2) {
            func_0038D328(m2, r + 32);
            func_0038D5B0(m1, m2);
            func_0038D000(a + 16, a + 16, m1);
            func_0038D000(a + 16, a + 16, b + 192);
        } else {
            func_0038D000(a + 16, a + 16, m0);
        }
        vec_add_ba(a + 16, a + 16, b + 16);
        func_0038D5F0(a + 192, m0, a + 192);
    }
}
/* localdecomp:end func_L01_002FFFF0 */

INCLUDE_ASM("asm/levels", func_L01_003000F8);

INCLUDE_ASM("asm/levels", func_L01_003002A8);

INCLUDE_ASM("asm/levels", func_L01_00300550);

INCLUDE_ASM("asm/levels", func_L01_00300678);

/* localdecomp:start func_L01_003006C0 */
extern u8 *func_003C24B0(s32, s32);
extern void func_L01_0044A7D0(u8 *);
extern void func_003C7C38(u8 *);
u8 *func_L01_003006C0(u8 *src, u128_t *pos, s32 arg, u128_t *alt) {
    u8 *m;
    u8 *pv;
    m = func_003C24B0(639, 128);
    if (m != 0) {
        m[48] = 255;
        m[49] = 1;
        *(u16 *)(m + 52) |= 1;
        m[32] = 0;
        m[188] = 0;
        pv = *(u8 **)(m + 104);
        *(u128_t *)(m + 16) = *pos;
        if (alt != 0)
            *(u128_t *)pv = *alt;
        else
            *(u128_t *)pv = *(u128_t *)src;
        *(s32 *)(pv + 32) = arg;
        *(s16 *)(m + 50) = src[60];
        pv[36] = src[16];
        pv[37] = src[17];
        pv[38] = src[18];
        pv[39] = src[19];
        pv[40] = src[20];
        pv[41] = src[21];
        pv[104] = src[61];
        *(u16 *)(pv + 108) = *(u16 *)(src + 64);
        pv[42] = src[22];
        pv[43] = src[23];
        pv[44] = src[24];
        pv[45] = src[25];
        pv[46] = src[26];
        pv[105] = src[62];
        *(u16 *)(pv + 110) = *(u16 *)(src + 66);
        pv[47] = src[27];
        pv[48] = src[28];
        pv[49] = src[29];
        pv[50] = src[30];
        pv[51] = src[31];
        pv[106] = src[63];
        *(u16 *)(pv + 112) = *(u16 *)(src + 68);
        *(f32 *)(pv + 52) = *(f32 *)(src + 32);
        *(f32 *)(pv + 56) = *(f32 *)(src + 36);
        *(f32 *)(pv + 60) = *(f32 *)(src + 40);
        *(f32 *)(pv + 64) = *(f32 *)(src + 44);
        *(f32 *)(pv + 68) = *(f32 *)(src + 48);
        pv[107] = src[72];
        *(u16 *)(pv + 114) = *(u16 *)(src + 70);
        *(s32 *)(pv + 72) = *(s32 *)(src + 52);
        *(s32 *)(pv + 76) = *(s32 *)(src + 56);
        pv[28] = src[73];
        *(s32 *)(pv + 100) = -1;
        func_003C7C38(m);
        func_L01_0044A7D0(m);
    }
    return m;
}
/* localdecomp:end func_L01_003006C0 */

INCLUDE_ASM("asm/levels", func_L01_00300890);

/* localdecomp:start func_L01_00301558 */

extern s32 D_L01_001D673C_00301558;
extern u8 *func_003C24B0(s32, s32);
extern void func_L01_0044A7D0(u8 *);
extern void func_L01_0043B9E8(u8 *, s32, s32, s32);
extern f32 func_00382538(void);
extern void func_003C5180(u8 *, Vec4 *, s32);
extern void func_L01_004515D8(u8 *, Vec4 *, Vec4 *);
extern void func_003C48A8(u8 *, u8 *);
extern void func_003C7C38(u8 *);

u8 *func_L01_00301558(Vec4 *pos, Vec4 *dir, u8 type, f32 scale, f32 f13) {
    Vec4 v;
    Vec4 mt[3];
    u8 *m;
    u8 *pv;

    m = func_003C24B0(775, 128);
    if (m != 0) {
        pv = *(u8 **)(m + 104);
        func_L01_0044A7D0(m);
        func_L01_0043B9E8(m, 40, 40, 70);
        m[48] = 255;
        *(s16 *)(m + 50) = 64;
        *(f32 *)(m + 44) *= scale;
        *(f32 *)pv = f13;
        pv[4] = type;
        *(u128_t *)(m + 16) = pos->q;
        *(f32 *)(m + 248) = func_00382538();
        if (dir->f[0] != 0.0f && dir->f[1] != 0.0f && dir->f[2] != 0.0f) {
            *(u128_t *)(m + 240) = dir->q;
        } else if (D_L01_001D673C_00301558 != 0) {
            func_003C5180(m + 16, &v, 0);
            func_L01_004515D8(m + 192, &v, mt);
            func_003C48A8(m + 192, m + 240);
        }
        func_003C7C38(m);
    }
    return m;
}
/* localdecomp:end func_L01_00301558 */

/* localdecomp:start func_L01_003016B0 */
extern u8 *func_L01_00301558(Vec4 *pos, Vec4 *dir, u8 type, f32 scale, f32 f13);
extern u8 D_L01_001D66B0[];


void func_L01_003016B0(s32 a0, u8 a1) {
    ((void (*)(s32 a0, u8 *a1, u8 a2))func_L01_00301558)(a0, D_L01_001D66B0, a1);
}
/* localdecomp:end func_L01_003016B0 */

/* localdecomp:start func_L01_003016D8 */
extern s32 D_L01_001D673C[];
extern void func_003C2880(u8 *);

void func_L01_003016D8(u8 *obj) {
    s32 d;
    u8 *a;
    u8 *p;
    Vec4 v;
    Vec4 mt[3];
    f32 f;
    s32 c;

    d = D_L01_001D673C[0];
    a = *(u8 **)(obj + 0x68);
    f = *(f32 *)(obj + 0x2C) * *(f32 *)a;
    *(f32 *)(obj + 0x2C) = f;
    if (d != 0) {
        p = obj + 0xC0;
        func_003C5180(obj + 0x10, &v, 0);
        func_L01_004515D8(p, &v, &mt[0]);
        func_003C48A8(p, obj + 0xF0);
    }
    c = obj[0x23] - a[4];
    obj[0x23] = c;
    if (!(a[4] < (u8)c)) {
        func_003C2880(obj);
    }
}
/* localdecomp:end func_L01_003016D8 */

/* localdecomp:start func_L01_00301788 */
s32 func_L01_00301788(u8 *obj) {
    return obj[32] == 1;
}
/* localdecomp:end func_L01_00301788 */

INCLUDE_ASM("asm/levels", func_L01_00301798);

LINKER_REMNANT("asm/levels", func_L01_003018B0);

INCLUDE_ASM("asm/levels", func_L01_003018B8);

INCLUDE_ASM("asm/levels", func_L01_00301B10);

INCLUDE_ASM("asm/levels", func_L01_00301C38);
