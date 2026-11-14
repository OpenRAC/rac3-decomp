#include "common.h"

/* NTSC-U counterpart of func_L04_00363B60 (src/levels/shared/L04_00362CE0.c) */
#include "vu0.h"
extern void func_L01_00441FB8(void *, s32, s32);
extern void func_003BE4F0(void *, s32, s32, s32);
extern void func_L01_00441FB8(void *, s32, s32);
extern f32 func_00388800(void *, void *);
extern void func_L01_00441FB8(void *, s32, s32);
extern void func_003BE4F0(void *, s32, s32, s32);
extern f32 func_00388800(void *, void *);
extern void func_L01_00441FB8(void *, s32, s32);
extern void func_L01_00441FB8(void *, s32, s32);
extern void func_003BE4F0(void *, s32, s32, s32);
extern f32 func_00388800(void *, void *);
extern void func_003BE4F0(void *, s32, s32, s32);
extern void func_L01_00441FB8(void *, s32, s32);
extern void func_003BE4F0(void *, s32, s32, s32);
extern void func_L01_00441FB8(void *, s32, s32);
extern f32 func_00388800(void *, void *);
extern void func_L01_00441FB8(void *, s32, s32);
extern s32 func_L01_00452EC8();
extern void func_L01_00441FB8(void *, s32, s32);
extern void func_003BE4F0(void *, s32, s32, s32);

/* localdecomp:start func_L04_00362AE0 */
extern s32 func_L01_00452EC8();
extern void func_003BE4F0(void *, s32, s32, s32);
extern void func_L01_00441FB8(void *, s32, s32);
extern f32 func_0037E250(f32, f32);
extern f32 func_00388800(void *, void *);
extern s32 func_L03_00446540(void *, s32, s32, s32);
extern s32 *D_L04_0021E2C0[];

s32 func_L04_00362AE0(u8 *a0) {
    u8 *pv = *(u8 **)(a0 + 0x68);
    s32 *path;
    f32 d;
    if (func_L01_00452EC8(a0) != 0) {
        *(f32 *)(a0 + 0x48) = func_0037E250(0.85000002f, 1.15f);
        if (a0[0x43] != 1) {
            func_003BE4F0(a0, 1, 0, (s32)func_0037E250(4.0f, 12.0f));
        }
    }
    if (a0[0x60] & 2) {
        if (*(s32 *)(pv + 0x300) != -1) {
            path = D_L04_0021E2C0[*(s32 *)(pv + 0x300)];
            func_L01_00441FB8(a0, 2, -1);
            d = func_00388800(a0 + 0x10, path + 4);
            if (func_00388800(a0 + 0x10, path + path[0] * 4) < d) {
                func_L03_00446540(a0, *(s32 *)(pv + 0x300), 0, path[0] - 1);
            } else {
                func_L03_00446540(a0, *(s32 *)(pv + 0x300), path[0] - 1, 0);
            }
        } else {
            func_L01_00441FB8(a0, 4, -1);
        }
        return 1;
    }
    return 0;
}
/* localdecomp:end func_L04_00362AE0 */
