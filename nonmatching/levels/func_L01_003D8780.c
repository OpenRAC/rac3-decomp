/* PAL near miss: cutting_wave_draw. 177 words differ with the file's flags (round 13,
 * 2026-11-22). It compiles in L01_003D0D48.c's context again: D_L01_001DFB40 is a scalar s32
 * there (blocks 003D1A50 and 003D1C60), not an array.
 * What still differs: the jitter bounds. Retail keeps 0.175 in $f21, computes -0.175 as
 * `neg.s $f20, $f21` in every iteration of the first loop, but once at the top for the second
 * (`neg.s $f25, $f21`, then `mov.s $f20, $f25` before it), and loads the upper 0.175 as a literal
 * (lui/ori/mtc1 $f13) at every call; the second loop's 0.25 reuses $f21. Here the block-scope
 * `spread` is folded by cse: -0.175 and 0.175 become two hoisted constants. Everything after the
 * first loop shifts registers from that.
 * Tried (all worse): `f32 spread = 0.175f` at function scope (207: cse then hoists the literal
 * upper bound and uses spread's register for it, and -spread is hoisted out of loop 1 too); an
 * inline jitter(s) helper returning func_003824E0(-s, s) (193: -0.175 folded to a literal).
 * Dropping -mvu0-use-vf0-vf2 (experiment only) changes nothing. With only 36 insns per loop,
 * loop.c moves every invariant (-dL), so retail's unhoisted neg.s in loop 1 means it was not an
 * invariant there at loop time.
 * Earlier worker's note: saved-FPR count, jitter negative bound materialization, copy addressing
 * and scheduling differ.
 */
#include "common.h"
/* localdecomp:start func_L01_003D8780 */
typedef struct {
    u8 pad[0x20];
    f32 phase;
    s32 index, count;
    u8 pad2[4];
    u128_t position[8];
    u128_t rotation[8];
    u8 pad3[16];
    u8 output[1];
} Trail_003D8780;
extern s32 D_L01_001DFB40;
extern s32 D_L01_001DF4BC, D_L01_001DF4B4, D_L01_001DF4B8;
__asm__(".extern D_L01_001DF4BC, 4");
__asm__(".extern D_L01_001DF4B4, 4");
__asm__(".extern D_L01_001DF4B8, 4");
extern f32 D_L01_001E23A0[][4] __attribute__((section(".sdata")));
extern f32 D_L01_001E23E0[][4] __attribute__((section(".sdata")));
void func_L01_003D8780(u8 *moby) {
    extern void func_003C3FC0(void *, void *);
    extern void func_L01_00408C98(void *, s32, void *, void *, s32, s32, s32, s32, s32, f32);
    extern f32 func_003824E0(f32, f32);
    extern void func_003C2F58(u8 *, s32, f32 *);
    extern void func_0038CDF8(f32 *, f32 *, f32 *, f32);
    extern void func_L01_0035A218(f32 (*)[4], s32, s32, s32, s32, s32, f32, f32);
    f32 a[4] __attribute__((aligned(16)));
    f32 b[4] __attribute__((aligned(16)));
    f32 c[4] __attribute__((aligned(16)));
    Trail_003D8780 *trail = *(Trail_003D8780 **)(moby + 0x68);
    f32 width, life;
    s32 i;
    f32 (*p)[4] = D_L01_001E23A0;
    trail->phase = (f32)(D_L01_001DFB40 % 8) * 0.125f;
    if (trail->phase == 0) {
        trail->index = (trail->index + 1) % 8;
        if (trail->count < 8) trail->count++;
    }
    func_003C3FC0(&trail->rotation[trail->index], moby + 0xF0);
    trail->position[trail->index] = *(u128_t *)(moby + 0x10);
    func_L01_00408C98(trail->output, 2, trail->position, trail->rotation, trail->index, trail->count,
                     D_L01_001DF4B4, D_L01_001DF4B8, D_L01_001DF4BC, trail->phase);
    width = func_003824E0(0.03f, 0.05f);
    life = func_003824E0(3.0f, 5.0f);
    func_003C2F58(moby, 0, a);
    func_003C2F58(moby, 3, b);
    func_003C2F58(moby, 6, c);
    for (i=0; i<4; i++, p++) {
        f32 spread = 0.175f;
        func_0038CDF8(*p, b, c, (f32)i * 0.25f);
        (*p)[0] += func_003824E0(-spread, 0.175f);
        (*p)[1] += func_003824E0(-spread, 0.175f);
        (*p)[2] += func_003824E0(-spread, 0.175f);
    }
    func_L01_0035A218(D_L01_001E23A0, 4, 0x4F, 0x7F7F7F, 0xFF8040, 0, width, life);
    p = D_L01_001E23E0;
    for (i=0; i<4; i++, p++) {
        f32 spread = 0.175f;
        func_0038CDF8(*p, b, a, (f32)i * 0.25f);
        (*p)[0] += func_003824E0(-spread, 0.175f);
        (*p)[1] += func_003824E0(-spread, 0.175f);
        (*p)[2] += func_003824E0(-spread, 0.175f);
    }
    func_L01_0035A218(D_L01_001E23E0, 4, 0x4F, 0x7F7F7F, 0xFF8040, 0, width, life);
}
/* localdecomp:end func_L01_003D8780 */
