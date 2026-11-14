#include "common.h"

/* NTSC-U counterpart of func_L39_0054C7E8 (src/levels/shared/L39_0054C7E8.c) */
/* localdecomp:start func_L39_0054BED0 */
#include "vu0.h"
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_0054C7E8;
typedef struct { u8 p0[0x2524]; void *f2524; } P_0054C7E8;
typedef struct {
    u8 p0[0x18]; f32 f18;
    u8 p1C[0x30 - 0x1C]; V4_0054C7E8 f30;
    V4_0054C7E8 f40;
    u8 p50[0x58 - 0x50]; P_0054C7E8 *p58;
    u8 p5C[0x64 - 0x5C]; u8 b64;
    u8 p65[3]; u8 b68;
    u8 p69[3]; u8 b6C; u8 b6D;
} V_0054C7E8;
typedef struct {
    u8 p0[0x10]; V4_0054C7E8 pos;
    u8 p20[0x68 - 0x20]; V_0054C7E8 *vars;
} M_0054C7E8;
typedef struct { u8 b0, b1, b2; } Msg_0054C7E8;
typedef struct {
    u8 p0[4]; s32 f4;
    u8 p8[0x170 - 0x8]; s32 f170;
    u8 p174[0x7D4 - 0x174]; u8 b7D4;
} S_1A5CD0_0054C7E8;
extern S_1A5CD0_0054C7E8 D_001A5E50;
extern s32 D_L39_00240730;
extern void func_003886E8(void *, void *, f32);
extern f32 func_003887C8(void *, void *);
extern s32 func_003CE740(void *, void *, s32, void *, s32);
extern void func_0014AD08(s32, s32, s32, s32, s32, void *);

void func_L39_0054BED0(M_0054C7E8 *m, V4_0054C7E8 *p1, V4_0054C7E8 *p2, f32 dist) {
    V_0054C7E8 *v = m->vars;
    V4_0054C7E8 tmp;
    V4_0054C7E8 a;
    V4_0054C7E8 b;
    Msg_0054C7E8 msg;
    f32 d;
    s32 hit;

    if (v->b6D == 0 || v->b6C != 0) {
        return;
    }
    if (!(dist <= v->f18 * 2.9f)) {
        return;
    }
    func_003886E8(&tmp, &v->f30, v->f18 * 2.0f);
    vec_add_ba(&a, &m->pos, &tmp);
    func_003886E8(&tmp, p2, 2.0f);
    vec_add_ba(&b, p1, &tmp);
    vec_add_ab(&b, &b, &v->f40);
    if (!(func_003887C8(&b, &a) <= v->f18)) {
        return;
    }
    if (func_003CE740(&a, &b, 0x12, v->p58->f2524, 0) != 0) {
        return;
    }
    d = func_003887C8(p1, &a);
    if (func_003CE740(&a, p1, 0x12, v->p58->f2524, 0) != 0) {
        return;
    }
    hit = 0;
    if (d <= v->f18) {
        hit = 1;
    } else {
        func_003886E8(&tmp, &v->f30, v->f18);
        vec_add_ab(&a, &m->pos, &tmp);
        if (func_003887C8(p1, &a) <= v->f18) {
            hit = 1;
        }
    }
    if (hit) {
        msg.b0 = v->b64;
        msg.b2 = v->b68;
        msg.b1 = 2;
        if (D_001A5E50.f170 == 0) {
            func_0014AD08(D_001A5E50.b7D4 | 0xC0, D_001A5E50.f4, -1, D_L39_00240730, 3, &msg);
        }
    }
}
/* localdecomp:end func_L39_0054BED0 */
