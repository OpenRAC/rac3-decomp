/* NTSC-U draft (Claude wave K): C of func_L39_005D2B70, the NTSC-U twin of func_L39_005D50A0, with NTSC-U names and addresses (the two versions' code differs).
 * near miss on NTSC-U, no count recorded (NTSC-U twin "func_L39_005D2B70", whose code is not the PAL one).
 * Worker's note: 10 words off (check_native with the two extras the PAL line lacks, vu0 vec_add_ab + @ps2as float immediates, and divs row 'func_L39_005D2B70 2 2' injected): only f0/f1 swapped in the first FP block (q[0xC] loaded into f1 and q[8] into f0 in retail; mine the ...
 */
#include "common.h"
#include "vu0.h"

/* localdecomp:start func_L39_005D2B70 */
/* Needs -mvu0-use-vf0-vf2 (vec_add_ab) and @ps2as beyond the PAL file's flags. */
typedef int U128_005D2B70 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_005D2B70;

extern u8 D_001D7E80_sda;
__asm__(".extern D_001D7E80_sda, 4");
extern s32 D_001D7E7C_sda;
__asm__(".extern D_001D7E7C_sda, 4");
extern f32 D_001D7E6C_sda;
__asm__(".extern D_001D7E6C_sda, 4");
extern f32 D_001D7E70_sda;
__asm__(".extern D_001D7E70_sda, 4");
extern s32 D_001D7E74_sda;
__asm__(".extern D_001D7E74_sda, 4");
extern s32 D_001D7E78_sda;
__asm__(".extern D_001D7E78_sda, 4");
extern f32 D_001D7E68_sda;
__asm__(".extern D_001D7E68_sda, 4");

extern s32 func_003883C8(void *);
extern void func_003C7CE0(void *);
extern s32 func_L39_005B2498(s32);
extern u8 *func_L01_00471970(s32, void *, void *, u32, f32, f32, f32, s32, s32, s32, s32);
extern void func_003BF6A8(void *, f32);
extern f32 func_00388A28(f32, f32);
extern f32 func_L39_005B2510(f32, f32);
extern f32 func_00389380(f32, f32);
extern f32 func_003887A0(void *);
extern void func_0037E4B8(void *, f32, f32, f32);
extern s32 func_L39_005B24C8(s32, s32);
extern s32 func_003CF790(void *, s32, void *, s32, f32);

void func_L39_005D2B70(u8 *self) {
    u8 *q;
    f32 sv;
    f32 t;
    f32 g;
    f32 inc;
    f32 limit;
    f32 nz;
    f32 a20;
    f32 b20;
    f32 a21;
    f32 a22;
    f32 a23;
    u8 alpha;
    s32 n;
    u8 *r;
    V4_005D2B70 v;
    V4_005D2B70 v2;
    V4_005D2B70 *pv2;

    if (func_003883C8(self + 0xA)) {
        func_003C7CE0(self);
        return;
    }
    q = self + 0x20;
    self[8] = self[8] + D_001D7E80_sda;
    sv = *(f32 *)(self + 0x1C);
    t = (f32)*(s16 *)(self + 0xA) * sv;
    alpha = (u8)(s32)((f32)q[0x1C] * t);
    *(u32 *)(self + 4) = (*(u32 *)(self + 4) & 0xFFFFFF) | ((u32)alpha << 24);
    g = *(f32 *)(q + 0x18);
    *(f32 *)(self + 0xC) = g + (*(f32 *)(q + 0x14) - g) * t;
    inc = *(f32 *)(self + 0xC) / 500000.0f;
    if (0.0f < *(f32 *)(q + 0xC) && *(f32 *)(q + 8) < 0.0f) {
        limit = *(f32 *)(q + 0xC) + inc;
        nz = *(f32 *)(q + 8);
        if (nz * 5.0f < limit - *(f32 *)(self + 0x18)) {
            *(f32 *)(q + 8) = (limit - *(f32 *)(self + 0x18)) / 5.0f;
        }
        vec_add_ab(self + 0x10, self + 0x10, self + 0x20);
        if (*(f32 *)(self + 0x18) < limit) {
            *(f32 *)(self + 0x18) = limit;
        }
    } else {
        vec_add_ab(self + 0x10, self + 0x10, q);
    }
    if (q[0x1E] != 0 && func_L39_005B2498(q[0x1E]) == 0) {
        if (func_L39_005B2498(D_001D7E7C_sda) == 0) {
            v = (V4_005D2B70){0.0f, 0.0f, inc * 0.16666667f, 0.0f};
            r = func_L01_00471970(*(s32 *)(q + 0x10), self + 0x10, &v,
                                  ((s32)(t * 64.0f) << 24) | 0x202020,
                                  0.0f, *(f32 *)(self + 0xC), *(f32 *)(self + 0xC) * 0.8f, 0x28, 0, 0, 1);
            if (r) {
                r[3] = 0x44;
            }
        } else {
            *(U128_005D2B70 *)&v = *(U128_005D2B70 *)(self + 0x10);
            func_003BF6A8(&v, inc);
            pv2 = &v2;
            a21 = D_001D7E6C_sda * inc;
            a20 = func_00388A28(*(f32 *)q, *(f32 *)(q + 4));
            a23 = D_001D7E70_sda * 0.017453292f;
            a22 = func_00389380(a20, func_L39_005B2510(-a23, a23));
            b20 = func_00388A28(func_003887A0(q), *(f32 *)(q + 8));
            func_0037E4B8(pv2, a21, a22,
                          func_00389380(b20, func_L39_005B2510(0.0f, D_001D7E70_sda * 0.017453292f)));
            n = func_L39_005B24C8(D_001D7E74_sda, D_001D7E78_sda);
            r = func_L01_00471970(*(s32 *)(q + 0x10), &v, pv2, *(u32 *)(self + 4),
                                  0.0f, *(f32 *)(self + 0xC), *(f32 *)(self + 0xC) * D_001D7E68_sda, n, 0, 0, 0);
            if (r) {
                r[2] = self[2];
            }
        }
    }
    if (q[0x1D] == 0 || alpha < 0xF) {
        *(f32 *)(self + 0x1C) = sv;
        return;
    }
    n = func_003CF790(self + 0x10, 1, *(void **)(q + 0x10), 0, inc);
    if (n > 0) {
        do {
        } while (--n);
    }
    *(f32 *)(self + 0x1C) = sv;
}
/* localdecomp:end func_L39_005D2B70 */
