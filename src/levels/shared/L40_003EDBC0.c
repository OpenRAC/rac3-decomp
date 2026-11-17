#include "common.h"

/* declared by functions of L40_003ED980.c, which this file was cut from */
extern void *func_L39_0066C2B8(void);
extern s32 func_L39_0066C280(s32, void *, s32, void *, void *);

/* localdecomp:start func_L40_003EDBC0 */
#include "vu0.h"

extern f32 func_0038CEA8(void *);
extern f32 func_L40_003F2158(s32, f32, f32);
extern void func_0038CF68(void *, void *, f32);

void func_L40_003EDBC0(u8 *a0, vu0_v4 *out, f32 angle) {
    u8 *vars = *(u8 **)(a0 + 0x68);
    vu0_v4 *dir = (vu0_v4 *)(vars + 0x110);

    *(f32 *)(vars + 0x118) = 0.0f;
    func_0038CF68(out, dir, func_L40_003F2158(*(s32 *)(vars + 0x250), func_0038CEA8(dir), angle));
    out->z = 0.0f;
    vec_add_ba(out, out, a0 + 0x10);
    out->z += *(f32 *)(vars + 0x70) + *(f32 *)(vars + 0x74);
}
/* localdecomp:end func_L40_003EDBC0 */

/* localdecomp:start func_L40_003EDC68 */
/* log: u8* offsets, if/else-if/else: 105 diff (default as: gp-lit floats; ps2as inline). struct views
   of moby/vars: no change. Copy order 2D0, 370, 380 (retail's alias-forced schedule) -> 6 diff and the
   cross-jumped i258 = 0. Last block: out = state->v2D0 after the 370 copy -> MATCH with --as ps2as.
   qzero() for retail's bare sq $zero. */
#include "vu0.h"

typedef struct {
    u8 b[16];
} B16_003EDC68;
typedef struct {
    u8 pad0[0x128];
    s32 time;
} G_003EDC68;
typedef struct {
    u8 pad0[0x70];
    f32 f70;
    f32 f74;
    u8 pad78[0x110 - 0x78];
    vu0_v4 v110;
    u8 pad120[0x250 - 0x120];
    s32 i250;
    u8 pad254[4];
    s32 i258;
    u8 pad25C[0x2B4 - 0x25C];
    s32 i2B4;
    u8 pad2B8[0x2D0 - 0x2B8];
    vu0_v4 v2D0;
    vu0_v4 v2E0;
    u8 pad2F0[0x370 - 0x2F0];
    vu0_v4 v370;
    vu0_v4 v380;
} St_003EDC68;
typedef struct {
    u8 pad0[0x10];
    vu0_v4 pos;
    u8 state;
    u8 pad21[0x68 - 0x21];
    St_003EDC68 *vars;
    u8 pad6C[0xF0 - 0x6C];
    vu0_v4 vF0;
} Mo_003EDC68;

__asm__(".extern D_L40_00246D94, 4");
extern f32 D_L40_00246D94;
extern G_003EDC68 D_001A5CD0;
extern f32 func_0038CEA8(void *);
extern void func_L40_003F16A8(void *);
extern void func_L40_003EDBC0(u8 *, vu0_v4 *, f32);
extern f32 func_L40_003F21B8(vu0_v4 *, vu0_v4 *, s32, void *, f32);
extern s32 func_L39_005BEAF8(vu0_v4 *, vu0_v4 *, s32);
extern f32 func_L40_003F2198(f32, s32);
extern void func_L40_003F19E0(vu0_v4 *);
extern void func_L40_003F1758(void *);
extern void *func_L39_0066C2B8(void);
extern s32 func_L39_0066C280(s32, void *, s32, void *, void *);

