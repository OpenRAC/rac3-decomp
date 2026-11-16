/* NTSC-U draft (Claude wave K): C of func_L01_0030F1F8, the NTSC-U twin of func_L01_0030F4E8, with NTSC-U names and addresses (the two versions' code differs).
 * near miss: 13 words differ on NTSC-U with "-O2 -G8 -fopt-stack -mno-check-zero-division @ps2as (NOT the PAL line: no -mno-split-addresses)" (the file's line: "-O2 -G8 -fopt-stack -mno-check-zero-division -mno-split-addresses") (NTSC-U twin "func_L01_0030F1F8", whose code is not the PAL one).
 * Worker's note: near: 13 aligned diff units (ck4; 118 of 118 words, 8 hunks; k04's medium draft was 15) but only WITHOUT the PAL line's -mno-split-addresses and WITH @ps2as, so it would land as a flags row (drop -mno-split-addresses, add @ps2as); with the PAL line as it is ...
 */
#include "common.h"
#include "vu0.h"

/* NTSC-U counterpart of func_L01_0030F4E8 (src/levels/shared/L01_0030E630.c). NEAR (high): 13 words differ by the aligned score
   (ck4 TOTAL; 118 of 118 words) when compiled WITHOUT the PAL line's -mno-split-addresses and WITH @ps2as (the PAL flags as
   they are: 60). Retail's address pairs (lui v0 / addiu s1,v0 for the table, lui v1 / addiu v1 for the rows) are compiler-split
   high/lo_sum pairs, so retail was not built with -mno-split-addresses. Left: retail keeps the two `return 0` exits as separate
   blocks (ours cross-jumps them into one), sb 0x20 before mul.s, v0/v1 of the final global copy. */

/* localdecomp:start func_L01_0030F1F8 */
extern s32 D_001427F0[];
extern u8 D_001425C0[];
extern u8 D_L01_002C5640[];
extern s32 D_L01_001DFBC0;
extern s32 D_L01_001E17A8;
extern s32 func_L01_0050D978(s32);
extern s32 func_L01_0050D980(s32, s32);
extern void func_L01_0044ED38(s32, s32, s32, s32);
extern void func_0039FE80(s32, s32, void *);

s32 func_L01_0030F1F8(u8 *m) {
    u8 *v;
    s32 *tbl;
    s32 a;
    s32 diff;
    f32 lim;
    s32 d;
    s32 arg;
    u8 *row;

    v = *(u8 **)(m + 0x68);
    if (m[0x20] == 2) {
        return 0;
    }
    tbl = D_001427F0;
    a = tbl[func_L01_0050D978(*(s32 *)(v + 0x68))];
    lim = (f32)func_L01_0050D980(*(s32 *)(v + 0x68), *(s32 *)(v + 0x60));
    if (a >= tbl[func_L01_0050D978(*(s32 *)(v + 0x68))]) {
        return 0;
    }
    diff = tbl[func_L01_0050D978(*(s32 *)(v + 0x68))] - a;
    if (diff == 1) {
        row = D_L01_002C5640 + D_001425C0[func_L01_0050D978(*(s32 *)(v + 0x68))] * 0xF0;
        arg = *(s16 *)(row + 0x36);
    } else {
        row = D_L01_002C5640 + D_001425C0[func_L01_0050D978(*(s32 *)(v + 0x68))] * 0xF0;
        arg = *(s16 *)(row + 0x34);
    }
    func_L01_0044ED38(arg, diff, -1, 0);
    if (lim < (f32)*(s32 *)(v + 0x60)) {
        *(f32 *)(m + 0x2C) = *(f32 *)(m + 0x2C) * 1.2f;
        qzero(v);
        m[0x20] = 2;
        *(f32 *)(v + 0x70) = 0.13333334f;
        d = abs_asm(D_L01_001DFBC0 - D_L01_001E17A8);
        if (d >= 0xB) {
            func_0039FE80(0, 0, m);
            D_L01_001E17A8 = D_L01_001DFBC0;
        }
    }
    return 1;
}
/* localdecomp:end func_L01_0030F1F8 */
