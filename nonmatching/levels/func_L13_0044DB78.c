/* NTSC-U draft (Claude wave C2): C of func_L13_0044A168, the NTSC-U twin of func_L13_0044DB78, with NTSC-U names and addresses (the two versions' code differs).
 * flags: byte-exact on NTSC-U only with "-O2 -G8 -fopt-stack -mno-check-zero-division @ps2as" (its file's line: "-O2 -G8 -fopt-stack -mno-check-zero-division") (NTSC-U twin "func_L13_0044A168", whose code is not the PAL one).
 * Worker's note: flags: byte-exact (0 diff) only with @ps2as (inline lui/ori/mtc1 for 0.12f, 210000.0f); its PAL file has no @ps2as (see note count in report). Source: V4 passed BY VALUE (struct param is copied to the frame, $s2 = &copy), switch kind 0/1 with the float local ...
 */
#include "common.h"

/* NTSC-U counterpart of func_L13_0044DB78 (src/levels/shared/L13_0044DB78.c) */
typedef int u128_t __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_0044A168;

/* localdecomp:start func_L13_0044A168 */
extern u8 *func_L01_0045E438(s32);
extern f32 func_0037E250(f32, f32);
extern u8 *D_L13_0021F0B8[];

void func_L13_0044A168(u128_t *pos, s32 kind, V4_0044A168 vec, f32 scale)
{
    u8 *p = func_L01_0045E438(0x49);
    f32 f20;
    s32 c;

    if (p != 0) {
        f20 = 0.0f;
        c = 0;
        switch (kind) {
        case 0:
            f20 = 0.12f;
            func_0037E250(0.25f, 0.25f);
            c = 0x20;
            break;
        case 1:
            f20 = 0.5f;
            func_0037E250(1.0f, 1.0f);
            c = 0xD;
            break;
        }
        *(s16 *)(p + 0xA) = 0x37;
        *(u32 *)(p + 4) = (c << 24) | 0xFFFFFF;
        p[9] = 0x24;
        p[3] = 0x48;
        p[1] = 0;
        p[2] = D_L13_0021F0B8[1][kind];
        *(f32 *)(p + 0xC) = f20 * 210000.0f;
        p[8] = (s32)func_0037E250(0.0f, 360.0f);
        *(u128_t *)(p + 0x10) = *pos;
        *(V4_0044A168 *)(p + 0x20) = vec;
        *(f32 *)(p + 0x2C) = scale;
    }
}
/* localdecomp:end func_L13_0044A168 */
