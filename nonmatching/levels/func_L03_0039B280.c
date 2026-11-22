/* func_L03_0039B280: near miss (file L03_0039AA48.c). 15 differences with -mvu0-use-vf0-vf2 (default assembler): retail keeps v[0] in
 * $v1 and reloads it at the join after the flag block, gcc (gcse PRE; -fno-gcse is 94 diff, so retail uses gcse too) puts
 * the reload after the call on the flag path only and keeps v[0] in $a1 on the no-flag path; the hero-near-path walk's moby
 * pointer goes straight to $a0 (retail $v1); lui is scheduled before the two lqc2 (retail after). Tried: type, alias-set,
 * inline-helper and branch-shape variants, four moby-pointer forms, table-address local/index forms, func_00382380
 * returning s32, a u8 pointer or u32 (same) or f32 (71), id as long/u32/s64 (84), S/N and ps2as modes.
 * LV-R2 retry (2026-11-22): re-measured at 15 differences (tools/check.py) at level 03 with -mvu0-use-vf0-vf2; it does not compile with the file's line as it is (vf17 spilled).
 */
#include "common.h"
#include "vu0.h"
extern u8 D_001A4C60[];
extern s32 func_00382380(void *, s32, s32);
extern f32 func_0038CE68(void *, void *);
typedef struct { u8 pad[0x80]; } S80;
extern S80 *D_L03_001DFA80[];
extern u16 *D_0021C620[];
extern u8 *D_001DF99C[];
extern s32 D_001DF9D8;
s32 func_L03_0039B280(u8 *a) {
    s32 *v;
    u16 *cur;
    u8 *m;
    s32 id;
    vu0_v4 d;

    v = *(s32 **)(a + 0x68);
    id = v[0];
    if (id == -1) {
        return 0;
    }
    if (((u8 *)v)[0xC] != 0) {
        vec_sub_ba(&d, D_001A4C60, a + 0x10);
        if (0.0f < func_0038CE68(&D_L03_001DFA80[0][id], &d)) {
            return 1;
        }
    }
    if (func_00382380(D_001A4C60, v[0], 0) != 0) {
        return 1;
    }
    if (v[1] != -1) {
    cur = D_0021C620[v[1]];
    for (; (v[1] & 0xFF) != 0xFF && D_001DF9D8 >= v[1] && cur != 0 &&
           (((s16 *)cur)[-1] >= 0 || cur == D_0021C620[v[1]]); cur++) {
        m = D_001DF99C[0] + ((*cur & 0x7FFF) << 8);
        if (m == 0) {
            return 0;
        }
        if (func_00382380(m + 0x10, v[0], 0) != 0) {
            return 1;
        }
    }
    }
    return 0;
}
