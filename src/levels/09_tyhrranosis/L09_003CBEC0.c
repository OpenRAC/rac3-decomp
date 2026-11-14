#include "common.h"

/* localdecomp:start func_L09_003CBEC0 */
#include "vu0.h"
extern void func_00382580(void *, f32, f32);
extern s32 func_00382468(s32);
extern s32 func_00382498(s32, s32);
extern f32 func_003824E0(f32, f32);
extern void func_0038CE20(void *, void *, f32);
extern void func_L01_003D8E60(void *, void *, s32, s32, s32, s32, void *, s32, f32, f32, f32);
extern u8 *func_L01_00475C60(void *, void *, s32, s32, s32, s32, f32, f32, f32, s32);
extern void func_L01_003303B8(void *, f32, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32,
    s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
extern u8 D_L09_00220018[];
__asm__(".extern D_L09_00220018, 16");

void func_L09_003CBEC0(f32 x, u8 *p, s32 n, u8 *a, s32 cnt) {
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
        u8 *tb = D_L09_00220018;
        cnt = n;
        v = 0xF2;
        do {
            func_00382580(loc, 0.040000003f, 0.080000006f);
            k = func_00382498(-2, 2);
            f22 = x * 3.0f;
            t = func_003824E0(-6.0f, -10.0f);
            f23 = f22 * 2.1e+05f;
            r = func_L01_00475C60(p, loc, 50, k, 0x7F407FFF, 0x407FFF, f23, f23, t, 0);
            if (r != 0) {
                r[9] = (u8)v;
                r[2] = ((u8 *)*(u8 **)(tb + 0x184))[3];
            }
            func_0038CE20(loc, loc, 2.0f);
            *(f32 *)(loc + 8) = fabs_asm(*(f32 *)(loc + 8));
            k = func_00382498(-2, 2);
            f21 = (f22 * 0.4f) * 2.1e+05f;
            f20 = (f22 * 0.04f) * 2.1e+05f;
            t = func_003824E0(24.0f, 4e+01f);
            r = func_L01_00475C60(p, loc, 50, k, 0x7F0048FF, 0x48FF, f21, f20, t, 0);
            if (r != 0) {
                r[9] = (u8)v;
                r[2] = ((u8 *)*(u8 **)(tb + 0x184))[3];
            }
            cnt--;
        } while (cnt != 0);
    }
}
/* localdecomp:end func_L09_003CBEC0 */

INCLUDE_ASM("asm/levels", func_L09_003CC1F0);

INCLUDE_ASM("asm/levels", func_L09_003CC3A0);

/* localdecomp:start func_L09_003CCB28 */
void func_L01_00445130(s32, s32, s32);
void func_L09_003CCB28(void *arg0, s32 arg1) {
    *(s32 *)((u8 *)((*(void **)((u8 *)arg0 + 0x68))) + 0x20) = arg1;
    func_L01_00445130((s32) arg0, 2, -1);
}
/* localdecomp:end func_L09_003CCB28 */

/* localdecomp:start func_L09_003CCB50 */
extern void func_L01_004450F0(void *, s32, s32);
extern s32 func_L01_00447490(void *, s32, s32);
extern void func_L09_003CCC00(void *, s32, f32, f32, f32, f32);
extern void func_003C2880(void *);
void func_L09_003CCB50(u8 *a0) {
    switch (a0[0x20]) {
    case 0:
        break;
    case 1:
        if (func_L01_00447490(a0, 0x8010000, 0) != 0) {
            func_L01_004450F0(a0, 2, -1);
        }
        a0[0xA8] = 0xFF;
        break;
    case 2:
        func_L09_003CCC00(a0, 0x3C, 0.4f, 10.0f, 10.0f, 0.100000009f);
        func_003C2880(a0);
        break;
    }
}
/* localdecomp:end func_L09_003CCB50 */

INCLUDE_ASM("asm/levels", func_L09_003CCC00);
