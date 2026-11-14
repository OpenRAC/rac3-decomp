#include "common.h"

INCLUDE_ASM("asm/levels", func_L40_00430928);

/* localdecomp:start func_L40_00430DD0 */
#include "vu0.h"
/* from func_L05_003AFC08 (src/levels/05_daxx/L05_003AFC08.c), with its constants read from tuning globals */
extern void func_00382580(void *, f32, f32);
extern s32 func_L39_005B4398(s32);
extern s32 func_L39_005B43C8(s32, s32);
extern f32 func_L39_005B4410(f32, f32);
extern void func_0038CE20(void *, void *, f32);
extern void func_L01_003D8E60(void *, void *, f32, s32, f32, s32, f32, s32, s32, s32, s32);
extern u8 *func_L01_00475C60(void *, void *, s32, s32, s32, s32, f32, f32, f32, s32);
extern void func_L01_003303B8(void *, f32, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32,
    s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
extern u8 D_L40_0029AF58[];
__asm__(".extern D_L40_0029AF58, 16");
extern f32 D_L40_002479D4;
extern s32 D_L40_002479D8;
extern s32 D_L40_002479DC;
extern f32 D_L40_002479E0;
extern f32 D_L40_002479E4;
extern f32 D_L40_002479E8;
extern f32 D_L40_002479EC;
extern s32 D_L40_002479F0;
extern s32 D_L40_002479F4;
extern f32 D_L40_002479F8;
extern f32 D_L40_002479FC;
extern s32 D_L40_00247A00;
__asm__(".extern D_L40_002479D4, 4");
__asm__(".extern D_L40_002479D8, 4");
__asm__(".extern D_L40_002479DC, 4");
__asm__(".extern D_L40_002479E0, 4");
__asm__(".extern D_L40_002479E4, 4");
__asm__(".extern D_L40_002479E8, 4");
__asm__(".extern D_L40_002479EC, 4");
__asm__(".extern D_L40_002479F0, 4");
__asm__(".extern D_L40_002479F4, 4");
__asm__(".extern D_L40_002479F8, 4");
__asm__(".extern D_L40_002479FC, 4");
__asm__(".extern D_L40_00247A00, 4");

void func_L40_00430DD0(f32 x, u8 *p, s32 n, s32 a, s32 cnt) {
    u8 loc[0x10];
    u8 *r;

    func_00382580(loc, D_L40_002479D4 * 0.5f * 0.020000001f, D_L40_002479D4 * 0.020000001f);
    func_L01_003D8E60(p, loc, -1e+05f, D_L40_002479DC, x * D_L40_002479E0, 7, -5.0f, 5, D_L40_002479D8, a, 0);
    if (cnt > 0) {
        if (func_L39_005B4398(cnt) == 0) {
            func_L01_003303B8(p, x * 0.6f, 0, 2, 2, 2, 1, 2, 1, 0.0f, 0.0f, 0.0f,
                0, 1, 0, 0, 0, 0, 0x1010000, 0, 0x388EF7, 0x63F7, 0x407FFF, 0x20FF,
                0x8FFF, 0x3064FF, 0x7F60A0FF, 0x280000FF, 0x3064FF, 0);
        }
    }
    if (n > 0) {
        u8 *tb = D_L40_0029AF58;
        do {
            func_00382580(loc, D_L40_002479E4 * 0.5f * 0.020000001f, D_L40_002479E4 * 0.020000001f);
            {
                s32 k = (D_L40_002479F0 * 5 + 2) / 6;
                s32 m = func_L39_005B43C8(-2, 2);
                f32 f20 = D_L40_002479EC * x * 2.1e+05f;
                f32 t = func_L39_005B4410(D_L40_002479F8 * 0.6f, D_L40_002479F8);
                r = func_L01_00475C60(p, loc, k, m, 0x7F407FFF, 0x407FFF, f20, f20, t, 0);
                if (r != 0) {
                    r[9] = 0xF2;
                    r[3] = func_L39_005B4398(D_L40_00247A00) ? 0x44 : 0x48;
                    r[2] = ((u8 *)*(u8 **)(tb + 0x184))[3];
                }
            }
            if (func_L39_005B4398(4)) {
                s32 k;
                s32 m;
                f32 s, f20, f21, t;
                func_0038CE20(loc, loc, D_L40_002479E8);
                *(f32 *)(loc + 8) = fabs_asm(*(f32 *)(loc + 8));
                k = (D_L40_002479F4 * 5 + 2) / 6;
                m = func_L39_005B43C8(-2, 2);
                s = D_L40_002479EC * x;
                f20 = s * 0.3f * 2.1e+05f;
                f21 = s * 0.04f * 2.1e+05f;
                t = func_L39_005B4410(D_L40_002479FC * 0.6f, D_L40_002479FC);
                r = func_L01_00475C60(p, loc, k, m, 0x7F0048FF, 0x48FF, f20, f21, t, 0);
                if (r != 0) {
                    r[9] = 0xF2;
                    r[3] = func_L39_005B4398(D_L40_00247A00) ? 0x44 : 0x48;
                    r[2] = ((u8 *)*(u8 **)(tb + 0x184))[3];
                }
            }
            n--;
        } while (n != 0);
    }
}
/* localdecomp:end func_L40_00430DD0 */
