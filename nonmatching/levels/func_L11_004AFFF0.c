/* near miss (level 11, Obani Moons): 2 differences (the class of func_L01_00350040): retail has lui, lw, xori, jr and leaves the jr delay slot as the nop at 0x4B0000, which the catalogue counts as the linker remnant func_L01_003ECA08 in its own file (L01_003EB9C8.c's slice); gcc fills the slot with the xori, so the C is the same 16 bytes in the other order. The C needs the remnant file to become this function's delay slot */
#include "common.h"

/* localdecomp:start func_L11_004AFFF0 */
extern s32 D_0016C5E4[];

s32 func_L11_004AFFF0(void)
{
    return D_0016C5E4[0] ^ 1;
}
/* localdecomp:end func_L11_004AFFF0 */
