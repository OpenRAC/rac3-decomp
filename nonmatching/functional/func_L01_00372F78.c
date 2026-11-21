/* functional: high. Verified against PAL asm block by block: phase timer 0x38, damage falloff, sparks, two hit-test phases (t<15, t<38), impact/continue conditions incl. 0x1625 class check, VU adds; bytes differ only in scheduling (155 words). */
#include "vu0.h"
typedef struct { u8 pad[0x10]; u8 *owner; u8 pad14[6]; u16 class_id; u8 tail[0x14]; } Hit_00372F78;
typedef struct { u8 pad[0x18]; u8 *object; u8 pad1c[4]; vu0_v4 position; } Collision_00372F78;
extern u8 D_L01_001D66B0[];
extern Collision_00372F78 D_L01_001EAA00;
extern vu0_v4 D_L01_001EAA20;
struct Moby_373368;
void func_L01_00372F78(u8 *obj) {
    extern f32 func_00382538(void);
    extern void func_L01_0046A610(void *, void *, s32, s32, u32, s32, f32, f32, f32, f32, f32);
    extern void func_0038CF68(void *, void *, f32);
    extern void func_L01_00446760(void *, void *, s32, void *, f32);
    extern s32 func_003D3CB0(void *, void *, s32, void *, void *);
    extern void func_L01_00404A10(void (*)(struct Moby_373368 *), u8 *);
    extern void func_L01_00373410(struct Moby_373368 *);
    extern f32 func_0038CF38(void *, void *);
    extern s32 func_L01_00456250(void *);
    extern void func_L01_003738E0(void *, s32);
    extern void func_L01_00456230(void *, s32);
    extern void func_003C2880(void *);
    extern void func_L01_003739B8(void *);
    vu0_v4 old, velocity;
    Hit_00372F78 hit;
    vu0_v4 center, accel;
    u8 *state = *(u8 **)(obj + 0x68);
    s32 angle;
    f32 damage = *(f32 *)(state + 0x3C);
    *(f32 *)(state + 0x38) += 1.0f;
    if (*(f32 *)(state + 0x38) > 32.0f) {
        damage *= 1.0f - (*(f32 *)(state + 0x38) - 32.0f) / 6.0f;
    }
    if (*(f32 *)(state + 0x38) > 2.0f) old = *(vu0_v4 *)(state + 0x10);
    else old = *(vu0_v4 *)state;
    angle = (s32)func_00382538();
    func_L01_0046A610(state + 0x10, D_L01_001D66B0, 3, 96, 0xFF1010, angle,
                     210000.0f, 200.0f, 0.95f, 0.0f, 0.0f);
    if (*(f32 *)(state + 0x38) < 15.0f) {
        *(f32 *)(state + 0x34) += 0.5000000596046448f;
        func_0038CF68(state + 0x10, state + 0x20, *(f32 *)(state + 0x34));
        func_0038CF68(&velocity, state + 0x20, 0.08000000566244125f);
        func_L01_00446760(&hit, obj, 0x10000, &velocity, damage);
        hit.owner = obj;
        hit.class_id = *(u16 *)(obj + 0xAA);
        __asm__("lqc2 $vf2, %2\n\tlqc2 $vf1, %1\n\tvadd.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0"
            : "=m"(*(vu0_v4 *)(state + 0x10))
            : "m"(*(vu0_v4 *)state), "m"(*(vu0_v4 *)(state + 0x10))
            : "vf1", "vf2");
        func_0038CF68(&center, state + 0x20, -0.5000000596046448f);
        __asm__("lqc2 $vf1, %1\n\tlqc2 $vf2, %2\n\tvadd.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0"
            : "=m"(center)
            : "m"(center), "m"(*(vu0_v4 *)(state + 0x10))
            : "vf1", "vf2");
        if (func_003D3CB0(state + 0x10, &old, 16, *(void **)(obj + 0xB8), &hit)
            && D_L01_001EAA00.object != *(u8 **)(obj + 0xB8)) {
            goto impact;
        }
        func_L01_00404A10(func_L01_00373410, obj);
    } else if (*(f32 *)(state + 0x38) < 38.0f) {
        if (func_0038CF38(state, state + 0x10) > 0.5000000596046448f) {
            *(f32 *)(state + 0x34) += 0.5000000596046448f;
            func_0038CF68(state + 0x10, state + 0x20, *(f32 *)(state + 0x34));
            func_0038CF68(&velocity, state + 0x20, 0.08000000566244125f);
            func_L01_00446760(&hit, obj, 0x10000, &velocity, damage);
            hit.class_id = *(u16 *)(obj + 0xAA);
            __asm__("lqc2 $vf2, %2\n\tlqc2 $vf1, %1\n\tvadd.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0"
            : "=m"(*(vu0_v4 *)(state + 0x10))
            : "m"(*(vu0_v4 *)state), "m"(*(vu0_v4 *)(state + 0x10))
            : "vf1", "vf2");
            func_0038CF68(&center, state + 0x20, -0.5000000596046448f);
            __asm__("lqc2 $vf1, %1\n\tlqc2 $vf2, %2\n\tvadd.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0"
            : "=m"(center)
            : "m"(center), "m"(*(vu0_v4 *)(state + 0x10))
            : "vf1", "vf2");
            if (!func_003D3CB0(state + 0x10, &old, 16, obj, &hit)
                || D_L01_001EAA00.object == *(u8 **)(obj + 0xB8)
                || (D_L01_001EAA00.object != 0 && *(s16 *)(D_L01_001EAA00.object + 0xAA) == 0x1625)) {
                goto continue_motion;
            }
impact:
    *(vu0_v4 *)(state + 0x10) = D_L01_001EAA00.position;
    if (!func_L01_00456250(obj)) {
        func_L01_003738E0(&D_L01_001EAA20, 20);
        func_L01_00456230(obj, 1);
    }
    func_003C2880(obj);
    return;
continue_motion:
            func_0038CF68(&accel, state + 0x20, 1.0000001192092896f);
            __asm__("lqc2 $vf1, %1\n\tlqc2 $vf2, %2\n\tvadd.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0"
                : "=m"(*(vu0_v4 *)state)
                : "m"(*(vu0_v4 *)state), "m"(accel)
                : "vf1", "vf2");
            func_L01_00404A10(func_L01_00373410, obj);
        }
    } else {
        func_L01_003739B8(state + 0x10);
        func_003C2880(obj);
    }
    return;

}
