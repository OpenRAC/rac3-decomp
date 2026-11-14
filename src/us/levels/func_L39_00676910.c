#include "common.h"

/* NTSC-U counterpart of func_L39_006792F8 (src/levels/shared/L39_00677F28.c) */
extern s32 D_L39_00240480;
extern s32 D_L39_00240484;

/* localdecomp:start func_L39_00676910 */
extern s32 func_00120884(char *);
extern void func_L39_00593620(s32, s32, s32, s32, unsigned long, char *, s32);
extern f32 D_L39_002467E4;
__asm__(".extern D_L39_002467E4, 4");
extern f32 D_L39_002467E8;
__asm__(".extern D_L39_002467E8, 4");
extern f32 D_L39_002467EC;
__asm__(".extern D_L39_002467EC, 4");
extern f32 D_L39_002467F0;
__asm__(".extern D_L39_002467F0, 4");
extern s32 D_L39_00240480;
extern s32 D_L39_00240484;
extern char D_L39_00353380[];

void func_L39_00676910(void) {
    f32 w = (f32)D_L39_00240480;
    f32 h = (f32)D_L39_00240484;
    s32 x = (s32)(D_L39_002467E4 * w);
    s32 y = (s32)(D_L39_002467E8 * h);
    s32 ww = (s32)(D_L39_002467EC * w);
    s32 hh = (s32)(D_L39_002467F0 * h);
    func_L39_00593620(x, y, ww, hh, 0x8066CCFF, D_L39_00353380, func_00120884(D_L39_00353380));
}
/* localdecomp:end func_L39_00676910 */
