#include "common.h"

/* NTSC-U counterpart of func_L40_003EDC68 (src/levels/shared/L40_003EDBC0.c) */
extern void *func_L39_006699B0(void);
extern s32 func_L39_00669978(s32, void *, s32, void *, void *);
#include "vu0.h"
extern f32 func_00388770(void *);

/* localdecomp:start func_L40_003ED7C8 */
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

__asm__(".extern D_L40_00246F14_003ED7C8, 4");
extern f32 D_L40_00246F14_003ED7C8;
extern G_003EDC68 D_001A5E50;
extern f32 func_00388770(void *);
extern void func_L40_003F1200(void *);
extern void func_L40_003ED720(u8 *, vu0_v4 *, f32);
extern f32 func_L40_003F1CF8(vu0_v4 *, vu0_v4 *, s32, void *, f32);
extern s32 func_L39_005BCB50(vu0_v4 *, vu0_v4 *, s32);
extern f32 func_L40_003F1CD8(f32, s32);
extern void func_L40_003F1538(vu0_v4 *);
extern void func_L40_003F12B0(void *);
extern void *func_L39_006699B0(void);
extern s32 func_L39_00669978(s32, void *, s32, void *, void *);

void func_L40_003ED7C8(Mo_003EDC68 *a0, s32 uid, s32 send) {
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

    n = (f32)(state->i2B4 + (s32)D_L40_00246F14_003ED7C8 - D_001A5E50.time) * 0.06f;
    state->i250 = n;
    dist = func_00388770(&state->v110);
    if (n <= 0) {
        return;
    }
    func_L40_003F1200(a0);
    pos = a0->pos;
    pos.z += state->f70 + state->f74;
    func_L40_003ED720((u8 *)a0, &out, 0.0f);
    t = func_L40_003F1CF8(&pos, &out, 0, a0, state->f70);
    hit = func_L39_005BCB50(&pos, &out, 0);
    if (t != 1.0f || hit == 0) {
        func_L40_003ED720((u8 *)a0, &out, 0.0f);
        t = func_L40_003F1CF8(&pos, &out, 0, a0, state->f70);
        hit = func_L39_005BCB50(&pos, &out, 0);
        if ((t != 1.0f || hit == 0) && state->i258 == 1) {
            func_L40_003ED720((u8 *)a0, &out, func_L40_003F1CD8(dist, n));
            t = func_L40_003F1CF8(&pos, &out, 0, a0, state->f70);
            hit = func_L39_005BCB50(&pos, &out, 0);
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
        func_L40_003F1538(&tmp);
        state->i258 = 0;
    }
    func_L40_003F12B0(a0);
    if (send == 1 && a0->state == 0x18) {
        msg = func_L39_006699B0();
        if (msg != 0) {
            p = msg + ((s32 (*)(s32, s32, s32, s32, void *))func_L39_00669978)(1, uid, D_001A5E50.time + 100, 2, msg);
            *(B16_003EDC68 *)p = *(B16_003EDC68 *)&out;
            p += 16;
            *(B16_003EDC68 *)p = *(B16_003EDC68 *)&a0->vF0;
            p += 16;
            *(B16_003EDC68 *)p = *(B16_003EDC68 *)&state->v110;
            p += 16;
            *(s32 *)p = D_001A5E50.time;
            p += 4;
            *(s32 *)msg = p - msg;
        }
    }
}
/* localdecomp:end func_L40_003ED7C8 */
