#include "common.h"

INCLUDE_ASM("asm/levels", func_L40_00449788);

LINKER_REMNANT("asm/levels", func_L40_00449820);

INCLUDE_ASM("asm/levels", func_L40_00449828);

/* localdecomp:start func_L40_00449A38 */
typedef struct {
    u8 b0;
    u8 b1;
    s16 id;
    s32 w4;
    s32 w8;
    s32 wC;
    s32 w10;
} E_00449A38;
extern s32 D_001D6D14_sda;
extern s32 D_001D6D10_sda;
extern E_00449A38 D_L40_00257CC0[];
extern u8 func_L40_00449828(void *, s32 *, s32 *, u16 *);

s32 func_L40_00449A38(void *a0, s32 *o1, s32 *o2, u16 *o3, u8 *o4) {
    u16 c0;
    s32 s4;
    s32 s8;
    u8 r;
    s32 i;

    if (((D_001D6D14_sda + 1) & 0xF) == D_001D6D10_sda) {
        return 0;
    }
    r = func_L40_00449828(a0, &s4, &s8, &c0);
    for (i = 0; i < 16; i++) {
        if (s4 == D_L40_00257CC0[i].w8 && s8 == D_L40_00257CC0[i].wC) {
            return 0;
        }
    }
    if (o1 != 0) {
        *o1 = s4;
        *o2 = s8;
        *o3 = c0;
        *o4 = r;
    }
    return 1;
}
/* localdecomp:end func_L40_00449A38 */
