/* functional: high. Camera placement for a follow camera (player index, collide flag): optionally offsets the camera by the spring angles rotated by the hero matrix and pulls it back along the line to the target if the collision probe hits; then rebuilds the camera basis (forward, right, up) toward the look point and copies it to +0x40. Calls, order and delay-slot stores mirror retail; VU0 adds/subs kept as COP2 asm */
#include "vu0.h"
static __inline__ void vec_add_ab_003E6DA0(void *d, void *a, void *b) {
    __asm__(
    "lqc2 $vf1, %1\n\t"
    "lqc2 $vf2, %2\n\t"
    "vadd.xyz $vf1, $vf1, $vf2\n\t"
    "sqc2 $vf1, %0"
    : "=m"(*(vu0_v4 *)d) : "m"(*(vu0_v4 *)a), "m"(*(vu0_v4 *)b) : "vf1", "vf2");
}
static __inline__ void vec_add_ba_003E6DA0(void *d, void *a, void *b) {
    __asm__(
    "lqc2 $vf2, %2\n\t"
    "lqc2 $vf1, %1\n\t"
    "vadd.xyz $vf1, $vf1, $vf2\n\t"
    "sqc2 $vf1, %0"
    : "=m"(*(vu0_v4 *)d) : "m"(*(vu0_v4 *)a), "m"(*(vu0_v4 *)b) : "vf1", "vf2");
}
static __inline__ void vec_sub_ba_003E6DA0(void *d, void *a, void *b) {
    __asm__(
    "lqc2 $vf2, %2\n\t"
    "lqc2 $vf1, %1\n\t"
    "vsub.xyz $vf1, $vf1, $vf2\n\t"
    "sqc2 $vf1, %0"
    : "=m"(*(vu0_v4 *)d) : "m"(*(vu0_v4 *)a), "m"(*(vu0_v4 *)b) : "vf1", "vf2");
}
extern s32 D_L01_001DF810[];
extern f32 D_L01_001EAA20[4];
void func_L01_003E6DA0(s32 player, s32 collision) {
    extern void func_0038D590(f32 *, u8 *);
    extern void func_0038D000(f32 *, f32 *, u8 *);
    extern void func_0038CE20(f32 *, f32 *, f32);
    extern s32 func_003D3CB0(f32 *, f32 *, s32, s32, s32);
    extern f32 func_0038CEA8(f32 *);
    extern void func_0038CF68(f32 *, f32 *, f32);
    extern void func_0038CE90(f32 *, f32 *, f32 *);
    f32 up[4] __attribute__((aligned(16)));
    f32 scaled[4] __attribute__((aligned(16)));
    f32 direction[4] __attribute__((aligned(16)));
    f32 target[4] __attribute__((aligned(16)));
    f32 offset[4] __attribute__((aligned(16)));
    f32 angles[4] __attribute__((aligned(16)));
    f32 matrix[12] __attribute__((aligned(16)));
    f32 delta[4] __attribute__((aligned(16)));
    Entry_3E6C58 *entry = &D_L01_001E2A40[player];
    u8 *cam = entry->p50;
    u8 *follow = *(u8 **)(cam + 0x70);
    u8 *look = follow + 0x60;
    u8 *hero = (u8 *)entry + 0x150;
    u8 *springs = follow + 0x180;
    f32 distance;
    f32 *from, *copy;
    if (!collision) goto finalize;
        angles[0] = -*(f32 *)(springs + 0x2C);
        angles[1] = 0.0f;
        angles[2] = *(f32 *)(springs + 0x30);
        angles[3] = 0.0f;
        func_0038D590(matrix, hero);
        func_0038D000(offset, angles, *(u8 **)(look + 0xE0) + 0xC0);
        vec_add_ba_003E6DA0(cam + 0x30, follow + 0x60, offset);
        func_0038CE20(scaled, (f32 *)(*(u8 **)(look + 0xE0) + 0xE0), *(f32 *)(look + 0xD0));
        vec_add_ab_003E6DA0(target, follow + 0x60, scaled);
        if (func_003D3CB0(target, (f32 *)(cam + 0x30), D_L01_001DF810[player], *(s32 *)(hero + 0xF0), 0)) {
            vec_sub_ba_003E6DA0(delta, D_L01_001EAA20, target);
            distance = func_0038CEA8(delta);
            if (distance == 0.0f) {
                *(vu0_q *)(cam + 0x30) = *(vu0_q *)target;
            } else {
                func_0038CE20(delta, delta, (distance - 0.5f) / distance);
                vec_add_ab_003E6DA0(cam + 0x30, target, delta);
            }
        }
finalize:
    from = (f32 *)(cam + 0x30);
    copy = (f32 *)(cam + 0x64);
    copy[0] = from[0];
    copy[1] = from[1];
    copy[2] = from[2];
    *(vu0_q *)up = *(vu0_q *)((u8 *)entry + 0x90);
    func_0038CF68(scaled, up, *(f32 *)(look + 0xD0));
    vec_add_ab_003E6DA0(target, scaled, look);
    vec_sub_ba_003E6DA0(direction, target, cam + 0x30);
    func_0038CF68((f32 *)cam, direction, 1.0f);
    *(vu0_q *)(cam + 0x20) = *(vu0_q *)up;
    func_0038CE90((f32 *)(cam + 0x10), (f32 *)cam, (f32 *)(cam + 0x20));
    func_0038CF68((f32 *)(cam + 0x10), (f32 *)(cam + 0x10), 1.0f);
    func_0038CE90((f32 *)(cam + 0x20), (f32 *)(cam + 0x10), (f32 *)cam);
    *(vu0_q *)(cam + 0x40) = *(vu0_q *)cam;
}
