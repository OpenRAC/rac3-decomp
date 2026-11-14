#include "common.h"

/* NTSC-U counterpart of func_L04_00364EC0 (src/levels/shared/L04_00362CE0.c): 50 -> 60; 8 -> 10; 0.02 -> 0.0166667 */
#include "vu0.h"
extern void func_L01_00441FB8(void *, s32, s32);
extern void func_003BE4F0(void *, s32, s32, s32);
extern void func_L01_00441FB8(void *, s32, s32);
extern f32 func_00388800(void *, void *);
extern void func_L01_00441FB8(void *, s32, s32);
extern void func_003BE4F0(void *, s32, s32, s32);
extern void func_0039FE80(s32, s32, void *);
extern f32 func_00388800(void *, void *);
extern void func_L01_00441FB8(void *, s32, s32);
extern s32 D_001D545C;
extern void func_L01_00441FB8(void *, s32, s32);
extern void func_003BE4F0(void *, s32, s32, s32);
extern f32 func_00388800(void *, void *);
extern void func_L01_00442AA8(s32, s32);
extern void func_003BE4F0(void *, s32, s32, s32);
extern void func_L01_00441FB8(void *, s32, s32);
extern s32 D_001D545C;
extern void func_003BE4F0(void *, s32, s32, s32);
extern void func_L01_00441FB8(void *, s32, s32);
extern s32 func_L01_0044AF40(void *, f32);
extern f32 func_00388800(void *, void *);
extern void func_L01_00441FB8(void *, s32, s32);
extern s32 func_L01_00452EC8();
extern void func_L01_00441FB8(void *, s32, s32);
extern void func_003BE4F0(void *, s32, s32, s32);
extern s32 func_L01_00452EC8();
extern void func_003BE4F0(void *, s32, s32, s32);
extern void func_L01_00441FB8(void *, s32, s32);
extern f32 func_00388800(void *, void *);
extern s32 func_L01_00452EC8();
extern void func_003BE4F0(void *, s32, s32, s32);
extern void func_L01_00441FB8(void *, s32, s32);
extern f32 func_00388A28(f32, f32);
extern f32 func_L01_00445758(void *, f32, void *, f32, f32, f32, s32);
extern f32 func_00388800(void *, void *);
extern s32 func_00388398(void *);
extern s32 func_L01_00452EC8();
extern void func_003BE4F0(void *, s32, s32, s32);
extern void func_L01_00441FB8(void *, s32, s32);
extern f32 func_00388800(void *, void *);
extern s32 D_001D545C;
extern s32 func_L01_00452EC8();
extern void func_003BE4F0(void *, s32, s32, s32);
extern void func_L01_00441FB8(void *, s32, s32);
extern f32 func_00388800(void *, void *);
extern f32 func_00388A28(f32, f32);
extern s32 func_L01_00452EC8();
extern void func_003BE4F0(void *, s32, s32, s32);
extern void func_L01_00441FB8(void *, s32, s32);
extern void func_00388830(void *, void *, f32);
extern f32 func_00388800(void *, void *);
extern f32 func_00388A28(f32, f32);
extern s32 func_00388398(void *);
extern s32 D_001D545C;
extern s32 func_L01_00452EC8();
extern void func_003BE4F0(void *, s32, s32, s32);
extern void func_L01_00441FB8(void *, s32, s32);
extern f32 func_00388A28(f32, f32);
extern s32 func_L01_00458A08(void *, f32);
extern void func_L01_0040C920(void *, void *);
extern void func_003888C8(void *, void *, void *);
extern void func_00388830(void *, void *, f32);
extern f32 func_00388990(f32);
extern f32 func_L01_00445758(void *, f32, void *, f32, f32, f32, s32);
extern void func_00388BD0(void *, void *);
extern void func_00388EB8(void *, void *, void *);
extern s32 D_001D545C;

/* localdecomp:start func_L04_00363DD8 */
extern s32 func_L01_00452EC8();
extern void func_003BE4F0(void *, s32, s32, s32);
extern void func_L01_00441FB8(void *, s32, s32);
extern f32 func_00388A28(f32, f32);
extern s32 func_L01_00458A08(void *, f32);
extern void func_L01_0040C920(void *, void *);
extern void func_003888C8(void *, void *, void *);
extern void func_00388830(void *, void *, f32);
extern f32 func_00388990(f32);
extern f32 func_L01_00445758(void *, f32, void *, f32, f32, f32, s32);
extern void func_00388BD0(void *, void *);
extern void func_00388EB8(void *, void *, void *);
extern s32 func_00388398(void *);
extern s32 func_L01_0044AF40(void *, f32);
extern void func_L01_00442AA8(s32, s32);
extern f32 func_00388800(void *, void *);
extern void func_003BD9A0(void *, s32, void *);
extern void func_0039FE80(s32, s32, void *);
extern void func_L01_003A7568(void *, void *, void *, f32);
extern void func_L01_003AD288(void *, void *, void *, s32, f32);
extern s32 D_001D545C;
__asm__(".extern D_L04_001DD724, 4");
extern f32 D_L04_001DD724;

