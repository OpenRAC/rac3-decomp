/* func_L01_0046FB40 (Claude wave 14 r72, 2026-11-28). Replaces the earlier draft of this function (PAL draft (k6 a6, 2026-11-26), written from retail). */
/* PAL near miss (wave 14 r72, 2026-11-28): func_L01_0046FB40 (468 B, 49 places), the particle spawner
 * the L02 callers call with (src, pos, life, colour, b15, alpha, alpha2, w, size, size2, f2C).
 * 33 diff with its file's line (was 46 in the k6 a6 draft), measured with wave10/p10/check.py.
 * Changed against the k6 a6 draft: the allocator is the file's own `S_467288 *func_L01_004618E0(s32)`
 * with the result cast (no typed alias); the header stores are written colour word, o[9], o[3] after
 * the w conversion (gives retail's sb 3 / sw 4 order and the v0/v1 choice) and the q stores as
 * pos[0], pos[1], pos[2], f2C, b15 (the whole float block and clamp now match retail).
 * Still differs: (1) the frame, 29 words: retail saves $s3 (life, the abs_asm operand) with sq in a
 * 16-byte slot at 0x0 and the others with sd from 0x10, frame 0x80; this C saves all with sd (0x70).
 * In every level function where retail's blezl/neg abs pair runs on a callee-saved register under
 * -fopt-stack, that register is saved with sq (func_L01_004BED50 and func_L01_004C48D0 $s0 too), and
 * the vu0.h abs_asm (int "+r") never gives it: an in-place asm on life, a TImode output operand, a
 * TImode local or a TImode parameter all keep sd or add por/dsll32/dsra32 copies (86 diff for a
 * u128_t life parameter). So the original abs macro's operand was seen by SN cc1 as 128-bit; no plain
 * C under this line reproduces it. (2) 0x44 for o[9] gets $v1 where retail has $a2, and the jal's
 * delay slot gets the sw 4 where retail has the sb 9 (4 words); about 70 statement orders of the header
 * stores tried (single moves from two bases), none below 33. */
#include "common.h"

/* localdecomp:start func_L01_0046FB40 */
extern u8 *D_L01_00221098[];
extern s32 func_00382468(s32);
extern S_467288 *func_L01_004618E0(s32 size);
extern void func_L01_0046FD18(u8 *);
u8 *func_L01_0046FB40(u128_t *src, f32 *pos, s32 life, s32 color, s32 b15, s32 alpha, s32 alpha2, s32 w,
                      f32 size, f32 size2, f32 f2C) {
    u8 *o;
    f32 n;
    f32 t;
    u8 *q;

    o = (u8 *)func_L01_004618E0(0x55);
    if (o != 0) {
        *(u128_t *)(o + 0x10) = *src;
        o[1] = 0;
        *(f32 *)(o + 0xC) = size;
        *(f32 *)(o + 0x1C) = (f32)w;
        *(s32 *)(o + 4) = (alpha << 24) | color;
        o[9] = 0x44;
        o[3] = 0x48;
        o[8] = func_00382468(0xFF);
        o[2] = D_L01_00221098[0x55][0];
        n = (f32)life;
        t = (f32)(alpha2 - alpha) / n * 0.05f;
        q = o + 0x20;
        *(f32 *)(q + 0) = pos[0];
        *(f32 *)(q + 4) = pos[1];
        *(f32 *)(q + 8) = pos[2];
        *(f32 *)(q + 0xC) = f2C;
        q[0x15] = b15;
        if (t > 1.0f) t = 1.0f;
        *(f32 *)(q + 0x18) = (f32)alpha;
        *(s16 *)(q + 0x16) = t * 32767.0f;
        *(f32 *)(q + 0x10) = (size2 - size) / n;
        *(s16 *)(o + 0xA) = abs_asm(life);
        *(void **)(q + 0x1C) = func_L01_0046FD18;
    }
    return o;
}
/* localdecomp:end func_L01_0046FB40 */
