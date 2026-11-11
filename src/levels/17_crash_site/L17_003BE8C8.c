#include "common.h"
#include "vu0.h"

typedef struct S_003BED98 {
    u8 pad0[0x20];
    u8 f20;
    u8 pad21[0x75];
    u16 f96;
} S_003BED98;

INCLUDE_ASM("asm/levels", func_L17_003BE8C8);

/* localdecomp:start func_L17_003BEB98 */
extern s32 func_L01_00447490(void *, s32, s32);
extern void func_L17_003BE8C8(void *, s32, s32, s32, s32, s32, s32, s32, f32, f32, s32, s32, s32, s32);

void func_L17_003BEB98(void *a0) {
    if (func_L01_00447490(a0, -1, 0) != 0) {
        func_L17_003BE8C8(a0, 0x7F, 0x1EAD, 1, 1, 1, 0x50202020, 0x60CC20, -1.5f, 1.0f,
                          0xFF4020, 0x7F60A0FF, 0x280000FF, 1);
    }
}
/* localdecomp:end func_L17_003BEB98 */

/* localdecomp:start func_L17_003BEC30 */
extern void func_0038CF68(void *, void *, f32);
extern void func_0038CE20(void *, void *, f32);
extern f32 func_003824E0(f32, f32);
extern void func_L01_00470668(void *, void *, s32, f32);

void func_L17_003BEC30(S_003BED98 *p, s32 n, f32 speed, f32 unused, f32 spread, f32 up, f32 upvar, f32 size) {
    u8 *m = (u8 *)p;
    vu0_v4 w, pos, v;
    s32 i;

    for (i = 0; i < n; i++) {
        pos = *(vu0_v4 *)(m + 0x10);
        v = *(vu0_v4 *)(m + 0xE0);
        func_0038CF68(&v, &v, *(f32 *)(m + 0x2C) / *(f32 *)(*(u8 **)(m + 0x24) + 0x24) * speed);
        vec_add_ab(&pos, &pos, &v);
        w = *(vu0_v4 *)(m + 0xE0);
        w.x += func_003824E0(-spread, spread);
        w.y += func_003824E0(-spread, spread);
        func_0038CE20(&w, &w, (up + func_003824E0(0.0f, upvar)) * 0.020000001f);
        func_L01_00470668(&pos, &w, 0x32, size * 0.00040000002f);
    }
}
/* localdecomp:end func_L17_003BEC30 */

/* localdecomp:start func_L17_003BED98 */
extern void func_L17_003BEC30(S_003BED98 *, s32, f32, f32, f32, f32, f32, f32);
extern s32 func_00382468(s32);
extern s32 func_00382498(s32, s32);
extern void func_L01_004450F0(u8 *, s32, s32);

void func_L17_003BED98(S_003BED98 *p) {
    s32 t;

    if (p->f20 == 0) {
        t = p->f96;
        if (t == 0) {
            func_L17_003BEC30(p, 3, -1.5f, 0.15f, 0.25f, -6.0f, -5.0f, 10.0f);
            if (func_00382468(10) < 9) {
                p->f96 = func_00382498(30, 250);
            } else {
                func_L01_004450F0((u8 *)p, 1, -1);
            }
        } else {
            p->f96 = t - 1;
        }
    }
}
/* localdecomp:end func_L17_003BED98 */

/* localdecomp:start func_L17_003BEE50 */
extern s32 func_L01_00447490(void *, s32, s32);
extern void func_L17_003BE8C8(void *, s32, s32, s32, s32, s32, s32, s32, f32, f32, s32, s32, s32, s32);

void func_L17_003BEE50(void *a0) {
    if (func_L01_00447490(a0, -1, 0) != 0) {
        func_L17_003BE8C8(a0, 0x3F, 0x1EC1, 1, 1, 1, 0x802060C0, 0x2060CC, 1.5f, 3.0f, 0x20CC80, 0x80608080, 0x280000FF, 0);
    }
}
/* localdecomp:end func_L17_003BEE50 */

INCLUDE_ASM("asm/levels", func_L17_003BEEE8);

/* localdecomp:start func_L17_003BF000 */
typedef int u128_t __attribute__((mode(TI)));

typedef struct P_3BF000 {
    u8 pad0[0x8];
    f32 f8;
    u8 pad1[0x4];
    f32 f10;
    s16 f14;
} P_3BF000;

typedef struct S_3BF000 {
    u8 pad0[0x18];
    f32 f18;
    u8 pad1[0x4];
    u8 f20;
    u8 pad2[0x3];
    struct { u8 pad[0x24]; f32 f24; } *f24;
    u8 pad3[0x4];
    f32 f2C;
    u8 pad4[0x1];
    u8 f31;
    u8 pad5[0x2];
    u16 f34;
    u8 pad6[0xC];
    u8 f42;
    u8 f43;
    u8 pad7[0x1C];
    u8 f60;
    u8 pad8[0x7];
    P_3BF000 *f68;
    u8 pad9[0x84];
    f32 fF0;
    f32 fF4;
    f32 fF8;
} S_3BF000;

