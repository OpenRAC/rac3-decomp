/* PAL near miss (b30 J6, b30 NM1): 2 words differ (S mode with @ps2as: the file needs a cut; the function would share one @ps2as file with func_L01_0047FAC8):
 *   python tools/check.py nonmatching/levels/func_L01_0047F520.c func_L01_0047F520 --mode S --as ps2as
 * Left: the loop-1 preheader has `ori $s3,$s3,0x19` (the constant 0xD0019) before `move $s1,$zero` (the giv `i * 20`, start 0), retail the reverse.
 * What made it close: float literals read off the `ori $at` words (0.333332986f, 0.0861538500f), one counter per loop (i, j), `if (D_sel > D_cnt)` operand order, indexed table
 * access (`D_L01_001D82E0[i]`), and (NM1) the CALLEE RETURN TYPES from the definitions: func_003B5060 returns s32 (declared void here before): the call then sets $v0 (REG_UNUSED) and
 * the loop-1 guard count `lw $v1,-0x45c4($gp); blez $v1` takes $v1 like retail (4 -> 2 words). func_003E8EF0 / func_003E8AE8 as s32 make no difference here; any of the other callees declared
 * void breaks code (5 to 12 raw words); func_003E9138 with its definition's parameter order (s32, s32, s32, f32 x4) gives 7 words, the L39 order used here is right.
 * Why the last two words differ (proved with `--flags=-dL`, file t.c.loop, and `-dS -dR -fsched-verbose-5`): the compiler runs loop.c TWICE (-frerun-loop-opt). Each pass emits the loop's
 * hoisted movables (the 0xD0019 `li`, the `li 20` of the multiply) in front of the loop first and the strength-reduction start values (`move $s1,$zero` = giv i*20) after them, and
 * sched1 keeps that emission order for ties (LUID). Retail's order giv-start-before-0xD0019 therefore means: in pass 1 the giv was already reduced (so `li 20` was hoisted in pass 1)
 * and the 0xD0019 constant was left for pass 2. move_movables hoists a movable only if threshold * savings * lifetime >= insn_count, threshold = 1 + n_non_fixed_regs = 64 when the loop
 * has a call, minus 3 for every move-insn already hoisted. Loop 1 has 65 insns at pass 1 here (`Loop from 369 to 555: 65 real insns`), the `li 20` (savings 1, life 1) misses by ONE
 * (64 * 1 * 1 < 65) and the giv is only found in pass 2, where both constants go out first, then the giv start: our order. Probes that only shorten the loop (one argument less in
 * func_L01_00516AA0: 64 insns) flip pass 1 exactly as retail needs: `li 20` hoisted, giv reduced in pass 1, 0xD0019 (life 1, threshold already down to 51..57) left for pass 2: preheader
 * order = retail's. So retail's loop 1 has at least 1 (and at most ~12) insns fewer than ours at the first loop pass, or its `li 20` has savings/lifetime 2 (two identical constants in
 * the loop, or one more insn between the `li` and the `mult`). The loop's insn count includes the two `(use (const_int 0))` nops flow.c puts after a call that ends a block before a
 * label, the zero_extend of the `lbu`, the copy of func_00381FF0's result, and the float constants copied into pseudos by precompute_register_parameters.
 * No effect on the pass-1 count or the order (all measured with -dL): `id = 0xD0019 + i;` as function-level or block-local local (24 diff: a user variable keeps its own register),
 * `i + 0xD0019`, `> 1` for `>= 2`, `D_cnt - 1 > i`, a pointer local `e = &D[i]` at function level or block-local, `(D + i)->w0`, the B7 argument through a temp (66 insns), the nested
 * call split into `t = func_00381FF0(...); func_003E8FE8(...)` (65 to 67 insns, 3 to 172 diff), all callee return types, all 120 declaration orders (J6).
 */
#include "common.h"

/* localdecomp:start func_L01_0047F520 */
typedef struct {
    s32 w0;
    s32 w4;
    u8 b8;
    u8 pad9[3];
    void (*fnC)(void);
    u8 b10;
    u8 pad11[3];
} E_0047F520;
typedef struct { f32 f0; f32 f4; } P_0047F520;
extern s32 D_001D545C;
extern s32 D_001D7BE0;
extern u8 D_00143950[];
extern E_0047F520 D_L01_002EA0C0[];
extern E_0047F520 D_L01_002EA178[];
extern E_0047F520 D_L01_002EA020[];
extern P_0047F520 D_L01_001D82D0;
extern P_0047F520 D_L01_001D82D8;
extern P_0047F520 D_L01_001D82C8;
extern E_0047F520 *D_L01_001D82E0;
extern P_0047F520 *D_L01_001D82E4;
extern s32 D_L01_001D82E8;
extern s32 D_L01_001D82EC;
extern s32 D_L01_001D82F0;
extern f32 D_L01_001D82F4;
extern f32 D_L01_001D82F8;
extern f32 D_L01_001D82FC;
__asm__(".extern D_L01_001D82C8, 8");
__asm__(".extern D_L01_001D82D0, 8");
__asm__(".extern D_L01_001D82D8, 8");
__asm__(".extern D_L01_001D82E0, 4");
__asm__(".extern D_L01_001D82E4, 4");
__asm__(".extern D_L01_001D82E8, 4");
__asm__(".extern D_L01_001D82EC, 4");
__asm__(".extern D_L01_001D82F0, 4");
__asm__(".extern D_L01_001D82F4, 4");
__asm__(".extern D_L01_001D82F8, 4");
__asm__(".extern D_L01_001D82FC, 4");
extern s32 func_00381FF0(s32);
extern s32 func_003E8EF0(s32, s32, s32, f32, f32, f32, f32, f32);
extern s32 func_003E9138(s32, s32, f32, f32, f32, f32, s32);
extern s32 func_003B5060(s32);
extern s32 func_003E8AE8(s32, s32, s32, s32, s32, s32);
extern s32 func_003E8348(s32, s32);
extern s32 func_003E8FE8(s32, s32, s32, f32, f32, f32, f32);
extern s32 func_L01_00516AA0(s32, s32, s32);
extern s32 func_003E8630(s32, s32);
extern s32 func_L01_00517538(s32, f32, f32);
extern s32 func_L01_00516470(s32, f32, f32);
extern s32 func_003E8A08(s32, s32, s32);

