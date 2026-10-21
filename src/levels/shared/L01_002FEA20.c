#include "common.h"

typedef int u128_t __attribute__((mode(TI)));
typedef union {
    u128_t q;
    f32 f[4];
} Vec4;
typedef int s128 __attribute__((mode(TI)));

INCLUDE_ASM("asm/levels", func_L01_002FEA20);

INCLUDE_ASM("asm/levels", func_L01_002FFBC8);

INCLUDE_ASM("asm/levels", func_L01_002FFCA8);

INCLUDE_ASM("asm/levels", func_L01_002FFF00);

LINKER_REMNANT("asm/levels", func_L01_002FFFE8);

INCLUDE_ASM("asm/levels", func_L01_002FFFF0);

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

INCLUDE_ASM("asm/levels", func_L01_003016D8);

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

INCLUDE_ASM("asm/levels", func_L01_00301F98);

INCLUDE_ASM("asm/levels", func_L01_00302048);

INCLUDE_ASM("asm/levels", func_L01_003020C0);

INCLUDE_ASM("asm/levels", func_L01_00302118);

INCLUDE_ASM("asm/levels", func_L01_00303228);

INCLUDE_ASM("asm/levels", func_L01_00303658);

INCLUDE_ASM("asm/levels", func_L01_003036D8);

INCLUDE_ASM("asm/levels", func_L01_00303C00);

INCLUDE_ASM("asm/levels", func_L01_00303D30);

INCLUDE_ASM("asm/levels", func_L01_00303E30);

INCLUDE_ASM("asm/levels", func_L01_00304018);

INCLUDE_ASM("asm/levels", func_L01_003041A0);

INCLUDE_ASM("asm/levels", func_L01_00304A58);

INCLUDE_ASM("asm/levels", func_L01_00304AA0);

INCLUDE_ASM("asm/levels", func_L01_00304C48);

/* localdecomp:start func_L01_003057A0 */

extern u8 *D_L01_001DC5C4;
extern void func_L01_004C8668(s32);
extern s32 func_L01_004C85C8(u8 *, u8 *, f32, f32, f32);

void func_L01_003057A0(u8 *a0, s128 *a1, s128 *a2, s32 a3) {
    s32 *v = *(s32 **)(a0 + 104);
    s32 n;
    if (D_L01_001DC5C4 != 0) {
        u8 *e = D_L01_001DC5C4 + (v[15] << 6);
        *(s128 *)e = *a1;
        *(s128 *)(e + 16) = *a2;
        if (*(s32 *)(e + 56) >= 0) {
            func_L01_004C8668(*(s32 *)(e + 56));
        }
        *(s32 *)(e + 56) = func_L01_004C85C8(a0, e, 1.0f, 1.0f, 1.0f);
        *(s32 *)(e + 48) = a3;
        *(s32 *)(e + 52) = 0;
    }
    n = v[15];
    v[18] = n;
    v[15] = n + 1;
    if (n + 1 >= 35) {
        v[15] = 0;
        v[16] = 1;
    } else if (v[16] != 1) {
        v[17]++;
    }
}
/* localdecomp:end func_L01_003057A0 */

INCLUDE_ASM("asm/levels", func_L01_00305880);

INCLUDE_ASM("asm/levels", func_L01_00305970);

INCLUDE_ASM("asm/levels", func_L01_00305AB8);

INCLUDE_ASM("asm/levels", func_L01_00305C50);

INCLUDE_ASM("asm/levels", func_L01_00305CB8);

LINKER_REMNANT("asm/levels", func_L01_00305D28);

INCLUDE_ASM("asm/levels", func_L01_00305D30);

INCLUDE_ASM("asm/levels", func_L01_00305F00);

INCLUDE_ASM("asm/levels", func_L01_00306628);