extern u8 D_001A4BE0[];
extern u8 D_001A4C60[];
extern u8 D_001CCFD0[];
extern u8 D_00142CC0[];
extern u8 D_00142D60[];
typedef struct T_3BF000 { s16 f0; s16 f2; s32 f4; } T_3BF000;
extern T_3BF000 D_L17_001DEDB4;
extern f32 D_L17_001DE66C;
extern f32 D_L17_001DE670;
extern f32 D_L17_001DE674;
extern s32 D_L17_001DE9DC;
__asm__(".extern D_L17_001DE66C, 4");
__asm__(".extern D_L17_001DE670, 4");
__asm__(".extern D_L17_001DE674, 4");
__asm__(".extern D_L17_001DE9DC, 4");
__asm__(".extern D_L17_001DEDB4, 16");

void func_L05_003DDB90(void *);
void func_L05_003DD790(void *);
void func_L04_003E3978(void *);
void func_003A1798(void);
void func_L01_004F50C8(void *, void *, s32, s32);
void func_L01_003EB5E0(s32, s32);
s32 func_0039EC28(s32, s32);
s32 func_0039EF28(void);
void func_L01_004450F0(u8 *, s32, s32);
void func_003C3A10(void *, s32, s32, s32);
void func_L01_00451F60(s32, s32, s32);
void func_003C2880(void *);
void func_L01_0050FB40(s32, s32, f32);
s32 func_L01_004561B8(void *);
s32 func_0038CB00(void *);
s32 func_L01_0041A5B0(s32, s32);
f32 func_0038DAB8(f32, f32);
f32 func_L01_0040E548(void *, void *);

void func_L17_003BF000(void *m) {
    S_3BF000 *s = m;
    P_3BF000 *p;
    u8 *c;
    u8 *g;

    p = s->f68;
    if (s->f20 == 0) {
        if (D_00142CC0[0] != 0) {
            func_003C2880(s);
            return;
        } else {
            f32 t;
            *(u128_t *)p = *(u128_t *)((u8 *)s + 0x10);
            p->f10 = s->fF8;
            s->f2C = s->f24->f24 * D_L17_001DE66C;
            t = p->f8 + D_L17_001DE670;
            s->fF4 = 1.5707964f;
            s->f18 = t;
            func_L01_004450F0((u8 *)s, 1, -1);
        }
    }

    switch (s->f20) {
    case 1:
        func_L05_003DDB90(s);
        s->fF0 = func_0038DAB8(s->fF0, D_L17_001DE674 * 0.017453292f * 0.020000001f);
        if (func_L01_0040E548((u8 *)s + 0x10, D_001A4C60) < 9.0f) {
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
        D_L17_001DEDB4.f4 = 1;
        func_L04_003E3978(s);
        *(u128_t *)((u8 *)s + 0x10) = *(u128_t *)(g + 0x80);
        *(u128_t *)((u8 *)s + 0xF0) = *(u128_t *)(g + 0x90);
        if (*(u32 *)(g + 0xC08) & 2) {
            func_L01_0050FB40(0, 0, 25.0f);
        }
        if (s->f42 == 1) {
            func_L05_003DDB90(s);
            if (s->f60 & 2) {
                if (s->f43 != 0) {
                    func_003C3A10(s, 0, 0, 0);
                }
                s->f31 = 0;
                s->f34 = s->f34 | 1;
                func_L01_004450F0((u8 *)s, 3, -1);
            }
        }
        break;
    case 3:
        if (func_0038CB00((u8 *)p + 0x14) != 0) {
            func_L01_00451F60(0xAF7, -1, 0);
            D_00142CC0[0] = 1;
            D_00142D60[0] = 1;
            func_0039EF28();
            s->f31 = 0;
            s->f34 = s->f34 | 1;
            D_L17_001DE9DC = 0;
            func_L01_004F50C8(D_001A4C60, D_001A4C60 + 0x10, 0, 0);
            func_L01_003EB5E0(0, 0);
            func_0039EC28(0, -1);
            p->f14 = 0x32;
            func_L01_004450F0((u8 *)s, 4, -1);
        }
        break;
    case 4:
        if (func_L01_004561B8(s)) {
            func_L01_00451F60(0xAF7, 0x64, 0);
        }
        if (func_0038CB00((u8 *)p + 0x14)) {
            if (func_L01_0041A5B0(0x1627, 0x138)) {
                func_003C2880(s);
            }
        }
        break;
    }
}
/* localdecomp:end func_L17_003BF000 */
