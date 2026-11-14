#include "common.h"

/* NTSC-U counterpart of func_L04_003652B8 (src/levels/shared/L04_00362CE0.c): 5 -> 6 */
#include "vu0.h"
extern void func_L01_00441FB8(void *, s32, s32);
extern void func_003BE4F0(void *, s32, s32, s32);
extern void func_L01_00441FB8(void *, s32, s32);
extern void func_L01_00441FB8(void *, s32, s32);
extern void func_003BE4F0(void *, s32, s32, s32);
extern void func_L01_00441FB8(void *, s32, s32);
extern void func_L01_00441FB8(void *, s32, s32);
extern void func_003BE4F0(void *, s32, s32, s32);
extern void func_003BE4F0(void *, s32, s32, s32);
extern void func_L01_00441FB8(void *, s32, s32);
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
extern s32 func_L01_00452EC8();
extern void func_003BE4F0(void *, s32, s32, s32);
extern void func_L01_00441FB8(void *, s32, s32);
extern s32 func_L01_00452EC8();
extern void func_003BE4F0(void *, s32, s32, s32);
extern void func_L01_00441FB8(void *, s32, s32);
extern s32 func_L01_00452EC8();
extern void func_003BE4F0(void *, s32, s32, s32);
extern void func_L01_00441FB8(void *, s32, s32);
extern s32 func_L01_00452EC8();
extern void func_003BE4F0(void *, s32, s32, s32);
extern void func_L01_00441FB8(void *, s32, s32);
extern s32 func_L01_00452EC8();
extern void func_003BE4F0(void *, s32, s32, s32);
extern void func_L01_00441FB8(void *, s32, s32);

/* localdecomp:start func_L04_003641D0 */
extern s32 func_L01_00452EC8();
extern void func_003BE4F0(void *, s32, s32, s32);
extern void func_L01_00441FB8(void *, s32, s32);
extern f32 func_L01_00436500(void *);
extern void func_003BDA38(void *, s32, void *);
extern s32 func_L01_00443648(void *, f32, void *, s32, f32, f32, s32, s32, s32);

s32 func_L04_003641D0(u8 *a0) {
    u8 *pv = *(u8 **)(a0 + 0x68);
    vu0_v4 b;
    vu0_v4 a;
    f32 d;
    if (func_L01_00452EC8(a0) != 0 && a0[0x43] != 0x16) {
        func_003BE4F0(a0, 0x16, 0, 6);
    }
    d = func_L01_00436500(a0);
    if (14.0f <= d && d < 19.0f && a0[0x42] == 0x16) {
        func_003BDA38(*(void **)(pv + 0x2FC), 0, &a);
        func_003BDA38(a0, 0, &b);
        func_L01_00443648(a0, 0.5f, &a, 1, pv[0x45], 1.0f, 0, 1, 0);
        func_L01_00443648(a0, 0.5f, &b, 1, pv[0x45], 1.0f, 0, 1, 0);
    }
    if (a0[0x60] & 2) {
        func_L01_00441FB8(a0, 0xD, -1);
        return 2;
    }
    return 0;
}
/* localdecomp:end func_L04_003641D0 */
