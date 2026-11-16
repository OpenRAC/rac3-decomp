/* NTSC-U draft (Claude wave S/us): C of func_L19_00335808, the NTSC-U twin of func_L19_003361E0, with NTSC-U names and addresses (the two versions' code differs).
 * near miss: 6 words differ on NTSC-U with "needs @ps2as (1.1f inline lui/ori/mtc1), PAL line L19_003357A0.c lacks it" (the file's line: "-O2 -G8 -fopt-stack -mno-check-zero-division") (NTSC-U twin "func_L19_00335808", whose code is not the PAL one).
 * Worker's note: 6 diff with @ps2as (19 without: 1.1f from the gp literal pool, retail inline), so it cannot land with the PAL file's flags even if exact. Left: store order of 0xA0/0xC0 and 0x64/0x6C and the lui a0/v1 constant registers (retail lui v0=80402080, v1=80004880, ...
 */
#include "common.h"

typedef int u128_t __attribute__((mode(TI)));

/* localdecomp:start func_L19_00335808 */
extern s32 D_001DCD60_sda;
__asm__(".extern D_001DCD60_sda, 4");

void func_L19_00335808(u8 *obj)
{
    u8 *p = *(u8 **)(obj + 0x68);

    *(s32 *)(p + 0x94) = 0;
    if (*(s32 *)(p + 0x9C) < 0) {
        *(s32 *)(p + 0x9C) = 0xE;
    }
    if (*(s32 *)(p + 0x80) < 0) {
        *(s32 *)(p + 0x80) = 0x10;
    }
    *(s32 *)(p + 0xA8) = 0;
    *(f32 *)(p + 0xA4) = 1.0f;
    *(f32 *)(p + 0xA0) = 0.25f;
    *(s32 *)(p + 0xBC) = 0x80402080;
    *(s32 *)(p + 0x60) = 0x807F0000;
    *(s32 *)(p + 0x6C) = 0x8000007F;
    *(s32 *)(p + 0x68) = 0x807F0000;
    *(s32 *)(p + 0x64) = 0x8000007F;
    *(s32 *)(p + 0xC0) = 0x80004880;
    *(u128_t *)(p + 0xE0) = *(u128_t *)(obj + 0x10);
    *(s32 *)(p + 0xD8) = -1;
    *(s32 *)(p + 0xDC) = *(s32 *)(p + 0xDC) << 3;
    *(f32 *)(p + 0xE8) = *(f32 *)(p + 0xE8) + 1.1f;
    D_001DCD60_sda = 0;
}
/* localdecomp:end func_L19_00335808 */
