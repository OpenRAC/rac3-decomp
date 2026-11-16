/* NTSC-U draft (Claude wave C2): C of func_L07_003C9438, the NTSC-U twin of func_L07_003CAE10, with NTSC-U names and addresses (the two versions' code differs).
 * flags: byte-exact on NTSC-U only with "-O2 -G8 -fopt-stack -mno-check-zero-division @ps2as" (its file's line: "-O2 -G8 -fopt-stack -mno-check-zero-division") (NTSC-U twin "func_L07_003C9438", whose code is not the PAL one).
 * Worker's note: flags: byte-exact (0 diff) only with @ps2as (inline lui/ori/mtc1 for 0.05f); its PAL file (shared L07_003B1350-area, flags without @ps2as) gives the gp-pool load instead. Spawner class 0x1B35 (template PAL C func_L01_003B1750 of the same family: quad copies, ...
 */
#include "common.h"
#include "vu0.h"

/* NTSC-U counterpart of func_L07_003CAE10 (src/levels/shared/L07_003CAE10.c) */
typedef int u128_t __attribute__((mode(TI)));

/* localdecomp:start func_L07_003C9438 */
extern u8 *func_003BCFB0(s32, s32);

u8 *func_L07_003C9438(u128_t *pos, u128_t *vec, s32 a2, s32 a3, s32 t0, s32 t1, s32 t2, f32 fa, f32 fb)
{
    u8 *o = func_003BCFB0(0x1B35, 0x80);
    u8 *v;

    if (o != 0) {
        o[0x30] = 0xFF;
        *(u16 *)(o + 0x32) = 0xFF;
        o[0x31] = 1;
        *(u16 *)(o + 0x34) |= 0x41;
        *(s32 *)(o + 0xB8) = a2;
        o[0x20] = 0;
        v = *(u8 **)(o + 0x68);
        *(u128_t *)(o + 0x10) = *pos;
        *(s32 *)(v + 0x40) = t1;
        *(s32 *)(v + 0x44) = t2;
        *(s32 *)(v + 0x24) = 0x14;
        *(f32 *)(v + 0x28) = 0.05f;
        *(f32 *)(v + 0x20) = fa;
        *(u128_t *)v = *vec;
        *(s32 *)(v + 0x3C) = t0;
        qzero(v + 0x10);
        *(f32 *)(v + 0x34) = fb;
        *(s32 *)(v + 0x38) = a3;
        *(s32 *)(v + 0x30) = 0;
    }
    return o;
}
/* localdecomp:end func_L07_003C9438 */
