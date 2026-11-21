/* func_L03_003D02A0 (L03_003D0120.c; also level 06 at 0x003C82C0): byte-exact with check.py, but only
 * structurally, so it stays a near miss: retail saves $s0-$s7 and $ra with `sq`, so it needs a row in
 * config/levels/sq_ra_funcs.txt, a divs_nops row `func_L03_003D02A0 1 0`, and it compiles to retail's
 * frame only without -fopt-stack (with the file's line and the two table rows: 25 diff rows; with the
 * committed tables and the file's line, plain check.py: 131). The function sits between
 * matched functions of L03_003D0120.c (003D0190 before it, 003D0598 after it), so that means
 * cutting the file in three (docs/build/build-fidelity.md, rule 1). With those three changes (the
 * flags tried as --flags with -fno-opt-stack, the table rows layered over the committed ones) it
 * printed MATCH in level 03 (Opus helper, 2026-11-20). What mattered: D_L01_001D66B0 as
 * `extern f32` used by address (an unsized u8[] keeps its address in a saved register), the
 * existing interleaved-float prototypes of func_L01_00451FE0 and func_L02_003E2E38, a `p = pos;`
 * just before the quadword copy, vec_add_ab. */
#include "common.h"
#include "vu0.h"
typedef int Q_003D02A0 __attribute__((mode(TI)));
extern f32 D_L01_001D66B0;
extern void func_003A52A0(s32, s32, void *);
extern void func_L01_00451FE0(void *, s32, void *, f32, f32, f32, f32, s32, f32, f32, s32, s32, s32, s32, f32, f32, s32, s32);
extern void func_L02_00429840(void *, void *, s32, s32, void *, s32, s32, s32, f32, f32, f32, f32);
extern void func_L02_003E2E38(void *, void *, f32, void *, s32, s32, f32, f32, f32, f32, s32);
extern s32 func_L01_003303B8(void *, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32, f32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
extern void func_L01_00451E78(void *, s32, f32);
extern void func_003C2880(void *);
extern void func_0038CF68(void *, void *, f32);
void func_L03_003D02A0(u8 *m, s32 cls, s32 row, s32 spawn, s32 fx1, s32 fx2, s32 fx3, s32 flip, s32 color, f32 a, f32 b) {
    f32 pos[4];
    f32 off[4];
    s16 r = row;
    f32 *p;
    func_003A52A0(0, 0, m);
    func_L01_00451FE0(m, cls, &D_L01_001D66B0, 3.0f, 6.0f, 3.0f, 6.0f, 0xFF, -1.0f, -1.0f, 0xB4, 0, 0, 0x23, 1.0f, 1.0f, 0, 3);
    if (spawn) {
        func_L03_003D0190(m, spawn, flip);
    }
    p = pos;
    *(Q_003D02A0 *)p = *(Q_003D02A0 *)(m + 0x10);
    *(Q_003D02A0 *)off = ((Q_003D02A0 *)m)[r + 12];
    func_0038CF68(off, off, *(f32 *)(m + 0x2C) / (*(f32 **)(m + 0x24))[0x24 / 4] * a);
    pos[2] += *(f32 *)(m + 0x2C) / (*(f32 **)(m + 0x24))[0x24 / 4] * b;
    vec_add_ab(p, p, off);
    if (fx1) {
        func_L02_00429840(m, p, 0x14, 0, &D_L01_001D66B0, color, 0, 0x4B, 4.0f, 0.2000000179f, 0.7f, 1.3f);
    }
    if (fx2) {
        func_L02_003E2E38(m, p, 1.0f, &D_L01_001D66B0, 0xF, 0, 0.0500000045f, 2.5f, 5.0f, 1.0f, 1);
    }
    if (fx3) {
        func_L01_003303B8(p, 0, 0, 0, 0, 2, 5, 0, 1.0f, 0.0f, 0.0f, 0.0f,
                          0, 1, 0, 0, 0, 0, 0x1000000, 0, 0x7FD68F, 0xFF8400, 0, 0, 0, 0, 0x7F60A0FF, 0x280000FF, 0, 0);
    }
    func_L01_00451E78(m, 1, 0.0f);
    func_003C2880(m);
}
