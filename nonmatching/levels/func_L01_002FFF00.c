/* NTSC-U draft (Codex wave 4): C of func_L01_002FFEA8, the NTSC-U twin of func_L01_002FFF00, with NTSC-U names and addresses.
 * near miss: 9 words differ on NTSC-U with the file's flags (NTSC-U twin "func_L01_002FFEA8").
 * Worker's note: sister build/codex/pool/X4/us_func_L01_002FFEA8_rac2.c; best log build/codex/w165/func_L01_002FFEA8.check01.log; Best 9 word diffs in supplied double-threshold variant: soft-float helper calls versus inline float compare; original sister float threshold ...
 */
#include "common.h"

/* localdecomp:start func_L01_002FFEA8 */
/* Ported from rac2-decomp/src/game/0030F7B0.c. */
extern void *D_L01_001DB02C;
__asm__(".extern D_L01_001DB02C, 16");
extern float D_L01_001DFBD0[];

void func_L01_002FFEA8(unsigned char *self)
{
    extern void func_L01_002FFF98(char *, void *);
    extern int func_L01_003F5D40(void *);
    extern int func_0037E1D8(int);
    extern void func_L01_00441FB8(void *, int, int);
    extern void func_003BD360(void *);
    if (D_L01_001DB02C != 0)
        func_L01_002FFF98((char *)self, D_L01_001DB02C);
    switch (self[0x20]) {
    case 0:
        if (func_L01_003F5D40(self) != 0 ||
            (D_L01_001DFBD0[0] > 0.949999988079071044921875 && func_0037E1D8(10) == 0)) {
            func_L01_00441FB8(self, 1, -1);
            *(unsigned short *)(self + 0x34) |= 0x2800;
        }
        break;
    case 1:
        func_L01_003F5D40(self);
        if (self[0x23] < 2)
            func_003BD360(self);
        else
            self[0x23] -= 2;
        break;
    }
}

/* localdecomp:end func_L01_002FFEA8 */