s32 func_L04_00363DD8(u8 *a0) {
    u8 *pv = *(u8 **)(a0 + 0x68);
    s32 r;
    if (func_L01_00452EC8(a0) != 0) {
        *(s32 *)(pv + 0x124) = 0;
        *(s32 *)(pv + 0x4AC) = 0x3C;
        if (a0[0x43] != 5) {
            func_003BE4F0(a0, 5, 0, 10);
        }
    }
    func_L01_00458A08(a0, func_00388A28(*(f32 *)(pv + 0x220) - *(f32 *)(a0 + 0x10), *(f32 *)(pv + 0x224) - *(f32 *)(a0 + 0x14)));
    if (*(s32 *)(pv + 0x4E4) != 0) {
        {
            vu0_v4 m0[3];
            vu0_v4 d;
            vu0_v4 m1[3];
            vu0_v4 v;
            vu0_v4 w;
            f32 f;
            func_L01_0040C920(m0, a0 + 0xC0);
            vec_sub_ab(&d, pv + 0x220, a0 + 0x10);
            func_003888C8(&d, &d, m0);
            d.z = 0.0f;
            func_00388830(&d, &d, 1.0f);
            f = func_00388990(d.y);
            {
                f32 y = *(f32 *)(pv + 0x88);
                f32 z = *(f32 *)(pv + 0x8C);
                f32 x = *(f32 *)(pv + 0x84);
                w.x = 0.0f;
                func_L01_00445758(&w, f, pv + 0x124, x, y, z, 0);
            }
            qzero(&v);
            v.z = *(f32 *)(pv + 0x124);
            func_00388BD0(m1, &v);
            func_00388EB8(a0 + 0xC0, a0 + 0xC0, m1);
        }
    }
    if (a0[0x21] == 0xFF) {
        r = 1;
    } else {
        r = a0[0xBC] == 0;
        if (func_00388398(pv + 0x4AC) == 0) {
            r = 0;
        }
    }
    if (func_L01_0044AF40(a0, 16.0f) != 0 && a0[0x42] == 5 && func_L01_00452EC8(a0) == 0 && r != 0) {
        if (a0[0x21] != 0xFF) {
            func_L01_00442AA8(a0[0x21], 1);
        }
        func_L01_00441FB8(a0, 0xF, -1);
        return 2;
    }
    if (D_001D545C != 0x10 && D_001D545C != 0xD && r != 0
        && (func_L01_0044AF40(a0, 3.0f) != 0 || func_L01_0044AF40(a0, 7.0f) != 0
            || func_L01_0044AF40(a0, 11.0f) != 0 || func_L01_0044AF40(a0, 15.0f) != 0)
        && a0[0x42] == 5) {
        vu0_v4 v;
        vu0_v4 m[4];
        vu0_v4 a;
        vu0_v4 b;
        func_003BD9A0(*(void **)(pv + 0x2FC), 0, m);
        func_0039FE80(0, 0, a0);
        a = m[3];
        b = m[0];
        func_L01_003A7568(a0, &a, &b, 0.649999976f);
        func_00388830(&v, &m[0], D_L04_001DD724 * 0.0166666675f);
        if (func_L01_0044AF40(a0, 3.0f) != 0) {
            v.z -= 0.200000003f;
        }
        if (func_L01_0044AF40(a0, 7.0f) != 0) {
            v.z -= 0.150000006f;
        }
        if (func_L01_0044AF40(a0, 11.0f) != 0) {
            v.z -= 0.100000001f;
        }
        if (func_L01_0044AF40(a0, 15.0f) != 0) {
            v.z -= 0.0500000007f;
        }
        func_L01_003AD288(a0, &v, &m[3], 1, 1.0f);
    }
    if (func_00388800(a0 + 0x10, pv + 0x220) < 2.5f && r == 0 && *(s32 *)(pv + 0x4E4) == 0) {
        func_L01_00441FB8(a0, 0x10, -1);
        return 2;
    }
    return 0;
}
/* localdecomp:end func_L04_00363DD8 */