void func_L40_003EDC68(Mo_003EDC68 *a0, s32 uid, s32 send) {
    vu0_v4 out;
    vu0_v4 pos;
    vu0_v4 tmp;
    St_003EDC68 *state = a0->vars;
    s32 n;
    f32 dist;
    f32 t;
    s32 hit;
    u8 *msg;
    u8 *p;

    n = (f32)(state->i2B4 + (s32)D_L40_00246D94 - D_001A5CD0.time) * 0.06f;
    state->i250 = n;
    dist = func_0038CEA8(&state->v110);
    if (n <= 0) {
        return;
    }
    func_L40_003F16A8(a0);
    pos = a0->pos;
    pos.z += state->f70 + state->f74;
    func_L40_003EDBC0((u8 *)a0, &out, 0.0f);
    t = func_L40_003F21B8(&pos, &out, 0, a0, state->f70);
    hit = func_L39_005BEAF8(&pos, &out, 0);
    if (t != 1.0f || hit == 0) {
        func_L40_003EDBC0((u8 *)a0, &out, 0.0f);
        t = func_L40_003F21B8(&pos, &out, 0, a0, state->f70);
        hit = func_L39_005BEAF8(&pos, &out, 0);
        if ((t != 1.0f || hit == 0) && state->i258 == 1) {
            func_L40_003EDBC0((u8 *)a0, &out, func_L40_003F2198(dist, n));
            t = func_L40_003F21B8(&pos, &out, 0, a0, state->f70);
            hit = func_L39_005BEAF8(&pos, &out, 0);
        }
    }
    if (t == 1.0f && hit == 1) {
        out.z = a0->pos.z;
        state->v2D0 = out;
        state->v370 = a0->vF0;
        state->v380 = state->v110;
        state->i258 = 0;
    } else if (state->i258 <= 0) {
        a0->state = 0x17;
        state->v2D0 = state->v2E0;
        state->v370 = a0->vF0;
        state->v380 = state->v110;
        state->i258++;
    } else {
        state->v2D0 = a0->pos;
        state->v370 = a0->vF0;
        out = state->v2D0;
        qzero(&state->v110);
        qzero(&state->v380);
        tmp = a0->pos;
        func_L40_003F19E0(&tmp);
        state->i258 = 0;
    }
    func_L40_003F1758(a0);
    if (send == 1 && a0->state == 0x18) {
        msg = func_L39_0066C2B8();
        if (msg != 0) {
            p = msg + ((s32 (*)(s32, s32, s32, s32, void *))func_L39_0066C280)(1, uid, D_001A5CD0.time + 100, 2, msg);
            *(B16_003EDC68 *)p = *(B16_003EDC68 *)&out;
            p += 16;
            *(B16_003EDC68 *)p = *(B16_003EDC68 *)&a0->vF0;
            p += 16;
            *(B16_003EDC68 *)p = *(B16_003EDC68 *)&state->v110;
            p += 16;
            *(s32 *)p = D_001A5CD0.time;
            p += 4;
            *(s32 *)msg = p - msg;
        }
    }
}
/* localdecomp:end func_L40_003EDC68 */

/* localdecomp:start func_L40_003EE008 */
#include "vu0.h"

extern void func_L01_00443B88(f32 *, f32, f32);
extern f32 func_003C3D30(void *, s32, f32, void *);
extern f32 func_0038CF00(void *, void *);
extern f32 func_L40_003F21B8(vu0_v4 *, vu0_v4 *, s32, void *, f32);

s32 func_L40_003EE008(u8 *a0) {
    vu0_v4 off;
    u8 *vars = *(u8 **)(a0 + 0x68);
    vu0_v4 *pos = (vu0_v4 *)(a0 + 0x10);
    vu0_v4 *aim = (vu0_v4 *)(vars + 0x390);

    func_L01_00443B88(&off.x, 1.5f, 2.5f);
    off.z = 0.0f;
    vec_add_ab(aim, &off, vars + 0x360);
    *(f32 *)(vars + 0x398) += 1.0f;
    *(f32 *)(vars + 0x398) = func_003C3D30(aim, 0, 0.5f, 0) + 0.5f;
    if (func_0038CF00(aim, pos) > 7.0f) {
        *(s32 *)(vars + 0x2B0) = 0;
        return 0;
    }
    if (func_L40_003F21B8(pos, aim, 0, a0, *(f32 *)(vars + 0x70)) > 0.9f) {
        *(s32 *)(vars + 0x2B0) = 1;
        return 1;
    }
    *(s32 *)(vars + 0x2B0) = 0;
    return 0;
}
/* localdecomp:end func_L40_003EE008 */
