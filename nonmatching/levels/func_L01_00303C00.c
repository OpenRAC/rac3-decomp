/* NTSC-U draft (Claude wave C2): C of func_L01_003039E8, the NTSC-U twin of func_L01_00303C00, with NTSC-U names and addresses (the two versions' code differs).
 * flags: byte-exact on NTSC-U only with "-O2 -G8 -fopt-stack -mno-check-zero-division -mno-split-addresses @ps2as" (its file's line: "-O2 -G8 -fopt-stack -mno-check-zero-division -mno-split-addresses") (NTSC-U twin "func_L01_003039E8", whose code is not the PAL one).
 * Worker's note: flags: byte-exact (MATCH) only with the extra @ps2as; its PAL counterpart file src/levels/shared/L01_002FEA20.c has -mno-split-addresses but no @ps2as (29 diff with the PAL flags: retail has inline lui/ori/mtc1 constants 0.1f and 0.01f). 12 places. Spawner: p ...
 */
#include "common.h"
#include "vu0.h"

/* NTSC-U counterpart of func_L01_00303C00 (src/levels/shared/L01_002FEA20.c) */
/* localdecomp:start func_L01_003039E8 */
extern u8 *func_003BCFB0(s32, s32);
extern f32 func_00388A28(f32, f32);
extern f32 func_003887A0(void *);
extern s32 func_L01_00468338(void *, s32, s32, s32, f32, f32);
extern void func_003C26C8(void *);

u8 *func_L01_003039E8(u8 *parent, f32 *dir, vu0_q *pos, f32 scale) {
    u8 *p;
    u8 *s;
    f32 a;

    p = func_003BCFB0(0x3A6, 0x80);
    if (p != 0) {
        p[0x30] = 0xFF;
        *(s16 *)(p + 0x32) = 0xFF;
        p[0x31] = 1;
        p[0x20] = 0;
        s = *(u8 **)(p + 0x68);
        *(unsigned long *)(p + 0x38) = *(unsigned long *)(parent + 0x38);
        *(vu0_q *)(p + 0x10) = *pos;
        *(vu0_q *)s = *(vu0_q *)dir;
        *(s32 *)(s + 0x38) = 0xF0;
        *(u8 **)(s + 0x3C) = parent;
        *(f32 *)(s + 0x40) = scale;
        *(f32 *)(p + 0xF8) = func_00388A28(dir[0], dir[1]);
        a = func_00388A28(func_003887A0(dir), dir[2]);
        *(f32 *)(p + 0xF4) = -a;
        *(s32 *)(s + 0x48) = func_L01_00468338(p, -1, 0xF0208080, 0x60, 0.1f, 0.01f);
        func_003C26C8(p);
        *(u16 *)(p + 0x34) |= 1;
        p[0x31] = 0;
    }
    return p;
}
/* localdecomp:end func_L01_003039E8 */
