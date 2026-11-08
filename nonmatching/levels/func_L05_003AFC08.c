/* near miss (level 5, Daxx): 4 differences: file already @ps2as; func_L01_003303B8 declared with the float second (as retail passes it) and the two equal floats of the first func_L01_00475C60 call through one local; left: two adjacent swaps, mov.s $f13,$f12 against move $t2,$zero around the first func_L01_00475C60 jal, and abs.s against addiu $a1,$zero,2 after func_0038CE20 */
#include "common.h"

/* localdecomp:start func_L05_003AFC08 */
extern void func_00382580(void *, f32, f32);
extern s32 func_00382468(s32);
extern s32 func_00382498(s32, s32);
extern f32 func_003824E0(f32, f32);
extern void func_0038CE20(void *, void *, f32);
extern void func_L01_003D8E60(void *, void *, s32, s32, s32, s32, void *, s32, f32, f32, f32);
extern u8 *func_L01_00475C60(void *, void *, s32, s32, s32, s32, s32, f32, f32, f32);
extern void func_L01_003303B8(void *, f32, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32,
    s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
extern u8 D_L05_00220758[];
__asm__(".extern D_L05_00220758, 16");

void func_L05_003AFC08(f32 x, u8 *p, s32 n, u8 *a, s32 cnt) {
    u8 loc[0x10];
    u8 *r;
    s32 k;
    f32 f22, f21, f20, f23, t;
    s32 v;

    func_00382580(loc, 0.020000001f, 0.040000003f);
    func_L01_003D8E60(p, loc, 60, 7, 5, n, a, 0, -1e+05f, x * 3.5f, -5.0f);
    if (cnt > 0) {
        if (func_00382468(cnt) == 0) {
            func_L01_003303B8(p, x, 0, 2, 2, 2, 1, 2, 1, 0.0f, 0.0f, 0.0f,
                0, 1, 0, 0, 0, 0, 0x1010000, 0, 0x388EF7, 0x63F7, 0x407FFF, 0x20FF,
                0x8FFF, 0x3064FF, 0x7F60A0FF, 0x280000FF, 0x3064FF, 0);
        }
    }
    if (n > 0) {
        u8 *tb = D_L05_00220758;
        cnt = n;
        v = 0xF2;
        do {
            func_00382580(loc, 0.020000001f, 0.040000003f);
            k = func_00382498(-2, 2);
            f22 = x * 3.0f;
            t = func_003824E0(-6.0f, -10.0f);
            f23 = f22 * 2.1e+05f;
            r = func_L01_00475C60(p, loc, 50, k, 0x7F407FFF, 0x407FFF, 0, f23, f23, t);
            if (r != 0) {
                r[9] = (u8)v;
                r[2] = ((u8 *)*(u8 **)(tb + 0x184))[3];
            }
            func_0038CE20(loc, loc, 2.0f);
            *(f32 *)(loc + 8) = __builtin_fabsf(*(f32 *)(loc + 8));
            k = func_00382498(-2, 2);
            f21 = (f22 * 0.4f) * 2.1e+05f;
            f20 = (f22 * 0.04f) * 2.1e+05f;
            t = func_003824E0(24.0f, 4e+01f);
            r = func_L01_00475C60(p, loc, 50, k, 0x7F0048FF, 0x48FF, 0, f21, f20, t);
            if (r != 0) {
                r[9] = (u8)v;
                r[2] = ((u8 *)*(u8 **)(tb + 0x184))[3];
            }
            cnt--;
        } while (cnt != 0);
    }
}
/* localdecomp:end func_L05_003AFC08 */
