#include "common.h"

/* declared by functions of L32_003B5828.c, which this file was cut from */
extern void func_L01_004450F0(void *, s32, s32);
extern void func_L32_003B7190(void *, void *);
s32 func_003A52A0(s32, s32, void *);
void func_L01_004450F0(void *, s32, s32);

/* localdecomp:start func_L32_003B7190 */
#include "vu0.h"

extern void func_003C4DA8(void *, void *, void *, void *);
extern void func_L30_003A2C68(void *, s32);
extern void func_003C2F58(void *, s32, void *);
extern s32 func_003A52A0(s32, s32, void *);
extern s32 func_L32_003B6618(void *);
extern s32 func_L01_003303B8(void *, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32, f32,
                              s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
__asm__(".extern D_L32_001DEE1C, 4");
extern f32 D_L32_001DEE1C;
__asm__(".extern D_L32_001DEE38, 4");
extern f32 D_L32_001DEE38;

void func_L32_003B7190(void *arg0, void *arg1) {
    u8 *a0 = (u8 *)arg0;
    f32 *old = (f32 *)arg1;
    u8 *st = *(u8 **)(a0 + 0x68);
    vu0_v4 d;
    vu0_v4 v;
    vu0_v4 w;
    u8 **list;
    f32 *t;
    s32 i;
    s32 j;
    s32 r;

    vec_sub_ab(&d, a0 + 0x10, old);
    func_003C4DA8(st + 0x30, &d, a0 + 0xF0, a0 + 0xF0);
    if (a0[0x20] != 1) {
        list = (u8 **)(st + 0x150);
        for (i = 0; i < 48; i++) {
            if (list[i] != 0 && list[i][0x20] >= 0xFD) {
                list[i] = 0;
            }
        }
        for (i = 0; i < 48; i++) {
            if (list[i] != 0) {
                u8 *s = *(u8 **)(list[i] + 0x68);
                if (s != 0) {
                    f32 *x = (f32 *)(s + 0x80);
                    f32 *z = (f32 *)(s + 0x100);
                    for (j = 0; j < 32; j++) {
                        x[j] += d.x;
                        z[j] += d.z;
                    }
                    vec_add_ba(s + 0x30, s + 0x30, &d);
                    vec_add_ab(s + 0x10, s + 0x10, &d);
                    vec_add_ba(list[i] + 0x10, list[i] + 0x10, &d);
                }
            }
        }
    } else {
        list = (u8 **)(st + 0x150);
        for (i = 0; i < 48; i++) {
            if (list[i] != 0) {
                func_L30_003A2C68(list[i], 0x42);
                list[i] = 0;
            }
        }
    }
    *(f32 *)(st + 0x254) += D_L32_001DEE1C;
    if (*(f32 *)(st + 0x254) > 1.0f) {
        r = func_L32_003B6618(a0);
        *(f32 *)(st + 0x254) -= 1.0f;
        if (r >= 0) {
            func_003C2F58(a0, r % 8 + 2, &w);
            w.y += D_L32_001DEE38;
        }
    }
    t = (f32 *)(st + 0xB0);
    for (i = 0; i < 16; i++) {
        if (old[0] < t[i] && t[i] <= *(f32 *)(a0 + 0x10)) {
            f32 *add = (f32 *)(st + 0xF0);
            *(f32 *)(st + 0x148) += add[i];
            if (i < 8) {
                func_003C2F58(a0, i + 2, &v);
                func_L01_003303B8(&v, 0, 0x19, 0x14, 0x14, 0x14, 0x2D, 1, 0.9f, 0.0f, 0.0f, 2.0f, 1, 1, 0, 0, 1, 1,
                                  0x1010000, 0, 0x388EF7, 0x63F7, 0x407FFF, 0x20FF, 0x8FFF, 0x3064FF, 0x7F60A0FF,
                                  0x280000FF, 0x3064FF, 0);
                func_003A52A0(1, 0, a0);
            }
        }
    }
    if (old[0] < *(f32 *)(st + 0x238) && *(f32 *)(st + 0x238) <= *(f32 *)(a0 + 0x10)) {
        func_003C2F58(a0, 1, &v);
        func_L01_003303B8(&v, 0, 0x19, 0x14, 0x14, 0x14, 0x2D, 1, 0.9f, 0.0f, 0.0f, 2.0f, 1, 1, 0, 0, 1, 1,
                          0x1010000, 0, 0x388EF7, 0x63F7, 0x407FFF, 0x20FF, 0x8FFF, 0x3064FF, 0x7F60A0FF,
                          0x280000FF, 0x3064FF, 0);
        func_003A52A0(1, 0, a0);
    }
}
/* localdecomp:end func_L32_003B7190 */

INCLUDE_ASM("asm/levels", func_L32_003B7610);
