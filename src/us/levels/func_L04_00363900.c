#include "common.h"

/* NTSC-U counterpart of func_L04_003649B8 (src/levels/shared/L04_00362CE0.c) */
#include "vu0.h"
extern void func_L01_00441FB8(void *, s32, s32);
extern void func_003BE4F0(void *, s32, s32, s32);
extern void func_L01_00441FB8(void *, s32, s32);
extern s32 func_0037E208(s32, s32);
extern f32 func_00388800(void *, void *);
extern void func_L01_00441FB8(void *, s32, s32);
extern void func_003BE4F0(void *, s32, s32, s32);
extern s32 func_0037E208(s32, s32);
extern f32 func_00388800(void *, void *);
extern void func_L01_00441FB8(void *, s32, s32);
extern void func_L01_00441FB8(void *, s32, s32);
extern void func_003BE4F0(void *, s32, s32, s32);
extern f32 func_00388800(void *, void *);
extern void func_003BE4F0(void *, s32, s32, s32);
extern void func_L01_00441FB8(void *, s32, s32);
extern s32 func_0037E208(s32, s32);
extern void func_003BE4F0(void *, s32, s32, s32);
extern void func_L01_00441FB8(void *, s32, s32);
extern s32 func_0037E208(s32, s32);
extern f32 func_00388800(void *, void *);
extern void func_L01_00441FB8(void *, s32, s32);
extern s32 func_L01_00452EC8();
extern void func_L01_00458A70(void *, f32, f32, f32, f32);
extern void func_L01_00441FB8(void *, s32, s32);
extern void func_003BE4F0(void *, s32, s32, s32);
extern s32 func_L01_00452EC8();
extern void func_003BE4F0(void *, s32, s32, s32);
extern void func_L01_00441FB8(void *, s32, s32);
extern f32 func_00388800(void *, void *);
extern s32 func_L01_00452EC8();
extern void func_003BE4F0(void *, s32, s32, s32);
extern void func_L01_00441FB8(void *, s32, s32);
extern void func_L01_00458A70(void *, f32, f32, f32, f32);
extern s32 func_0037E208(s32, s32);
extern f32 func_00388A28(f32, f32);
extern f32 func_00388800(void *, void *);
extern s32 func_L01_00452EC8();
extern void func_L01_00458A70(void *, f32, f32, f32, f32);
extern void func_003BE4F0(void *, s32, s32, s32);
extern void func_L01_00441FB8(void *, s32, s32);
extern f32 func_00388800(void *, void *);

/* localdecomp:start func_L04_00363900 */
extern s32 func_L01_00452EC8();
extern void func_L01_00458A70(void *, f32, f32, f32, f32);
extern void func_003BE4F0(void *, s32, s32, s32);
extern void func_L01_00441FB8(void *, s32, s32);
extern s32 func_0037E208(s32, s32);
extern void func_L01_00455E98(void *, s32, void *);
extern void func_L01_00455C88(void *, void *, s32, s32);
extern void func_L01_00457440(void *, void *);
extern f32 func_00388800(void *, void *);
extern f32 func_00388A28(f32, f32);
extern f32 func_00389468(f32, f32);

s32 func_L04_00363900(u8 *a0) {
    u8 *pv = *(u8 **)(a0 + 0x68);
    if (func_L01_00452EC8(a0) != 0) {
        func_L01_00458A70(a0, 0.004444444552063942f, 0.10000000894069672f, 0.0069813174195587635f, 0.20943953096866608f);
        if (a0[0x43] != 3) {
            func_003BE4F0(a0, 3, 0, func_0037E208(8, 14));
        }
        func_L01_00455E98(a0, *(s32 *)(pv + 0x230), pv + 0x410);
    }
    if (*(s32 *)(pv + 0x4E4) == 0) {
        *(s32 *)(pv + 0x460) = *(s32 *)(pv + 0x230);
        func_L01_00455C88(a0, pv + 0x410, 0, 0);
        func_L01_00457440(a0, pv + 0x410);
    }
    if (*(f32 *)(pv + 0x120) < *(f32 *)(pv + 0x98) * 0.8f) {
        (*(s32 *)(pv + 0x450))++;
    }
    if (*(s32 *)(pv + 0x230) != *(s32 *)(pv + 0x460)) {
        func_L01_00455E98(a0, *(s32 *)(pv + 0x230), pv + 0x410);
    }
    if (func_00388800(a0 + 0x10, pv + 0x220) < 15.0f
        && func_00389468(*(f32 *)(a0 + 0xF8), func_00388A28(*(f32 *)(pv + 0x220) - *(f32 *)(a0 + 0x10), *(f32 *)(pv + 0x224) - *(f32 *)(a0 + 0x14))) < 0.17453292f) {
        func_L01_00441FB8(a0, 0xD, -1);
        return 1;
    }
    return 0;
}
/* localdecomp:end func_L04_00363900 */
