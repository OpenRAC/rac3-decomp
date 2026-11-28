/* func_L01_00451FE0 (Claude wave 14 r69, 2026-11-28). Replaces the earlier draft of this function (NTSC-U draft of `func_L01_0044ED60` (Codex wave 3)). */
/* func_L01_00451FE0 (816 B, 49 places): PAL C written from the retail assembly, wave 14 worker r69
 * (2026-11-28). Replaces the NTSC-U draft of func_L01_0044ED60, which names the NTSC-U function and gives
 * no count on PAL. The body matches retail apart from the frame: retail saves $s0-$s7/$fp/$ra with sq in
 * 16-byte slots (frame 0x190), which this file's -fopt-stack line cannot give (54 diff under the file's
 * line, all in the prologue/epilogue and the two stack-argument offsets). Under the existing line
 * "-mvu0-use-vf0-vf2 -O2 -G8 -mno-check-zero-division @ps2as" (tools/check.py --flags=-fno-opt-stack,
 * level 01) the frame is 0x190 and what is left is the $ra/sq slot order (an sq_ra_funcs row) and
 * two prologue scheduling runs: retail sets count first and copies it into i (move $s3, $s4), and
 * loads the 0.02f constant into $f24 before the spill store of the mask (sw $a1, 0x78($sp)); here
 * i = 0 is a constant move and the mask store goes first (the entry loads of the two stack
 * parameters h and k take the memory unit ahead of the constant in sched1).
 * Levers used: u8 local for the particle flags (andi in the prologue, as retail), the spawn callee
 * declared with its two floats before the u8 argument (same EABI registers; puts mov.s $f12 before
 * move $t3 as retail), vec_add_ab for the VU0 add. The function's own prototype is the one
 * func_L01_00452310's block declares. Cut for its own file: 0x00451FE0-0x00452310 (both 8-aligned). */
#include "common.h"

/* localdecomp:start func_L01_00451FE0 */
extern void func_L01_00439880(void *, s32 *, s32 *);
extern f32 func_00382538(void);
extern f32 func_003824E0(f32, f32);
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);
extern void func_0038D000(void *, void *, void *);
extern s32 D_L01_001D673C;
extern s32 func_00382498(s32, s32);
extern u8 *func_L01_003F79D8(void *, s32, s32, s32, void *, void *, void *, f32, f32, u8, s32, s32, s32);
typedef void (*Fn_00451FE0)(s32, s32 *, s32, s32, s32, f32, f32);
extern Fn_00451FE0 *func_L01_0043B548(s32, s32);
extern void func_L01_003D4C08(s32, s32 *, s32, s32, s32, f32);

void func_L01_00451FE0(void *m, s32 a, void *b, f32 x1, f32 x2, f32 x3, f32 x4, s32 e,
                          f32 x5, f32 x6, s32 f, s32 g, s32 c, s32 d, f32 x0, f32 one,
                          s32 h, s32 k) {
    s32 ids[15];
    vu0_v4 vec;
    s32 n0, n1;
    s32 count = 0;
    s32 i;
    f32 ang, scale, r;
    Fn_00451FE0 *cb;
    u8 type = e;

    for (i = 0; i < 15; i++) {
        if (((a >> i) ^ 1) & 1) {
            continue;
        }
        func_L01_00439880(m, &n0, &n1);
        ang = func_00382538();
        scale = func_003824E0(x1, x2) * 0.020000001f;
        vec.x = func_0038D098(ang) * scale;
        vec.y = func_0038D0B0(ang) * scale;
        vec.z = 0.0f;
        vec.z = func_003824E0(x3, x4) * 0.020000001f;
        if (D_L01_001D673C) {
            func_0038D000(&vec, &vec, (u8 *)m + 0xC0);
        }
        vec_add_ab(&vec, &vec, b);
        if (x6 == -1.0f) {
            x6 = func_003824E0(90.0f, 270.0f);
        }
        if (x5 == -1.0f) {
            r = func_003824E0(10.0f, 20.0f);
        } else {
            r = func_003824E0(x5 * 0.7f, x5 * 1.3f);
        }
        x5 = r;
        f = f > 180 ? func_00382498(180, f) : f;
        ids[i] = (s32)func_L01_003F79D8(m, 2, *(s16 *)((u8 *)m + 0xAA), i, (u8 *)m + 0x10, (u8 *)m + 0xF0,
                                        &vec, x6, r, type, f, g, 0x80);
        if (ids[i]) {
            count++;
        }
    }
    if (c) {
        cb = func_L01_0043B548(0x1CD7, 4);
        if (cb) {
            (*cb)(count, ids, d, 7, 5, x0, -100000.0f);
        }
    }
    if (h) {
        func_L01_003D4C08(count, ids, h, k, 30, one);
    }
}
/* localdecomp:end func_L01_00451FE0 */
