#include "common.h"

/* localdecomp:start func_L30_0034A880 */
extern f32 D_001DD490_sda;
__asm__(".extern D_001DD490_sda, 4");
extern f32 D_001DD498_sda;
__asm__(".extern D_001DD498_sda, 4");
extern s32 D_L30_001DF2C0_0034A880;
extern void func_L30_0034ACE0(void *);
extern void func_L30_0034AE48(void *);
extern s32 func_L30_0034AAA0(u8 *a0);
extern void func_L30_0034ABA8(void *);
extern s32 func_L01_00452EC8(void *);
extern void func_003BE4F0(void *, s32, s32, s32);
extern void func_L01_00441FB8(void *, s32, s32);

void func_L30_0034A880(u8 *a0) {
    s32 two = 2;
    u8 *p;
    s32 st;
    s32 v;

    p = *(u8 **)(a0 + 0x68);
    func_L30_0034ACE0(a0);
    st = a0[0x20];
    if (st == two) {
        goto state2;
    }
    if (st < 3) {
        if (st == 0) {
            goto state0;
        }
        if (st == 1) {
            goto state13;
        }
        return;
    }
    if (st == 4) {
        goto state4;
    }
    if (st < 4) {
        goto state13;
    }
    return;
state0:
    *(s32 *)(p + 0x228) = 0;
    *(f32 *)(p + 0x210) = *(f32 *)(p + 0x220);
    if (*(f32 *)(p + 0x224) <= 0.0f) {
        *(f32 *)(p + 0x224) = D_001DD498_sda;
    }
    if ((u32)(*(s32 *)(p + 0x214) - 1) < 0x41) {
        func_L01_00441FB8(a0, *(s32 *)(p + 0x214), -1);
    }
    return;
state2:
    if (func_L01_00452EC8(a0) != 0) {
        if (a0[0x43] != 2) {
            func_003BE4F0(a0, 2, 0, 0);
        }
    }
    func_L30_0034AE48(a0);
    if (func_L30_0034AAA0(a0) != 0) {
        func_L30_0034ABA8(a0);
    }
    return;
state13:
    if (func_L01_00452EC8(a0) != 0) {
        if (a0[0x43] != two) {
            func_003BE4F0(a0, 2, 0, 0);
        }
    }
    if (func_L30_0034AAA0(a0) != 0) {
        func_L30_0034ABA8(a0);
    }
    return;
state4:
    if (func_L01_00452EC8(a0) != 0) {
        if (a0[0x43] != 4) {
            func_003BE4F0(a0, 4, 0, 0);
        }
    }
    if (a0[0x60] & 2) {
        v = a0[0x43];
        if (v == 4) {
            func_003BE4F0(a0, 0, 0, 0);
        } else if (v == 0) {
            if ((f32)*(s32 *)(p + 0x228) + D_001DD490_sda < (f32)D_L30_001DF2C0_0034A880) {
                func_003BE4F0(a0, 1, 0, 0);
            }
        } else if (v == 1) {
            *(f32 *)(p + 0x50) = (f32)*(s16 *)(p + 0x54);
            func_L01_00441FB8(a0, *(s32 *)(p + 0x214), -1);
        }
    }
}
/* localdecomp:end func_L30_0034A880 */
