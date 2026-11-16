/*
 * PAL near miss, P02 wave 2, 2026-11-16.
 * Owner: src/levels/07_annihilation_nation/L07_003A46C8.c.
 * Exact flags: -O2 -G8 -fopt-stack -mno-check-zero-division
 *              -fno-sched-interblock @ps2as.
 * Stock checker: 112 differing instructions after an initial compiler ICE.
 * Aligned float arrays avoid that ICE. Retail saves callee registers and ra
 * with sq/lq; these file flags produce sd/ld and a smaller frame.
 * Other differences include argument/store scheduling and particle-call setup.
 * No alternative flags or transforms tested. Uses stock owning-file context.
 */
#include "common.h"
typedef int Q_003A6C90 __attribute__((mode(TI)));
extern void func_003CD250(void *);
extern u8 *func_L01_00470150(void *, s32, s32, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32);
s32 func_L07_003A6C90(u8 *obj, void *position, s16 a, s16 b, s16 c, s16 d, s32 e, s32 f)
{
    u8 *p = *(u8 **)(obj + 0x68);
    f32 base[4] __attribute__((aligned(16)));
    f32 point[4] __attribute__((aligned(16)));
    s32 i;
    u8 *effect;
    if (*(s32 *)(p + 0x70) != -1) return 0;
    obj[0x30] = 64;
    *(s16 *)(obj + 0x32) = 64;
    obj[0x31] = 1;
    *(f32 *)(obj + 0x2C) = *(f32 *)(*(u8 **)(obj + 0x24) + 0x24);
    *(Q_003A6C90 *)(p + 0x90) = *(Q_003A6C90 *)(obj + 0x10);
    *(Q_003A6C90 *)(obj + 0x10) = *(Q_003A6C90 *)position;
    *(s32 *)(p + 0x80) = a;
    *(s16 *)(p + 0x7C) = d - (b + c);
    *(s32 *)(p + 0x74) = e;
    *(s32 *)(p + 0x6C) |= 1;
    *(s32 *)(p + 0x70) = f;
    *(s16 *)(p + 0x78) = b;
    *(s16 *)(p + 0x7A) = c;
    *(Q_003A6C90 *)base = *(Q_003A6C90 *)(obj + 0x10);
    base[2] += 0.5f;
    for (i = 0; i < 9; i++) {
        *(Q_003A6C90 *)point = *(Q_003A6C90 *)base;
        point[0] += (1 - i / 3) * 1.1f;
        point[1] += (1 - i % 3) * 1.1f;
        *(Q_003A6C90 *)(p + 0xA0 + i * 16) = *(Q_003A6C90 *)point;
    }
    for (i = 0; i < 9; i++) {
        effect = *(u8 **)(p + 0x130 + i * 4);
        if (effect) func_003CD250(effect);
        effect = func_L01_00470150(p + 0xA0 + i * 16, 0, 0x18204080, -1, 1, -1, 0, -1, 0, 0, 0.0f, 0.5f, 1.0f);
        *(u8 **)(p + 0x130 + i * 4) = effect;
        if (effect) *(f32 *)(effect + 0x18) -= 0.75f;
    }
    return 1;
}
