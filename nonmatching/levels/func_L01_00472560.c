/* NTSC-U draft (Claude wave K): C of func_L01_0046EE10, the NTSC-U twin of func_L01_00472560, with NTSC-U names and addresses (the two versions' code differs).
 * near miss: 35 words differ on NTSC-U (the worker's best count) (NTSC-U twin "func_L01_0046EE10", whose code is not the PAL one).
 * Worker's note: 35 diff (sched order of the quad copy / constants only; every opcode decoded): spark spawner u8 *f(u128 *pos, f32 *vel, s32 id, s32 life, f32 scale): p = func_L01_0045E438(0x6B); p[3]=id; p[1]=0; p[9]=0x44; quad copy at +0x10; p[8]=func_0037E1D8(0xFF); ...
 */
#include "common.h"

/* NTSC-U counterpart of func_L01_0046EE10's PAL twin (src/levels/shared/L01_0046A938.c) */
/* localdecomp:start func_L01_0046EE10 */
typedef int u128_t __attribute__((mode(TI)));
extern u8 *D_L01_002212C4[];
extern u8 *func_L01_0045E438(s32);
extern s32 func_0037E1D8(s32);
extern s32 func_0037E208(s32, s32);
extern f32 func_0037E250(f32, f32);

u8 *func_L01_0046EE10(u128_t *pos, f32 *vel, s32 id, s32 life, f32 scale) {
    u8 *p;
    u8 *q;
    s32 r;

    p = func_L01_0045E438(0x6B);
    if (p != 0) {
        p[3] = id;
        p[1] = 0;
        q = p + 0x20;
        p[9] = 0x44;
        *(u128_t *)(p + 0x10) = *pos;
        p[8] = func_0037E1D8(0xFF);
        p[2] = *D_L01_002212C4[0];
        *(s16 *)(p + 0xA) = life;
        *(f32 *)(q + 0) = vel[0];
        *(f32 *)(q + 4) = vel[1];
        *(f32 *)(q + 8) = vel[2];
        r = func_0037E208(0xF, 0xB);
        *(s32 *)(q + 0xC) = (r << 16) + (r << 8) + r;
        q[0x11] = life;
        q[0x13] = 0;
        q[0x10] = func_0037E208(1, 4);
        q[0x12] = func_0037E208(0x5F, 0x7F);
        *(f32 *)(q + 0x18) = func_0037E250(0.125f, 0.15f) * 0.5f * 210000.0f;
        *(f32 *)(q + 0x1C) = func_0037E250(0.25f, 0.5f) * 210000.0f;
        q[0x14] = (s32)(scale * 128.0f);
        q[0x15] = (s32)(func_0037E250(0.9f, 1.1f) * 0.083333336f * 128.0f);
        q[0x17] = 0;
        q[0x16] = (s32)(func_0037E250(0.0f, 0.0125f) * 128.0f);
        *(s32 *)(p + 4) = (q[0x12] << 24) | 0x103080;
    }
    return p;
}
/* localdecomp:end func_L01_0046EE10 */
