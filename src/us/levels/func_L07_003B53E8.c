#include "common.h"

/* NTSC-U counterpart of func_L07_003B6CD8 (src/levels/07_annihilation_nation/L07_003AF398.c) */
#include "structs/moby.h"
#include "vu0.h"
extern s32 func_L01_00452F60(void *);
extern s32 func_L01_00452F60(void *);
extern s32 func_L07_003A0BC0(u8, s32, u8, s16);

/* localdecomp:start func_L07_003B53E8 */
extern u8 *D_L07_001DF41C_003B53E8;
extern s32 func_L01_00452F60(void *);
extern s32 func_L07_003A0BC0(u8, s32, u8, s16);

s32 func_L07_003B53E8(u8 *arg0, u8 arg1) {
    u8 *s = *(u8 **)(arg0 + 0x68);
    u8 *p;
    f32 d;

    if (s[0x321] != 0) {
        return 0;
    }
    if (s[0x320] >= 4) {
        return 1;
    }
    if (func_L01_00452F60(arg0) != 0) {
        if (*(s16 *)(s + 0x32A) == 0) {
            p = D_L07_001DF41C_003B53E8 + (*(s32 *)(s + 0x300) << 8);
            if (p[0xBC] == 0) {
                p[0xBC] = 1;
            }
            func_L07_003A0BC0(0xC, (s32)p, 0, 0x78);
            *(s16 *)(s + 0x32A) = 0x4B0;
        }
        return 1;
    }
    if (arg1 != 0) {
        return 0;
    }
    d = *(f32 *)(s + 0x310) - *(f32 *)(s + 0x30);
    if ((f32)*(s16 *)(s + 0x34) * 0.1f < d) {
        return 1;
    }
    return 0;
}
/* localdecomp:end func_L07_003B53E8 */
