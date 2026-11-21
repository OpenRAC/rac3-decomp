/* functional: high. Control flow, constants and callee read block by block against the PAL asm; differs from retail only in instruction scheduling/register allocation around the VU0 blocks (compiler cannot interleave). */
#include "common.h"
typedef struct { s32 count; s32 pad[3]; V_004734A8 nodes[1]; } Path_00476498;
s32 func_L01_00476498(u8 *path, s128_00470258 *out, s32 *index, f32 *offset, s32 wrap, f32 distance) {
    extern void func_0038CF68(void *, void *, f32);
    s32 direction = 1;
    s32 crossed = 0;
    s32 next;
    s32 n;
    f32 old;
    s32 beyond;
    V_004734A8 delta;
    if (distance < 0.0f) {
        distance = -distance;
        direction = -1;
    }
    next = *index;
    while (distance != 0.0f) {
        if (next == *(s32 *)path - 1 && !wrap) break;
        if (direction == 1) {
            old = *offset;
            beyond = ((Path_00476498 *)path)->nodes[next].w < old + distance;
        } else {
            old = *offset;
            beyond = old < distance;
        }
        next += direction;
        if (beyond) {
            if (next >= *(s32 *)path || next < 0) next = (next + *(s32 *)path) % *(s32 *)path;
            if (direction == 1) {
                distance -= ((Path_00476498 *)path)->nodes[*index].w - old;
                *offset = 0.0f;
                if (distance < *offset) distance = *offset;
            } else {
                distance -= old;
                *offset = ((Path_00476498 *)path)->nodes[next].w;
            }
            if ((direction == 1 && *index == *(s32 *)path - 1) || (direction == -1 && *index == 0)) crossed = 1;
            *index = next;
        } else {
            *offset = direction == 1 ? old + distance : old - distance;
            distance = 0.0f;
        }
        next = *index;
    }
    *out = *(s128_00470258 *)(path + next * 16 + 0x10);
    if (*index == *(s32 *)path - 1 && !wrap) {
        if (direction == -1) {
            *index = 0;
            *out = *(s128_00470258 *)(path + 0x10);
            *offset = 0.0f;
        }
        return 1;
    }
    n = *(s32 *)path;
    next = *index + 1;
    if (next >= n) next %= n;
    __asm__("lqc2 $vf1, %1\n\tlqc2 $vf2, %2\n\tvsub.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0"
        : "=m"(delta)
        : "m"(*(V_004734A8 *)(path + next * 16 + 0x10)), "m"(*(V_004734A8 *)(path + *index * 16 + 0x10))
        : "vf1", "vf2");
    func_0038CF68(&delta, &delta, *offset);
    __asm__("lqc2 $vf1, %0\n\tlqc2 $vf2, %1\n\tvadd.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0"
        : "+m"(*out) : "m"(delta) : "vf1", "vf2");
    return crossed;
}
