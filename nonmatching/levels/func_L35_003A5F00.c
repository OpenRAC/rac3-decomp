/* NTSC-U draft (2026-11-14, Claude worker): C of func_L35_003A45E8, the NTSC-U twin of func_L35_003A5F00, with NTSC-U names
 * and addresses. Byte-exact on NTSC-U with "-O2 -G8 -fopt-stack -mno-check-zero-division @ps2as" (src/levels/35_vidcomic_5/L35_003A5F00.c's line: "-O2 -G8 -fopt-stack -mno-check-zero-division").
 */
#include "common.h"

/* NTSC-U counterpart of func_L35_003A5F00 (src/levels/35_vidcomic_5/L35_003A5F00.c) */
/* localdecomp:start func_L35_003A45E8 */
extern u8 *D_L35_001DF91C;
extern u8 *D_001DFA00_sda;
__asm__(".extern D_001DFA00_sda, 4");
extern u8 *D_L35_0021D900[];
extern void func_L01_00441FB8(void *, s32, s32);

void func_L35_003A45E8(u8 *a0) {
    u8 *p;
    u8 *e;
    f32 *fp;
    f32 t;
    s32 i;

    a0[0x30] = 0xFF;
    *(u16 *)(a0 + 0x32) = 0;
    p = *(u8 **)(a0 + 0x68);
    fp = (f32 *)(p + 0x10);
    for (i = 3; i >= 0; i--) {
        *fp = *fp * 0.016666668f;
        fp++;
    }
    t = *(f32 *)(p + 0x54);
    e = D_L35_001DF91C + (*(s32 *)(p + 0x6C) << 8);
    *(f32 *)(p + 0x48) = t;
    *(s32 *)(p + 0x58) = 0;
    e[0x31] = 1;
    *(u16 *)(e + 0x34) &= 0xFFFE;
    if (*(s32 *)(p + 0x5C) != -1) {
        *(u8 **)(p + 0x60) = D_001DFA00_sda + (*(s32 *)(p + 0x5C) << 7);
    }
    if (*(s32 *)(p + 0x64) != -1) {
        *(u8 **)(p + 0x68) = D_L35_0021D900[*(s32 *)(p + 0x64)];
    }
    func_L01_00441FB8(a0, 1, -1);
}
/* localdecomp:end func_L35_003A45E8 */
