/* PAL near miss (haiku-w1): 14 words differ with the file's flags (-O2 -G8 -fopt-stack -mno-check-zero-division @ps2as); the VU0 helpers need j-form operands (-mvu0-use-vf0-vf2 is not on the file line); the remaining words are the hit=1 store placement and the prologue saves. */
#include "common.h"
/* localdecomp:start func_L01_004C7E70 */
typedef struct {
    Vec4_004C4AD8 direction, position, velocity;
    u8 *target;
    s32 *ignore;
    s32 ignore_count;
    f32 radius, blend, min_dot;
    s32 unused48, mask, allow_type5, stamp, offset_enabled;
    f32 offset;
} State_004C7E70;
typedef struct {
    u8 pad[0x18];
    u8 *target;
    u8 pad1C[4];
    Vec4_004C4AD8 near_pos, hit_pos, direction;
} Collision_004C7E70;
extern Collision_004C7E70 D_L01_001EAA00;
static __inline__ void add_004C7E70(Vec4_004C4AD8 *d, Vec4_004C4AD8 *a, Vec4_004C4AD8 *b) {
    __asm__("lqc2 $vf2, %2\n\tlqc2 $vf1, %1\n\tvadd.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0"
        : "=m"(*d) : "m"(*a), "m"(*b) : "vf1", "vf2", "memory");
}
static __inline__ void sub_004C7E70(Vec4_004C4AD8 *d, Vec4_004C4AD8 *a, Vec4_004C4AD8 *b) {
    __asm__("lqc2 $vf2, %2\n\tlqc2 $vf1, %1\n\tvsub.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0"
        : "=m"(*d) : "m"(*a), "m"(*b) : "vf1", "vf2", "memory");
}
s32 func_L01_004C7E70(State_004C7E70 *s) {
    extern void func_L01_004C7D98(void *, Vec4_004C4AD8 *);
    extern void func_0038CF68(Vec4_004C4AD8 *, Vec4_004C4AD8 *, f32);
    extern s32 func_L01_003FB640(Vec4_004C4AD8 *, f32, s32, u8 *);
    extern s32 func_003D3CB0(void *, Vec4_004C4AD8 *, s32, u8 *, s32);
    extern s32 func_003D5630(void);
    extern void func_0038CE20(Vec4_004C4AD8 *, Vec4_004C4AD8 *, f32);
    extern f32 func_0038CE68(Vec4_004C4AD8 *, T_004C4AD8 *);
    extern void func_L01_0040E790(Vec4_004C4AD8 *, Vec4_004C4AD8 *, Vec4_004C4AD8 *);
    Vec4_004C4AD8 original, position, projected, residual;
    s32 result = 0;
    s32 hit;
    s32 i;
    f32 dot;
    func_L01_004C7D98(s->target + 0x10, &original);
    if (s->offset_enabled) {
        func_0038CF68(&position, (Vec4_004C4AD8 *)(s->target + 0xE0), s->offset);
        add_004C7E70(&position, &s->position, &position);
    } else {
        *(u128_4C4A18 *)&position = *(u128_4C4A18 *)&s->position;
    }
    if (func_L01_003FB640(&position, s->radius, s->mask, s->target)) {
        hit = 1;
    } else {
        hit = 0;
        if (func_003D3CB0(s, &s->position, s->mask, s->target, 0)) hit = 2;
    }
    s->target = 0;
    if (hit) {
        s->stamp = func_003D5630();
        if (D_L01_001EAA00.target) {
            for (i = 0; i < s->ignore_count; i++) {
                if (*(s16 *)(D_L01_001EAA00.target + 0xAA) == s->ignore[i]) return 0;
            }
            s->target = D_L01_001EAA00.target;
        }
        if (hit == 1) {
            *(u128_4C4A18 *)&s->position = *(u128_4C4A18 *)&D_L01_001EAA00.hit_pos;
        } else {
            *(u128_4C4A18 *)&s->position = *(u128_4C4A18 *)&D_L01_001EAA00.near_pos;
        }
        func_0038CE20(&s->direction, &D_L01_001EAA00.direction, 0.0009765625f);
        func_0038CF68(&s->direction, &s->direction, 1.0f);
        if (func_0038CE68(&original, (T_004C4AD8 *)s) < s->min_dot ||
            (s->target && (*(u8 **)(s->target + 0x24))[0x46] == 5 && s->allow_type5)) {
            func_L01_0040E790(&s->velocity, &s->velocity, &s->direction);
            result = 1;
            dot = func_0038CE68(&s->velocity, (T_004C4AD8 *)s);
            func_0038CE20(&projected, &s->direction, dot);
            sub_004C7E70(&residual, &s->velocity, &projected);
            func_0038CE20(&s->velocity, &projected, s->blend);
            add_004C7E70(&s->velocity, &residual, &s->velocity);
        } else {
            result = 2;
            *(u128_4C4A18 *)&s->position = *(u128_4C4A18 *)&D_L01_001EAA00.near_pos;
        }
    }
    return result;
}
