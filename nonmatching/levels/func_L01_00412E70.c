/* NTSC-U draft (2026-11-14, Claude worker): C of func_L01_00410840, the NTSC-U twin of func_L01_00412E70, with NTSC-U names
 * and addresses. Byte-exact on NTSC-U with "-O2 -G8 -fopt-stack -mno-check-zero-division @ps2as" (src/levels/shared/L01_00412E30.c's line: "-O2 -G8 -fopt-stack -mno-check-zero-division").
 */
#include "common.h"

/* NTSC-U counterpart of func_L01_00412E70 (src/levels/shared/L01_00412E30.c) */
#include "vu0.h"

/* localdecomp:start func_L01_00410840 */
extern f32 D_001D6530_sda;
__asm__(".extern D_001D6530_sda, 4");
extern void func_00388BD0(void *, void *);

void func_L01_00410840(u8 *o, vu0_q *v, s32 a2, f32 x, f32 y) {
    vu0_v4 t;

    *(f32 *)(o + 0x48) = 0.104719765f;
    qzero(o + 0xA0);
    *(f32 *)(o + 0x4C) = 0.026179941f;
    *(f32 *)(o + 0x50) = 0.0058177644f;
    *(f32 *)(o + 0x54) = 0.0019392548f;
    *(f32 *)(o + 0x5C) = 0.5f;
    *(f32 *)(o + 0x68) = 0.03490659f;
    *(f32 *)(o + 0x6C) = 0.0014544411f;
    *(f32 *)(o + 0x70) = 0.6f;
    *(f32 *)(o + 0x74) = 0.666f;
    *(f32 *)(o + 0x78) = 0.85f;
    *(f32 *)(o + 0x7C) = 0.2617994f;
    *(s32 *)(o + 0xBC) = a2;
    *(f32 *)(o + 0x120) = 30.0f;
    *(f32 *)(o + 0xB4) = 1.553343f;
    *(f32 *)(o + 0xB8) = -1.553343f;
    *(s32 *)(o + 0x44) = 0;
    *(s32 *)(o + 0x64) = 0;
    *(s16 *)(o + 0x86) = 0;
    *(s32 *)(o + 0x88) = 0;
    *(s16 *)(o + 0x84) = 0;
    *(s32 *)(o + 0x80) = 0;
    *(s32 *)(o + 0x12C) = 0;
    *(s32 *)(o + 0x138) = 0;
    *(s32 *)(o + 0x8C) = 0;
    *(s32 *)(o + 0xB0) = 0;
    *(vu0_q *)&t = 0;
    *(f32 *)(o + 0x40) = x;
    *(f32 *)(o + 0x60) = y;
    t.y = y;
    t.z = x;
    func_00388BD0(o, &t);
    *(vu0_q *)(o + 0x30) = *v;
    *(vu0_q *)(o + 0x140) = *v;
    *(f32 *)(o + 0x134) = D_001D6530_sda;
}
/* localdecomp:end func_L01_00410840 */
