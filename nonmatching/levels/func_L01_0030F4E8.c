/* PAL near miss (nm/b17-p2): the NTSC-U twin's draft (func_L01_0030F1F8; its code is not the PAL one) ported to PAL: PAL callees and
 * data (D_L01_002C5600, D_L01_001DFB40/1728), 1.24f and 0.16000001f (retail 0x3F9EB852 / 0x3E23D70B), `d >= 9` (slti 9). 33 diff words
 * with `--mode S`, 112 with the file's `-mno-split-addresses`: retail's lui/addiu pairs for D_1427F0, D_1425C0 and D_002C5600 are
 * compiler-split, so the file's line must become `-O2 -G8 -fopt-stack -mno-check-zero-division @ps2as` (the file is all assembly
 * otherwise). The body then matches retail except for three things:
 * 1. the exits: retail keeps the first `return 0` inline (`bne v0,v1,L520; lw s0 (delay); b epi; move v0,0`) and the second as
 *    `beqz v1,epi` with `move v0,0` in its delay slot; ours cross-jumps the first into the second's block (`beq v0,v1,<far>`, then
 *    `bnez v1,L; nop; b epi; move v0,0`), two words more. Nested forms (one return 0 at the end, an else branch, a nested if for the
 *    rest) move the whole layout (98 diff).
 * 2. retail stores `sb 2,0x20(m)` before the `mul.s` and the `swc1 0x2C(m)`, ours after them (with `m[0x20] = 2` as the first statement
 *    of the block the sb moves up but `swc1 0x70(v)` jumps ahead of the `sq`: also 33).
 * 3. the final copy of D_L01_001DFB40 uses $v1 in retail, $v0 in ours. */
#include "common.h"
#include "vu0.h"
/* localdecomp:start func_L01_0030F4E8 */
extern s32 D_001427F0[];
extern u8 D_001425C0[];
extern u8 D_L01_002C5600[];
extern s32 D_L01_001DFB40;
extern s32 D_L01_001E1728;
extern s32 func_L01_00511950(s32);
extern s32 func_L01_00511958(s32, s32);
extern void func_L01_00451FB8(s32, s32, s32, s32);
extern void func_003A52A0(s32, s32, void *);

s32 func_L01_0030F4E8(u8 *m) {
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
    a = tbl[func_L01_00511950(*(s32 *)(v + 0x68))];
    lim = (f32)func_L01_00511958(*(s32 *)(v + 0x68), *(s32 *)(v + 0x60));
    if (a >= tbl[func_L01_00511950(*(s32 *)(v + 0x68))]) {
        return 0;
    }
    diff = tbl[func_L01_00511950(*(s32 *)(v + 0x68))] - a;
    if (diff == 1) {
        row = D_L01_002C5600 + D_001425C0[func_L01_00511950(*(s32 *)(v + 0x68))] * 0xF0;
        arg = *(s16 *)(row + 0x36);
    } else {
        row = D_L01_002C5600 + D_001425C0[func_L01_00511950(*(s32 *)(v + 0x68))] * 0xF0;
        arg = *(s16 *)(row + 0x34);
    }
    func_L01_00451FB8(arg, diff, -1, 0);
    if (lim < (f32)*(s32 *)(v + 0x60)) {
        *(f32 *)(m + 0x2C) = *(f32 *)(m + 0x2C) * 1.24f;
        qzero(v);
        m[0x20] = 2;
        *(f32 *)(v + 0x70) = 0.16000001f;
        d = abs_asm(D_L01_001DFB40 - D_L01_001E1728);
        if (d >= 9) {
            func_003A52A0(0, 0, m);
            D_L01_001E1728 = D_L01_001DFB40;
        }
    }
    return 1;
}
/* localdecomp:end func_L01_0030F4E8 */
