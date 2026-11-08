#include "common.h"

typedef int u128_t __attribute__((mode(TI)));

INCLUDE_ASM("asm/levels", func_L05_0035F360);

INCLUDE_ASM("asm/levels", func_L05_0035F6E0);

INCLUDE_ASM("asm/levels", func_L05_00360070);

/* localdecomp:start func_L05_003601F0 */
extern void func_L01_00448890(u8 *a0, u8 *a1, f32 f12, f32 f13, f32 f14, f32 f15, s32 a2);
extern f32 func_0038D160(f32, f32);

void func_L05_003601F0(u8 *p) {
    u8 *q = *(u8 **)(p + 0x68);
    f32 d;
    *(f32 *)(p + 0x2C) = *(f32 *)(*(u8 **)(p + 0x24) + 0x24) * 0.5f;
    d = func_0038D160(*(f32 *)(q + 0x30) - *(f32 *)(p + 0x10), *(f32 *)(q + 0x34) - *(f32 *)(p + 0x14));
    {
        f32 k = 2.0943953132e-4f;
        func_L01_00448890(p + 0xF8, q + 0xAC, d, k, k, 0.02792526968f, 0);
    }
}
/* localdecomp:end func_L05_003601F0 */

/* localdecomp:start func_L05_00360280 */
s32 func_L05_00360280(u8 *a0) {
    s32 v;
    s32 r;
    if (a0 == 0) {
        return 0;
    }
    v = *(s16 *)(a0 + 0xAA);
    if (v == 0x1684) {
        return 1;
    }
    r = 0;
    if (v == 0x15F7) {
        u8 *q = *(u8 **)(a0 + 0x68);
        s32 x = *(s32 *)(q + 0x70);
        s32 m = -1;
        if (x != m) {
            return 1;
        }
    }
    return r;
}
/* localdecomp:end func_L05_00360280 */

/* localdecomp:start func_L05_003602D0 */
extern u16 *D_L05_0021DAE0[];
extern u8 *D_L05_001DFB9C;
__asm__(".extern D_L05_001DFB9C, 16");
extern s32 D_L05_001DFBD8;
extern s32 func_L01_00456250(u8 *);
extern f32 func_L01_0040E570(u8 *, void *);
extern s32 func_L05_00360280(u8 *);
u8 *func_L05_003602D0(u8 *a0, void *a1) {
    u8 *s = *(u8 **)(a0 + 0x68);
    u16 *p = D_L05_0021DAE0[*(s32 *)(s + 0x50)];
    u8 *best = 0;
    s32 k;
    u8 *e;
    f32 d;
    while (1) {
        k = *(s32 *)(s + 0x50);
        if ((k & 0xFF) == 0xFF) break;
        if (D_L05_001DFBD8 < k) break;
        if (p == 0) break;
        if (!((s16)p[-1] >= 0 || p == D_L05_0021DAE0[k])) break;
        e = D_L05_001DFB9C + ((*p & 0x7FFF) << 8);
        if (e == 0) break;
        if (e[0x20] != 0xFE) {
            if (e[0x20] == 0xFD) {
                p++;
                continue;
            }
            if (func_L01_00456250(e) != 0) {
                p++;
                continue;
            }
            d = func_L01_0040E570(e + 0x10, a1);
            if (func_L05_00360280(e) != 0 && d < 64.0f) {
                *(u128_t *)a1 = *(u128_t *)(e + 0x10);
                return e;
            }
            if (d < 4.84f) {
                best = e;
            }
        }
        p++;
    }
    return best;
}
/* localdecomp:end func_L05_003602D0 */

INCLUDE_ASM("asm/levels", func_L05_00360448);

INCLUDE_ASM("asm/levels", func_L05_00360730);

/* localdecomp:start func_L05_00360868 */
extern s32 func_00382498(s32, s32);
extern f32 func_003824E0(f32, f32);
extern f32 func_0038DAB8(f32, f32);
extern void func_00382760(void *, f32, f32, f32);
extern s32 func_00382468(s32);
extern void func_L01_0046FB40(void *, void *, s32, s32, s32, s32, s32, s32, f32, f32, f32);

void func_L05_00360868(u8 *p, f32 a, f32 b) {
    f32 v[4];
    s32 n;
    s32 n2;
    s32 sg;
    f32 s1;
    f32 t2;
    f32 t3;
    f32 t4;
    f32 t5;

    s32 r;
    r = func_00382498(4, 8);
    if (r > 0) {
        n = r;
        do {
            n--;
            s1 = func_003824E0(15.0f, 20.0f) * 0.020000001f;
            t2 = func_003824E0(-0.52359879f, 0.52359879f);
            t3 = func_0038DAB8(a, t2);
            t4 = func_003824E0(-0.52359879f, 0.52359879f);
            func_00382760(v, s1, t3, t4);
            t5 = func_003824E0(2.5f, 3.0f) * b;
            n2 = func_00382498(4, 10);
            sg = func_00382468(2) != 0 ? 1 : -1;
            func_L01_0046FB40(p, v, n2, 0x204080, sg, 110, 32, 0, t5 * 210000.0f, t5 * 0.75f * 210000.0f, 0.0f);
        } while (n != 0);
    }
}
/* localdecomp:end func_L05_00360868 */
