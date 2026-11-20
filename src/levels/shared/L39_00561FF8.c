#include "common.h"

/* localdecomp:start func_L39_00561FF8 */
#include "vu0.h"

typedef struct { u8 *g; s32 pad; f32 v[4]; } S_00561FF8;

extern u8 *D_L39_0024CE20[] __attribute__((section(".sdata")));
extern S_00561FF8 D_L39_0025F758;
extern u8 D_L39_00242930[] __attribute__((section(".sdata")));
extern u8 D_L39_002FB000[];
extern s32 func_L01_004561B8(void *);
extern s32 func_0038CAD0(void *);
extern void func_003C2880(void *);
extern f32 func_0038CEA8(void *);
extern void func_0038CF68(void *, void *, f32);
extern void func_L01_00446760(void *, void *, s32, void *, f32);
extern void func_L39_005FFDF8(s32);
extern s32 func_003D3CB0(void *, void *, s32, void *, void *);
extern void func_L39_005FFE78(void);
extern f32 func_0038CF00(void *, void *);
extern void func_L07_003CC1C0(void *);
extern void func_L39_00562858(void *, void *);
extern void func_L01_00404A10(void *, void *);
extern void func_L07_003CB1F8(void *);

static __inline__ void step_00561FF8(vu0_v4 *out, u8 *pos, u8 *vel) {
    if (*(f32 *)(vel + 0x20) < func_0038CEA8(vel)) {
        vec_add_ab(out, pos, vel);
    } else {
        func_0038CF68(out, vel, *(f32 *)(vel + 0x20));
        vec_add_ab(out, out, pos);
    }
}

static __inline__ s32 coll_00561FF8(void *from, void *to, s32 flags, void *ign, void *info, s32 player) {
    u8 *p = D_L39_0024CE20[player];
    s32 hit;

    player = -1;
    if (p != 0) {
        player = *(s32 *)(p + 0x2548);
    }
    func_L39_005FFDF8(player);
    hit = func_003D3CB0(from, to, flags, ign, info);
    func_L39_005FFE78();
    return hit;
}

void func_L39_00561FF8(u8 *o) {
    u8 *st = *(u8 **)(o + 0x68);
    vu0_v4 old;
    vu0_v4 v;
    u8 b[0x30] __attribute__((aligned(16)));
    s32 hit;
    s32 n;
    f32 f;

    old = *(vu0_v4 *)(o + 0x10);
    if (o[0x20] == 0) {
        if (func_L01_004561B8(o) == 0) {
            vec_add_ab(o + 0x10, o + 0x10, st);
        }
        if (func_0038CAD0(st + 0x24) != 0) {
            func_003C2880(o);
            return;
        }
        if (*(s32 *)(st + 0x30) == 0) {
            step_00561FF8(&v, o + 0x10, st);
            func_L01_00446760(b, o, 0x10001, D_L39_00242930, *(f32 *)(st + 0x34));
            *(s32 *)(b + 0x28) = *(s32 *)(st + 0x44);
            hit = coll_00561FF8(o + 0x10, &v, 0x10, *(void **)(o + 0xB8), b, *(s32 *)(st + 0x40));
            if (hit != 0) {
                *(s32 *)(st + 0x30) = 1;
                *(vu0_v4 *)(st + 0x10) = *(vu0_v4 *)D_L39_0025F758.v;
                f = func_0038CF00(o + 0x10, st + 0x10) / func_0038CEA8(st);
                n = ((s32)f * 5 + 2) / 6;
                *(s32 *)(st + 0x24) = n;
                *(f32 *)(st + 0x28) = 1.0f / n;
                if (D_L39_0025F758.g == 0) {
                    func_L07_003CC1C0(o);
                } else {
                    func_L39_00562858(st + 0x10, D_L39_002FB000);
                }
            }
        }
        func_L01_00404A10(func_L07_003CB1F8, o);
    }
    if (*(f32 *)(o + 0x10) < 2.0f || 1021.0f < *(f32 *)(o + 0x10) ||
        *(f32 *)(o + 0x14) < 2.0f || 1021.0f < *(f32 *)(o + 0x14) ||
        *(f32 *)(o + 0x18) < 2.0f || 1021.0f < *(f32 *)(o + 0x18)) {
        func_003C2880(o);
    }
}
/* localdecomp:end func_L39_00561FF8 */
