#include "common.h"

/* NTSC-U counterpart of func_L04_00364D38 (src/levels/shared/L04_00362CE0.c): 8 -> 10 */
#include "vu0.h"
extern void func_L01_00441FB8(void *, s32, s32);
extern void func_003BE4F0(void *, s32, s32, s32);
extern void func_L01_00441FB8(void *, s32, s32);
extern void func_L01_00441FB8(void *, s32, s32);
extern void func_003BE4F0(void *, s32, s32, s32);
extern void func_L01_00441FB8(void *, s32, s32);
extern s32 D_001D545C;
extern void func_L01_00441FB8(void *, s32, s32);
extern void func_003BE4F0(void *, s32, s32, s32);
extern void func_003BE4F0(void *, s32, s32, s32);
extern void func_L01_00441FB8(void *, s32, s32);
extern s32 D_001D545C;
extern void func_003BE4F0(void *, s32, s32, s32);
extern void func_L01_00441FB8(void *, s32, s32);
extern void func_L01_00441FB8(void *, s32, s32);
extern s32 func_L01_00452EC8();
extern void func_L01_00441FB8(void *, s32, s32);
extern void func_003BE4F0(void *, s32, s32, s32);
extern s32 func_L01_00452EC8();
extern void func_003BE4F0(void *, s32, s32, s32);
extern void func_L01_00441FB8(void *, s32, s32);
extern s32 func_L01_00452EC8();
extern void func_003BE4F0(void *, s32, s32, s32);
extern void func_L01_00441FB8(void *, s32, s32);
extern f32 func_00388A28(f32, f32);
extern f32 func_L01_00445758(void *, f32, void *, f32, f32, f32, s32);
extern s32 func_L01_00452EC8();
extern void func_003BE4F0(void *, s32, s32, s32);
extern void func_L01_00441FB8(void *, s32, s32);
extern void func_003BF360(void *, void *);
extern s32 D_001D545C;
extern s32 func_L01_00452EC8();
extern void func_003BE4F0(void *, s32, s32, s32);
extern void func_L01_00441FB8(void *, s32, s32);
extern f32 func_00388A28(f32, f32);
extern s32 func_L01_00452EC8();
extern void func_003BE4F0(void *, s32, s32, s32);
extern void func_L01_00441FB8(void *, s32, s32);
extern void func_00388830(void *, void *, f32);
extern f32 func_00388A28(f32, f32);
extern s32 D_001D545C;

/* localdecomp:start func_L04_00363C50 */
extern s32 func_L01_00452EC8();
extern void func_003BE4F0(void *, s32, s32, s32);
extern void func_L01_00441FB8(void *, s32, s32);
extern void func_003BF360(void *, void *);
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

s32 func_L04_00363C50(u8 *a0) {
    u8 *pv = *(u8 **)(a0 + 0x68);
    vu0_v4 m0[3];
    vu0_v4 d;
    vu0_v4 m1[3];
    vu0_v4 v;
    vu0_v4 w;
    f32 f;
    if (func_L01_00452EC8(a0) != 0) {
        *(s32 *)(pv + 0x124) = 0;
        if (a0[0x43] != 4) {
            func_003BE4F0(a0, 4, 0, 10);
        }
        if (*(s32 *)(pv + 0x4E4) != 0) {
            func_003BF360(a0 + 0xC0, a0 + 0xF0);
        }
    }
    func_L01_00458A08(a0, func_00388A28(*(f32 *)(pv + 0x220) - *(f32 *)(a0 + 0x10), *(f32 *)(pv + 0x224) - *(f32 *)(a0 + 0x14)));
    if (*(s32 *)(pv + 0x4E4) != 0 && D_001D545C == 0x10) {
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
    if (a0[0x60] & 2) {
        func_L01_00441FB8(a0, 0xE, -1);
        return 2;
    }
    return 0;
}
/* localdecomp:end func_L04_00363C50 */
