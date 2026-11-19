/* functional: high. Prior near-miss draft (65 words differ: s0/s1, s5/s6 allocation and scheduling), re-verified block by block against the PAL assembly (clamp on height step, 1.2*radius probe, wall slide using the hit normal, up to 6 ceiling pushes, final height check). Its local sub/add inline-asm helpers are the same lqc2/vsub.xyz/vadd.xyz/sqc2 sequences as vu0.h vec_sub/vec_add. Block-scope vu0_v4/D_L01_001EAA00 declarations may conflict with other files in the TU. */
#include "vu0.h"
typedef struct {
    u8 pad0[0x18]; s32 f18; s32 f1C;
    vu0_v4 point; vu0_v4 adjusted; vu0_v4 normal;
} Collision_00445728;
extern Collision_00445728 D_L01_001EAA00[];
extern vu0_v4 D_L01_001EAA20[];
static __inline__ void sub_00445728(vu0_v4 *d, vu0_v4 *a, vu0_v4 *b) {
    __asm__("lqc2 vf2, %2\n\tlqc2 vf1, %1\n\tvsub.xyz vf1, vf1, vf2\n\tsqc2 vf1, %0"
        : "=m"(*d) : "m"(*a), "m"(*b) : "vf1", "vf2");
}
static __inline__ void add_00445728(vu0_v4 *d, vu0_v4 *a, vu0_v4 *b) {
    __asm__("lqc2 vf1, %1\n\tlqc2 vf2, %2\n\tvadd.xyz vf1, vf1, vf2\n\tsqc2 vf1, %0"
        : "=m"(*d) : "m"(*a), "m"(*b) : "vf1", "vf2");
}
static __inline__ void add_b_00445728(vu0_v4 *d, vu0_v4 *a, vu0_v4 *b) {
    __asm__("lqc2 vf2, %1\n\tlqc2 vf1, %2\n\tvadd.xyz vf2, vf2, vf1\n\tsqc2 vf2, %0"
        : "=m"(*d) : "m"(*a), "m"(*b) : "vf1", "vf2");
}
static __inline__ void add_rev_00445728(vu0_v4 *d, vu0_v4 *a, vu0_v4 *b) {
    __asm__("lqc2 vf2, %2\n\tlqc2 vf1, %1\n\tvadd.xyz vf1, vf1, vf2\n\tsqc2 vf1, %0"
        : "=m"(*d) : "m"(*a), "m"(*b) : "vf1", "vf2");
}
s32 func_L01_00445728(void *obj, vu0_v4 *old, vu0_v4 *pos, s32 flags,
                     f32 height, f32 radius, f32 limit, f32 slope) {
    extern f32 func_L01_004463D0(void *);
    extern void func_0038CF68(void *, void *, f32);
    extern s32 func_003D3CB0(void *, void *, s32, void *, s32);
    extern f32 func_0038CED8(void *);
    extern f32 func_0038D160(f32, f32);
    extern void func_0012FE98(void *, void *);
    extern void func_0038CE20(void *, void *, f32);
    extern s32 func_L01_003FB640(void *, s32, void *, f32);
    extern f32 func_0038CF38(void *, void *);
    vu0_v4 delta, scaled, start, end, offset, test;
    Collision_00445728 *hit;
    f32 h, angle, dot, distance;
    s32 i;
    s32 ok = 1;
    s32 collision_flags;
    collision_flags = flags & 2;
    pos->z += height;
    h = func_L01_004463D0(pos);
    pos->z -= height;
    if (limit < fabs_asm(h - old->z)) {
        if ((((flags ^ 1) & 1) && h < old->z) || old->z < h) {
            *(vu0_q *)pos = *(vu0_q *)old;
            ok = 0;
        }
    }
    sub_00445728(&delta, pos, old);
    func_0038CF68(&scaled, &delta, radius * 1.2f);
    *(vu0_q *)&offset = 0;
    offset.z = height;
    add_b_00445728(&start, old, &offset);
    add_00445728(&end, &start, &scaled);
    if (ok && func_003D3CB0(&start, &end, collision_flags | 0x24, obj, 0)) {
        hit = D_L01_001EAA00;
        if (hit->f1C > 0) {
            distance = func_0038CED8(&hit->normal);
            angle = func_0038D160(hit->normal.z, distance);
            if (slope <= angle) {
                hit->normal.z = 0;
                func_0012FE98(&hit->normal, &hit->normal);
                dot = -delta.x * hit->normal.x - delta.y * hit->normal.y;
                if (0.0f < dot) {
                    ok = 0;
                    func_0038CE20(&hit->normal, &hit->normal, dot);
                    add_rev_00445728(&delta, &delta, &hit->normal);
                }
            }
            add_00445728(pos, old, &delta);
        }
    }
    if ((flags & 2) == 0) {
        f32 reach = height + radius;
        i = 0;
        do {
            *(vu0_q *)&test = *(vu0_q *)pos;
            test.z += reach;
            if (!func_L01_003FB640(&test, 0x24, obj, radius)) break;
            distance = func_0038CF38(pos, D_L01_001EAA20);
            hit = (Collision_00445728 *)((u8 *)D_L01_001EAA20 - 0x20);
            angle = func_0038D160(distance, hit->point.z - pos->z);
            if (hit->f18 != 0) goto push;
            if (slope < angle) {
            push:
                *(vu0_q *)pos = *(vu0_q *)&hit->adjusted;
                ok = 0;
                pos->z -= reach;
            }
            i++;
        } while (i < 6);
    }
    pos->z += height;
    h = func_L01_004463D0(pos);
    pos->z -= height;
    if (limit < fabs_asm(h - old->z)) {
        if ((((flags ^ 1) & 1) && h < old->z) || old->z < h) {
            *(vu0_q *)pos = *(vu0_q *)old;
            ok = 0;
        }
    }
    old->x = pos->x;
    old->y = pos->y;
    return ok;
}
