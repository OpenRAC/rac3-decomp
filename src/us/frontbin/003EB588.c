#include "common.h"

/* NTSC-U version of func_003F0B20 (frontbin): NTSC-U stores the value as it is; PAL stores
   (a * 5 + 2) / 6, the same time in 50 Hz frames instead of 60 Hz ones */
/* localdecomp:start func_U_003EB588 */
typedef struct { u8 pad[0x2C]; u8 *f2C; } T_003EB588;
void func_U_003EB588(T_003EB588 *p, s32 a) {
    *(u16 *)(p->f2C + 0x4C) = a;
}
/* localdecomp:end func_U_003EB588 */
