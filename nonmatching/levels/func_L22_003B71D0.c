/* NTSC-U draft (Claude wave C2): C of func_L22_003B5980, the NTSC-U twin of func_L22_003B71D0, with NTSC-U names and addresses (the two versions' code differs).
 * near miss: 7 words differ on NTSC-U with "-O2 -G8 -fopt-stack -mno-check-zero-division" (the file's line: "-O2 -G8 -fopt-stack -mno-check-zero-division @ps2as") (NTSC-U twin "func_L22_003B5980", whose code is not the PAL one).
 * Worker's note: 7 diff, only the two temporaries of the 0x2000 / 0x8000 arms: retail puts the alternative value (6 / 8) in v0 (li v0 sits in the delay slot of the preceding beqz) and the byte D_001D5477 in v1, then one shared movz s0,v0,v1; ours has them the other way round ...
 */
#include "common.h"

/* NTSC-U counterpart of the PAL function at the same position (L22 shared) */
/* localdecomp:start func_L22_003B5980 */
extern u8 *D_001D52FC;
__asm__(".extern D_001D52FC, 16");
extern u8 D_001D5477;
__asm__(".extern D_001D5477, 16");
extern s32 D_L22_001E2080;
__asm__(".extern D_L22_001E2080, 16");
extern void func_L01_0050BB98(s32, s32, f32);

s32 func_L22_003B5980(u8 *obj, u8 *other) {
    u8 *sub = *(u8 **)(obj + 0x68);
    s32 r = 0;
    s32 b;
    s32 c;

    if (*(s32 *)(sub + 0x480) != 0) {
        if (other[0x60] & 2) {
            *(s32 *)(sub + 0x480) = 0;
        }
    }
    b = *(s32 *)(D_001D52FC + 0x1A0);
    if (b & 0x10) {
        r = 1;
    } else if (b & 0x20) {
        r = 2;
    } else if (b & 0x40) {
        r = 3;
    } else if (b & 0x80) {
        r = 4;
    } else if (b & 0x1000) {
        r = 5;
    } else if (b & 0x4000) {
        r = 7;
    } else if (b & 0x2000) {
        c = 6;
        r = 8;
        if (D_001D5477 == 0) {
            r = c;
        }
    } else if (b & 0x8000) {
        c = 8;
        r = 6;
        if (D_001D5477 == 0) {
            r = c;
        }
    }
    if (D_L22_001E2080 != r) {
        if (*(s32 *)(sub + 0x480) == 0 || r > 0) {
            func_L01_0050BB98(r == 0 ? 1 : r + 5, 0, 12.0f);
        }
    }
    return r;
}
/* localdecomp:end func_L22_003B5980 */
