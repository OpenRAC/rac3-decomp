#include "common.h"

/* NTSC-U counterpart of func_L05_003624B0 (src/levels/05_daxx/L05_003619F0.c): 0.0004 -> 0.000277778 */
#include "vu0.h"
extern void func_00388830(void *, void *, f32);

/* localdecomp:start func_L05_00361198 */
__asm__(".extern D_L05_001DDA68, 4");
__asm__(".extern D_L05_001DDA6C, 4");
__asm__(".extern D_L05_001DDA70, 4");
__asm__(".extern D_L05_001DDA74, 4");
extern f32 D_L05_001DDA68;
extern f32 D_L05_001DDA6C;
extern f32 D_L05_001DDA70;
extern f32 D_L05_001DDA74;
void func_L05_00361488(void *);
extern void func_00388830(void *, void *, f32);
extern f32 func_00388800(void *, void *);
extern f32 func_00388770(void *);
extern f32 func_00388A28(f32, f32);
extern f32 func_003893C8(f32, f32);
extern f32 func_00389380(f32, f32);

void func_L05_00361198(u8 *o) {
    vu0_v4 t;
    vu0_v4 u;
    vu0_v4 w;
    u8 *v;
    u8 *a;
    f32 d;
    f32 ang;

    func_L05_00361488(o);
    v = *(u8 **)(o + 0x68);
    if (o[0x20] != 1) {
        return;
    }
    if (v[0x10] == 0) {
        a = *(u8 **)(v + 8);
        if ((*(u8 **)(a + 0x68))[0x10] == 1) {
            func_00388830(&t, a + 0xC0, D_L05_001DDA68);
            vec_add_ba(o + 0x10, *(u8 **)(v + 8) + 0x10, &t);
            d = func_00388800(o + 0x10, *(u8 **)(v + 0xC) + 0x10);
            ang = func_00388A28(d, *(f32 *)(*(u8 **)(v + 0xC) + 0x18) - *(f32 *)(o + 0x18));
            *(f32 *)(o + 0xF4) = func_00389380(*(f32 *)(o + 0xF4), func_003893C8(-ang, *(f32 *)(o + 0xF4)) * 0.1f);
            ang = func_00388A28(*(f32 *)(*(u8 **)(v + 0xC) + 0x10) - *(f32 *)(o + 0x10),
                                *(f32 *)(*(u8 **)(v + 0xC) + 0x14) - *(f32 *)(o + 0x14));
            *(f32 *)(o + 0xF8) = func_00389380(*(f32 *)(o + 0xF8), func_003893C8(ang, *(f32 *)(o + 0xF8)) * 0.1f);
        } else {
            vec_sub_ba(&t, *(u8 **)(v + 0xC) + 0x10, o + 0x10);
            func_00388830(&t, &t, (func_00388770(&t) - D_L05_001DDA68) * D_L05_001DDA74);
            vec_sub_ba(&u, *(u8 **)(v + 8) + 0x10, o + 0x10);
            func_00388830(&u, &u, (func_00388770(&u) - D_L05_001DDA68) * D_L05_001DDA70);
            vec_add_ba(&w, &t, &u);
            w.z -= D_L05_001DDA6C * 0.000277777785f;
            vec_add_ab(o + 0x10, o + 0x10, &w);
            d = func_00388800(o + 0x10, *(u8 **)(v + 0xC) + 0x10);
            ang = func_00388A28(d, *(f32 *)(*(u8 **)(v + 0xC) + 0x18) - *(f32 *)(o + 0x18));
            *(f32 *)(o + 0xF4) = func_00389380(*(f32 *)(o + 0xF4), func_003893C8(-ang, *(f32 *)(o + 0xF4)) * 0.1f);
            ang = func_00388A28(*(f32 *)(*(u8 **)(v + 0xC) + 0x10) - *(f32 *)(o + 0x10),
                                *(f32 *)(*(u8 **)(v + 0xC) + 0x14) - *(f32 *)(o + 0x14));
            *(f32 *)(o + 0xF8) = func_00389380(*(f32 *)(o + 0xF8), func_003893C8(ang, *(f32 *)(o + 0xF8)) * 0.1f);
        }
    } else {
        a = *(u8 **)(v + 0xC);
        if (*(s16 *)(a + 0xAA) == 0x16C7) {
            func_00388830(&t, a + 0xD0, D_L05_001DDA68);
            vec_add_ba(o + 0x10, *(u8 **)(v + 0xC) + 0x10, &t);
            *(vu0_q *)(o + 0xF0) = *(vu0_q *)(*(u8 **)(v + 0xC) + 0xF0);
            *(f32 *)(o + 0xF4) = func_00389380(*(f32 *)(o + 0xF4), 1.5707964f);
        }
        if (*(s16 *)(*(u8 **)(v + 8) + 0xAA) == 0x16C7) {
            *(vu0_q *)(o + 0x10) = *(vu0_q *)(*(u8 **)(v + 8) + 0x10);
            *(vu0_q *)(o + 0xF0) = *(vu0_q *)(*(u8 **)(v + 8) + 0xF0);
            *(f32 *)(o + 0xF8) = func_00389380(*(f32 *)(o + 0xF8), 1.5707964f);
        }
    }
}
/* localdecomp:end func_L05_00361198 */
