#include "common.h"

/* NTSC-U counterpart of func_L39_005A5CE8 (src/levels/shared/L39_005A5C90.c) */
extern s32 D_001A4568[];

/* localdecomp:start func_L39_005A4078 */
extern s32 D_L39_0024057C;
extern s32 D_L39_00240578;
__asm__(".extern D_L39_0024057C, 16");
__asm__(".extern D_L39_00240578, 16");
extern s32 D_001A4568[];
extern void func_00397238(void);

/* Picks the next memory-card state: 4 when the card state is not 2, otherwise 0x12 (after
 * func_00397238) when flag 0x20 is set, 0x1D when flag 0x2000 is set, else leaves it unchanged. */
void func_L39_005A4078(void) {
    s32 r;
    if (D_001A4568[0] != 2) {
        r = 4;
    } else {
        s32 x = D_L39_0024057C;
        if (x & 0x20) {
            func_00397238();
            r = 0x12;
        } else if (x & 0x2000) {
            r = 0x1D;
        } else {
            return;
        }
    }
    D_L39_00240578 = r;
}
/* localdecomp:end func_L39_005A4078 */
