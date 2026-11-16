/* PAL near miss (Codex wave 6): near miss: 214 words differ with the file's flags.
 * Worker's note: Best 213 diff: build/codex/w250/func_L01_003E7B80.a07.log; VU0 sequence scheduling, saved-register allocation and stack layout; j helpers fail under fixed flags; 9 attempts
 */
#include "common.h"
/* localdecomp:start func_L01_003E7B80 */
#include "vu0.h"
static __inline__ void add_ba_003E7B80(void *d, void *a, void *b) {
    __asm__("lqc2 $vf2, %1\n\tlqc2 $vf1, %2\n\tvadd.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0"
        : "=m"(*(vu0_v4 *)d) : "m"(*(vu0_v4 *)b), "m"(*(vu0_v4 *)a) : "vf1", "vf2");
}
static __inline__ void add_ab_003E7B80(void *d, void *a, void *b) {
    __asm__("lqc2 $vf1, %1\n\tlqc2 $vf2, %2\n\tvadd.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0"
        : "=m"(*(vu0_v4 *)d) : "m"(*(vu0_v4 *)a), "m"(*(vu0_v4 *)b) : "vf1", "vf2");
}
static __inline__ void sub_ab_003E7B80(void *d, void *a, void *b) {
    __asm__("lqc2 $vf1, %1\n\tlqc2 $vf2, %2\n\tvsub.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0"
        : "=m"(*(vu0_v4 *)d) : "m"(*(vu0_v4 *)a), "m"(*(vu0_v4 *)b) : "vf1", "vf2");
}
extern u8 D_L01_001E2B90[];
extern u128_t D_L01_001EAA20[];
extern s32 D_L01_001DF818[];
s32 func_L01_003E7B80(u8 *cam, vu0_v4 *position, f32 gain, f32 radius) {
    extern f32 func_L01_00476920(void *, void *, void *, void *, f32);
    extern f32 func_0038CF00(void *, void *);
    extern void func_L01_003E7AB0(u8 *, void *, void *, void *, void *, f32, f32);
    extern s32 func_L01_003FB640(void *, s32, s32, f32);
    u128_t total, delta, old, origin, result, target, closest, extra;
    u8 *entry = D_L01_001E2B90 + *(s32 *)(cam + 0x94) * 1120;
    u8 *hero = *(u8 **)(*(u8 **)(entry - 0x100) + 0x70);
    u8 *follow = *(u8 **)(cam + 0x70);
    u8 *look = follow + 0xB0;
    u8 *springs = follow + 0x180;
    u8 *steer = follow + 0x210;
    f32 limit = *(f32 *)(hero + 0x254) * *(f32 *)(hero + 0x24C) * (*(f32 *)(hero + 0x250) - 1.0f) + 0.35f;
    f32 t, distance, threshold;
    s32 changed = 0;
    *(u128_t *)&old = *(u128_t *)position;
    *(u128_t *)&origin = D_L01_001EAA20[0];
    *(u128_t *)&result = D_L01_001EAA20[1];
    qzero(&total);
    add_ba_003E7B80(&target, look, springs);
    t = func_L01_00476920(&closest, &origin, look, &target, 0.0f);
    limit -= 0.35f;
    distance = func_0038CF00(look, &closest);
    threshold = (limit * (distance / (*(f32 *)(springs + 0x2C) - *(f32 *)(steer + 0x30))) + 0.35f) * 0.75f;
    if (t < threshold) {
        func_L01_003E7AB0(cam, &total, &closest, &origin, &old, threshold - t, gain);
        changed = 1;
        *(u128_t *)position = *(u128_t *)&result;
        if (func_L01_003FB640(position, D_L01_001DF818[*(s32 *)(cam + 0x94)], *(s32 *)(entry + 0xF0), radius) != 0) {
            sub_ab_003E7B80(&delta, &old, position);
            add_ab_003E7B80(&origin, D_L01_001EAA20, &delta);
            t = func_L01_00476920(&closest, &origin, look, &target, 0.0f);
            distance = func_0038CF00(look, &closest);
            threshold = (limit * (distance / (*(f32 *)(springs + 0x2C) - *(f32 *)(steer + 0x30))) + 0.35f) * 0.75f;
            if (t < threshold) {
                func_L01_003E7AB0(cam, &extra, &closest, &origin, &old, threshold - t, gain);
                add_ab_003E7B80(&total, &total, &extra);
                *(u128_t *)position = D_L01_001EAA20[1];
                if (func_L01_003FB640(position, D_L01_001DF818[*(s32 *)(cam + 0x94)], *(s32 *)(entry + 0xF0), radius) != 0) {
                    sub_ab_003E7B80(&delta, &old, position);
                    add_ab_003E7B80(&origin, D_L01_001EAA20, &delta);
                    t = func_L01_00476920(&closest, &origin, look, &target, 0.0f);
                    distance = func_0038CF00(look, &closest);
                    threshold = (limit * (distance / (*(f32 *)(springs + 0x2C) - *(f32 *)(steer + 0x30))) + 0.35f) * 0.75f;
                    if (t < threshold) {
                        func_L01_003E7AB0(cam, &extra, &closest, &origin, &old, threshold - t, gain);
                        add_ab_003E7B80(&total, &total, &extra);
                    }
                }
            }
        }
    }
    add_ab_003E7B80(position, &old, &total);
    return changed;
}
/* localdecomp:end func_L01_003E7B80 */
