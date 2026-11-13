#include "common.h"

INCLUDE_ASM("asm/levels", func_L39_0052DF20);

INCLUDE_ASM("asm/levels", func_L39_0052E550);

INCLUDE_ASM("asm/levels", func_L39_0052EE60);

/* localdecomp:start func_L39_00530490 */
#include "vu0.h"

typedef int Q_00530490 __attribute__((mode(TI)));

extern f32 func_0038CEA8(void *);
extern void func_0038CE20(void *, void *, f32);
extern f32 func_0038DBA0(f32, f32);
extern void func_L01_00448690(void *, s32, f32, f32);
extern f32 func_L01_00448728(void *, f32, void *, f32, f32, f32, s32);
extern void func_L39_0052EE60(u8 *);

void func_L39_00530490(u8 *a0) {
    vu0_v4 v;
    u8 *g;
    u8 *s;
    u8 *c;
    u8 *t;
    f32 len;
    f32 sc;
    f32 k;
    f32 ang;

    g = *(u8 **)(a0 + 0x68);
    s = *(u8 **)(g + 0x720);
    c = *(u8 **)(g + 0x6D0);
    if (s == 0) {
        return;
    }
    if (a0[0xBC] == 0xB && (*(u16 *)(g + 0x710) & 8)) {
        return;
    }
    if (!(*(s32 *)(c + 0x2F8) & 2)) {
        t = *(u8 **)(c + 0x2D8);
        if (t != 0 && t[0x1A14] == 0 && (*(s32 *)(*(u8 **)(t + 0x2558) + 0x1AC) & 4)) {
            vec_sub_ab(&v, t + 0x4D30, a0 + 0x10);
            len = func_0038CEA8(&v);
            sc = 0.0f;
            if (len < 1.5f) {
                sc = 1.0f;
            } else if (len < 3.0f) {
                sc = 1.75f;
            } else if (len < 5.0f) {
                sc = 2.5f;
            }
            if (0.0f < sc) {
                func_0038CE20(&v, &v, sc / 10.0f);
            }
            vec_add_ab(a0 + 0x10, a0 + 0x10, &v);
            ang = func_0038DBA0(*(f32 *)(a0 + 0xF8), *(f32 *)(c + 0x208));
            k = 10.0f;
            if (0.7853982f < ang) {
                k = 120.0f;
            }
            func_L01_00448690(a0 + 0xF8, 0, *(f32 *)(t + 0x4D68), k * 0.017453292f * 0.020000001f);
        } else {
            vec_sub_ba(&v, c + 0x1F0, a0 + 0x10);
            func_0038CE20(&v, &v, 0.1f);
            vec_add_ab(a0 + 0x10, a0 + 0x10, &v);
            ang = func_0038DBA0(*(f32 *)(a0 + 0xF8), *(f32 *)(c + 0x208));
            k = 10.0f;
            if (0.7853982f < ang) {
                k = 120.0f;
            }
            func_L01_00448690(a0 + 0xF8, 0, *(f32 *)(c + 0x208), k * 0.017453292f * 0.020000001f);
        }
    }
    if (*(s32 *)(c + 0x2F8) & 2) {
        *(Q_00530490 *)(a0 + 0x10) = *(Q_00530490 *)(c + 0xB0);
        func_L01_00448728(a0 + 0xF0, *(f32 *)(c + 0x200), g + 0x650, *(f32 *)(s + 0x1C) * 1.44f, *(f32 *)(s + 0x20) * 1.44f, *(f32 *)(s + 0x4) * 0.020000001f, 0);
        func_L01_00448728(a0 + 0xF4, *(f32 *)(c + 0x204), g + 0x654, *(f32 *)(s + 0x1C) * 1.44f, *(f32 *)(s + 0x20) * 1.44f, *(f32 *)(s + 0x4) * 0.020000001f, 0);
        func_L01_00448728(a0 + 0xF8, *(f32 *)(c + 0x208), g + 0x658, *(f32 *)(s + 0x1C) * 1.44f, *(f32 *)(s + 0x20) * 1.44f, *(f32 *)(s + 0x4) * 0.020000001f, 0);
    } else {
        func_L39_0052EE60(a0);
    }
}
/* localdecomp:end func_L39_00530490 */
