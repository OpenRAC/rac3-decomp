/* functional: high. Same calls and arguments as retail; only register allocation and scheduling differ. */
#include "vu0.h"

extern u8 *D_L39_00296818[];
extern void func_0038CF68(void *, void *, f32);
extern f32 func_L39_005B4468(f32, f32);
extern f32 func_L39_005B4410(f32, f32);
extern void func_0038CE20(void *, void *, f32);
extern s32 func_L39_005B43C8(s32, s32);
extern s32 func_0019D510(void);
extern s32 func_L39_005B4398(s32);
extern void func_003C4C18(void *, f32);
extern u8 *func_L39_005C7B40(void *, void *, s32, s32, s32, s32, s32, s32, s32, f32);
extern u8 *func_L01_0046A610(void *, void *, s32, s32, s32, s32, f32, f32, f32, f32, f32);

void func_L39_00534880(u8 *obj, vu0_v4 *pa, vu0_v4 *pb) {
    vu0_v4 a;
    vu0_v4 b;
    vu0_v4 v30;
    vu0_v4 c;
    vu0_v4 d;
    vu0_v4 v60;
    u8 *st;
    u8 *fp;
    f32 len;
    s32 n;
    s32 i;

    a = *pa;
    b = *pb;
    if (obj != 0 && obj[0x20] != 0xFE && obj[0x20] != 0xFD) {
        st = *(u8 **)(obj + 0x68);
        fp = *(u8 **)(st + 0x28);
        len = func_0038CEA8((void *)st);
        n = (s32)(len / 0.100000001f);
        c = b;
        vec_sub_ab(&d, &a, &b);
        func_0038CF68(&d, &d, len / (f32)n);
        for (i = n; i > 0; i--) {
            s32 life = (s32)func_L39_005B4468(1.0f, 3.0f);
            s32 r;
            s32 size;
            s32 color;
            u8 *p;
            f32 s = func_L39_005B4410(0.100000001f, 0.300000012f) * 0.0200000014f;
            func_0038CE20(&v30, fp + 0x250, -s);
            r = func_L39_005B43C8(3, 6);
            if (func_0019D510() & 2) {
                size = 0x40;
                color = 0x407FFF;
            } else {
                size = 0x60;
                color = 0x4040FF;
            }
            p = func_L01_0046A610(&c, &v30, (r * 5 + 2) / 6, size, color, life, 42000.0f, 1000.0f, 1.0f, 0.0f, 0.0f);
            vec_add_ab(&c, &c, &d);
            if (p != 0) {
                if (func_L39_005B4398(2)) {
                    p[2] = D_L39_00296818[0x184 / 4][4];
                } else {
                    p[2] = D_L39_00296818[0x184 / 4][5];
                }
                p[3] = (size == 0x40) ? 0x48 : 0x44;
            }
        }
        func_0038CE20(&v60, st, -0.0400000028f);
        {
            s32 color;
            s32 x;
            u8 *p;
            color = 0x7F80DFFF;
            func_003C4C18(&v60, 0.120000005f);
            v60.z += 0.0600000024f;
            if (func_L39_005B4398(2)) color = 0x7F407FFF;
            x = func_L39_005B43C8(8, 17);
            p = func_L39_005C7B40(obj + 0x10, &v60, color, 0xFF, x, 0, -1, -1, 0, 94500.0f);
            if (p != 0) {
                *(f32 *)(p + 0x2C) = 0.0024000001f;
                p[2] = *D_L39_00296818[0xD4 / 4];
            }
        }
    }
}
