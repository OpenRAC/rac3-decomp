/* func_L40_0040D310: near miss, 2 diff at level 40. 428 bytes, 14 levels (40-53),
   src/levels/shared/L40_0040A4D0.c (flags -mvu0-use-vf0-vf2 -O2 -G8 -fopt-stack
   -mno-check-zero-division @ps2as). Rewritten from asm (2026-11-11), replacing the earlier port
   (about 60 diff with -O2 -G8 -fopt-stack -mno-check-zero-division). A walk step towards `target`
   that stops short of it (within the walker's +0x34); `mode` 1 also steers (func_L40_0040D7D0).

   Every instruction is retail's except the $gp immediates of the two loads of the frame counter
   D_L40_0024112C in branch delay slots: the same Ps2EeAs gp0 problem as func_L40_0040D678 (its
   file header has the details). Retail reads the counter through lui/lw where it can and through
   $gp in a delay slot; Ps2EeAs writes such a $gp access with addend -0x4000 and gp0 0x4000, which
   GNU ld, tools/check.py and tools/level_symbols.py do not apply.
   Found on the way: func_L40_0040D7D0's float parameter is its fourth (m, w, target, yaw, a, b);
   in any other place the argument moves are scheduled differently (4-6 diff).
   Context: the file's prelude (vu0.h, the vector helpers) and earlier blocks (D_L40_0024112C[]
   in .sdata is func_L40_0040B9C0's). */
#include "common.h"
#include "vu0.h"

extern f32 func_0038CF38(void *a, void *b);
extern s32 D_L40_0024112C[] __attribute__((section(".sdata")));
/* localdecomp:start func_L40_0040D310 */
extern u8 *func_L01_0045B958(u8 *m);
extern void func_L01_0045B908(u8 *m, u8 *w);
extern void func_L01_0045B6C8(u8 *m, u8 *w, f32 f);
extern void func_L01_0045B110(u8 *m, u8 *w, void *target);
extern void func_L01_0045BB60(u8 *m, u8 *w, f32 yaw);
extern void func_L01_0045C240(void);
extern void func_L40_0040D7D0(u8 *m, u8 *w, void *target, f32 yaw, vu0_v4 *a, vu0_v4 *b);
extern void func_L40_0040D4C0(u8 *m, u8 *w, vu0_v4 *a, vu0_v4 *b);

/* A walk step towards `target` that stops short of it (within the walker's +0x34). */
s32 func_L40_0040D310(u8 *m, void *target, s32 mode, f32 yaw) {
    u8 *w;
    s32 flags;
    s32 last;
    vu0_v4 old;
    vu0_v4 a;
    vu0_v4 b;

    w = func_L01_0045B958(m);
    if (func_0038CF38(m + 0x10, target) < *(f32 *)(w + 0x34)) {
        return 0;
    }
    if (w == 0) {
        return 8;
    }
    if (D_L40_0024112C[0] == *(s32 *)(w + 0xBC)) {
        return *(s32 *)(w + 0x94);
    }
    flags = *(s32 *)(w + 0x38);
    *(s32 *)(w + 0x38) = flags | 4;
    *(s32 *)(w + 0xA8) = 0;
    *(s32 *)(w + 0x98) = *(s32 *)(w + 0x94);
    *(s32 *)(w + 0x94) = 0;
    if (!((flags | 4) & 0x100)) {
        func_L01_0045B908(m, w);
    }
    old = *(vu0_v4 *)(m + 0x10);
    last = *(s32 *)(w + 0xBC);
    if (D_L40_0024112C[0] - last >= 2 || last == 0) {
        func_L01_0045B6C8(m, w, 0.0f);
        *(f32 *)(w + 0xB4) = 0.0f;
        *(u8 *)(w + 0xEA) = 0xFF;
        *(s32 *)(w + 0x9C) &= ~2;
        *(s32 *)(w + 0x80) = 0;
    }
    *(s32 *)(w + 0xBC) = D_L40_0024112C[0];
    if (mode == 1) {
        func_L40_0040D7D0(m, w, target, yaw, &a, &b);
    }
    func_L40_0040D4C0(m, w, &old, &b);
    func_L01_0045B110(m, w, target);
    func_L01_0045BB60(m, w, yaw);
    func_L01_0045C240();
    *(s32 *)(w + 0x38) = flags;
    return *(s32 *)(w + 0x94);
}
/* localdecomp:end func_L40_0040D310 */
