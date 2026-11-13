#include "common.h"

/* NTSC-U counterpart of func_L39_00608180 (src/levels/shared/L39_00608180.c) */
/* localdecomp:start func_L39_00605A80 */
extern void func_00194E58(s32, s32, s32, s32, s32);
typedef struct { s32 f0, f4; s32 f8, fC, f10; s32 f14, f18; u8 p1C[0x2C]; s32 f48, f4C; u8 p50[0xC]; s32 f5C; } Type1;

/* from rac4-decomp's func_004EF790, renamed */
void func_L39_00605A80(Type1 *a) {
    if (a->f4 != 3) {
        func_00194E58(a->f48, (a->f4C / 1024) * 1024, a->f48 + a->f5C, 0, 0);
    } else {
        func_00194E58(a->f48, (a->f4C / 1024) * 1024, a->f5C, a->f14, a->f18);
    }
    a->f0 = 2;
}
/* localdecomp:end func_L39_00605A80 */
