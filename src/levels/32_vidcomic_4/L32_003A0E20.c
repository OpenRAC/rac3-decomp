#include "common.h"
#include "vu0.h"

/* localdecomp:start func_L32_003A0E20 */
extern u8 D_1A4BE0[];
extern u8 *D_L32_001DFE1C;
extern s32 D_L32_001DE6F0;
extern f32 D_L32_001DE6B0;
__asm__(".extern D_L32_001DE6F0, 4");
__asm__(".extern D_L32_001DE6B0, 4");
extern s32 func_0038CAD0(void *);
extern s32 func_L30_0034D8D8(void *, f32);
extern void func_L32_0034B5A8(void *);
extern void func_L01_0044ABD0(void *, void *);
extern void func_003C6FB0(void *, s32 *, s32 *, s32 *);
extern void func_L01_0043B9E8(void *, s32, s32, s32);
extern void func_L30_0034CDC0(f32 *, f32 *, f32 *, f32 *, f32);
extern void func_L32_003A2468(void *, s32);
extern void func_L01_00456230(void *, s32);
extern void func_L32_003A1670(void *, s32);
extern void *func_L01_00447490(void *, u32, s32);
extern void func_003C4A40(void *, void *);
extern void func_0038CF68(void *, void *, f32);
extern s32 func_003A52A0(s32, s32, void *);

void func_L32_003A0E20(void *arg0) {
    u8 *v = *(u8 **)((u8 *)arg0 + 0x68);
    vu0_v4 d;
    s32 a, b, c;
    f32 x0, x1, x2, x3;
    u8 **q;
    u8 **list;
    s32 *p;
    s32 i;
    u8 *r;
    f32 dmg;
    u8 *h;

    func_0038CAD0(v + 0x74);
    if (func_L30_0034D8D8((u8 *)arg0 + 0x10, 1.0f) != 0) {
        func_L32_0034B5A8(arg0);
    }
    func_L01_0044ABD0(arg0, v + 0x40);
    list = (u8 **)(v + 0x200);
    func_003C6FB0(arg0, &a, &b, &c);
    for (i = 0; i < 6; i++) {
        if (list[i] != 0) {
            func_L01_0043B9E8(list[i], a, b, c);
        }
    }
    if (*(f32 *)(*(u8 **)(*(u8 **)(v + 0x218) + 0x68) + (*(s32 *)(v + 0xE8) << 5) + 0x4C) >= 1.0f) {
        func_L30_0034CDC0(&x0, &x1, 0, &x2, 0.93f);
        func_L30_0034CDC0(0, 0, &x3, 0, 1.0f);
        {
            u8 *h = D_1A4BE0;
            if ((x0 >= *(f32 *)(h + 0x80) && *(f32 *)(h + 0xF0) < 0.0f) ||
                (x1 <= *(f32 *)(h + 0x80) && *(f32 *)(h + 0xF0) > 0.0f)) {
                u8 *g = D_1A4BE0;
                *(f32 *)(g + 0x100) -= *(f32 *)(g + 0xF0);
            }
        }
        {
            u8 *h = D_1A4BE0;
            if (x2 <= *(f32 *)(h + 0x88) && *(f32 *)(h + 0xF8) > 0.0f) {
                *(f32 *)(h + 0x108) -= *(f32 *)(h + 0xF8);
            }
        }
        h = D_1A4BE0;
        if (x3 >= *(f32 *)(h + 0x88) && *(f32 *)(h + 0xF8) < 0.0f) {
            func_L32_003A2468(arg0, 0);
            p = (s32 *)(v + 0xE0);
            for (i = 0; i < 2; i++) {
                if (p[i] != -1) {
                    func_L01_00456230(D_L32_001DFE1C + (p[i] << 8), 0);
                }
            }
            func_L32_003A1670(arg0, 3);
        }
    }
    for (i = 0; i < 6; i++) {
        q = &list[i];
        if (*q != 0) {
            r = func_L01_00447490(*q, 0x10000, 0);
            if (r != 0) {
                (*q)[0xA8] = 0xFF;
                dmg = *(f32 *)(r + 0x2C);
                if (dmg > 0.0f && *(u8 *)((u8 *)arg0 + 0x20) != 0x42 &&
                    *(s32 *)(v + 0x74) <= 0) {
                    *(s32 *)(v + 0x74) = D_L32_001DE6F0;
                    *(f32 *)v -= dmg;
                    func_003C4A40(arg0, v + 0x40);
                    func_0038CF68(&d, r + 0x10, D_L32_001DE6B0);
                    vec_add_ab(v + 0x60, v + 0x60, &d);
                    if (*(f32 *)v <= 0.0f) {
                        func_L32_003A1670(arg0, 0x42);
                        func_003A52A0(5, 0, arg0);
                    } else {
                        func_003A52A0(4, 0, arg0);
                        *(s16 *)(v + 0x22A) = *(s32 *)(v + 0xF0);
                    }
                }
            }
        }
    }
    h = D_1A4BE0;
    *(f32 *)((u8 *)arg0 + 0x14) = *(f32 *)(h + 0x84);
    *(s32 *)(v + 0x64) = 0;
}
/* localdecomp:end func_L32_003A0E20 */

INCLUDE_ASM("asm/levels", func_L32_003A11C8);
