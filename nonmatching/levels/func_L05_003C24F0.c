/* NTSC-U draft (Claude wave C2): C of func_L05_003C0480, the NTSC-U twin of func_L05_003C24F0, with NTSC-U names and addresses (the two versions' code differs).
 * flags: byte-exact on NTSC-U only with "-O2 -G8 -fopt-stack -mno-check-zero-division @ps2as" (its file's line: "-mvu0-use-vf0-vf2 -O2 -G8 -fopt-stack -mno-check-zero-division @ps2as") (NTSC-U twin "func_L05_003C0480", whose code is not the PAL one).
 * Worker's note: flags: byte-exact (MATCH) only with the extra @ps2as; its PAL counterpart file src/levels/shared/L05_003C0EA8.c has no @ps2as (60 diff with the PAL flags: inline lui/ori/mtc1 constants). Twin of func_L11_003A2550 with struct offsets 0x328->0x32C / ...
 */
#include "common.h"

/* NTSC-U counterpart of func_L05_003C24F0 (src/levels/shared/L05_003C0EA8.c) */
/* localdecomp:start func_L05_003C0480 */
extern s32 func_L01_0044EAB8(void *, s32, s32, f32);
extern s32 func_0038DBD8(s32, s32, f32);
extern void func_003C2F58(void *, s32, void *);
extern void func_003D9508(void *, int, int, int, float, float, float);

void func_L05_003C0480(u8 *a0)
{
    u8 *v = *(u8 **)(a0 + 0x68);
    u8 buf[0x10];
    u8 st;

    if (a0[0x95] == 0) {
        *(s32 *)(v + 0x328) = func_L01_0044EAB8(v + 0x32C, 0x40108010, 0x40042004, 0.139626354f);
    } else if (a0[0x95] == 2) {
        st = a0[0x20];
        if (st == 7 || st == 9 || st == 8) {
            *(s32 *)(v + 0x328) = func_L01_0044EAB8(v + 0x32C, 0x40101080, 0x40040420, 0.139626354f);
        } else {
            *(s32 *)(v + 0x328) = func_L01_0044EAB8(v + 0x32C, 0x40108080, 0x40084040, 0.139626354f);
        }
    } else {
        *(s32 *)(v + 0x328) = func_L01_0044EAB8(v + 0x32C, 0x40108080, 0x40084040, 0.139626354f);
    }
    *(s32 *)(a0 + 0x78) = func_0038DBD8(*(s32 *)(v + 0x328), *(s32 *)(a0 + 0x78), 0.920000017f);
    func_003C2F58(a0, 0, buf);
    func_003D9508(buf, 0xB, *(s32 *)(a0 + 0x78), 1, 0.25f, 0.08f, 0.0f);
}
/* localdecomp:end func_L05_003C0480 */
