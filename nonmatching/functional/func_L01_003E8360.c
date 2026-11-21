/* functional: medium. Camera per-frame spring/collision step (obj = camera, follow block at +0x70). Finds mobys near the camera line (func_003D4D00 around the midpoint of follow+0xB0 and the player entry), temporarily clearing their +0x98 word (restored from *(m+0x24)+0x10 at the end) and nudging the spring by +-1 degree about the player's up axis for the listed kinds (0x477, 0xB, 0x1AD6, 0x1ADA, 0x1944, 0x18DE, 0x1F89, 0x1CAA, 0x109E, 0x109F) when they sit within 25 degrees of the spring plane; kinds 0x191F/0x1920 also trigger func_003E8F20. When steer+0x4E is clear it runs func_003E7FA8 and func_003E7AA0, always func_003E77B0 (any non-zero result sets a 'moved' flag), clamps the spring length to >= 1.5 (steer+0x34 = 0x683, 0x589 for secondary kinds 4/0x51 when entry+0x454 < 8), steps the steer timer steer+0x34/+0x3A with the countdown helper func_0038CB00 and eases steer+0x30 with func_003C3BE8, rescales the spring, sets flag 0x20 of D_001DF810[player] for the rest of the step, counts frames of blocked line of sight in steer+0x4C (reset via func_003F5AC0 after 25), and calls func_003F5AC0(player, 0) when the camera is more than 30 units away (or 20 with a facing hero). Branches, constants, offsets and callee args checked against PAL asm; callee prototypes (func_003D4D00, func_003E8F20) taken from the call sites */
#include "vu0.h"
extern Entry_3E6C58 D_L01_001E2A40[];
extern u8 *D_L01_001EEA80[];
extern u8 *D_002A41C0[];
extern s32 D_L01_001DF810[];
extern vu0_v4 D_L01_001EAA20;
extern s32 D_L01_001D7BE0;
extern f32 D_L01_001DF680;
extern s32 D_001A5EF8;
__asm__(".extern D_L01_001D7BE0, 4");
__asm__(".extern D_L01_001DF680, 4");
extern s32 func_003D4D00(void *, s32, s32, s32, f32);
extern s32 func_003D3CB0(void *, void *, s32, s32, s32);
extern void func_L01_003E8F20(s32, f32, f32, f32);
extern s32 func_L01_00446720(void *);
extern s32 func_L01_003E7FA8(u8 *);
extern s32 func_L01_003E7AA0(u8 *);
extern s32 func_L01_003E77B0(u8 *);
extern s32 func_L01_003E4168(void *);
extern void func_L01_003F5AC0(s32, s32);
extern void func_0038CDF8(f32 *, f32 *, f32 *, f32);
extern f32 func_0038CE68(f32 *, f32 *);
extern void func_0038CE20(f32 *, f32 *, f32);
extern void func_0038CF68(f32 *, f32 *, f32);
extern f32 func_0038CEA8(f32 *);
extern void func_0038CE90(f32 *, f32 *, f32 *);
extern f32 func_0038D0C8(f32);
extern void func_0038D890(f32 *, f32 *, f32 *, f32);
extern f32 func_003C3BE8(f32, f32, f32);
static __inline__ void vsub_003E8360(void *d, void *x, void *y) {
    __asm__("lqc2 $vf1, %1\n\tlqc2 $vf2, %2\n\tvsub.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0"
        : "=m"(*(vu0_v4 *)d) : "m"(*(vu0_v4 *)x), "m"(*(vu0_v4 *)y) : "vf1", "vf2");
}
static __inline__ void vadd_003E8360(void *d, void *x, void *y) {
    __asm__("lqc2 $vf1, %1\n\tlqc2 $vf2, %2\n\tvadd.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0"
        : "=m"(*(vu0_v4 *)d) : "m"(*(vu0_v4 *)x), "m"(*(vu0_v4 *)y) : "vf1", "vf2");
}
void func_L01_003E8360(u8 *obj) {
    f32 center[4] __attribute__((aligned(16)));
    f32 pos[4] __attribute__((aligned(16)));
    f32 e[4] __attribute__((aligned(16)));
    f32 d[4] __attribute__((aligned(16)));
    f32 c[4] __attribute__((aligned(16)));
    u8 *follow = *(u8 **)(obj + 0x70);
    u8 *look = follow + 0x60;
    u8 *springs = follow + 0x180;
    u8 *steer = follow + 0x210;
    u8 *entry = (u8 *)D_L01_001E2A40 + *(s32 *)(obj + 0x94) * 0x460;
    u8 *hero = entry + 0x150;
    u8 *ent60 = entry + 0x60;
    u8 *m;
    s32 acc = 0, found = 0, fl, n, i, id;
    f32 radius, len, ratio, ang;
    u8 **in = D_L01_001EEA80;
    u8 **out = D_002A41C0;

    radius = *(f32 *)(springs + 0x2C) - *(f32 *)(steer + 0x30);
    func_0038CDF8(center, (f32 *)(follow + 0xB0), (f32 *)entry, 0.5f);
    radius = radius + 1.5f;
    n = func_003D4D00(center, 1, *(s32 *)(hero + 0xF0), 0, radius * 0.5f);
    for (i = 0; i < n; i++, in++) {
        m = *in;
        id = *(u16 *)(m + 0xAA);
        if ((u32)(id - 0x191F) < 2) {
            func_L01_003E8F20(*(s32 *)(obj + 0x94), -1.0f, -1.0f, D_L01_001DF680);
        }
        if (*(s32 *)(m + 0x98) == 0) continue;
        if (func_L01_00446720(m) != 0 && *(s16 *)(m + 0xAA) != 0xB6B) continue;
        id = *(s16 *)(m + 0xAA);
        if (id == 0x477 || id == 0xB || id == 0x1AD6 || id == 0x1ADA || id == 0x1944 ||
            id == 0x18DE || id == 0x1F89 || id == 0x1CAA || id == 0x109E || id == 0x109F) {
            vsub_003E8360(pos, m + 0x10, look + 0x50);
            func_0038CE20(e, (f32 *)(ent60 + 0x30), func_0038CE68((f32 *)(ent60 + 0x30), pos));
            vsub_003E8360(d, pos, e);
            func_0038CF68(d, d, 1.0f);
            len = func_0038CE68(d, (f32 *)springs);
            ratio = len / (*(f32 *)(springs + 0x2C) - *(f32 *)(steer + 0x30));
            ang = 1.5707964f - func_0038D0C8(ratio);
            if (__builtin_fabsf(ang) < 0.4363323f) {
                func_0038CE90(c, (f32 *)springs, (f32 *)(ent60 + 0x30));
                func_0038CF68(c, c, 1.0f);
                if (0.0f < func_0038CE68(c, pos)) {
                    func_0038D890((f32 *)springs, (f32 *)springs, (f32 *)(ent60 + 0x20), -0.017453292f);
                } else {
                    func_0038D890((f32 *)springs, (f32 *)springs, (f32 *)(ent60 + 0x20), 0.017453292f);
                }
            }
        } else {
            *out++ = m;
            found++;
            *(s32 *)(m + 0x98) = 0;
        }
    }
    if (*(s16 *)(steer + 0x4E) == 0) {
        if (func_L01_003E7FA8(obj) != 0) acc = 1;
        if (func_L01_003E7AA0(obj) != 0) acc = 1;
    }
    if (func_L01_003E77B0(obj) != 0) acc = 1;
    if (*(f32 *)(springs + 0x2C) - *(f32 *)(steer + 0x30) < 1.5f) {
        *(s16 *)(steer + 0x34) = 0x683;
        *(f32 *)(steer + 0x30) = *(f32 *)(springs + 0x2C) - 1.5f;
    }
    if (*(u8 **)(entry + 0x54) != 0) {
        id = *(s16 *)(*(u8 **)(entry + 0x54) + 0x86);
        if (id == 4 || id == 0x51) {
            if (*(s32 *)(entry + 0x454) < 8) *(s16 *)(steer + 0x34) = 0x589;
        }
    }
    if (*(s16 *)(steer + 0x3A) == 0) {
        if (acc != 0) goto reset_timer;
        if ((u16)(*(u16 *)(steer + 0x34) - 1) < 0x682) goto count_down;
        {
            u8 *p = *(u8 **)(hero + 0x134);
            if (*(f32 *)(p + 0x100) < 0.3f && *(f32 *)(p + 0x104) < 0.3f) goto count_down;
        }
        goto reset_timer;
    }
count_down:
    if (func_0038CB00(steer + 0x34) != 0) *(s16 *)(steer + 0x3A) = 0;
    if (*(s16 *)(steer + 0x3A) != 0) {
        if (func_0038CB00(steer + 0x34) != 0) *(s16 *)(steer + 0x3A) = 0;
    }
    *(f32 *)(steer + 0x30) = func_003C3BE8(0.0f, *(f32 *)(steer + 0x30), (f32)*(s16 *)(steer + 0x34) / 1664.0f);
    goto after_timer;
reset_timer:
    if (*(s16 *)(steer + 0x34) < 0x684) *(s16 *)(steer + 0x34) = 0x683;
    else func_0038CB00(steer + 0x34);
after_timer:
    func_0038CF68((f32 *)springs, (f32 *)springs, *(f32 *)(springs + 0x2C) - *(f32 *)(steer + 0x30));
    fl = 0;
    vadd_003E8360(pos, springs, look + 0x50);
    if (!(D_L01_001DF810[*(s32 *)(obj + 0x94)] & 0x20)) {
        D_L01_001DF810[*(s32 *)(obj + 0x94)] |= 0x20;
        fl = 1;
    }
    if (*(s32 *)(hero + 0x100) == 0x31) {
        *(s16 *)(steer + 0x4C) = 0;
    } else if (D_L01_001D7BE0 != -1 || *(s16 *)(steer + 0x4E) != 0) {
        *(s16 *)(steer + 0x4C) = 0;
    } else if (func_003D3CB0(look + 0x50, pos, D_L01_001DF810[*(s32 *)(obj + 0x94)], *(s32 *)(hero + 0xF0), 0) == 0) {
        *(s16 *)(steer + 0x4C) = 0;
    } else if (func_L01_003E4168(&D_L01_001EAA20) != 0) {
        *(s16 *)(steer + 0x4C) = 0;
    } else {
        *(s16 *)(steer + 0x4C) = *(u16 *)(steer + 0x4C) + 1;
        if (*(s16 *)(steer + 0x4C) >= 0x19) func_L01_003F5AC0(*(s32 *)(obj + 0x94), 1);
    }
    vsub_003E8360(d, obj + 0x30, pos);
    len = func_0038CEA8(d);
    vsub_003E8360(e, obj + 0x30, look + 0x50);
    func_0038CF68(e, e, 1.0f);
    if (30.0f < len && *(s32 *)(entry + 0x454) >= 9) {
        func_L01_003F5AC0(*(s32 *)(obj + 0x94), 0);
    } else if (hero[0x12B] == 0
               && (D_L01_001D7BE0 == -1 || D_001A5EF8 != 3)
               && *(s32 *)(hero + 0x11C) > 0
               && 0.0f < func_0038CE68(e, (f32 *)(hero + 0x80))
               && len < 20.0f
               && func_003D3CB0(obj + 0x30, pos, D_L01_001DF810[*(s32 *)(obj + 0x94)], *(s32 *)(hero + 0xF0), 0) != 0) {
        func_L01_003F5AC0(*(s32 *)(obj + 0x94), 0);
    }
    if (fl) D_L01_001DF810[*(s32 *)(obj + 0x94)] &= ~0x20;
    for (i = 0; i < found; i++) {
        m = D_002A41C0[i];
        *(s32 *)(m + 0x98) = *(s32 *)(*(u8 **)(m + 0x24) + 0x10);
    }
}
