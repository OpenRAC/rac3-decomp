/* PAL near miss (k6 a6, 2026-11-26): func_L01_0046FB40 (468 B, 50 places), the particle spawner
 * the L02 callers call with (src, pos, life, colour, b15, alpha, alpha2, w, size, size2, f2C);
 * written from retail (splat marks it handwritten only for the blezl/neg pair, which is abs_asm).
 * 46 diff with its file's line and the divs_nops row `func_L01_0046FB40 2 2` (added with this draft).
 * What differs: retail saves $s3 (life) with sq in a 16-byte slot at 0x0($sp) and the others with
 * sd from 0x10, frame 0x80; this C saves all with sd (frame 0x70), which shifts every slot, plus
 * some ordering in the store block. A TImode life (param or abs operand) gives the sq save but a
 * por copy where retail has move. */
#include "common.h"
/* localdecomp:start func_L01_0046FB40 */
extern u8 *D_L01_00221098[];
extern s32 func_00382468(s32);
extern u8 *func_L01_004618E0_0046FB40(s32) __asm__("func_L01_004618E0");
extern void func_L01_0046FD18(u8 *);
u8 *func_L01_0046FB40(u128_t *src, f32 *pos, s32 life, s32 color, s32 b15, s32 alpha, s32 alpha2, s32 w,
                      f32 size, f32 size2, f32 f2C) {
    u8 *o;
    f32 n;
    f32 t;
    u8 *q;

    o = func_L01_004618E0_0046FB40(0x55);
    if (o != 0) {
        *(u128_t *)(o + 0x10) = *src;
        o[1] = 0;
        *(f32 *)(o + 0xC) = size;
        *(f32 *)(o + 0x1C) = (f32)w;
        o[3] = 0x48;
        *(s32 *)(o + 4) = (alpha << 24) | color;
        o[9] = 0x44;
        o[8] = func_00382468(0xFF);
        o[2] = D_L01_00221098[0x55][0];
        n = (f32)life;
        t = (f32)(alpha2 - alpha) / n * 0.05f;
        q = o + 0x20;
        *(f32 *)(q + 0) = pos[0];
        *(f32 *)(q + 4) = pos[1];
        *(f32 *)(q + 0xC) = f2C;
        *(f32 *)(q + 8) = pos[2];
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
