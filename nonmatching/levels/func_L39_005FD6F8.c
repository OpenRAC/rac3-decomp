/* PAL near miss (Codex wave 4): held at landing: the C of its NTSC-U twin func_L39_005FAF60, which matches NTSC-U, renamed to PAL names: it matches PAL at level 39 but not at level 40 (1 word differs), so it cannot be the one source of every place.
 */
#include "common.h"

/* localdecomp:start func_L39_005FD6F8 */
/* Ported from rac2-decomp/src/game/002FC8D0.c, gfx_remove_dma_handlers.
 * The two views name the same handler cell: the branch delay slot reads its
 * gp slot, while the path that writes D_STAT reloads its absolute address. */
extern s32 D_L39_0024CAE8;
extern s32 D_001E13D8_sda;
extern s32 D_L39_0024CAEC;
__asm__(".extern D_L39_0024CAE8, 16");
__asm__(".extern D_L39_0024CAEC, 16");

void func_L39_005FD6F8(void)
{
    extern void func_00125F90(s32, s32);
    extern void func_00126DD0(s32);
    s32 handler;
    if ((*(volatile u32 *)0x1000E010 & 0x20000) != 0) {
        *(volatile u32 *)0x1000E010 = 0x20000;
        handler = D_L39_0024CAE8;
    } else {
        handler = D_001E13D8_sda;
    }
    func_00125F90(1, handler);
    func_00125F90(15, D_L39_0024CAEC);
    func_00126DD0(1);
    D_L39_0024CAE8 = 0;
    D_L39_0024CAEC = 0;
}
/* localdecomp:end func_L39_005FD6F8 */