void func_L01_0047F520(void) {
    s32 m = D_001D545C;
    s32 mode;
    s32 i;
    s32 j;
    f32 f20;
    f32 f21;

    if ((m == 0xC || m == 0x12 || m == 0x14 || m == 0x1A || m == 0x1D || m == 4) && D_001D7BE0 != -1) {
        D_L01_001D82E0 = D_L01_002EA0C0;
        D_L01_001D82E4 = &D_L01_001D82D0;
        D_L01_001D82EC = 9;
        mode = 1;
    } else if ((m == 7 || m == 3) && D_001D7BE0 != -1) {
        D_L01_001D82E0 = D_L01_002EA178;
        D_L01_001D82E4 = &D_L01_001D82D8;
        D_L01_001D82EC = 9;
        mode = 1;
    } else {
        D_L01_001D82E0 = D_L01_002EA020;
        D_L01_001D82E4 = &D_L01_001D82C8;
        D_L01_001D82EC = 8;
        mode = 0;
    }
    if (D_L01_001D82F0 != mode) {
        D_L01_001D82E8 += mode - D_L01_001D82F0;
        D_L01_001D82F0 = mode;
    }
    if (D_L01_001D82E8 > D_L01_001D82EC) {
        D_L01_001D82E8 = D_L01_001D82EC;
    }
    if (D_L01_001D82E8 < 0) {
        D_L01_001D82E8 = 0;
    }
    f21 = (f32)D_L01_001D82EC * 0.09f + -0.18f;
    if (f21 < 0.0f) {
        f21 = 0.0f;
    }
    f21 = f21 + 1.0f;
    func_003E8EF0(0xD0000, 0x3D, 0x332299DE, 0.5f, 0.5f, 1.0f, 1.0f, f21);
    func_003E8EF0(0xD0001, 0x3E, 0x332299DE, 0.5f, 0.5f, 1.0f, 1.0f, f21);
    func_003E8EF0(0xD0002, 0x3F, 0x331465B7, 0.5f, 0.5f, 1.0f, 1.0f, f21);
    func_003E8EF0(0xD0003, 0x40, 0x802299DE, 0.5f, 0.5f, 1.0f, 1.0f, f21);
    func_003E9138(0xD0028, 0x402299DE, 0.5f, 0.5f, 0.333332986f, 0.025f, 0);
    func_003B5060(0xD000B);
    func_003E8AE8(0xD000B, 0xD0000, 0xD0001, 0xD0002, 0xD0003, 0xD0028);
    func_003E8348(0x10, 0xD000B);
    func_003B5060(0xD0025);
    func_003B5060(0xD0026);
    for (i = 0; i < D_L01_001D82EC; i++) {
        func_003E8FE8(D_L01_001D82E0[i].w0, func_00381FF0(D_L01_001D82E0[i].w4), 0x8066CCFF, 0.0f, 0.0f, 1.0f, 1.0f);
        func_L01_00516AA0(D_L01_001D82E0[i].w0, 0x40, 1);
        func_003E8630(0xD0025, D_L01_001D82E0[i].w0);
        if (i < D_L01_001D82EC - 1) {
            func_003E9138(0xD0019 + i, 0x202299DE, 0.0f, 0.0f, 1.0f, 1.0f, 0);
            func_003E8630(0xD0026, 0xD0019 + i);
        }
        if (D_00143950[0xB7] >= 2) {
            func_L01_00517538(D_L01_001D82E0[i].w0, 0.7f, 0.8f);
        }
    }
    func_003E8630(0xD0025, 0xD0026);
    func_003E8348(0x11, 0xD0025);
    f20 = 0.5f - (f32)(D_L01_001D82EC - 1) * 0.03f;
    for (j = 0; j < D_L01_001D82EC; j++) {
        func_L01_00516470(D_L01_001D82E0[j].w0, 0.5f, f20);
        if (j < D_L01_001D82EC - 1) {
            func_L01_00516470(0xD0019 + j, 0.5f, f20 + D_L01_001D82F4 * 0.5f);
            func_L01_00517538(0xD0019 + j, 0.43f, 0.0048f);
        }
        f20 += D_L01_001D82F4;
    }
    func_003E9138(0x5A0001, 0x332299DE, D_L01_001D82F8, D_L01_001D82E4->f0, -0.07f, 0.0861538500f, 0xED5A);
    func_003E9138(0x5A0002, 0x332299DE, D_L01_001D82FC, D_L01_001D82E4->f4, 0.07f, -0.0861538500f, 0xED5A);
    func_003E8A08(0xD000B, 0x5A0001, 0x5A0002);
}
/* localdecomp:end func_L01_0047F520 */
