#include "common.h"

typedef struct {
    u8 pad00[0x7C];
    u16 x7C;
} Obj_003B2B90;

extern void func_L19_003B2968(u8 *a0, s32 a1);
extern s32 func_00382468(s32);
extern s32 func_003A5348(s32, s32, s32);

INCLUDE_ASM("asm/levels", func_L19_003B1A80);

INCLUDE_ASM("asm/levels", func_L19_003B1E08);

INCLUDE_ASM("asm/levels", func_L19_003B2190);

INCLUDE_ASM("asm/levels", func_L19_003B2290);

INCLUDE_ASM("asm/levels", func_L19_003B2370);

INCLUDE_ASM("asm/levels", func_L19_003B2538);

INCLUDE_ASM("asm/levels", func_L19_003B2748);

typedef struct { f32 x, y, z, w; } V_3B2880 __attribute__((aligned(16)));

/* localdecomp:start func_L19_003B2880 */
extern u8 *D_001E8E58[];
extern void func_003C2F58(u8 *a0, s32 a1, u8 *a2);
extern s32 func_003D3CB0(void *, void *, s32, void *, s32);

s32 func_L19_003B2880(u8 *obj) {
    u8 *p = *(u8 **)(obj + 0x68);
    V_3B2880 a;
    V_3B2880 b;
    u8 *t;
    u8 *u;

    func_003C2F58(obj, 3, (u8 *)&a);
    func_003C2F58(obj, 2, (u8 *)&b);
    if (func_003D3CB0(&a, p + 0x220, 0, obj, 0) != 0) {
        t = D_001E8E58[0];
        if (t != 0 && *(s16 *)(t + 0xAA) == 0x1AB8 && t != *(u8 **)(p + 0x230))
            return 0;
    }
    if (func_003D3CB0(&b, p + 0x220, 0, obj, 0) != 0) {
        u = D_001E8E58[0];
        if (u != 0 && *(s16 *)(u + 0xAA) == 0x1AB8 && u != *(u8 **)(p + 0x230))
            return 0;
    }
    return 1;
}
/* localdecomp:end func_L19_003B2880 */

INCLUDE_ASM("asm/levels", func_L19_003B2968);

/* localdecomp:start func_L19_003B2AC8 */
void func_L19_003B2AC8(u8 *a0)
{
    s32 i;
    u16 flags;

    flags = *(u16 *)(a0 + 0x7C);
    if (flags & 2) {
        *(u16 *)(a0 + 0x7C) = flags | 0x100;
    }
    for (i = 0; i < 16; i++) {
        func_L19_003B2968(a0, i);
    }
}
/* localdecomp:end func_L19_003B2AC8 */

/* localdecomp:start func_L19_003B2B28 */
void func_L19_003B2B28(void *a0)
{
    s32 i;
    s32 m = 1;

    for (i = 0; i < 16; i++) {
        if ((m & 0x701) == 0) {
            func_L19_003B2968(a0, i);
        }
        m <<= 1;
    }
}
/* localdecomp:end func_L19_003B2B28 */

/* localdecomp:start func_L19_003B2B90 */
void func_L19_003B2B90(u8 *self, s32 a1) {
    Obj_003B2B90 *o = (Obj_003B2B90 *)self;
    s32 n;
    s32 k;
    s32 bit;
    s32 r;

    r = func_00382468(a1);
    n = 0;
    k = r + 1;
    bit = 1;
    if (k != 0) {
        while (k != 0) {
            s32 t;
            bit <<= 1;
            t = k - 1;
            if (o->x7C & bit) {
                k = t;
            }
            n++;
            if (n == 2) {
                bit <<= 1;
                n = 3;
            }
        }
    }
    func_L19_003B2968(self, n);
    func_003A5348(7, 0, 0);
    if (n == 3) {
        func_L19_003B2968(self, 2);
    }
    if (n == 1) {
        o->x7C |= 0x100;
    }
}
/* localdecomp:end func_L19_003B2B90 */

/* localdecomp:start func_L19_003B2C48 */
extern void func_L19_003B2B90(u8 *, s32);

s32 func_L19_003B2C48(u8 *self, f32 a, f32 b, f32 c)
{
    s32 i;
    f32 k;
    f32 lo;

    if (self[0x95] == 5) {
        return 0;
    }
    k = c * 0.13333300f;
    lo = c - k;
    i = 6;
    do {
        if (lo <= a) {
            if (b < lo) {
                func_L19_003B2B90(self, i);
            }
        }
        i--;
        lo -= k;
    } while (i != 0);
    return 1;
}
/* localdecomp:end func_L19_003B2C48 */

INCLUDE_ASM("asm/levels", func_L19_003B2D00);

/* localdecomp:start func_L19_003B2EA8 */
extern void func_003C2F58(u8 *a0, s32 a1, u8 *a2);
extern void func_003D9508(void *p, s32 a, u32 color, s32 b, f32 f0, f32 f1, f32 f2);

void func_L19_003B2EA8(u8 *a0) {
    u8 buf[0x10];
    func_003C2F58(a0, 1, buf);
    func_003D9508(buf, 0x2E, 0x8080FFFF, 1, 0.45f, 0.0f, 0.0f);
    func_003D9508(buf, 0xC, 0x8020F020, 1, 0.45f, 0.0f, 0.0f);
}
/* localdecomp:end func_L19_003B2EA8 */
