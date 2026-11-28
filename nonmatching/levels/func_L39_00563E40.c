/* Wave 13 (c42, 2026-11-28) replaces the earlier draft of this function (k6 Opus near miss (2026-11-26)). */
/* func_L39_00563E40 (levels 39-53, now in L39_00563DB8.c): wave 13c c42 near under the line
 * "-mvu0-use-vf0-vf2 -O2 -G8 -fopt-stack -mno-check-zero-division @ps2as" (the line of the next file,
 * L39_005640A0.c, and of L39_00561FF8/00562858/00563370.c): tools/check.py level 39, 126 diff (148 aligned
 * rows, 4 instructions short; r22 measured 148 under the file's own line); keeping -mno-split-addresses this C gives 150 (no split
 * addresses: worse). Changed against r22's draft: include/vu0.h's vec_sub_ab/vec_add_ab (separate "j" statements,
 * so the pointer steps interleave as in retail: both VU0 loops now match), D_L39_0024D714 a plain scalar
 * (retail's lui $at/lwc1 inside loop 2 is the Ps2EeAs expansion of a small-data guess with no .extern),
 * D_L39_0024D6D0 through one pointer (retail keeps its address in one register for both loops, copied
 * to t6 for loop 1 and to s0 for loop 2), plain i++ outer loop (the n = i + 1 form gives the same code).
 * Still differs: retail computes the head store D[i][0] with its own 0xA0 constant and product (two mults
 * after the vsub loop, the address copied to a1 for the .w store) where this C shares one product, and
 * keeps D_L39_0024D6F0's address inside loop 1; the extra pressure puts the D_003CD480 high half in s0 and
 * the D_6D0 pointer in s2 in retail; loop 2's colour loads are scheduled B4FC first.
 */
#include "common.h"

/* localdecomp:start func_L39_00563E40 */
#include "vu0.h"

__asm__(".extern D_L39_0024B544, 4");
__asm__(".extern D_L39_0024B4F8, 4");
__asm__(".extern D_L39_0024B4FC, 4");
extern vu0_v4 D_L39_003CD480[][10];
extern s16 D_L39_0024D6D0[];
extern s16 D_L39_0024D6E0[];
extern s16 D_L39_0024D6F0[];
extern f32 D_L39_0024D714;
extern f32 D_L39_0024B544;
extern s32 D_L39_0024B4F8;
extern s32 D_L39_0024B4FC;

void func_L39_00563E40(u8 *m)
{
    extern void func_L01_00409658(void *, s32, s32, s32, s32, s32, s32, f32, f32, f32);
    vu0_v4 pos;
    vu0_v4 d[10];
    s32 i;
    s32 j;
    s32 k;
    s32 a;
    s32 col;
    s16 *cnt;

    cnt = D_L39_0024D6D0;
    pos = *(vu0_v4 *)(*(u8 **)(m + 0x68) + 0x30);
    for (i = 0; i < 5; i++) {
        if (cnt[i] != 0) {
            for (j = 1; j < 10; j++) {
                vec_sub_ab(&d[j], &D_L39_003CD480[i][j], &D_L39_003CD480[i][j - 1]);
            }
            D_L39_003CD480[i][0] = pos;
            D_L39_003CD480[i][0].w = 0.04f;
            for (j = 1; j < 10; j++) {
                vec_add_ab(&D_L39_003CD480[i][j], &D_L39_003CD480[i][j - 1], &d[j]);
                D_L39_003CD480[i][j].w = 0.04f;
            }
            if (cnt[i] > 0) {
                D_L39_0024D6E0[i] = D_L39_0024B544 * ((f32)cnt[i] / (f32)D_L39_0024D6F0[i]);
            } else {
                D_L39_0024D6E0[i] = 0;
            }
        }
    }
    for (k = 0; k < 5; k++) {
        if (cnt[k] != 0) {
            a = (s32)((f32)D_L39_0024D6E0[k] * D_L39_0024D714) << 24;
            col = D_L39_0024B4F8;
            if (*(s16 *)(m + 0xAA) == 0x1192) {
                col = D_L39_0024B4FC;
            }
            func_L01_00409658(D_L39_003CD480[k], 0x17, 0xE, 0xA, a | 0x7F7F7F, a | col, 1, 0.0f, 4.0f, 0.0f);
        }
    }
}
/* localdecomp:end func_L39_00563E40 */
