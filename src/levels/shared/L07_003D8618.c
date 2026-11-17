#include "common.h"

/* localdecomp:start func_L07_003D8618 */
#include "vu0.h"

extern void func_00382580(void *, f32, f32);
extern s32 func_00382468(s32);
extern s32 func_00382498(s32, s32);
extern f32 func_003824E0(f32, f32);
extern void func_0038CE20(void *, void *, f32);
extern void func_L01_003D8E60(f32, f32, void *, void *, s32, s32, s32, s32, s32, s32, f32);
extern u8 *func_L01_00475C60(void *, void *, s32, s32, s32, s32, f32, f32, f32, s32);
extern void func_L01_003303B8(void *, f32, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32,
    s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
extern f32 D_L07_001DE8D0;
__asm__(".extern D_L07_001DE8D0, 4");
extern s32 D_L07_001DE8D4;
__asm__(".extern D_L07_001DE8D4, 4");
extern f32 D_L07_001DE8D8;
__asm__(".extern D_L07_001DE8D8, 4");
extern f32 D_L07_001DE8DC;
__asm__(".extern D_L07_001DE8DC, 4");
extern f32 D_L07_001DE8E0;
__asm__(".extern D_L07_001DE8E0, 4");
extern s32 D_L07_001DE8E4;
__asm__(".extern D_L07_001DE8E4, 4");
extern f32 D_L07_001DE8E8;
__asm__(".extern D_L07_001DE8E8, 4");
extern f32 D_L07_001DE8EC;
__asm__(".extern D_L07_001DE8EC, 4");
extern u8 D_L07_0021EC98[];

void func_L07_003D8618(f32 x, void *p, s32 n, s32 a, s32 cnt) {
    u8 loc[0x10];
    u8 *r;

    func_00382580(loc, D_L07_001DE8D0 * 0.5f * 0.020000001f, D_L07_001DE8D0 * 0.020000001f);
    func_L01_003D8E60(-1e+05f, x * 3.5f, p, loc, D_L07_001DE8D4, 7, 5, n, a, 0, -5.0f);
    if (cnt > 0) {
        if (func_00382468(cnt) == 0) {
            func_L01_003303B8(p, x, 0, 2, 2, 2, 1, 2, 1, 0.0f, 0.0f, 0.0f,
                0, 1, 0, 0, 0, 0, 0x1010000, 0, 0x388EF7, 0x63F7, 0x407FFF, 0x20FF,
                0x8FFF, 0x3064FF, 0x7F60A0FF, 0x280000FF, 0x3064FF, 0);
        }
    }
    if (n > 0) {
        u8 *tb = D_L07_0021EC98;
        do {
            func_00382580(loc, D_L07_001DE8D8 * 0.5f * 0.020000001f, D_L07_001DE8D8 * 0.020000001f);
            {
                s32 k = (D_L07_001DE8E4 * 5 + 2) / 6;
                s32 j = func_00382498(-2, 2);
                f32 s = D_L07_001DE8E0 * x * 210000.0f;
                f32 t = func_003824E0(D_L07_001DE8E8 * 0.6f, D_L07_001DE8E8);
                r = func_L01_00475C60(p, loc, k, j, 0x7F407FFF, 0x407FFF, s, s, t, 0);
            }
            if (r != 0) {
                r[9] = 0xF2;
                r[2] = (*(u8 **)(tb + 0x184))[3];
            }
            func_0038CE20(loc, loc, D_L07_001DE8DC);
            *(f32 *)(loc + 8) = fabs_asm(*(f32 *)(loc + 8));
            {
                s32 k = (D_L07_001DE8E4 * 5 + 2) / 6;
                s32 j = func_00382498(-2, 2);
                f32 u = D_L07_001DE8E0 * x;
                f32 s0 = u * 0.4f * 210000.0f;
                f32 s1 = u * 0.04f * 210000.0f;
                f32 t = func_003824E0(D_L07_001DE8EC * 0.6f, D_L07_001DE8EC);
                r = func_L01_00475C60(p, loc, k, j, 0x7F0048FF, 0x48FF, s0, s1, t, 0);
            }
            if (r != 0) {
                r[9] = 0xF2;
                r[2] = (*(u8 **)(tb + 0x184))[3];
            }
            n--;
        } while (n != 0);
    }
}
/* localdecomp:end func_L07_003D8618 */

/* localdecomp:start func_L07_003D89A8 */
#include "vu0.h"

typedef struct {
    f32 x, y, z, w;
} __attribute__((aligned(16))) V4_003D89A8;

extern s32 func_0038DC20(void *, f32);
extern void func_00382580(void *, f32, f32);
extern void func_L07_003D8618(f32, void *, s32, s32, s32);
extern s32 D_L07_001DE8F0;
__asm__(".extern D_L07_001DE8F0, 4");

void func_L07_003D89A8(f32 a, f32 b, f32 c, f32 d, u8 *obj, s32 n, s32 col, s32 cnt) {
    V4_003D89A8 v;
    V4_003D89A8 w;
    V4_003D89A8 u;
    f32 f;
    s32 i;

    col = (col == 0x1FF) ? 0xFF : col;
    v = *(V4_003D89A8 *)(obj + 0x10);
    v.w = d + d;
    f = 128.0f;
    if (col > 0x80) {
        f = (f32)col;
    }
    if (func_0038DC20(&v, f) >= 0) {
        func_00382580(&w, b * 0.8f, b * 1.2f);
        w.z += a;
        vec_add_ba(&w, &w, obj + 0x10);
        for (i = 0; i < D_L07_001DE8F0; i++) {
            func_00382580(&u, c * 0.75f, c * 1.25f);
            vec_add_ab(&u, &w, &u);
            func_L07_003D8618(d * 0.75f, &u, n, col, cnt);
        }
    }
}
/* localdecomp:end func_L07_003D89A8 */
