/* functional: high. VU0 inline asm kept (lqc2/vsub/sqc2); all callees, offsets, constants and branches checked against the PAL asm; only scheduling differs. */
#include "common.h"
/* localdecomp:start func_L01_0036C828 */
#include "vu0.h"
static __inline__ void sub_ab_0036C828(void *d, void *a, void *b) {
    __asm__("lqc2 vf1, %1\n\tlqc2 vf2, %2\n\tvsub.xyz vf1, vf1, vf2\n\tsqc2 vf1, %0" : "=m"(*(vu0_v4 *)d) : "m"(*(vu0_v4 *)a), "m"(*(vu0_v4 *)b) : "vf1", "vf2");
}
static __inline__ void sub_ba_0036C828(void *d, void *a, void *b) {
    __asm__("lqc2 vf2, %2\n\tlqc2 vf1, %1\n\tvsub.xyz vf1, vf1, vf2\n\tsqc2 vf1, %0" : "=m"(*(vu0_v4 *)d) : "m"(*(vu0_v4 *)a), "m"(*(vu0_v4 *)b) : "vf1", "vf2");
}
typedef struct { u8 pad[0x54]; s32 mode; } Vars_0036C828;
typedef struct { u8 pad[0x18]; u8 *hit; u8 pad1C[4]; vu0_v4 pos; } Hit_0036C828;
typedef struct { u8 p0; u8 effect; u8 p2[0x6A]; f32 damage; u8 p70[0x80]; } Weapon_0036C828;
extern Hit_0036C828 D_L01_001EAA00;
extern vu0_v4 D_L01_001EAA20;
extern u8 *D_001A71A0[];
extern u8 D_001425C0[];
extern Weapon_0036C828 D_L01_002C5600[];
u8 *func_L01_0036C828(u8 *owner, vu0_v4 *from, vu0_v4 *to, f32 *out, f32 damage) {
    extern void func_0038CF68(void *, void *, f32);
    extern s32 func_003D3CB0(void *, void *, s32, u8 *, s32);
    extern void func_L01_00389B00(void *, void *, void *, s32, f32);
    extern void func_L01_0036AA60(void *, void *, void *, s32, f32);
    extern f32 func_0038CF00(void *, void *);
    extern void func_L01_00446978(u8 *, f32 *);
    extern void func_L01_0034C9F0(u8 *, s32, u8 *);
    Vars_0036C828 *vars;
    vu0_v4 delta;
    f32 dist;
    u8 *hit;
    u8 *result;
    sub_ab_0036C828(out, to, from);
    vars = *(Vars_0036C828 **)(owner + 0x68);
    func_0038CF68(out, out, 1.5f);
    out[3] = 5627.9248046875f;
    if (func_003D3CB0(from, to, 16, D_001A71A0[0], 0)) {
        sub_ba_0036C828(&delta, to, from);
        func_0038CF68(&delta, &delta, 1.0f);
        sub_ba_0036C828(&delta, &D_L01_001EAA20, from);
        if (vars->mode) func_L01_00389B00(from, &delta, &D_L01_001EAA20, 1, damage);
        else func_L01_0036AA60(from, &delta, &D_L01_001EAA20, 1, damage);
        if (D_L01_001EAA00.hit != 0) {
            damage = ((Weapon_0036C828 *)(D_001425C0[0x27] * 0xF0 + (u8 *)D_L01_002C5600))->damage;
            if (vars->mode) damage *= 3.0f;
            dist = func_0038CF00(&D_L01_001EAA00.pos, from);
            if (dist < 10.0f) out[7] = damage;
            else if (dist < 14.0f) out[7] = damage * 0.75f;
            else if (dist < 20.0f) out[7] = damage * 0.5f;
            else out[7] = damage * 0.125f;
            func_L01_00446978(D_L01_001EAA00.hit, out);
            if (D_L01_002C5600[D_001425C0[0x27]].effect) func_L01_0034C9F0(D_L01_001EAA00.hit, 39, owner);
            hit = D_L01_001EAA00.hit;
            result = hit;
            if (hit == 0) goto none;
            if (*(u8 **)(hit + 0x24) == 0) goto none;
            if ((*(u8 **)(hit + 0x24))[0x46] != 5) result = 0;
            goto done;
        }
    } else {
        sub_ab_0036C828(&delta, to, from);
        if (vars->mode) func_L01_00389B00(from, &delta, to, 0, damage);
        else func_L01_0036AA60(from, &delta, to, 0, damage);
    }
none:
    result = 0;
done:
    return result;
}
/* localdecomp:end func_L01_0036C828 */
