/* functional: high. branch-merged tail so not byte exact; each mode variant written out; other modes leave the table untouched, as retail */
#include "common.h"

extern u8 *D_L39_00241640;
__asm__(".extern D_L39_00241640, 16");
extern u8 D_L39_00352CE0[];

void func_L39_006787B0(void) {
    u8 *g = D_L39_00241640;
    u8 *t = D_L39_00352CE0;
    s32 mode = *(s32 *)(g + 0x180);

    if (mode == 1) {
        t[0] = 0;
        t[1] = 0;
        t[2] = 0;
        t[3] = (*(u32 *)(t + 0x6A8) == 0);
        t[4] = (g[0x19F] != 0);
        t[5] = (*(s8 *)(g + 0x188) != 0);
        t[6] = (*(s8 *)(g + 0x18F) != 0);
        t[7] = (*(s8 *)(g + 0x194) == 0);
    } else if (mode == 0) {
        t[0] = 0;
        t[2] = 1;
        t[1] = 0;
        t[3] = (*(u32 *)(t + 0x6A8) == 0);
        t[4] = (g[0x19F] != 0);
        t[5] = (*(s8 *)(g + 0x188) != 0);
        t[6] = (*(s8 *)(g + 0x18F) != 0);
        t[7] = (*(s8 *)(g + 0x194) != 0);
    } else if (mode == 2) {
        t[0] = 0;
        t[1] = 0;
        t[2] = 0;
        t[3] = (*(u32 *)(t + 0x6A8) == 0);
        t[4] = (g[0x19F] != 0);
        t[5] = (*(s8 *)(g + 0x188) != 0);
        t[6] = (*(s8 *)(g + 0x18F) == 0);
        t[7] = (*(s8 *)(g + 0x194) == 0);
    } else {
        return;
    }
    t[8] = (*(s8 *)(g + 0x19B) == 0);
    t[9] = (*(s8 *)(g + 0x19A) == 0);
    t[0xA] = (*(s8 *)(g + 0x19C) == 0);
}
