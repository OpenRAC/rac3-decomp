#include "common.h"

/* NTSC-U counterpart of func_L04_00365910 (src/levels/shared/L04_00362CE0.c) */
#include "vu0.h"
extern void func_L01_00441FB8(void *, s32, s32);
extern void func_003BE4F0(void *, s32, s32, s32);
extern void func_L01_00441FB8(void *, s32, s32);
extern s32 func_0037E208(s32, s32);
extern void func_L01_00441FB8(void *, s32, s32);
extern void func_003BE4F0(void *, s32, s32, s32);
extern s32 func_0037E208(s32, s32);
extern void func_L01_00441FB8(void *, s32, s32);
extern void func_L01_00441FB8(void *, s32, s32);
extern void func_003BE4F0(void *, s32, s32, s32);
extern void func_003BE4F0(void *, s32, s32, s32);
extern void func_L01_00441FB8(void *, s32, s32);
extern s32 func_0037E208(s32, s32);
extern void func_003BE4F0(void *, s32, s32, s32);
extern void func_L01_00441FB8(void *, s32, s32);
extern s32 func_0037E208(s32, s32);
extern void func_L01_00441FB8(void *, s32, s32);
extern s32 func_L01_00452EC8();
extern void func_L01_00458A70(void *, f32, f32, f32, f32);
extern void func_L01_00441FB8(void *, s32, s32);
extern void func_003BE4F0(void *, s32, s32, s32);
extern s32 func_L01_00452EC8();
extern void func_003BE4F0(void *, s32, s32, s32);
extern void func_L01_00441FB8(void *, s32, s32);
extern s32 func_L01_00452EC8();
extern void func_003BE4F0(void *, s32, s32, s32);
extern void func_L01_00441FB8(void *, s32, s32);
extern void func_L01_00458A70(void *, f32, f32, f32, f32);
extern s32 func_0037E208(s32, s32);
extern s32 func_L01_00452EC8();
extern void func_L01_00458A70(void *, f32, f32, f32, f32);
extern void func_003BE4F0(void *, s32, s32, s32);
extern void func_L01_00441FB8(void *, s32, s32);
extern s32 func_L01_00452EC8();
extern void func_L01_00458A70(void *, f32, f32, f32, f32);
extern void func_003BE4F0(void *, s32, s32, s32);
extern void func_L01_00441FB8(void *, s32, s32);
extern s32 func_0037E208(s32, s32);
extern s32 func_L01_00452EC8();
extern void func_L01_00458A70(void *, f32, f32, f32, f32);
extern void func_003BE4F0(void *, s32, s32, s32);
extern void func_L01_00441FB8(void *, s32, s32);
extern s32 func_0037E208(s32, s32);
extern s32 func_L01_00452EC8();
extern void func_003BE4F0(void *, s32, s32, s32);
extern void func_L01_00441FB8(void *, s32, s32);
extern s32 func_L01_00452EC8();
extern void func_003BE4F0(void *, s32, s32, s32);
extern void func_L01_00441FB8(void *, s32, s32);
extern s32 func_L01_00452EC8();
extern void func_003BE4F0(void *, s32, s32, s32);
extern void func_L01_00441FB8(void *, s32, s32);
extern f32 func_L01_00436500(void *);
extern s32 func_L01_00452EC8();
extern void func_003BE4F0(void *, s32, s32, s32);
extern void func_L01_00441FB8(void *, s32, s32);
extern s32 func_0037E208(s32, s32);
extern s32 func_L01_00452EC8();
extern void func_003BE4F0(void *, s32, s32, s32);
extern void func_L01_00441FB8(void *, s32, s32);

/* localdecomp:start func_L04_00364808 */
extern s32 func_L01_00452EC8();
extern void func_L01_00458A70(void *, f32, f32, f32, f32);
extern void func_003BE4F0(void *, s32, s32, s32);
extern void func_L01_00441FB8(void *, s32, s32);
extern s32 func_0037E208(s32, s32);
extern f32 func_L01_00436500(void *);
extern void func_L04_00360BC8(u8 *, u8 *, f32);
__asm__(".extern D_L04_001DD710, 4");
__asm__(".extern D_L04_001DD714, 4");
extern f32 D_L04_001DD710;
extern f32 D_L04_001DD714;

s32 func_L04_00364808(u8 *a0) {
    u8 *pv = *(u8 **)(a0 + 0x68);
    f32 d;
    if (func_L01_00452EC8(a0) != 0) {
        func_L01_00458A70(a0, D_L04_001DD714 * 0.00027777778f, D_L04_001DD710 * 0.016666668f, 0.0069813174f, 0.20943953f);
        if (a0[0x43] != 0xB) {
            func_003BE4F0(a0, 0xB, 0, func_0037E208(6, 0xC));
        }
        if ((*(u16 *)(a0 + 0x34) & 0x8000) && a0[0x43] != 7) {
            func_003BE4F0(a0, 7, 0, func_0037E208(6, 0xC));
        }
    }
    d = func_L01_00436500(a0);
    if (3.0f < d && d < 12.0f) {
        func_L04_00360BC8(a0, pv, -1.0f);
    }
    if (a0[0x60] & 2) {
        func_L01_00441FB8(a0, 0x14, -1);
        return 2;
    }
    return 0;
}
/* localdecomp:end func_L04_00364808 */
