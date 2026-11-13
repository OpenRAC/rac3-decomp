#include "common.h"

/* NTSC-U counterpart of func_L39_00505270 (src/levels/39_multiplayer_menu/L39_005051E0.c) */
extern void func_0011D534(void *, s32, s32);

/* localdecomp:start func_L39_00505070 */
typedef struct {
    u8 pad0[0xC];
    void *fC;
} S_00505270;
extern S_00505270 *D_0019DA00 __attribute__((section(".data")));
extern u8 D_L39_004796B8[];
extern u8 D_L39_004796D0[];
extern void *func_L39_0050C018(void);
extern s32 func_L39_0050C030(void *, s32, void *, s32);
extern void func_L39_004BC4C8(s32, s32, s32, s32, s32);
extern void func_0011D534(void *, s32, s32);
extern s32 func_00120884(void *);
extern void func_0011AF90(void *, void *, s32);

s32 func_L39_00505070(void *arg0, s32 arg1, s32 arg2) {
    void *p;
    s32 r;

    p = func_L39_0050C018();
    if (p == 0) {
        p = D_L39_004796B8;
    }
    while (1) {
        if (func_L39_0050C030(arg0, arg1, p, arg2) != 0) {
            func_L39_004BC4C8(9, 0x77, 0x6D, 0, 0);
            func_0011D534(arg0, 0, arg1);
            return -1;
        }
        r = func_00120884(arg0);
        if (r >= 4) {
            return r;
        }
        func_0011AF90(D_0019DA00->fC, D_L39_004796D0, 4);
    }
}
/* localdecomp:end func_L39_00505070 */
