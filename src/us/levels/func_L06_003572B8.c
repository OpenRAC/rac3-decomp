#include "common.h"

/* NTSC-U counterpart of func_L06_00357FB8 (src/levels/shared/L06_00356C80.c): w28 = 30 against PAL's 25 (60 Hz) */
/* localdecomp:start func_L06_003572B8 */
#include "vu0.h"

extern int func_L01_00452EC8(u8 *);
extern void func_L06_00350C38(u8 *, u8 *, int, int, int);
extern s32 func_L06_00350528(u8 *, u8 *);
extern void func_L06_00352108(s32, u8 *);
extern s32 func_L01_0044AF40(void *, f32);
extern void func_L06_00351418(u8 *, u8 *);
typedef struct { u8 pad[0x20]; f32 f20; u8 pad24[4]; s32 w28; s32 w2C; } S_003572B8;
extern S_003572B8 D_L06_001E1700;
s32 func_L06_003572B8(u8 *a0) {
    u8 *v = *(u8 **)(a0 + 0x68);
    if (func_L01_00452EC8(a0)) {
        func_L06_00350C38(a0, v, 0x13, 0, 10);
        func_L06_00352108((s32)a0, v);
        *(s32 *)(v + 0x384) = 0;
        qzero(v + 0x110);
    }
    func_L06_00350528(a0, v);
    if (func_L01_0044AF40(a0, 21.0f) || func_L01_0044AF40(a0, 53.0f)) {
        D_L06_001E1700.f20 = 0.1f;
        D_L06_001E1700.w28 = 30;
        D_L06_001E1700.w2C = 0;
    }
    if (a0[0x60] & 2) {
        func_L06_00351418(a0, v);
        return 5;
    }
    return 0;
}
/* localdecomp:end func_L06_003572B8 */
