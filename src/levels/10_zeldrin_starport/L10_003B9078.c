#include "common.h"

/* localdecomp:start func_L10_003B9078 */
extern void func_003C3A10(u8 *, s32, s32, s32);

void func_L10_003B9078(u8 *a0, s32 a1, s32 a2, s32 a3) {
    u8 *s3 = *(u8 **)(a0 + 0x68);
    if (*(u8 *)(a0 + 0x43) != a1) {
        func_003C3A10(a0, a1, a2, a3);
        func_003C3A10(*(u8 **)(s3 + 0x2DC), a1, a2, a3);
    }
}
/* localdecomp:end func_L10_003B9078 */

INCLUDE_ASM("asm/levels", func_L10_003B90E0);

INCLUDE_ASM("asm/levels", func_L10_003B9570);

/* localdecomp:start func_L10_003B9D28 */
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_3B9D28;
extern void func_003C2F58(void *, s32, void *);
extern s32 func_003D3CB0(void *, void *, s32, void *, s32);
extern s32 D_L10_001E8918[];

s32 func_L10_003B9D28(u8 *a0) {
    u8 *s1 = *(u8 **)(a0 + 0x68);
    V4_3B9D28 a;
    V4_3B9D28 b;
    s32 t;
    s32 r;

    func_003C2F58(*(void **)(s1 + 0x2DC), 0, &a);
    b = *(V4_3B9D28 *)(s1 + 0x220);
    if (func_003D3CB0(&a, &b, 0x10, a0, 0) == 0) {
        return 1;
    }
    t = D_L10_001E8918[0];
    if (t != 0 && t == *(s32 *)(s1 + 0x230)) {
        return 1;
    }
    return 0;
}
/* localdecomp:end func_L10_003B9D28 */

/* localdecomp:start func_L10_003B9DB0 */
typedef int u128_t_3B9DB0 __attribute__((mode(TI)));
typedef struct P_3B9DB0 {
    u8 pad0[0x10];
    f32 f10;
    s16 f14;
} P_3B9DB0;
typedef struct S_3B9DB0 {
    u8 pad0[0x20];
    u8 f20;
    u8 pad1[0x3];
    u8 *f24;
    u8 pad2[0x4];
    f32 f2C;
    u8 pad3[0x1];
    u8 f31;
    u8 pad4[0x2];
    u16 f34;
    u8 pad5[0xC];
    u8 f42;
    u8 f43;
    u8 pad6[0x1C];
    u8 f60;
    u8 pad7[0x7];
    P_3B9DB0 *f68;
    u8 pad8[0x8C];
    f32 fF8;
} S_3B9DB0;
typedef struct T_3B9DB0 { s16 f0; s16 f2; s32 f4; } T_3B9DB0;
extern u8 D_001A4BE0[];
extern u8 D_001A4C60[];
extern u8 D_001CCFD0[];
extern u8 D_00142CBA[];
extern T_3B9DB0 D_L10_001DF034;
extern f32 D_L10_001DE780;
extern s32 D_L10_001DEC5C;
__asm__(".extern D_L10_001DE780, 4");
__asm__(".extern D_L10_001DF034, 16");

void func_L04_003E3618(void *);
void func_L05_003DD790(void *);
void func_L04_003E3978(void *);
s32 func_003A1798(void);
void func_L01_00419188(s32);
void func_L01_004F50C8(void *, void *, s32, s32);
void func_L01_003EB5E0(s32, s32);
s32 func_0039EC28(s32, s32);
void func_L01_004450F0(void *, s32, s32);
extern void func_003C3A10(u8 *, s32, s32, s32);
void func_L01_00451F60(s32, s32, s32);
void func_003C2880(void *);
void func_L01_0050FB40(s32, s32, f32);
s32 func_L01_004561B8(void *);
s32 func_0038CB00(void *);
s32 func_L01_0041A5B0(s32, s32);
f32 func_0038DAB8(f32, f32);
f32 func_L01_0040E570(void *, void *);

void func_L10_003B9DB0(void *m) {
    S_3B9DB0 *s = m;
    P_3B9DB0 *p;
    u8 *c;
    u8 *g;

    p = s->f68;
    if (s->f20 == 0) {
        if (D_00142CBA[0] != 0) {
            func_003C2880(s);
            return;
        }
        s->f2C = *(f32 *)(s->f24 + 0x24) * D_L10_001DE780;
        *(u128_t_3B9DB0 *)p = *(u128_t_3B9DB0 *)((u8 *)s + 0x10);
        p->f10 = s->fF8;
        func_L01_004450F0(s, 1, -1);
    }

    switch (s->f20) {
    case 1:
        s->fF8 = func_0038DAB8(s->fF8, 0.090757132f);
        func_L04_003E3618(s);
        if (func_L01_0040E570(D_001A4C60, (u8 *)s + 0x10) < 25.0f) {
            func_L05_003DD790(s);
        }
        break;
    case 2:
        c = D_001CCFD0;
        if (*(s16 *)(c + 0x76) == 0) {
            if (*(s16 *)(c + 0x9E) == 3 && *(s16 *)(c + 0x98) < 0x1B58) {
                if (func_L01_004561B8(s)) {
                    func_003A1798();
                }
            }
        }
        g = D_001A4BE0;
        *(s16 *)(g + 0x1DC) = 3;
        D_L10_001DF034.f4 = 1;
        func_L04_003E3978(s);
        *(u128_t_3B9DB0 *)((u8 *)s + 0x10) = *(u128_t_3B9DB0 *)(g + 0x80);
        *(u128_t_3B9DB0 *)((u8 *)s + 0xF0) = *(u128_t_3B9DB0 *)(g + 0x90);
        if (*(u32 *)(g + 0xC08) & 2) {
            func_L01_0050FB40(0, 0, 25.0f);
        }
        if (s->f42 == 1 && (s->f60 & 2)) {
            if (s->f43 != 0) {
                func_003C3A10((u8 *)s, 0, 0, 0);
            }
            s->f31 = 0;
            s->f34 = s->f34 | 1;
            func_L01_004450F0(s, 5, -1);
        }
        break;
    case 5:
        if (func_0038CB00((u8 *)p + 0x14) != 0) {
            func_L01_00419188(0x1A);
            func_L01_00419188(7);
            D_L10_001DEC5C = 0;
            func_L01_004F50C8(D_001A4C60, D_001A4C60 + 0x10, 0, 0);
            func_L01_003EB5E0(0, 0);
            func_0039EC28(0, -1);
            p->f14 = 0x32;
            func_L01_004450F0(s, 4, -1);
        }
        break;
    case 4:
        if (func_L01_004561B8(s)) {
            func_L01_00451F60(0x1B82, 0x64, 0);
        }
        if (func_0038CB00((u8 *)p + 0x14) != 0 && func_L01_0041A5B0(0x1426, 0x114) != 0) {
            func_003C2880(s);
        }
        break;
    }
}
/* localdecomp:end func_L10_003B9DB0 */
